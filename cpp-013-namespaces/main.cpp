/*
** Namespaces in C++
** Namespaces are a fundamental feature in C++ that help organize code and prevent
** naming conflicts. Here's a comprehensive overview:
** 
** What is a Namespace?
** A namespace is a declarative region that provides a scope to the identifiers 
** (names of types, functions, variables, etc.) inside it. They are used to
** organize code into logical groups and to prevent name collisions.
**
** Best Practices
** Avoid using namespace in header files (can cause name collisions)
** Prefer qualified names or specific using declarations over using namespace
** Use namespaces to group related functionality together
** Keep namespace hierarchies reasonably shallow (2-3 levels max)
** The std Namespace
** Namespaces are essential for large-scale C++ development as they help maintain 
** clean, organized, and conflict-free codebases.
*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

namespace MyNamespace 
{
    int x;
    void foo();
    class MyClass {};
    void foo() {}
} // namespace MyNamespace

//Nested Namespaces (C++17 and later)
namespace Outer {
    namespace Inner {
        void display() {
            std::cout << "Inside Inner namespace" << std::endl;
        }
    }
}

/*
Inline Namespaces (C++11)
Inline namespaces make their members appear as if they were members of the enclosing namespace:
*/
namespace Version1 {
    inline namespace V1 {
        void func() {
            std::cout << "Version 1" << std::endl;
        }
    }
}

/*
Anonymous Namespaces
Anonymous namespaces have internal linkage (similar to static):
*/
namespace {
    int local_variable; //Only accessible within this translation unit
    int hiddenVar = 42;
    void hiddenFunc() {
        std::cout << "This is a hidden function" << std::endl;
    }
}

/*
Namespace Aliases
Create aliases for long namespace names:
*/
namespace MN = MyNamespace;


int main (int argc, char** argv)
{
    MyNamespace::x = 10; // Accessing variable x from MyNamespace
    MyNamespace::foo();  // Calling function foo from MyNamespace
    MyNamespace::MyClass obj; // Creating an object of MyClass from MyNamespace
    std::cout << "Value of x in MyNamespace: " << MyNamespace::x << std::endl;
    using namespace MyNamespace;
    x=20;
    std::cout << "Value of x after using directive: " << x << std::endl;
    Outer::Inner::display(); // Accessing function from nested namespace
    Version1::func(); // Calls func from inline namespace V1
    std::cout << "Hidden variable value: " << hiddenVar << std::endl;
    hiddenFunc(); // Calling hidden function
    MN::x = 30; // Using namespace alias to access x
    std::cout << "Value of x using namespace alias: " << MN::x << std::endl;
    return EXIT_SUCCESS;
}