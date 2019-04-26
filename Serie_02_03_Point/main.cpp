#include "point.h"

int main()
{
    Point p1;
    Point *p2 = new Point("p2", 3, 4);
    Point p3(p1);

    p1.show();
    p2->show();
    p3.show();

    p1.translate(2, 2);
    p1.show();

    p1.showCounter();
    delete p2;
    p1.showCounter();

    return 0;
}