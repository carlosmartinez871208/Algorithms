/*
** RAII in C++ (Resource Acquisition Is Initialization)
** RAII is a fundamental C++ programming technique that binds resource management to 
** object lifetime, ensuring proper cleanup of resources like memory, file handles, 
** network connections, etc.
** 
** Key Concepts
** Resource Acquisition in Constructor: Resources are acquired during object construction
** Resource Release in Destructor: Resources are automatically released when the object 
** goes out of scope
** Exception Safety: Provides strong exception safety guarantee
** Avoids Resource Leaks: Ensures resources are properly released, preventing leaks.
** 
** Why RAII Matters
** Automatic Cleanup: No need for manual delete or close calls
** Exception Safety: Resources are properly released even if exceptions occur
** Deterministic Destruction: C++ guarantees destructor calls when objects go out of scope
** Standard Library RAII Examples
** std::unique_ptr, std::shared_ptr for memory management
** std::lock_guard, std::unique_lock for mutex management
** std::fstream for file handling
** Containers like std::vector, std::string that manage their own memory
** Implementing Move Semantics with RAII
*/

#include <iostream>
#include <string>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class FileHandler
{
    FILE* file;
    public:
    explicit FileHandler(const char* filename,const char* mode):file(fopen(filename,mode))
    {
        if(!file)
        {
            throw std::runtime_error("Failed to open file");
        }
    }
    ~FileHandler()
    {
        if(file)
        {
            fclose(file);
        }
    }
    FileHandler(const FileHandler&) = delete; // Disable copy constructor
    FileHandler& operator=(const FileHandler&) = delete; // Disable copy assignment operator
    void write(const std::string& content)
    {
        if (fputs(content.c_str(), file) == EOF) {
            throw std::runtime_error("Write failed");
        }
    }
};

int main (int argc, char** argv)
{
    FileHandler file("example.txt","w");
    file.write("Hello, RAII in C++!\n");
    return EXIT_SUCCESS;
}