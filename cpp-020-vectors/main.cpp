/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Vectors in C++
Vectors are a fundamental part of the C++ Standard Template Library (STL) that provide dynamic array functionality.
Common Vector Methods
Method	Description
push_back()	Adds an element to the end
pop_back()	Removes the last element
insert()	Inserts elements at specified position
erase()	Removes elements from specified position
clear()	Removes all elements
size()	Returns number of elements
capacity()	Returns storage capacity
resize()	Changes size of vector
empty()	Checks if vector is empty
Performance Considerations
Access time: O(1) for random access (like arrays)
Insertion/Deletion:
O(1) at end (amortized)
O(n) at beginning or middle (due to shifting)
Advanced Techniques
Vectors are generally preferred over raw arrays in modern C++ due to their flexibility and safety features. 
They manage memory automatically and provide a rich set of functionalities that simplify many programming tasks.
*/

int main (int argc, char** argv)
{
    std::vector<int> numbers; // Declare a vector of integers
    numbers.push_back(10);    // Add elements to the vector
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    std::cout << "Vector elements: ";
    for (const int& num : numbers) // Range-based for loop to iterate through the vector
    {
        std::cout << num << " "; // Print each element
    }
    std::cout << std::endl;
    std::cout << "Vector size: " << numbers.size() << std::endl;
    std::cout << "Vector capacity: " << numbers.capacity() << std::endl;
    numbers.pop_back(); // Remove the last element
    std::cout << "After pop_back, vector elements: ";
    for (const int& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Vector size after pop_back: " << numbers.size() << std::endl;
    std::cout << "Vector capacity after pop_back: " << numbers.capacity() << std::endl;
    std::vector<int> vec;
    vec.reserve(9); // Resize the vector to hold 9 elements
    std::cout << "Vector capacity after reserve(9): " << vec.capacity() << std::endl;
    for(auto i=vec.begin(); i!=vec.end(); ++i)
    {
        std::cout << *i << " "; // This will not print anything as the vector is empty
    }
    std::cout << std::endl;
    std::sort(numbers.begin(), numbers.end(), std::greater<int>()); // Sort in descending order
    std::cout << "Sorted vector elements in descending order: ";
    for (const int& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}