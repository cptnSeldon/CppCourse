#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>

using namespace std;

class Point
{
    public:
        //CONSTRUCTORS
        ///default
        Point() : name("point"), x(0), y(0) { this->counter++; }
        ///parameterized
        Point(string name, int x, int y){ this->name = name; this->x = x; this->y = y; this->counter++; }
        ///copy
        Point(const Point & point) { this->name = point.name; this->x = point.x; this->y = point.y; this->counter++; }

        //DESTRUCTOR
        ///decrement counter
        ~Point() { this->counter--; }

        //CLASS METHODS
        ///print a point
        void show() { cout << this->name << " : (" << this->x << ", " << this->y << ")" <<endl; }
        ///translate a points
        void translate(int x, int y) { this->x = x; this->y = y; }
        ///get counter
        static void showCounter() { cout << counter << endl; }

    protected:
        static int counter;
        string name;
        int x;
        int y;
};

#endif // POINT_H
