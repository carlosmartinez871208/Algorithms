#!python3
# loops in Python
for i in range(5):
    print(i)
print("Loop finished")
# while loop
count = 0
while count < 5:
    print(count)
    count += 1
print("While loop finished")
# break and continue
for i in range(10):
    if i == 3:
        continue  # skip the rest of the loop when i is 3
    if i == 7:
        break     # exit the loop when i is 7
    print(i)
print("Loop with break and continue finished")
# nested loops
for i in range(3):
    for j in range(2):
        print(f"i: {i}, j: {j}")
print("Nested loops finished")
# loop with else
for i in range(3):
    print(i)
else:
    print("Loop completed without break")
print("Loop with else finished")
# iterating over a list
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)
print("List iteration finished")
# iterating over a dictionary
person = {"name": "Alice", "age": 30}
for key, value in person.items():
    print(f"{key}: {value}")
print("Dictionary iteration finished")
# using enumerate
for index, fruit in enumerate(fruits):
    print(f"Index: {index}, Fruit: {fruit}")
print("Enumeration finished")
# using zip
names = ["Alice", "Bob", "Charlie"]
ages = [25, 30, 35]
for name, age in zip(names, ages):
    print(f"{name} is {age} years old")
print("Zipping finished")
# list comprehension with loops
squares = [x**2 for x in range(5)]
print("Squares:", squares)
print("List comprehension finished")
# dictionary comprehension with loops
squared_dict = {x: x**2 for x in range(5)}
print("Squared Dictionary:", squared_dict)
print("Dictionary comprehension finished")
# set comprehension with loops
squared_set = {x**2 for x in range(5)}
print("Squared Set:", squared_set)
print("Set comprehension finished")
# generator comprehension with loops
squared_gen = (x**2 for x in range(5))
print("Squared Generator:", list(squared_gen))
print("Generator comprehension finished")
# iterating over a string
for char in "hello":
    print(char)
print("String iteration finished")
# using range with different parameters
for i in range(1, 10, 2):
    print(i)
print("Range with step finished")
# using reversed
for i in reversed(range(5)):
    print(i)
print("Reversed iteration finished")
# using sorted
unsorted_list = [3, 1, 4, 2]
for num in sorted(unsorted_list):
    print(num)
print("Sorted iteration finished")
# using filter with loops
even_numbers = filter(lambda x: x % 2 == 0, range(10))
for num in even_numbers:
    print(num)
print("Filter iteration finished")
# using map with loops
squared_numbers = map(lambda x: x**2, range(5))
for num in squared_numbers:
    print(num)
print("Map iteration finished")
# using itertools (if available)
try:
    import itertools
    for combo in itertools.combinations(range(4), 2):
        print(combo)
    print("itertools combinations finished")
except ImportError:
    print("itertools module not available")
print("All loops examples finished")
