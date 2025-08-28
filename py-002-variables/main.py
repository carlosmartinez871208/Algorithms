#!python3
# In Python, variables are used to store data values. Unlike some other programming languages, 
# Python is dynamically typed, meaning you don't need to declare a variable's type explicitly. 
# The type is inferred at runtime based on the assigned value.

# Key Characteristics of Python Variables:
# No Declaration Needed: Just assign a value to create a variable.
# Dynamic Typing: A variable can change its type after being set.
# Case-Sensitive: myVar and myvar are different variables.
# Naming Rules:
# Must start with a letter or underscore (_).
# Can contain letters, numbers, and underscores.
# Cannot be a Python keyword (e.g., if, for, while).

# 1. Basic variables assigment
x = 10             # Integer
name = "Ninmah"    # String
pi = 3.14156       # Float
is_active = True   # Boolean

print(x)           # Output: 10
print(name)        # Output: Alice

# 2. Dynamic typing (Variable type can chnage)
var = 100          # Initialia an integer
print(var)         # Output: 100
print(type(var))   # Output: <class 'int'>

var = "Hello"      # String assigment to the same variable
print(var)         #Output: Hello
print(type(var))   # Output: <class 'str'>

# 3. Multiple variable assigment at once
a,b,c=1,"Hello",3.14159
print(a)           # Output: 1
print(b)           # Output: Hello
print(c)           # Output: 3.14159

# 4. Assing the same value to multiple variables
x = y = z = 50
print(x)           # Output: 50
print(y)           # Output: 50
print(z)           # Output: 50

# 5. Variable naming conventions
# Valid variable names
my_variable = 10
_variable = 20
variable123 = 30
user_name = "Ninmah"

# Invalid variable names (uncommenting these will raise errors)
# 1st_variable = 40   # Cannot start with a number
# my-variable = 50    # Hyphens are not allowed
# if = 60             # 'if' is a reserved keyword  
# my variable = 70    # Spaces are not allowed
print(my_variable, _variable, variable123, user_name)
# Output: 10 20 30 Ninmah

# 6. Swapping variables
a = 5
b = 10
print("Before swapping: a =", a, ", b =", b)  # Output: Before swapping: a = 5 , b = 10
a, b = b, a  # Swap the values
print("After swapping: a =", a, ", b =", b)   # Output: After swapping: a = 10 , b = 5
# 7. Constants (by convention, use uppercase letters)
PI = 3.14159    
GRAVITY = 9.81
SPEED_OF_LIGHT = 299792458  # in meters per second
print(PI, GRAVITY, SPEED_OF_LIGHT)  # Output: 3.14159 9.81 299792458
# Note: Python does not enforce constants, but using uppercase names indicates that these values should not be changed.
# 8. Type conversion
num_str = "100"
num_int = int(num_str)      # Convert string to integer
num_float = float(num_str)  # Convert string to float
print(num_int)              # Output: 100
print(num_float)            # Output: 100.0
# 9. Using variables in expressions
a = 10
b = 20
sum_ab = a + b
print("Sum of a and b is:", sum_ab)  # Output: Sum of a and b is: 30
# 10. Deleting variables
temp_var = 50
print(temp_var)  # Output: 50
del temp_var     # Delete the variable
# print(temp_var)  # Uncommenting this line will raise an error since temp_var is deleted
# Output: NameError: name 'temp_var' is not defined
# This code demonstrates various aspects of variables in Python, including assignment, dynamic typing,
# multiple assignments, naming conventions, swapping, constants, type conversion, and deletion.
# Variable scope:
# Local Variables: Defined within a function and accessible only inside that function.
# Global Variables: Defined outside any function and accessible throughout the module.
# Nonlocal Variables: Used in nested functions to refer to variables in the nearest enclosing scope that
# is not global.
# Example of variable scope
global_var = "I am a global variable"
def my_function():
    local_var = "I am a local variable"
    print(local_var)  # Accessible here
    print(global_var) # Accessible here

    def nested_function():
        nonlocal local_var
        local_var = "I am modified in nested function"
        print(local_var)  # Accessible here
    
    nested_function()
    print(local_var)  # Modified value accessible here

my_function()
# print(local_var)  # Uncommenting this line will raise an error since local_var is not accessible here
# Output: NameError: name 'local_var' is not defined
print(global_var)  # Accessible here
# Output: I am a global variable
# This code snippet illustrates the concept of variable scope in Python, demonstrating local, global,
# and nonlocal variables.
# Note: Python does not have block-level scope (e.g., within if or for blocks), so variables defined
# in such blocks are accessible in the enclosing function or global scope.
