#include <iostream>

const double PI {3.14159};

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class cylinder
{
    private:
        double base_radius {1.0};
        double height      {1.0};
    
    public:
        double volume()
        {
            return PI*base_radius*base_radius*height;
        }
        cylinder(double cylinder_radius,double cylinder_height)
        {
            base_radius = cylinder_radius;
            height = cylinder_height;
        }
        cylinder() = default;
};

int main (int argc, char** argv)
{
    cylinder cylinder1;
    double height,radius;
    std::cin >> height;
    std::cin >> radius;
    cylinder cylinder2(radius,height);
    std::cout << "This program calculates cylinder volume: " << std::endl;
    std::cout << "Cylinder volume is: " << cylinder1.volume() << std::endl;
    std::cout << "Cylinder volume is: " << cylinder2.volume() << std::endl;
    return EXIT_SUCCESS;
}
