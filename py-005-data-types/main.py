#!python3
#!python3
# In Python, data types are classifications that specify which type of value a variable can hold. 
# Python has several built-in data types, categorized as follows:

# 1. Numeric Types
# int: Integer numbers (e.g., 5, -3, 1000)
x = 10

#float: Floating-point numbers (decimals) (e.g., 3.14, -0.001)
y = 3.14

# complex: Complex numbers (e.g., 1 + 2j)
z = 1 + 2j

# 2. Sequence Types
# str (String): Ordered sequence of characters (immutable)
name = "Alice"

# list: Ordered, mutable collection of items
fruits = ["apple", "banana", "cherry"]

# tuple: Ordered, immutable collection of items
coordinates = (10, -5)

# 3. Mapping Type
# dict (Dictionary): Key-value pairs (unordered, mutable)
person = {"name": "Bob", "age": 30}

### **4. Set Types**
# - **`set`**: Unordered collection of unique items (mutable)  
# ```python
unique_numbers = {1, 2, 3}

# frozenset`: Immutable version of a set
frozen_set = frozenset([1, 2, 3])

# 5. Boolean Type (bool)
# Represents True or False
is_valid = True 

###6.Binary Types -bytes`: Immutable sequence of bytes (0–255)
data_bytes= b"hello"

#-bytearray`: Mutable sequence of bytes
data_bytearray= bytearray(b"hello")

#-memoryview`: Memory view object for binary data
##Checking Data Types with type() You can check the type of a variable using the type() function:
x=10 
print(type(x)) # Output: <class 'int'> 

##Type Conversion (Casting) Python allows converting between types using functions like:
int("5") # →5 
float(3) # →3.0 str(42)# →"42" list("abc")#→['a','b','c'] 

# Understanding data types is crucial for effective programming in Python, 
# as they determine how data can be manipulated and interacted with.