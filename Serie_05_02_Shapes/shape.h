#ifndef SHAPE_H
#define SHAPE_H

class Shape2D
{
    public:
        //
        Shape2D(double _x, double _y) : x(_x), y(_y) {}
        //
        virtual ~Shape2D() {}
        //
        double getX() { return x; }
        double getY() { return y; }
        //
        virtual double area() = 0;

    protected:
        double x, y;
};

#endif //SHAPE_H