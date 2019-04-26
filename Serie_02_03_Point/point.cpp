#include "point.h"

using namespace std;

//initialize counter to 0 one time
int Point::counter = 0;

//CONSTRUCTORS
///default
Point::Point() : name("point"), x(0), y(0)
{
    this->counter++;
}
///parameterized
Point::Point(string name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;

    this->counter++;
}
///copy
Point::Point(const Point & point)
{
    this->name = point.name;
    this->x = point.x;
    this->y = point.y;

    this->counter++;
}

//CLASS METHODS
///print a point
void Point::show()
{
    cout << this->name << " : ("
         << this->x << ", " << this->y << ")"
         <<endl;
}
///translate a points
void Point::translate(int x, int y)
{
    this->x = x;
    this->y = y;
}