/* Standard libraries: */
#include <iostream>

/* User libraries */
#include "cylinder.h"

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif


int main (int argc, char** argv)
{
    Cylinder cylinder1 (2,4);
    std::cout << "Base radius: " << cylinder1.get_base_radius() << std::endl;
    cylinder1.set_base_radius(3);
    cylinder1.set_height(3);
    std::cout << "Cylinder volume: " << cylinder1.calculate_volume() << std::endl;
    return EXIT_SUCCESS;
}
