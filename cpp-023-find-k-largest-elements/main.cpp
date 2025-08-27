/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Given an array arr[] and an integer k, the task is to find k largest elements in the given array. 
Elements in the output array should be in decreasing order.
Examples:
    Input:  [1, 23, 12, 9, 30, 2, 50], k = 3
    Output: [50, 30, 23]
    Input:  [11, 5, 12, 9, 44, 17, 2], k = 2
    Output: [44, 17]
*/

int main (int argc, char** argv)
{
    std::vector<int> arr {1, 23, 12, 9, 30, 2, 50};
    const unsigned int k = 3u;
    std::sort(arr.begin(), arr.end(), std::greater<int>());
    for(unsigned int i = 0u; i < k; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}