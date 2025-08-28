#!python3
# Python Exception Handling
# Exception handling in Python allows you to gracefully manage errors and unexpected situations 
# that may occur during program execution. 
try:
    # Code that might raise an exception
    result = 10 / 0
except ZeroDivisionError:
    # Handle the specific exception
    print("Cannot divide by zero!")

# Handling multiple exceptions
try:
    # Code that might raise exceptions
    value = int(input("Enter a number: "))
    result = 10 / value
except ValueError:
    print("That's not a valid number!")
except ZeroDivisionError:
    print("Cannot divide by zero!")

# Catching all exceptions
try:
    # Code that might raise exceptions
    value = int(input("Enter a number: "))
    result = 10 / value
except Exception as e:
    print(f"An error occurred: {e}")

# Else Clause (Executes if no exception occurs)
try:
    value = int(input("Enter a number: "))
    result = 10 / value
except ZeroDivisionError:
    print("Handling error...")
else:
    print("Success! No exceptions occurred.")

# Finally Clause (Always executes)
try:
    value = int(input("Enter a number: "))
    result = 10 / value
except Exception as e:
    print(f"An error occurred: {e}")
finally:
    print("This will always execute, regardless of exceptions.")

# Raising Exceptions
def check_positive(number):
    if number < 0:
        raise ValueError("The number must be positive.")
    return number
try:
    num = int(input("Enter a positive number: "))
    check_positive(num)
except ValueError as ve:
    print(ve)
print("Program continues...")

# Custom exceptions
class InvalidEmailError(Exception):
    """Raised when an email doesn't match the required format"""
    
def validate_email(email):
    if "@" not in email or "." not in email.split("@")[1]:
        raise InvalidEmailError(f"{email} is not a valid email address")

try:
    validate_email("user.example.com")
except InvalidEmailError as e:
    print(e)