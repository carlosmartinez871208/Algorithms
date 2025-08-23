/*
** Inheritance in C++
** Inheritance in C++ is a fundamental Object-Oriented Programming (OOP) concept that 
** allows a class (called the derived class) to inherit properties and behaviors (members)
** from another class (called the base class). This promotes code reusability and establishes
** hierarchical relationships.
**
** Types of Inheritance in C++
** C++ supports several types of inheritance:
**
** Single Inheritance – A derived class inherits from only one base class.
** Multiple Inheritance – A derived class inherits from multiple base classes.
** Multilevel Inheritance – A derived class acts as a base class for another derived class.
** Hierarchical Inheritance – Multiple derived classes inherit from a single base class.
** Hybrid (Virtual) Inheritance – Combines multiple and hierarchical inheritance, often using
** virtual to avoid ambiguity.
**
** access-specifier can be:
** public: Public and protected members of the base remain as-is in the derived.
** protected: Public and protected members of the base become protected in the derived.
** private: Public and protected members of the base become private in the derived.
**
** Important Notes on Inheritance
** Constructor & Destructor Order:
** 
** Constructors are called from Base → Derived.
** Destructors are called from Derived → Base.
** Access Control:
**
** Private members of a base class are not accessible in the derived class.
** Protected members can be accessed within derived classes but not outside.
**
** When to Use Inheritance?
** When there’s an "is-a" relationship (Dog is an Animal).
** To reuse existing functionality while extending it.
** To implement polymorphism via function overriding.
*/

#include <iostream>
#include <string>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/* Single inheritance:  */
/* Base class */
class Animal
{
    public:
        void eat()
        {
            std::cout<<"Eating..."<<std::endl;
        }
};

/* Derived class */
class Dog : public Animal
{
    public:
        void bark()
        {
            std::cout<<"Barking..."<<std::endl;
        }
};
/* Multiple Inheritance: */
/* Base class A */
class A
{
    public:
        void funcA(){std::cout<<"Function A"<<std::endl;}
};

/* Base class B */
class B
{
    public:
        void funcB(){std::cout<<"Function B"<<std::endl;}
};

/* Derived Class inheriting from both A & B: */
class C : public A, public B
{
    public:
        void funcC(){std::cout<<"Function C"<<std::endl;}
};

int main (int argc, char** argv)
{
    Dog ex;
    ex.eat();
    ex.bark();
    C obj;
    obj.funcA();
    obj.funcB();
    obj.funcC();
    return EXIT_SUCCESS;
}