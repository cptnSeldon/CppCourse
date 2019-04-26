#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

using namespace std;

class Point
{
    public:
    friend class Rectangle;
        //CONSTRUCTORS
        ///default
        Point() : name("point"), x(0), y(0) {  }
        ///parameterized
        Point(string name, int x, int y){ this->name = name; this->x = x; this->y = y; }
        ///copy
        Point(const Point & point) { this->name = point.name; this->x = point.x; this->y = point.y; }

        //DESTRUCTOR
        ///decrement counter
        ~Point() { }

        //CLASS METHODS
        ///print a point
        void show() { cout << this->name << " : (" << this->x << ", " << this->y << ")" <<endl; }
        ///translate a points
        void translate(int x, int y) { this->x = x; this->y = y; }

    protected:
        string name;
        int x;
        int y;
};

#endif // POINT_H
