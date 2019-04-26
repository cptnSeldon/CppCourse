#ifndef H_RECTANGLE
#define H_RECTANGLE

#include "figure.h"

class Rectangle : public Figure
{
    public:
        //CONSTRUCTOR
        Rectangle(int _color=0, double _x=0, double _y=0, double _width=0, double _height=0) : Figure(_color, _x, _x), width(_width), height(_height) { }

        //METHODS
        ///display figure
        void show() override
        {
            cout << "Rectangle: (x="
                 << x
                 << ", y="
                 << y
                 << ", width="
                 << width
                 << ", height="
                 << height
                 << ", color="
                 << internal << setfill('0') << setw(8) << hex
                 << color
                 << dec
                 << ")"
                 << endl;
        }

        private:
            double width, height;
};

#endif //H_RECTANGLE