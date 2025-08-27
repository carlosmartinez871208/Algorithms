/*

*/

#include <iostream>
#include <thread>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

/*
Threads in C++
Threads in C++ allow you to run multiple functions concurrently, enabling parallel execution and 
better utilization of multi-core processors. Since C++11, threading support has been built into 
the standard library via the <thread> header.
Joining vs Detaching
join(): Wait for the thread to finish execution before continuing
detach(): Allow the thread to run independently (daemon thread)
*/

void threadFunction(int id)
{
    std::cout << "Thread " << id << " is executing.\n";
}

int main (int argc, char** argv)
{
    std::thread t(threadFunction, 1); // Create a thread that runs threadFunction with argument 1
    t.detach(); // Wait for the thread to finish
    std::cout << "Main thread is done.\n";
    return EXIT_SUCCESS;
}