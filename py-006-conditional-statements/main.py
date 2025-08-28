#!python3

# In Python, conditional statements allow you to execute different blocks of code based on 
# whether certain conditions are true or false. The primary conditional statements in Python are:

# 1. if statement
x=10
if x > 5:
    print("x is greater than 5")
# 2. elif statement (short for "else if")
elif x == 5:
    print("x is equal to 5")
# Note: The elif statement must come after an if statement and before an else statement.
# 3. else statement
else:
    print("x is less than 5")
# 4. nested if statements
if x > 0:
    if x < 10:
        print("x is a positive single-digit number")
    else:
        print("x is a positive number with multiple digits")
# 5. conditional expressions (ternary operator)
result = "Even" if x % 2 == 0 else "Odd"
print(f"x is {result}")
# 6. match statement (introduced in Python 3.10)
command = "start"
match command:
    case "start":
        print("Starting...")
    case "stop":
        print("Stopping...")
    case _:
        print("Unknown command")
# The underscore (_) acts as a wildcard, matching any value not explicitly handled by previous cases.
# 7. short-circuit evaluation with logical operators
if x > 0 and (x % 2 == 0):
    print("x is a positive even number")
# The second condition (x % 2 == 0) is only evaluated if the first condition (x > 0) is true.
# 8. assert statement
assert x > 0, "x must be positive"
# If the condition is false, an AssertionError is raised with the provided message.
# 9. pass statement
if x > 0:
    pass  # Placeholder for future code to be added here
# 10. break and continue statements in loops
for i in range(10):
    if i == 5:
        break  # Exit the loop when i is 5
    if i % 2 == 0:
        continue  # Skip even numbers
    print(i)  # This will print only odd numbers less than 5
# 11. try-except blocks for exception handling
try:
    result = 10 / x
    print(result)
except ZeroDivisionError:
    print("Cannot divide by zero")
# 12. with statement for context management
with open("example.txt", "r") as file:
    content = file.read()
    print(content)
# The with statement ensures that the file is properly closed after its suite finishes,
# even if an exception is raised.
# 13. lambda functions with conditional logic
max_value = lambda a, b: a if a > b else b
print(max_value(10, 20))
# This lambda function returns the maximum of two values.
# Additional conditional constructs and techniques in Python include:
# 14. list comprehensions with conditional filtering
squares = [x**2 for x in range(10) if x % 2 == 0]
print(squares)
# This creates a list of squares of even numbers from 0 to 9.
# 15. generator expressions with conditional filtering
evens = (x for x in range(10) if x % 2 == 0)
for num in evens:
    print(num)
# This creates a generator that yields even numbers from 0 to 9.
# 16. any() and all() functions for evaluating conditions in iterables
numbers = [1, 2, 3, 4, 5]
print(any(n > 3 for n in numbers))  # True if any number is greater than 3
print(all(n > 0 for n in numbers))  # True if all numbers are greater than 0
# 17. isinstance() function for type checking
value = 10
if isinstance(value, int):
    print("value is an integer")
# 18. bool() function for evaluating truthiness of values
if bool(value):
    print("value is truthy")
# 19. Using conditional statements in function definitions
def check_number(num):
    if num > 0:
        return "Positive"
    elif num < 0:
        return "Negative"
    else:
        return "Zero"
print(check_number(10))
print(check_number(-5))
print(check_number(0))
# 20. Using conditional statements in class methods
class Number:
    def __init__(self, value):
        self.value = value

    def is_positive(self):
        if self.value > 0:
            return True
        else:
            return False
num = Number(10)
print(num.is_positive())
num = Number(-5)
print(num.is_positive())
# These examples demonstrate the versatility and power of conditional statements in Python,
# allowing for complex decision-making and control flow in your programs.