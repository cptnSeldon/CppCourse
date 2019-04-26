#ifndef H_TRIANGLE
#define H_TRIANGLE

#include "figure.h"

class Triangle : public Figure
{
    public:
        //CONSTRUCTOR
        Triangle(int _color=0, double _x=0, double _y=0, double _x2=0, double _y2=0, double _x3=0, double _y3=0) : Figure(_color, _x, _x), x2(_x2), y2(_y2), x3(_x3), y3(_y3) { }

        //METHODS
        ///display figure
        void show() override
        {
            cout << "Triangle: (x1="
                 << x
                 << ", y1="
                 << y
                 << ", x2="
                 << x2
                 << ", y2="
                 << y2
                 << ", x3="
                 << x3
                 << ", y3="
                 << y3
                 << ", color="
                 << internal << setfill('0') << setw(8) << hex
                 << color
                 << dec
                 << ")"
                 << endl;
        }

        ///translate figure
        virtual void translate(double dx, double dy) override
        {
            Figure::translate(dx, dy);
            x2 += dx;
            y2 += dy;
            x3 += dx;
            y3 += dy;
        }

        private:
            double x2, y2, x3, y3;
};

#endif //H_TRIANGLE