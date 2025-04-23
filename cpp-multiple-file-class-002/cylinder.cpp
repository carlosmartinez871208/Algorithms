/* Cylinder */
#include "cylinder.h"

/* Constructor: */
Cylinder::Cylinder (double rad_param,double height_param)
{
    base_radius = rad_param;
    height = height_param;
}
/* Get base radius method: */
double Cylinder::get_base_radius()
{
    return base_radius;
}
/* Get height method: */
double Cylinder::get_height()
{
    return height;
}
/* Set base radius method: */
void Cylinder::set_base_radius(double radius_param)
{
    base_radius = radius_param;
}
/* Set height method: */
void Cylinder::set_height(double height_param)
{
    height = height_param;
}
/* Calculate volume method:  */
double Cylinder::calculate_volume()
{
    return (PI*base_radius*base_radius*height);
}