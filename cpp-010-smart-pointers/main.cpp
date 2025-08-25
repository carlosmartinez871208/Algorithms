/*
** Smart Pointers in C++
** Smart pointers are objects that manage the lifetime of dynamically allocated memory in C++. 
** They automatically deallocate memory when it's no longer needed, helping to prevent memory leaks.
**
** Types of Smart Pointers in C++ (since C++11)
** 1. std::unique_ptr
** Exclusive ownership of the managed object
** Cannot be copied (only moved)
** Lightweight, zero overhead compared to raw pointers
** Destroys the object when it goes out of scope
**
** 2. std::shared_ptr
** Shared ownership of the managed object
** Uses reference counting to track usage
** Can be copied and assigned
** Deletes the object when last shared_ptr is destroyed
**
** 3. std::weak_ptr
** Non-owning "weak" reference to an object managed by shared_ptr
** Doesn't increase reference count
** Used to break circular references between shared_ptrs
**
** Best Practices
** Prefer smart pointers over raw pointers for ownership semantics.
** Use make_unique and make_shared instead of direct new operations:
** More efficient (single allocation for control block + object)
** Exception-safe.
** Use unique_ptr by default - it's the most lightweight option.
** Use shared_ptr only when truly needed for shared ownership.
** Use weak_ptr to break circular references between shared_ptrs.
** Avoid mixing smart pointers and raw pointers for the same resource.
** Custom Deleters
** Smart pointers can be configured with custom deleters:
** Smart pointers provide automatic memory management while maintaining 
** performance close to raw pointers, making them essential tools for modern C++ development.
*/

#include <iostream>
#include <string.h>
#include <memory> // For std::unique_ptr, std::shared_ptr, std::weak_ptr

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

void example_unique_ptr() {
    // Creating a unique_ptr
    std::unique_ptr<int> ptr(new int(42));
    
    // Using make_unique (preferred since C++14)
    auto ptr2 = std::make_unique<int>(100);
    
    // Accessing the pointer
    *ptr = 50;
    
    // Releasing ownership (returns raw pointer)
    int* raw = ptr.release();
    
    // Resetting with new object
    ptr.reset(new int(200));
    
    // Automatically deleted when out of scope
}

void example_shared_ptr() {
    // Creating a shared_ptr
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    
    // Copying increases reference count
    std::shared_ptr<int> ptr2 = ptr1;
    
    // Accessing the pointer (same as unique_ptr)
    *ptr1 = 50;
    
    // Getting reference count (use_count is approximate)
    long count = ptr1.use_count();
    
    // Resetting decreases reference count or replaces object
    ptr1.reset();
}

void example_weak_ptr() {
    std::shared_ptr<int> shared = std::make_shared<int>(42);
    
    // Creating weak pointer from shared pointer
    std::weak_ptr<int> weak = shared;
    
    // Converting weak to shared (if object still exists)
    if (auto temp = weak.lock()) {
        *temp = 50;  // use temp like a shared_ptr
        
        long count = temp.use_count();  // ref count is at least 2 now
        
        std::cout << "Value: " << *temp << std::endl;
        
        std::cout << "Ref count: " << temp.use_count() << std::endl;
        
        std::cout << "Expired? " << weak.expired() << std::endl;  
     }
    else 
    {std::cout << "Object has been deleted" << std::endl;}
}

int main (int argc, char** argv)
{
    example_weak_ptr();
    return EXIT_SUCCESS;
}