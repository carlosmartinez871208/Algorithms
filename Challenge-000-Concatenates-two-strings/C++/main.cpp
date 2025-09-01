#include <iostream>
#include <string>
#include <cstring>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif


int main (int argc, char** argv)
{
    std::string s1 = "Hello";
    std::string s2 = " World";
    std::string result = s1 + s2; // Concatenates s1 and s2
    std::cout << result << std::endl; // Output: Hello World

    //or
    /*
    std::string s1 = "Modern ";
    std::string s2 = "C++";
    s1.append(s2); // Appends s2 to s1
    std::cout << s1 << std::endl; // Output: Modern C++
    */

    //or
    /*
    char s1[50] = "I love ";
    char s2[50] = "C++ programming";
    strcat(s1, s2); // Appends s2 to s1
    std::cout << s1 << std::endl; // Output: I love C++ programming
    */
    return EXIT_SUCCESS;
}
