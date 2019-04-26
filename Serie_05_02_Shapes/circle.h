#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape2D
{
    public:
        //
        Circle(double radius, double y = 0) : Shape2D(radius, y) {}
        //
        double area() { return 3.14 * x * x; }
};

#endif //CIRCLE_H