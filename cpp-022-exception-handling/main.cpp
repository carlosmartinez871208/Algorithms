/*

*/

#include <iostream>
#include <stdexcept>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
In C++, the mutable storage class specifier is used to modify a class member variable even when the 
object is declared as const. This is particularly useful when you have a member that needs to be 
modified for internal bookkeeping or caching purposes, even if the object itself is logically constant.
In C++, exception handling is done using try, catch, and throw blocks. This mechanism allows you to handle runtime errors gracefully.

Basic Syntax:
try {
    // Code that might throw an exception
    if (error_condition) {
        throw exception_object; // Throw an exception
    }
}
catch (exception_type e) {
    // Handle the exception
}
Key Components:
try block: Contains code that might throw an exception.
throw statement: Signals an exception when an error occurs.
catch block: Catches and handles the thrown exception.
Key Notes:
Always catch exceptions by reference (const &) to avoid slicing and improve performance.
Use catch (...) as a fallback to handle unexpected exceptions.
Exceptions should be used for exceptional conditions, not for regular control flow.
Would you like a deeper explanation of custom exceptions or Rethrowing?
*/

int main (int argc, char** argv)
{
    //Basic exception handling example:
    try 
    {
        int numerator = 10;
        int denominator = 0; // This will cause a division by zero error

        if (denominator == 0) 
        {
            throw std::runtime_error("Division by zero error");
        }
        int result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    //Multiple catch blocks example:
    try 
    {
        throw std::out_of_range("Out of range error");
    }
    catch (const std::runtime_error& e) 
    {
        std::cerr << "Caught a runtime error: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Caught an out of range error: " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cerr << "Caught an unknown exception" << std::endl;
    }
    return EXIT_SUCCESS;
}