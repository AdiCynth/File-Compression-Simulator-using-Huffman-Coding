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

typedef struct {
    char character;
    char code[MAX_SIZE];
    int frequency;
} CodeEntry;

CodeEntry codes[MAX_SIZE];
int codeCount = 0;

Node* createNode(char data, unsigned freq);
void insertSorted(Node** head, Node* newNode);
Node* extractMin(Node** head);
void buildHuffmanTree(char data[], int freq[], int size);
void storeCodes(Node* root, int arr[], int top);
void simulateCompression(const char *text);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("{\"error\": \"No input text provided\"}\n");
        return 1;
    }
    
    simulateCompression(argv[1]);
    return 0;
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

void storeCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        codes[codeCount].character = root->data;
        codes[codeCount].frequency = root->freq;
        codes[codeCount].code[0] = '\0';
        for (int i = 0; i < top; i++) {
            char bit[2] = {arr[i] + '0', '\0'};
            strcat(codes[codeCount].code, bit);
        }
        codeCount++;
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
    storeCodes(head, arr, top);
}

void simulateCompression(const char *text) {
    int freq[MAX_SIZE] = {0};
    int totalChars = 0;
    
    for (int i = 0; text[i]; i++) {
        freq[(unsigned char)text[i]]++;
        totalChars++;
    }

    char data[MAX_SIZE];
    int freqArr[MAX_SIZE], size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i]) {
            data[size] = (char)i;
            freqArr[size++] = freq[i];
        }
    }

    buildHuffmanTree(data, freqArr, size);
    
    // Calculate compression stats
    int originalBits = totalChars * 8;
    int compressedBits = 0;
    for (int i = 0; i < codeCount; i++) {
        compressedBits += codes[i].frequency * strlen(codes[i].code);
    }
    
    // Output JSON
    printf("{\"codes\": [");
    for (int i = 0; i < codeCount; i++) {
        printf("{\"char\": \"%c\", \"code\": \"%s\", \"freq\": %d}", 
               codes[i].character, codes[i].code, codes[i].frequency);
        if (i < codeCount - 1) printf(", ");
    }
    printf("], \"original_bits\": %d, \"compressed_bits\": %d, \"compression_ratio\": %.2f}\n",
           originalBits, compressedBits, (float)originalBits / compressedBits);
}

