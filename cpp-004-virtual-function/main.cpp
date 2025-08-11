/*
** In C++, a virtual function is a member function that you expect to be redefined in derived classes. 
** When you refer to a derived class object using a pointer or reference to the base class, you can call 
** a virtual function for that object and execute the derived class's version of the function.
**
** Key Characteristics
** Runtime Polymorphism: Virtual functions enable runtime polymorphism (late binding)
** Base Class Declaration: Declared with the virtual keyword in the base class
** Override Capability: Can be overridden in derived classes (using override keyword in C++11+)
**
** This will output "Derived class show()" because of the virtual function mechanism.
** Important Points
** Must be declared in public/protected sections (private virtual functions can't be overridden)
** Constructors cannot be virtual
** Destructors should almost always be virtual if you're dealing with inheritance
** Static functions cannot be virtual
** Virtual functions can have default arguments (but it's generally not recommended)
** Virtual functions are fundamental to implementing polymorphism in C++ and are widely used in object-oriented 
** design patterns.
*/
#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class Base
{
    public:
        virtual void show()
        {
            std::cout<<"Show the base!"<<std::endl;
        }
};

class Derived : public Base
{
    public:
        void show() override 
        {
            std::cout<<"Show the derived!"<<std::endl;
        }
};

int main (int argc, char** argv)
{
    Base* basePtr = new Derived();
    basePtr->show();
    return EXIT_SUCCESS;
}