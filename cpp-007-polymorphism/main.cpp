/*
** Polymorphism in C++
** Polymorphism is a core concept in object-oriented programming that allows objects 
** of different types to be treated as objects of a common super type. In C++, there 
** are two main types of polymorphism:
**
** 1. Compile-time Polymorphism (Static Polymorphism)
** This is achieved through:
** 
** Function overloading
** Operator overloading
** Templates
** Example of Function Overloading:
** 
** 2. Runtime Polymorphism (Dynamic Polymorphism)
** This is achieved through:
**
** Virtual functions
** Inheritance
**
** Key Points About Polymorphism in C++:
** Virtual Functions: Must be declared in the base class with the virtual keyword.
**
** Can be overridden in derived classes using override (C++11 and later)
** Pure Virtual Functions: Make a class abstract (cannot be instantiated)
**
** Virtual Destructor: Always declare base class destructor as virtual when dealing with 
** polymorphism to ensure proper cleanup.
**
** Override Keyword: Use override (C++11+) to explicitly indicate you're overriding a virtual function.
**
**Final Keyword: Use final to prevent further overriding of a virtual function.
**
** V-Table: Runtime polymorphism is implemented through virtual tables (v-tables) which 
** store pointers to the correct function implementations.
** 
** Polymorphism allows for more flexible and maintainable code by enabling you to 
** write more generic code that works with the base class interface while allowing 
** derived classes to provide their own specific implementations.
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class Math
{
    public:
        int add(int a,int b) /* Function overloading */
        {
            return a+b;
        }
        double add(double a,double b)
        {
            return a+b;
        }
        int add(int a,int b,int c)
        {
            return a+b+c;
        }
};

/* Virtual functions: */
class Animal
{
    public:
        virtual void makeSound()
        {
            std::cout<<"Some generic animal sound"<<std::endl;
        }
        virtual ~Animal(){}
};

class Dog : public Animal
{
    public:
        void makeSound() override
        {
            std::cout<<"Woof woof!"<<std::endl;
        }
};

class Cat : public Animal
{
    public:
        void makeSound() override
        {
            std::cout<<"Meow Meow!"<<std::endl;
        }
};

int main (int argc, char** argv)
{
    Math m;
    std::cout<<m.add(2,3)<<std::endl;
    std::cout<<m.add(2.5,3.8)<<std::endl;
    std::cout<<m.add(2,3,4)<<std::endl;
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    for (int i=0;i<3;i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    return EXIT_SUCCESS;
}