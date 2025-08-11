/*
** In C++, a lambda function (or lambda expression) is an anonymous function that can be defined inline, 
** directly where it is needed. Lambdas provide a concise way to create simple function objects without 
** explicitly declaring a named function or functor.
**
** Syntax:
[capture-list](parameters) -> return-type 
{
    // body
}
** Key Components:
** Capture List ([]):
** Specifies which variables from the enclosing scope are accessible inside the lambda.
** Can capture by value ([=]), by reference ([&]), or selectively ([x, &y]).
** Parameters ( ):
** Similar to regular function parameters (optional if no parameters are needed).
** Return Type (-> type) (optional):
** Can often be omitted if the compiler can deduce it.
** Body { }:
** Contains the code to execute.
**
** Use cases:
** Passing short functions as arguments.
** Defining quick callbacks.
** Replacing small functors without boilerplate code.
*/
#include <algorithm>
#include <iostream>
#include <vector>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*Simple Lambda: */
auto greet = []()
{
    std::cout << "Hello World!" << std::endl;
};

/*Lambda with parameters: */
auto add = [](int a,int b) -> int
{
    return (int)(a+b);
};

/* Generic Lambdas: */
auto multiply = [](auto a,auto b){return a*b;};

int main (int argc, char** argv)
{
    int sum=0;
    greet();
    sum = add(3,4);
    std::cout << "Result:"<< sum << std::endl;
    /* Capturing variables: */
    auto increment =[sum](int y){return sum+y;};
    std::cout<<"Increment: "<<increment(3)<<std::endl;
    /* Modifying captured variables by reference: */
    auto counter = [&sum](){sum++;};
    counter();
    std::cout<<"Counter: "<< sum << std::endl;
    std::vector<int> nums = {5,1,7,5,9,2,3};
    std::sort(nums.begin(),nums.end(), [](int a,int b){return a>b;});
    std::cout << "Sort: "<< std::endl;;
    for(int i=0;i<(int)nums.size();i++)
    {
        std::cout << nums[i];
    }
    std::cout<<std::endl;
    std::cout<< multiply(1.5f,3) <<std::endl;
    /* Mutable lambdas: */
    auto modValue = [sum]() mutable{sum+=10;};
    modValue(); /* Does not affect original value */
    std::cout<< sum <<std::endl;
    return EXIT_SUCCESS;
}