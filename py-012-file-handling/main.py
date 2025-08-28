#!python3
# Python File Handling
# File handling is a crucial aspect of programming in Python, allowing you to read from 
# and write to files. Here's a comprehensive guide:

# Basic File Operations
# Open a file for reading (default mode)
file = open('example.txt', 'r')

# Common modes:
# 'r' - Read (default)
# 'w' - Write (creates new file or truncates existing)
# 'a' - Append
# 'x' - Exclusive creation (fails if file exists)
# 'b' - Binary mode
# 't' - Text mode (default)
# '+' - Updating (read/write)

# Reading from a file
# Read entire file content
content = file.read()

# Read line by line
for line in file:
    print(line)

# Read all lines into a list
lines = file.readlines()

# Read first 100 characters
partial = file.read(100)

# Writing to a file
with open('output.txt', 'w') as f:
    f.write("Hello, World!\n")
    f.writelines(["Line 1\n", "Line 2\n"])

# Closing a file
file.close()  # Always close files when done

# Better: use context manager (automatically closes file)
with open('example.txt') as f:
    content = f.read()

# Advanced Techniques
# Working with Binary Files
with open('image.png', 'rb') as img_file:
    img_data = img_file.read()
