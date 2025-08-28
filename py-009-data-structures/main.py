#!python3
# Python Data Structures
# In Python, data structures are used to store and organize data efficiently. 
# Python provides several built-in data structures, each with its own characteristics and use cases. 
# Here are some of the most commonly used data structures in Python:
# 1. List: An ordered, mutable collection of items. Lists can contain elements of different types.
my_list = [1, 2, 3, "hello", 4.5]
print(my_list)
# You can add, remove, or modify elements in a list.
my_list.append(6)
print(my_list)
my_list[0] = 10
print(my_list)
my_list.remove("hello")
print(my_list)
# Lists support indexing and slicing.
print(my_list[1:4])
# Insert at specific index
my_list.insert(1, "world")
print(my_list)
# Extend list with another list
my_list.extend([7, 8, 9])
print(my_list)
# Pop last element
last_element = my_list.pop()
print("Popped element:", last_element)
print(my_list)
# Clear the list
my_list.clear()
print("Cleared list:", my_list)
# 2. Tuple: An ordered, immutable collection of items. Tuples are similar to lists but cannot be 
# modified after creation.
my_tuple = (1, 2, 3, "hello", 4.5)
print(my_tuple)
# You can access elements in a tuple using indexing and slicing, but you cannot change them.
print(my_tuple[1:4])
# Tuples can be used as keys in dictionaries because they are immutable.
my_dict = {my_tuple: "value"}
print(my_dict)
# 3. Dictionary: An unordered collection of key-value pairs. Dictionaries are mutable and allow for 
# fast lookups based on keys.
my_dict = {"name": "Alice", "age": 30, "city": "New York"}
print(my_dict)
# You can add, remove, or modify key-value pairs in a dictionary.
my_dict["age"] = 31
print(my_dict)
my_dict["country"] = "USA"
print(my_dict)
del my_dict["city"]
print(my_dict)
# You can access values using their keys.
print(my_dict["name"])
# You can also use the get method to access values, which returns None if the key does not exist.
print(my_dict.get("city"))
# You can iterate over keys, values, or key-value pairs in a dictionary.
for key in my_dict:
    print(key, my_dict[key])
for key, value in my_dict.items():
    print(key, value)
# Common dictionary methods
print("Keys:", my_dict.keys())
print("Values:", my_dict.values())
print("Items:", my_dict.items())
# Clear the dictionary
my_dict.clear()
print("Cleared dictionary:", my_dict)
# 4. Set: An unordered collection of unique items. Sets are mutable and support mathematical set operations.
my_set = {1, 2, 3, 4, 5}
print(my_set)
# You can add or remove elements from a set.
my_set.add(6)
print(my_set)
my_set.remove(3)
print(my_set)
# Sets support operations like union, intersection, and difference.
set_a = {1, 2, 3}
set_b = {3, 4, 5}
print("Union:", set_a | set_b)
print("Intersection:", set_a & set_b)
print("Difference:", set_a - set_b)
# You can check for membership in a set.
print(2 in my_set)
print(10 in my_set)
# Common set methods
print("Set A:", set_a)
print("Set B:", set_b)
print("Is subset:", set_a.issubset(my_set))
print("Is superset:", my_set.issuperset(set_a))
print("Is disjoint:", set_a.isdisjoint(set_b))
# Clear the set
my_set.clear()
print("Cleared set:", my_set)
# 5. String: A sequence of characters. Strings are immutable and support various operations and methods.
my_string = "Hello, World!"
print(my_string)
# You can access characters in a string using indexing and slicing.
print(my_string[0])
print(my_string[7:12])
# Strings support concatenation and repetition.
greeting = "Hello" + ", " + "Alice!"
print(greeting)
print("Ha" * 3)
# Common string methods
print("Lowercase:", my_string.lower())
print("Uppercase:", my_string.upper())
print("Replace:", my_string.replace("World", "Python"))
print("Split:", my_string.split(", "))
print("Find:", my_string.find("World"))
print("Length:", len(my_string))
# 6. Other Data Structures: Python also provides other data structures like deque (double-ended queue) 
# from the collections module, namedtuple, and more for specific use cases.
from collections import deque, namedtuple
# Deque
my_deque = deque([1, 2, 3])
print(my_deque)
my_deque.appendleft(0)
print(my_deque)
my_deque.append(4)
print(my_deque)
my_deque.pop()
print(my_deque)
my_deque.popleft()
print(my_deque)
# Namedtuple
Point = namedtuple("Point", ["x", "y"])
p = Point(1, 2)
print(p)
print(p.x, p.y)
# In summary, Python provides a variety of built-in data structures that cater to different needs.
# Understanding these data structures and their characteristics is essential for writing efficient and effective Python code.