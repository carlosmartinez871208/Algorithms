/*
In C++, a destructor is a special member function that is automatically called when an object 
goes out of scope or is explicitly deleted. Its primary purpose is to release resources 
(e.g., memory, file handles, network connections) allocated by the object during its lifetime.
Key Properties of a Destructor:
Name: The destructor has the same name as the class, prefixed with a tilde (~).
No Parameters: It cannot take any arguments.
No Return Type: It does not return a value (not even void).
Automatic Invocation: Called automatically when:
An object goes out of scope.
delete is called on a dynamically allocated object.
An exception is thrown (during stack unwinding).
Cannot be Overloaded: There can only be one destructor per class.
When to Use a Destructor?
Resource Management:
Free dynamically allocated memory.
Close files or database connections.
Release locks or other system resources.
RAII (Resource Acquisition Is Initialization):
A C++ idiom where resources are acquired in the constructor and released in the destructor.
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif
 /*
 Basic Destructor Example
 */
class BasicDestructor
{
    int *data; // Pointer to dynamically allocated memory
    public:
        BasicDestructor(int value) // Constructor to allocate memory
        {
            data = new int(value);
        }
        ~BasicDestructor() // Destructor to free allocated memory
        {
            delete data;
            std::cout << "Destructor called, memory freed!" << std::endl;
        }
        void display()
        {
            std::cout << "Value: " << *data << std::endl;
        }
};

/*
Example: Destructor for Dynamic Memory
*/
class DynamicMemoryDestructor
{
    int *data;
    public:
        DynamicMemoryDestructor(int value) // Constructor to allocate memory
        {
            data = new int(value);
        }
        ~DynamicMemoryDestructor() // Destructor to free allocated memory
        {
            delete data;
            std::cout << "Destructor called, dynamic memory freed!" << std::endl;
        }
        void display()
        {
            std::cout << "Value: " << *data << std::endl;
        }
};

/*
Virtual Destructors:
If a class is intended to be inherited from, its destructor should be declared virtual.
Ensures proper cleanup when deleting objects through a base-class pointer.
*/
class Base
{
    public:
        virtual ~Base() // Virtual destructor
        {
            std::cout << "Base destructor called!" << std::endl;
        }
};

class Derived : public Base
{
    public:
        ~Derived() // Destructor for derived class
        {
            std::cout << "Derived destructor called!" << std::endl;
        }
};


int main (int argc, char** argv)
{
    BasicDestructor obj(42); // Constructor is called here
    obj.display();
    DynamicMemoryDestructor obj2(100); // Constructor is called here
    obj2.display();
    Base *b = new Derived(); // Creating a Derived object but referencing it with a Base pointer
    delete b; // Properly calls both Derived and Base destructors due to virtual destructor
    return EXIT_SUCCESS;
}