/* Cylinder  */
#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "constants.h"

class Cylinder 
{
    public:
        /* Default constructor: */
        Cylinder() = default;
        /* Constructor: */
        Cylinder (double rad_param,double height_param);
        /* Get base radius method: */
        double get_base_radius();
        /* Get height method: */
        double get_height();
        /* Set base radius method: */
        void set_base_radius(double radius_param);
        /* Set height method: */
        void set_height(double height_param);
        /* Calculate volume method:  */
        double calculate_volume();
    private:
        double base_radius {1};
        double height      {1};
};

#endif