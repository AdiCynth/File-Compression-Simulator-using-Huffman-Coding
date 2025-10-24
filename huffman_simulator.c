#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
    struct Node *next;
} Node;

Node* createNode(char data, unsigned freq);
void insertSorted(Node** head, Node* newNode);
Node* extractMin(Node** head);
void buildHuffmanTree(char data[], int freq[], int size);
void printCodes(Node* root, int arr[], int top);
void simulateCompression(const char *text);
void printIntro();

int main() {
    printIntro();

    char text[MAX_SIZE];
    printf("\nEnter a text to simulate compression: ");
    fgets(text, MAX_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';
    simulateCompression(text);
    return 0;
}

void printIntro() {
    printf("===========================================\n");
    printf("      FILE COMPRESSION SIMULATOR (C)       \n");
    printf("===========================================\n");
    printf("This program demonstrates Huffman Coding using:\n");
    printf("- Binary Tree (for encoding structure)\n");
    printf("- Sorted Linked List (for frequency ordering)\n");
    printf("- Recursive Traversal (stack-like behavior)\n");
    printf("===========================================\n");
}

Node* createNode(char data, unsigned freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = node->next = NULL;
    return node;
}

void insertSorted(Node** head, Node* newNode) {
    if (*head == NULL || (*head)->freq >= newNode->freq) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next && temp->next->freq < newNode->freq)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

Node* extractMin(Node** head) {
    if (*head == NULL)
        return NULL;
    Node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    return temp;
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void buildHuffmanTree(char data[], int freq[], int size) {
    Node *head = NULL;
    for (int i = 0; i < size; ++i)
        insertSorted(&head, createNode(data[i], freq[i]));

    while (head && head->next) {
        Node* left = extractMin(&head);
        Node* right = extractMin(&head);
        Node* top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertSorted(&head, top);
    }

    int arr[MAX_SIZE], top = 0;
    printf("\nGenerated Huffman Codes:\n");
    printCodes(head, arr, top);
}

void simulateCompression(const char *text) {
    int freq[MAX_SIZE] = {0};
    for (int i = 0; text[i]; i++)
        freq[(unsigned char)text[i]]++;

    char data[MAX_SIZE];
    int freqArr[MAX_SIZE], size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i]) {
            data[size] = (char)i;
            freqArr[size++] = freq[i];
        }
    }

    buildHuffmanTree(data, freqArr, size);
    printf("\nSimulation Complete. Compression ratio is illustrative only.\n");
}
