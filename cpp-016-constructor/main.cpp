/*
In C++, a constructor is a special member function of a class that is automatically called when 
an object of that class is created. Constructors are primarily used to initialize the object's 
data members and set up any required resources.

Key Characteristics of Constructors:
Same name as the class.
No return type (not even void).
Can be overloaded (multiple constructors with different parameters).
Automatically invoked when an object is created.
If no constructor is defined, the compiler provides a default constructor.
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Default Constructor
Takes no arguments.
If not defined, the compiler generates one (but if any constructor is defined, the default 
constructor is not provided unless explicitly declared).
*/
class DefaultConstructor
{
public:
    DefaultConstructor() // Default constructor
    {
        std::cout << "Default Constructor called!" << std::endl;
    }
};

/*
Parameterized Constructor
Takes arguments to initialize objects with specific values.
*/
class ParameterizedConstructor
{
    int data;
    public:
        ParameterizedConstructor(int value) // Parameterized constructor
        {
            data = value;
        }
        void display()
        {
            std::cout << "Parameterized Constructor called with value: " << data << std::endl;
        }
};

/*
Copy Constructor
Creates an object by copying another object of the same class.
Takes an object reference (const ClassName &obj) as argument.
*/
class CopyConstructor
{
    int data;
    public:
        CopyConstructor(int value) : data(value) {} // Regular constructor
        CopyConstructor(const CopyConstructor &obj) // Copy constructor
        {
            data = obj.data;
            std::cout << "Copy Constructor called!" << std::endl;
        }
        void display()
        {
            std::cout << "Value: " << data << std::endl;
        }
};

/*
Move Constructor (C++11 and later)
Efficiently transfers resources from one object to another (used with rvalue references).
*/
class MoveConstructor
{
    int *data;
    public:
        MoveConstructor(int value) // Regular constructor
        {
            data = new int(value);
        }
        // Move constructor
        MoveConstructor(MoveConstructor &&obj) noexcept : data(obj.data)
        {
            obj.data = nullptr; // Leave the moved-from object in a valid state
            std::cout << "Move Constructor called!" << std::endl;
        }
        ~MoveConstructor() // Destructor to free allocated memory
        {
            delete data;
        }
        void display()
        {
            if (data)
                std::cout << "Value: " << *data << std::endl;
            else
                std::cout << "Data is null!" << std::endl;
        }
};

/*
Delegating Constructor (C++11 and later)
One constructor can call another in the same class.
*/
class DelegatingConstructor
{
    int data1;
    int data2;
    public:
        DelegatingConstructor() : DelegatingConstructor(0, 0) // Delegates to the parameterized constructor
        {
            std::cout << "Default Constructor called!" << std::endl;
        }
        DelegatingConstructor(int value1, int value2) : data1(value1), data2(value2) // Parameterized constructor
        {
            std::cout << "Parameterized Constructor called with values: " << data1 << ", " << data2 << std::endl;
        }
};

/*
Initialization Lists: Prefer initializing members using an initialization list for efficiency.
*/
class InitializationList
{
    int data;
    public:
        InitializationList(int value) : data(value) // Using initialization list
        {
            std::cout << "Initialization List Constructor called with value: " << data << std::endl;
        }
};

int main (int argc, char** argv)
{
    DefaultConstructor obj1; // Default constructor is called here
    ParameterizedConstructor obj2(42); // Parameterized constructor is called here
    obj2.display();
    CopyConstructor obj3(100); // Regular constructor is called here
    CopyConstructor obj4 = obj3; // Copy constructor is called here
    obj4.display();
    MoveConstructor obj5(200); // Regular constructor is called here
    MoveConstructor obj6 = std::move(obj5); // Move constructor is called here
    obj6.display();
    obj5.display(); // obj5's data should be null after the move
    DelegatingConstructor obj7; // Default constructor delegates to parameterized constructor
    InitializationList obj8(300); // Initialization list constructor is called here
    return EXIT_SUCCESS;
}