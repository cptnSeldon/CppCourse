#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape2D
{
    public:
        //
        Triangle(double base, double height) : Shape2D(base, height) {}
        //
        double area() { return x * 0.5 * y; }
};

#endif //TRIANGLE_H