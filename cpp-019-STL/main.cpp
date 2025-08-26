/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
STL in C++ (Standard Template Library)
The Standard Template Library (STL) is a powerful set of C++ template classes that provide general-purpose 
classes and functions with templates that implement many popular and commonly used algorithms and data structures.
Main Components of STL
1. Containers
Sequence Containers: vector, deque, list, array, forward_list
Associative Containers: set, multiset, map, multimap
Unordered Associative Containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap
Container Adapters: stack, queue, priority_queue
2. Algorithms
Sorting: sort(), stable_sort(), partial_sort()
Searching: binary_search(), lower_bound(), upper_bound()
Non-modifying operations: count(), find(), for_each()
Modifying operations: copy(), transform(), replace()
Numeric operations: accumulate(), inner_product()
3. Iterators
Input iterators, output iterators
Forward iterators, bidirectional iterators
Random access iterators
4. Functors (Function Objects)
Classes that overload the function call operator (operator())
Predefined functors in <functional>: plus, minus, multiplies, etc.
Advantages of STL
Reusability: Well-tested components reduce development time
Efficiency: Optimized implementations of algorithms and data structures
Generic programming: Works with any data type through templates
Standardization: Part of the C++ standard library
*/

int main (int argc, char** argv)
{
     // Vector example
    std::vector<int> v = {5, 3, 1, 4, 2};
    std::sort(v.begin(), v.end()); // Sort the vector
    
    // Set example (automatically sorted)
    std::set<int> s = {5, 3, 1, 4, 2};
    
    // Map example
    std::map<std::string, int> m;
    m["apple"] = 5;
    m["banana"] = 3;
    
    // Algorithm example - find_if with lambda
    auto it = std::find_if(v.begin(), v.end(), [](int x) {
        return x > 3;
    });
    
    if (it != v.end()) {
        std::cout << "First element >3 is: " << *it << '\n';
    }
    return EXIT_SUCCESS;
}