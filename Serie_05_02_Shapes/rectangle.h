#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape2D
{
    public:
        //
        Rectangle(double length, double height) : Shape2D(length, height) {}
        //
        double area() { return x * y; }
};

#endif //RECTANGLE_H