#!python3
# Functions in Python
def greet(name):
    """Function to greet a person"""
    return f"Hello, {name}!"
print(greet("Alice"))

# Function with default arguments
def power(base, exponent=2):
    """Function to calculate power with default exponent"""
    return base ** exponent
print(power(3))        # Uses default exponent
print(power(3, 3))     # Uses provided exponent

# Function with variable-length arguments
def sum_all(*args):
    """Function to sum all arguments"""
    return sum(args)
print(sum_all(1, 2, 3))        # Sums 1, 2, 3
print(sum_all(4, 5, 6, 7))  # Sums 4, 5, 6, 7

# Function with keyword arguments
def display_info(**kwargs):
    """Function to display key-value pairs"""
    for key, value in kwargs.items():
        print(f"{key}: {value}")
display_info(name="Bob", age=25, city="New York")

# Lambda function
square = lambda x: x ** 2
print(square(5))  # Outputs 25

# Higher-order function
def apply_function(func, value):
    """Function that applies a given function to a value"""
    return func(value)
print(apply_function(lambda x: x + 10, 5))  # Outputs 15

# Nested functions
def outer_function(msg):
    """Outer function"""
    def inner_function():
        """Inner function"""
        return f"Message: {msg}"
    return inner_function()
print(outer_function("Hello from nested function"))

# Function with docstring
def factorial(n):
    """Function to calculate factorial of a number"""
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
print(factorial(5))  # Outputs 120

# Function annotations
def add(a: int, b: int) -> int:
    """Function to add two integers"""
    return a + b
print(add(3, 4))  # Outputs 7

# Using map with a function
numbers = [1, 2, 3, 4]
squared_numbers = list(map(lambda x: x ** 2, numbers))
print(squared_numbers)  # Outputs [1, 4, 9, 16]

# Using filter with a function
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # Outputs [2, 4]

# Using reduce with a function
from functools import reduce
product = reduce(lambda x, y: x * y, numbers)
print(product)  # Outputs 24

# Recursion example
def fibonacci(n):
    """Function to return the nth Fibonacci number"""
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)
print(fibonacci(6))  # Outputs 8

# Function with type hints and default values
def concatenate(a: str, b: str = "World") -> str:
    """Function to concatenate two strings"""
    return f"{a} {b}"
print(concatenate("Hello"))          # Outputs "Hello World"
print(concatenate("Hello", "Python"))  # Outputs "Hello Python"

# Using functools.lru_cache for memoization
from functools import lru_cache
@lru_cache(maxsize=None)
def fib_memo(n):
    """Memoized Fibonacci function"""
    if n < 2:
        return n
    return fib_memo(n - 1) + fib_memo(n - 2)
print(fib_memo(50))  # Outputs 12586269025

# Using a function as a return value
def make_multiplier(factor):
    """Function that returns a multiplier function"""
    def multiply(x):
        return x * factor
    return multiply
double = make_multiplier(2)
triple = make_multiplier(3)
print(double(5))  # Outputs 10
print(triple(5))  # Outputs 15

# Using functools.partial to create a new function with fixed arguments
from functools import partial
add_five = partial(add, 5)
print(add_five(10))  # Outputs 15

# Using a function to sort a list of tuples
data = [(1, 'b'), (2, 'a'), (3, 'c')]
sorted_data = sorted(data, key=lambda x: x[1])
print(sorted_data)  # Outputs [(2, 'a'), (1, 'b'), (3, 'c')]

# Using a function to group data
from itertools import groupby
data = [('a', 1), ('b', 2), ('a', 3)]
data.sort(key=lambda x: x[0])  # Sort by the first element
grouped_data = {k: list(v) for k, v in groupby(data, lambda x: x[0])}
print(grouped_data)  # Outputs {'a': [('a', 1), ('a', 3)], 'b': [('b', 2)]}

# Using a function to validate input
def is_positive(num):
    """Function to check if a number is positive"""
    return num > 0
numbers = [-2, -1, 0, 1, 2]
positive_numbers = list(filter(is_positive, numbers))
print(positive_numbers)  # Outputs [1, 2]

# Using a function to format strings
def format_name(first, last):
    """Function to format a full name"""
    return f"{first.title()} {last.title()}"
print(format_name("john", "doe"))  # Outputs "John Doe"

# Using a function to read a file
def read_file(file_path):
    """Function to read and print file contents"""
    with open(file_path, 'r') as file:
        content = file.read()
        print(content)
# Uncomment the line below to test with an actual file path
# read_file('example.txt')

# Using a function to write to a file
def write_file(file_path, content):
    """Function to write content to a file"""
    with open(file_path, 'w') as file:
        file.write(content)
# Uncomment the line below to test with an actual file path
# write_file('output.txt', 'Hello, World!')

# Using a function to handle exceptions
def safe_divide(a, b):
    """Function to safely divide two numbers"""
    try:
        return a / b
    except ZeroDivisionError:
        return "Cannot divide by zero"
print(safe_divide(10, 2))  # Outputs 5.0
print(safe_divide(10, 0))  # Outputs "Cannot divide by zero"
print("All functions examples finished")