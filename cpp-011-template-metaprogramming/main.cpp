/*
** Template Metaprogramming in C++
** Template metaprogramming (TMP) is a metaprogramming technique in which templates are used by a 
** compiler to generate temporary source code, which is merged by the compiler with the rest of the 
** source code and then compiled.
**
** Key Concepts
** 1. Compile-Time Computation
** TMP performs computations at compile time rather than runtime, resulting in more efficient programs.
** 2. Type Manipulation
** TMP allows for the manipulation and transformation of types, enabling the creation of generic and 
** reusable code.
** 3. Recursion
** TMP often relies on recursive templates to perform complex computations and generate code.
** 4. SFINAE (Substitution Failure Is Not An Error)
** SFINAE is a key principle in TMP that allows for the selection of template specializations based on 
** the validity of template arguments.
** 5. Variadic Templates
** Variadic templates enable the creation of templates that can accept a variable number of template 
** parameters, enhancing flexibility and reusability.
** 6. Type Traits
** Type traits are a set of template classes that provide information about types at compile time, 
** facilitating type manipulation and decision-making in TMP.
** 7. Expression Templates
** Expression templates are a technique used in TMP to represent mathematical expressions as types, 
** allowing for optimizations and efficient code generation.
** 8. Template Specialization
** Template specialization allows for the customization of template behavior for specific types or 
** conditions, enabling fine-tuned control over code generation.
** 9. Metafunctions
** Metafunctions are templates that operate on types and produce new types or values, serving as building 
** blocks for TMP.
** 10. Boost.MPL and Other Libraries
** Libraries like Boost.MPL provide a rich set of tools and utilities for TMP, making it easier to 
** implement complex metaprogramming techniques.
** Applications
** 1. Generic Programming
** TMP is widely used in generic programming to create algorithms and data structures that can operate 
** on a variety of types.
** 2. Compile-Time Assertions
** TMP can be used to enforce constraints and validate conditions at compile time, improving code safety 
** and correctness.
** 3. Domain-Specific Languages (DSLs)
** TMP can be employed to create DSLs that allow for expressive and concise code tailored to specific 
** problem domains.
** 4. Performance Optimization
** TMP can lead to performance optimizations by enabling inlining, unrolling loops, and eliminating 
** unnecessary computations at compile time.
** 5. Type-Safe Interfaces
** TMP can help create type-safe interfaces that prevent runtime errors by enforcing type constraints 
** at compile time.
** 6. Code Generation
** TMP can be used to generate boilerplate code, reducing redundancy and improving maintainability.
** 7. Library Development
** TMP is often used in the development of libraries to provide flexible and reusable components that 
** can adapt to different types and use cases.
** Conclusion
** Template metaprogramming is a powerful technique in C++ that enables compile-time computation, 
** type manipulation, and code generation. By leveraging TMP, developers can create efficient, generic, 
** and type-safe code that enhances performance and maintainability.
*/

#include <iostream>


#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

// Example: Compute factorial of a number at compile time using template metaprogramming
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};
template<>
struct Factorial<0> {
    static const int value = 1;
};

// Example: Type manipulation using template metaprogramming
template<bool Condition, typename TrueType, typename FalseType>
struct If {
    using type = TrueType;
};

template<typename TrueType, typename FalseType>
struct If<false, TrueType, FalseType> {
    using type = FalseType;
};

// SFINAE (Substitution Failure Is Not An Error)
// A technique that allows template specializations to be selected based on properties of types.
template<typename T>
auto foo(T t) -> decltype(t.bar(), void()) {
    // This version is called when T has a bar() method
    t.bar();
}

template<typename T>
void foo(T t) {
    // Fallback version
}
int main (int argc, char** argv)
{
    constexpr int val = Factorial<5>::value;
    std::cout << "Factorial of 5 is: " << val << std::endl;
    std::cout << "If<true, int, double>::type is: " << typeid(If<true, int, double>::type).name() << std::endl;
    std::cout << "If<false, int, double>::type is: " << typeid(If<false, int, double>::type).name() << std::endl;
    return EXIT_SUCCESS;
}