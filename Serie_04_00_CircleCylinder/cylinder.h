#ifndef H_CYLINDER
#define H_CYLINDER

#include "circle.h"

class Cylinder : Circle
{
    public:
        //CONSTRUCTOR
        ///default
        Cylinder() : Circle(1), height(1) {}
        ///parameterized
        Cylinder(int radius, int height) : Circle(radius) { this->height = height; }
        //METHODS
        double getRadius() { return Circle::getRadius(); }
        double getHeight() { return height; }
        /// A = 2πrh + 2πr^2
        double getArea()  { return (2 * M_PI * radius * height) + (2 * M_PI * radius * radius); }
        /// V = πr^2
        double getVolume() { return M_PI * radius * radius * height; }
    private:
        double height;
};

#endif //H_CYLINDER