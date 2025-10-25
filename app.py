from flask import Flask, render_template, request, jsonify
import subprocess
import json
import os

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/compress', methods=['POST'])
def compress():
    data = request.json
    text = data.get('text', '')
    
    if not text:
        return jsonify({'error': 'No text provided'}), 400
    
    # Check if compiled executable exists
    exe_path = 'huffman_web.exe'
    if not os.path.exists(exe_path):
        return jsonify({'error': 'Please compile huffman_web.c first using: gcc huffman_web.c -o huffman_web.exe'}), 500
    
    try:
        # Run the C program and capture output
        result = subprocess.run([exe_path, text], 
                              capture_output=True, 
                              text=True, 
                              timeout=5)
        
        if result.returncode != 0:
            return jsonify({'error': 'Compression failed'}), 500
        
        # Parse JSON output from C program
        output = json.loads(result.stdout.strip())
        return jsonify(output)
    
    except subprocess.TimeoutExpired:
        return jsonify({'error': 'Compression timeout'}), 500
    except json.JSONDecodeError:
        return jsonify({'error': 'Invalid output from compression'}), 500
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True, port=5173, host='127.0.0.1')

