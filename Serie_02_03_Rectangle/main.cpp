#include "rectangle.h"

int main()
{
    Point p1("up", 2, 2);
    Point p2("down", 5, 5);

    Point p3("up", 9, 9);
    Point p4("down", 15, 15);

    Rectangle r1(p1, p2);
    Rectangle r2(p3, p4);

    r1.show();
    cout << endl;
    cout << endl;
    r2.show();

    return 0;
}