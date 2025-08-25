/*
** Templates in C++
** Templates are a powerful feature in C++ that allow you to write generic code that works 
** with different data types. They enable writing functions and classes that operate on any 
** data type without rewriting the code for each specific type.
*/

#include <iostream>
#include <vector>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*Function Templates
Function templates allow you to create a single function definition that works with multiple types.
*/
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

/*
Class Templates
Class templates allow you to define classes that can work with different data types.
*/
template <typename T>
class Stack
{
    private:
        std::vector<T> elements;
    public:
        void push(const T& element) {
            elements.push_back(element);
        }
        void pop() {
            if (!elements.empty()) {
                elements.pop_back();
            }
        }
        T top() const {
            if (!elements.empty()) {
                return elements.back();
            }
            throw std::out_of_range("Stack is empty");
        }
};

/*
Variadic Templates (C++11 and later)
Allow templates to accept a variable number of arguments:
*/
template<typename... Args>
void printAll(const Args&... args) {
    (std::cout << ... << args) << std::endl; // Fold expression (C++17)
}

/*
Template Parameters
Templates can have multiple parameters and non-type parameters:
*/
template <typename T, int size>
class FixedArray {
    private:
        T arr[size];
    public:
        T& operator[](int index) {
            return arr[index];
        }
        int getSize() const {
            return size;
        }
};

int main (int argc, char** argv)
{
    std::cout << "Max of 3 and 7: " << max(3, 7) << std::endl;             // Works with integers
    std::cout << "Max of 3.5 and 2.1: " << max(3.5, 2.1) << std::endl;     // Works with doubles
    std::cout << "Max of 'a' and 'b': " << max('a', 'b') << std::endl;     // Works with characters
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    std::cout << "Top of intStack: " << intStack.top() << std::endl;          // Outputs 2
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Top of stringStack: " << stringStack.top() << std::endl;    // Outputs "World"
    printAll(1, 2.5, "Hello", 'A'); // Works with different types
    FixedArray<int, 5> intArray;
    for (int i = 0; i < intArray.getSize(); ++i) 
    {
        intArray[i] = i * 10;
        std::cout<<intArray[i]<<std::endl;
    }
    return EXIT_SUCCESS;
}