# Huffman Compression Web Simulator

A modern web interface for visualizing Huffman compression with red-orange-blue highlights.

## Setup Instructions

### 1. Compile the C Program
```bash
gcc huffman_web.c -o huffman_web.exe
```

### 2. Install Python Dependencies
```bash
pip install flask
```

### 3. Run the Web Server
```bash
python app.py
```

### 4. Open Your Browser
Navigate to: **http://127.0.0.1:5173**

## Features

- 🎨 Modern UI with gradient backgrounds (red-orange-blue theme)
- 📊 Visual statistics cards showing compression metrics
- 📈 Interactive table with frequency bars
- ⚡ Real-time compression visualization
- 🎯 Smooth animations and hover effects

## Usage

1. Enter or paste text into the input field
2. Click "Compress Text" button
3. View the generated Huffman codes and compression statistics
4. See character frequencies visualized with colorful bars

## Port

The application runs on **port 5173** (localhost only).

