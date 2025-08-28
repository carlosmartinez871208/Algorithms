#!python3
# Python Operators
# Operators are special symbols that perform operations on variables and values. 
# Python supports various types of operators.
# Arithmetic Operators
a = 10
b = 3
print("Arithmetic Operators:")
print(f"a + b = {a + b}")  # Addition
print(f"a - b = {a - b}")  # Subtraction
print(f"a * b = {a * b}")  # Multiplication
print(f"a / b = {a / b}")  # Division
print(f"a // b = {a // b}")  # Floor Division
print(f"a % b = {a % b}")  # Modulus
print(f"a ** b = {a ** b}")  # Exponentiation
print()
# Comparison Operators
print("Comparison Operators:")
print(f"a == b: {a == b}")  # Equals
print(f"a != b: {a != b}")  # Not Equals
print(f"a > b: {a > b}")    # Greater Than
print(f"a < b: {a < b}")    # Less Than
print(f"a >= b: {a >= b}")  # Greater Than or Equal To
print(f"a <= b: {a <= b}")  # Less Than or Equal To
print()
# Logical Operators
x = True
y = False
print("Logical Operators:")
print(f"x and y: {x and y}")  # Logical AND
print(f"x or y: {x or y}")    # Logical OR
print(f"not x: {not x}")      # Logical NOT
xor = (x and not y) or (not x and y)
print(f"x xor y: {xor}")      # Logical XOR
print()