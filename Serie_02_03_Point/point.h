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
        Point();
        ///parameterized
        Point(string name, int x, int y);
        ///copy
        Point(const Point & point);

        //DESTRUCTOR
        ///decrement counter
        ~Point() { this->counter--; }

        //CLASS METHODS
        ///print a point
        void show();
        ///translate a points
        void translate(int x, int y);
        ///get counter
        static void showCounter() { cout << counter << endl; }

    protected:
        static int counter;
        string name;
        int x;
        int y;
};

#endif // POINT_H
