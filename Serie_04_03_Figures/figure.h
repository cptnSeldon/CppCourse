#ifndef H_FIGURE
#define H_FIGURE

#include <iostream>
#include <iomanip>

using namespace std;

class Figure
{
    public:
        //CONSTRUCTOR
        Figure(int _color, double _x, double _y) : color(_color), x(_x), y(_y) {}

        //DESTRUCTOR
        virtual ~Figure() {}

        //METHODS
        ///display figure
        virtual void show() = 0;

        ///translate figure
        virtual void translate(double dx, double dy)
        {
            x += dx;
            y += dy;
        }

    protected:
        int color;
        double x;
        double y;
};

#endif //H_FIGURE