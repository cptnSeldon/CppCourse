#include "circle.h"
#include "cylinder.h"

#include <iostream>

using namespace std;

int main()
{
    Circle circle(2);
    cout << "Circle :" << endl
         << "\tradius [" << circle.getRadius() << "]" << endl
         << "\tarea [" << circle.getArea() << "]" << endl;

    Cylinder cylinder(2, 5);
    cout << "Cylinder : " << endl
         << "\tradius [" << cylinder.getRadius() << "]" << endl
         << "\theight [" << cylinder.getHeight() << "]" << endl
         << "\tarea [" << cylinder.getArea() << "]" << endl
         << "\tvolume [" << cylinder.getVolume() << "]" << endl;

    return 0;
}