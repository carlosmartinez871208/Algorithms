/*

*/

#include <array>
#include <iostream>
#include <algorithm>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Given an array of positive integers, the task is to determine if a Pythagorean triplet exists 
in the given array. A triplet {a, b, c} is considered a Pythagorean triplet if it satisfies 
the condition a2 + b2 = c2.
Example:
    Input: arr[] = [3, 1, 4, 6, 5] 
    Output: true
    Explanation: The array contains a Pythagorean triplet {3, 4, 5}.

    Input: arr[] = [10, 4, 6, 12, 5]
    Output: false 
    Explanation: There is no Pythagorean triplet. 
*/

int main (int argc, char** argv)
{
    std::array<int, 5> arr = {1, 1, 4, 5, 3};
    for(auto& i : arr)
    {
        i = i * i;
    }
    std::sort(arr.begin(), arr.end());
    for(unsigned int i=0;i<(arr.size()-2);i++)
    {
        for(unsigned int j=i+1;j<(arr.size()-1);j++)
        {
            if((arr[i] + arr[j]) == arr[j+1])
            {
                std::cout << "true" << std::endl;
                return EXIT_SUCCESS;
            }
            else
            {/*Do nothing*/}
        }
    }
    std::cout << "false" << std::endl;
    return EXIT_SUCCESS;
}