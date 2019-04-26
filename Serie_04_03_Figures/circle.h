#ifndef H_CIRCLE
#define H_CIRCLE

#include "figure.h"

class Circle : public Figure
{
    public:
        //CONSTRUCTOR
        Circle(int _color=0, double _x=0, double _y=0, double _radius=0) : Figure(_color, _x, _x), radius(_radius){ }

        //METHODS
        ///display figure
        void show() override
        {
            cout << "Circle: (x="
                 << x
                 << ", y="
                 << y
                 << ", radius="
                 << radius
                 << ", color="
                 << internal << setfill('0') << setw(8) << hex
                 << color
                 << dec
                 << ")"
                 << endl;
        }

        private:
            double radius;
};

#endif //H_CIRCLE