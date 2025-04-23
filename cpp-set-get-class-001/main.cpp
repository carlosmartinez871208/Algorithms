#include <iostream>
#include <ostream>

const double PI {3.14159265359};

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class Cylinder 
{
    public:
        /* Default constructor: */
        Cylinder() = default;
        /* Constructor: */
        Cylinder (double rad_param,double height_param)
        {
            base_radius = rad_param;
            height = height_param;
        }
        /* Get base radius method: */
        double get_base_radius()
        {
            return base_radius;
        }
        /* Get height method: */
        double get_height()
        {
            return height;
        }
        /* Set base radius method: */
        void set_base_radius(double radius_param)
        {
            base_radius = radius_param;
        }
        /* Set height method: */
        void set_height(double height_param)
        {
            height = height_param;
        }
        /* Calculate volume method:  */
        double calculate_volume()
        {
            return (PI*base_radius*base_radius*height);
        }

    private:
        double base_radius {1};
        double height      {1};
};

int main (int argc, char** argv)
{
    Cylinder cylinder1 (2,4);
    std::cout << "Base radius: " << cylinder1.get_base_radius() << std::endl;
    cylinder1.set_base_radius(3);
    cylinder1.set_height(3);
    std::cout << "Cylinder volume: " << cylinder1.calculate_volume() << std::endl;
    return EXIT_SUCCESS;
}
