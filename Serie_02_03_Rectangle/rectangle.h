#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <iomanip>

#include "point2.h"

using namespace std;

class Rectangle
{
    public:
        //CONSTRUCTORS
        ///default
        Rectangle();
        ///parameterized
        Rectangle(Point upLeft, Point downRight);
        ///copy
        Rectangle(const Rectangle & other);
        //FUNCTIONS
        ///getters : maths functions
        int getPerimeter();
        int getArea();
        ///print graphic result
        void show();
        ///translation of rectangle
        void translate(int x, int y);
        ///check if a point is inside the current rectangle
        bool contains(Point & other);

    private:
        Point upLeft;
        Point downRight;
};

#endif //RECTANGLE_H