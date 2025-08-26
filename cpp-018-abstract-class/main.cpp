/*
Abstract Classes in C++
An abstract class in C++ is a class that cannot be instantiated on its own and serves 
as a base for other classes. It's designed to provide a common interface and shared 
functionality for derived classes.
Key Characteristics
Cannot be instantiated - You can't create objects of an abstract class
Contains at least one pure virtual function
Used as a base class for other classes to inherit from
Pure Virtual Functions
A pure virtual function is declared with = 0 at the end.
When to Use Abstract Classes
When you want to define an interface that multiple classes will implement
When you want to share common code among related classes
When you need polymorphic behavior through base class pointers/references
Important Notes
Derived classes must implement all pure virtual functions or they become abstract too
Abstract classes can have data members and non-virtual functions
You can have pointers/references to abstract classes, which is useful for polymorphism
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

//Abstract base class
class Shape {
    public:
        // Pure virtual function - must be implemented by derived classes
        virtual double area() const = 0;
    
        // Pure virtual function
        virtual void draw() const = 0;
    
        // Regular virtual function with implementation
        virtual void printInfo() const 
        {
            std::cout << "This is a shape\n";
        }
    
        // Non-virtual function
        void commonFunction() 
        {
            std::cout << "Common functionality for all shapes\n";
        }
};

// Concrete derived class
class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        // Must implement all pure virtual functions
        double area() const override 
        {
            return 3.14159 * radius * radius;
        }
        void draw() const override 
        {
            std::cout << "Drawing a circle\n";
        }
    
        // Can override regular virtual functions (optional)
        void printInfo() const override 
        {
            std::cout << "This is a circle with radius " << radius << "\n";
        }
};

int main (int argc, char** argv)
{
    Circle circle(5.0);
    circle.printInfo(); // Calls overridden method
    circle.draw();      // Calls Circle's draw method
    std::cout << "Area: " << circle.area() << "\n"; // Calls Circle's area method
    circle.commonFunction(); // Calls non-virtual method from Shape
    return EXIT_SUCCESS;
}