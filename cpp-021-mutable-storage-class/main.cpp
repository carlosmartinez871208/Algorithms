/*

*/

#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
In C++, the mutable storage class specifier is used to modify a class member variable even when the 
object is declared as const. This is particularly useful when you have a member that needs to be 
modified for internal bookkeeping or caching purposes, even if the object itself is logically constant.
Key Points About mutable:
Applies only to class data members (not local variables or functions).
Allows modification of the member even in a const object.
Useful for caching, logging, or thread-safety mechanisms.
Common Use Cases:
Caching Computed Results: Storing results of expensive computations.
Thread Synchronization: Marking a mutex as mutable to allow locking in const methods.
*/

class Example {
    private:
        mutable int cache; // Can be modified even in const objects
        int value;

    public:
        Example(int v) : cache(0),value(v) {}
        // Const member function modifying 'cache'
        int getValue() const 
        {
            cache++; // Allowed because 'cache' is mutable
            return value;
        }
        int getCache() const { return cache; }
};

int main (int argc, char** argv)
{
    const Example ex(42);
    std::cout << "Value: " << ex.getValue() << std::endl; // Outputs: Value: 42
    std::cout << "Cache after first call: " << ex.getCache() << std::endl; // Outputs: Cache after first call: 1
    std::cout << "Value: " << ex.getValue() << std::endl; // Outputs: Value: 42
    std::cout << "Cache after second call: " << ex.getCache() << std::endl; // Outputs: Cache after second call: 2
    return EXIT_SUCCESS;
}