/*
** The 'this' Pointer in C++
** In C++, the 'this' pointer is an implicit parameter to all non-static member functions
** It points to the object for which the member function is called.
** Key Characteristics
** Implicitly passed: You don't need to declare it; it's automatically available in member functions
** Type: It's a pointer to the class type
** Const correctness: In const member functions, 'this' is a pointer to a const object
** Usage: Commonly used to refer to the calling object, especially in cases of name conflicts
** Returning *this: Member functions can return *this to allow for method chaining
** Important Notes
** Not available in static member functions since they are not tied to any particular object
** Can be used to check for self-assignment in assignment operators
** Can be used to access members of the calling object explicitly
** Overuse can lead to less readable code; use it judiciously
**
** Important Notes
** You cannot modify the this pointer itself (it's const)
** It's not available in static member functions (since they don't operate on an instance)
** Arrow operator (->) is used with pointers, dot operator (.) with objects
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

//1. Disambiguate between member variables and parameters
class MyClass {
    int x;
    public:
        void setX(int x) {
            this->x = x; // Use this-> to refer to the member variable
        }
};

//2. Return the current object (for method chaining)
class Counter {
    int count;
    public:
        Counter& increment() {
            count++;
            return *this; // Return reference to current object
        }
};

//3. Pass the current object as an argument
class MyClass1; // Forward declaration

void externalFunction(MyClass1* obj){}

class MyClass1 {
public:
    void callExternal() {
        externalFunction(this); // Pass current object pointer
    }
};

//4. Check for self-assignment in assignment operators
class MyClass2 {
public:
    MyClass2& operator=(const MyClass2& other) {
        if (this != &other) { // Check for self-assignment
            // perform assignment...
        }
        return *this;
    }
};

class Person {
    std::string name;
    int age;
    public:
        Person(const std::string& name, int age) : name(name), age(age) {}
    
        Person& setName(const std::string& name) 
        {
            this->name = name;
            return *this;
        }
    
        Person& setAge(int age) 
        {
            this->age = age;
            return *this;
        }
    
        void print() const 
        {
            std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
        }
};

int main (int argc, char** argv)
{
    Person person("Alice", 30);
    person.setName("Bob").setAge(25).print(); // Method chaining using 'this' pointer
    return EXIT_SUCCESS;
}