# File Compression Simulator using Huffman Coding

## Overview

This project simulates the process of file compression using Huffman Coding, a lossless data compression algorithm. The simulator demonstrates how fundamental data structures such as Min Heap, Binary Tree, and Stack work together to efficiently encode text data based on character frequency.

**Note:** This is a simulator for educational purposes, not a fully functional compressor.

## Features

- **Min Heap Implementation**: Used for efficient frequency-based sorting of characters
- **Binary Tree Structure**: Creates the optimal encoding tree based on character frequencies
- **Huffman Code Generation**: Generates variable-length binary codes for each character
- **Interactive Interface**: User-friendly console interface for testing different texts

## Data Structures Used

1. **Min Heap**: 
   - Maintains nodes in frequency order
   - Supports efficient insertion and extraction of minimum frequency nodes
   - Used for building the Huffman tree

2. **Binary Tree**:
   - Represents the Huffman encoding structure
   - Internal nodes contain combined frequencies
   - Leaf nodes contain actual characters and their frequencies

3. **Stack (Implicit)**:
   - Used during tree traversal for code generation
   - Maintains the path from root to leaf nodes

## Algorithm Overview

1. **Frequency Analysis**: Count the occurrence of each character in the input text
2. **Min Heap Construction**: Create a min heap with character-frequency pairs
3. **Tree Building**: Repeatedly extract two minimum frequency nodes and combine them
4. **Code Generation**: Traverse the tree to generate binary codes for each character
5. **Output**: Display the generated Huffman codes

## Compilation and Usage

### Prerequisites
- GCC compiler (or any C99 compatible compiler)
- Make utility (optional, for using Makefile)

### Compilation

#### Using Makefile (Recommended)
```bash
# Compile the program
make

# Compile with debug information
make debug

# Compile optimized release version
make release

# Clean build artifacts
make clean
```

#### Manual Compilation
```bash
gcc -Wall -Wextra -std=c99 -g -o huffman_simulator huffman_simulator.c
```

### Running the Program

#### Linux/macOS
```bash
make run
# or
./huffman_simulator
```

#### Windows
```bash
make run-win
# or
huffman_simulator.exe
```

### Example Usage

```
===========================================
        FILE COMPRESSION SIMULATOR         
===========================================
This program demonstrates Huffman Coding using:
- Min Heap (for frequency sorting)
- Binary Tree (for encoding structure)
- Stack (for traversal and code generation)
Note: This is a simulation, not a real compressor.

Enter a text to simulate compression: hello world

Generated Huffman Codes:
 : 00
d: 010
e: 011
h: 100
l: 101
o: 110
r: 1110
w: 1111

Simulation Complete. Compression ratio is illustrative only.
```

## Project Structure

```
DS IA2/
├── huffman_simulator.c    # Main source file
├── Makefile              # Build configuration
└── README.md             # This file
```

## Educational Value

This simulator helps understand:

- **Greedy Algorithm Design**: Huffman coding uses a greedy approach to build optimal trees
- **Data Structure Integration**: How different data structures work together
- **Algorithm Complexity**: Time and space complexity analysis
- **Lossless Compression**: Principles behind efficient data encoding

## Technical Details

- **Time Complexity**: O(n log n) where n is the number of unique characters
- **Space Complexity**: O(n) for storing the tree and heap
- **Character Support**: Full ASCII character set (0-255)
- **Maximum Input Size**: 256 characters per input

## Limitations

- This is a simulation for educational purposes only
- Does not perform actual file compression/decompression
- No persistence of generated codes
- Limited to single input session

## Future Enhancements

Potential improvements for a full implementation:

- File I/O operations for actual compression
- Binary output format
- Decompression functionality
- GUI interface
- Performance optimizations
- Support for larger files

## License

This project is created for educational purposes. Feel free to use and modify as needed.

## Author

[Your Name] - Data Structures Implementation Assignment 2
