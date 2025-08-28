#!python3
# Keywords in Python are reserved words that have special meaning and cannot be used as 
# identifiers (like variable names, function names, or class names). Here is a list of 
# Python keywords as of Python 3.9:
# Note: The list of keywords may change with different versions of Python. You can always 
# check the current list of keywords by importing the `keyword` module and using `keyword.kwlist`.
import keyword
print(keyword.kwlist)
# Here are some commonly used Python keywords with brief explanations:
# and: Logical AND operator
# as: Used to create an alias while importing a module
# assert: Used for debugging purposes to check a condition
# break: Exits a loop prematurely
# class: Used to define a class
# continue: Skips the current iteration of a loop and moves to the next iteration
# def: Used to define a function
# del: Deletes an object
# elif: Used in conditional statements, same as else if
# else: Used in conditional statements
# except: Used with try to catch exceptions
# False: Boolean value representing false
# finally: Used with try to execute code regardless of whether an exception occurred or not
# for: Used to create a for loop
# from: Used to import specific parts of a module
# global: Declares a variable as global
# if: Used to create a conditional statement
# import: Used to import a module
# in: Used to check if a value exists in a sequence (like a list, tuple, or string)
# is: Used to test object identity
# lambda: Used to create an anonymous function
# None: Represents the absence of a value
# nonlocal: Declares a variable as non-local (not local, not global)
# not: Logical NOT operator
# or: Logical OR operator
# pass: A null statement, used as a placeholder
# raise: Used to raise an exception
# return: Exits a function and optionally returns a value
# True: Boolean value representing true
# try: Used to specify exception handling
# while: Used to create a while loop
# with: Used to wrap the execution of a block with methods defined by a context manager
# yield: Used to end a function and return a generator
# Example usage of some keywords:
def example_function(x):
    if x > 0:
        return True
    else:
        return False
result = example_function(10)
print(result)  # Output: True
# You can use these keywords to write Python programs, but remember that you cannot use them 
# as names for your variables or functions.
# For example, the following would result in a syntax error:
# if = 5  # SyntaxError: invalid syntax
# Instead, use a different name:
if_value = 5  # This is valid
print(if_value)  # Output: 5