#!python3
# Object-Oriented Programming in Python
# Python supports object-oriented programming (OOP) which allows you to structure your code by 
# creating objects that contain both data (attributes) and behavior (methods).

# Basic Class Definition
class Dog:
    # Class attribute - shared by all instances
    species = "Canis familiaris"
    
    # Initializer / Instance attributes
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    # Instance method
    def bark(self):
        return f"{self.name} says woof!"
    
    def __str__(self):
        return f"{self.name} is {self.age} years old"

# Creating instances
dog1 = Dog("Buddy", 5)
dog2 = Dog("Milo", 3)

print(dog1.bark())  # Buddy says woof!
print(dog2)         # Milo is 3 years old

# Encapsulation
# Bundling data and methods that work on that data within one unit.
class BankAccount:
    def __init__(self, account_holder, balance=0):
        self._account_holder = account_holder  # protected attribute
        self.__balance = balance               # private attribute
    
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
    
    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
    
    def get_balance(self):  # getter method
        return self.__balance

account = BankAccount("Alice", 1000)
account.deposit(500)
print(account.get_balance())  # 1500

# 2. Inheritance
# Creating a new class from an existing class.
# 3. Polymorphism
# Using a unified interface for objects of different classes.
# Using the Animal example above, notice how we can call speak() 
# on different animal types without knowing their specific class.
class Animal:
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        raise NotImplementedError("Subclass must implement this method")

class Cat(Animal):
    def speak(self):
        return f"{self.name} says meow!"

class Dog(Animal):
    def speak(self):
        return f"{self.name} says woof!"

animals = [Cat("Whiskers"), Dog("Rover")]
for animal in animals:
    print(animal.speak())

# 4. Abstraction (via ABC module)
# Hiding complex implementation details.
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass
    
    @abstractmethod 
    def perimeter(self):
        pass

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width  
        self.height = height
    
    def area(self):  
        return self.width * self.height
    
    def perimeter(self):  
        return 2 * (self.width + self.height)

# shape = Shape()  # This would raise an error - can't instantiate abstract class 
rect = Rectangle(5, 10)
print(rect.area())     # 50 
print(rect.perimeter())# 30 

# Special Methods (Magic/Dunder Methods)
# Python classes can implement special methods for operator overloading and other functionality:
class Vector:
    def __init__(self, x, y):
        self.x = x  
        self.y = y  
    
    def __add__(self, other):  
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):  
        return Vector(self.x - other.x, self.y - other.y)
    
    def __mul__(self, scalar):  
        return Vector(self.x * scalar, self.y * scalar)
    
    def __repr__(self):  
        return f"Vector({self.x}, {self.y})"
    
v1 = Vector(2,4) 
v2 = Vector(1,-2) 
print(v1 + v2)   # Vector(3,2) 
print(v1 * 3)   # Vector(6,-12) 

# Class methods and static methods
class Circle:
    pi = 3.14159
    
    def __init__(self, radius):
        self.radius = radius
    
    @classmethod
    def from_diameter(cls, diameter):  # class method as alternative constructor
        return cls(diameter / 2)
    
    @staticmethod
    def area(radius):  # static method - utility function
        return Circle.pi * (radius ** 2)
    
circle = Circle.from_diameter(10)
print(circle.radius)  # 5.0
print(Circle.area(5)) # 78.53975

# Property decorators
class Temperature:
    def __init__(self, celsius=0):
        self._celsius = celsius
    
    @property
    def celsius(self):
        return self._celsius
    
    @celsius.setter
    def celsius(self, value):
        if value < -273.15:
            raise ValueError("Temperature below -273.15 is not possible")
        self._celsius = value
    
    @property
    def fahrenheit(self):
        return (self._celsius * 9/5) + 32

temp=Temperature(25)
print(temp.fahrenheit)  # 77.0
temp.celsius = 30
print(temp.fahrenheit)  # 86.0
# temp.celsius = -300  # This would raise a ValueError
# This code provides a comprehensive overview of object-oriented programming concepts in Python,
# including class definitions, encapsulation, inheritance, polymorphism, abstraction, special methods,
# class and static methods, and property decorators.