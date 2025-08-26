/*
** Friend Functions in C++
** A friend function in C++ is a special type of function that is not a member of a class but has access to 
** the class's private and protected members. This breaks the usual encapsulation rules but can be useful in 
** certain situations.
**
** Key Characteristics
** Non-member function: It's declared inside the class but defined outside
** Access privileges: Can access private and protected members
** Not inherited: Friendship isn't transitive or inherited
**
** Common Use Cases
** Operator overloading: Especially for symmetric operators like +, ==
** Utility functions that need access to private data but don't logically belong as member functions
**
** Inter-class operations when two classes need to share private data
**
** Important Notes
** Friendship is granted, not taken (the class declares who its friends are)
** Friend functions don't have a this pointer (they're not member functions)
** Friendship is not mutual unless explicitly declared both ways
** Too many friend functions can violate encapsulation principles
** Friend functions should be used judiciously as they can weaken the benefits of encapsulation if overused.
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class Box 
{
    private:
        double width;
    
    public:
        Box(double w) : width(w) {}
    
        // Declaration of friend function
        friend void printWidth(Box box);
};

// Definition of friend function (not a member function)
void printWidth(Box box) 
{
    // Can access private member 'width'
    std::cout << "Width: " << box.width << std::endl;
}

int main (int argc, char** argv)
{
    Box box(10.0);
    printWidth(box); // Call the friend function
    return EXIT_SUCCESS;
}