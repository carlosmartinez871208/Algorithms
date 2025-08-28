#!python3
import csv
import json
from pathlib import Path
# Python Input and Output (I/O) Basics
# Python provides several ways to handle input and output operations. Here's a comprehensive overview:
# Standard Input/Output

# Basic printing
print("Hello World!")
# Printing multiple items
print("Hello", "World", 2024)
# or
name = "Ninmah"
age = 5
print("My name is", name, "and I am", age, "years old.")
# Formatted strings (f-strings)
print(f"My name is {name} and I am {age} years old.")
# Using format() method
print("My name is {} and I am {} years old.".format(name, age))
# Using % operator
print("My name is %s and I am %d years old." % (name, age))
# Controlling end character
print("Hello", end=" ")
print("World!")
# Controlling separator
print("Hello", "World", sep=", ")
# Redirecting output to a file
with open("test.log", "w") as f:
    print("Hello, World\n",name,age, file=f)
# Reading input from the user
user_name = input("Enter your name: ")
user_age = input("Enter your age: ")
print(f"Hello {user_name}, you are {user_age} years old.")
# Reading input with a prompt
user_input = input("Please enter something: ")
print(f"You entered: {user_input}")
# File I/O
# Writing to a file
with open("file.txt", "w") as file:
    file.write("Hello, World!\n")
    file.write(f"My name is {name} and I am {age} years old.\n")
# Reading from a file
with open("file.txt", "r") as file:
    content = file.read()
    print("File Content:")
    print(content)
# Reading file line by line
with open("file.txt", "r") as file:
    for line in file:
        print(line.strip())
# Appending to a file
with open("file.txt", "a") as file:
    file.write("This is an appended line.\n")
# Error handling in file operations
try:
    with open("non_existent_file.txt", "r") as file:
        content = file.read()
except FileNotFoundError:
    print("File not found. Please check the file path.")
# Working with binary files
# Writing binary data
with open("binary_file.bin", "wb") as file:
    file.write(b'\x00\xFF\x7F\x80')
# Reading binary data
with open("binary_file.bin", "rb") as file:
    binary_content = file.read()
    print("Binary Content:", binary_content)
# Summary
# Python's input and output capabilities are versatile and easy to use. 
# Whether you're printing to the console, reading user input, or handling files, 
# Python provides straightforward methods to accomplish these tasks efficiently.
# # This script demonstrates the basics of input and output operations in Python.

# Mode	Description
# 'r'	Read (default)
# 'w'	Write (truncates existing)
# 'x'	Exclusive creation (fails if exists)
# 'a'	Append
# 'b'	Binary mode
# 't'	Text mode (default)
# '+'	Updating (read/write)
# Example combinations: 'rb' (read binary), 'w+' (write and read), etc.

#clean up
#Path("test.log").unlink(missing_ok=True)Path("file.txt").unlink(missing_ok=True)
#Path("binary_file.bin").unlink(missing_ok=True)

# Modern way to handle paths
file_path = Path('data/output.txt')

# Create parent directories if they don't exist
file_path.parent.mkdir(parents=True, exist_ok=True)

# Write to the path object directly
file_path.write_text("File content")

# Read from the path object
content = file_path.read_text()
print(content)

data = {
    "name": "Ninmah",
    "age": 5,
    "hobbies": ["reading", "hiking"]
}

# Write JSON to a file
with open('data.json', 'w') as f:
    json.dump(data, f, indent=4)

# Read JSON from a file
with open('data.json', 'r') as f:
    loaded_data = json.load(f)

print(loaded_data)

data = [
    ["Name", "Age", "City"],
    ["Ninmah", 5, "Michigan"],
    ["Mariana", 35, "Chicago"]
]

# Write CSV data to a file - version A - lists of lists/rows approach 
with open('data.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(data)

# Read CSV data from a file - version A - lists of lists/rows approach
with open('data.csv', 'r') as f:
    reader = csv.reader(f)
    for row in reader:
        print(row)
# Write CSV data to a file - version B - list of dictionaries approach
with open('data_dict.csv', 'w', newline='') as f:
    fieldnames = ["Name", "Age", "City"]
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    for row in data[1:]:  # Skip header row
        writer.writerow({"Name": row[0], "Age": row[1], "City": row[2]})
# Read CSV data from a file - version B - list of dictionaries approach
with open('data_dict.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        print(row)
# Clean up
Path("test.log").unlink(missing_ok=True)
Path("file.txt").unlink(missing_ok=True)
Path("binary_file.bin").unlink(missing_ok=True)
Path("data/output.txt").unlink(missing_ok=True)
Path("data").rmdir()  # Remove the directory if empty
Path("data.json").unlink(missing_ok=True)
Path("data.csv").unlink(missing_ok=True)
Path("data_dict.csv").unlink(missing_ok=True)