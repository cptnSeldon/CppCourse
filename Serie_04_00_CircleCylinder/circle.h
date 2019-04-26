#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <cmath>

class Circle
{
    public:
        //CONSTRUCTOR
        //default
        Circle() : radius(1) {}
        //parameterized
        Circle(int radius) { this-> radius = radius; }
        //copy
        Circle(const Circle & other) { this->radius = other.radius; }
        //METHODS
        double getRadius() { return radius; }
        /// A = πr^2
        double getArea() { return M_PI * radius * radius; }

    protected:
        double radius;

};

#endif // CIRCLE_H