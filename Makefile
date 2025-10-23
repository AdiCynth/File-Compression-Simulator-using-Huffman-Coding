# Makefile for Huffman Compression Simulator

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = huffman_simulator
SOURCE = huffman_simulator.c

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Clean build artifacts
clean:
	rm -f $(TARGET) $(TARGET).exe

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run on Windows
run-win: $(TARGET)
	$(TARGET).exe

# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build
release: CFLAGS += -O2
release: $(TARGET)

# Install (copy to system path - Unix/Linux only)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/$(TARGET)

.PHONY: all clean run run-win debug release install uninstall
