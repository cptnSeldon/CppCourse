#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

#include <iostream>
#include <cstdlib>   // rand()
#include <typeinfo>  // typeid
#include <ctime>
#include <iomanip>  // setprecision

using namespace std;

Shape2D * createShape()
{
    cout << "A random shape is created" << endl;

    static double x = (rand() % 100) / 3.0;    // entre [0; 33]
    static double y = (rand() % 50)  / 7.0;    // entre [0;  7]

    switch(rand() % 3 )
    {
        case 0:
            return new Circle(x);
        case 1:
            return new Triangle(x, y);
        case 2:
            return new Rectangle(x, y);
        default:
            return new Circle(x);
    }
}

bool compareShapes(Shape2D * a, Shape2D * b)
{
    cout
        << "Comparison of an objet " << typeid(*a).name()
        << " with an objet " << typeid(*b).name()
        << endl;

    if(typeid(*a) != typeid(*b))
    {
        return false;
    }

    if(a->getX() != b->getX() || a->getY() != b->getY())
    {
        return false;
    }

  return true;
}

int main()
{
    srand(time(NULL));

    Shape2D * shapes = nullptr;

    //create 6 random shapes
    for(int i = 0; i < 6; i++)
    {
        if (shapes != NULL)
        {
            delete shapes;
        }

        shapes = createShape();

        //
        cout   << " Type:  (p)  " << typeid(shapes).name() << endl;
        cout   << " Type:  (*p) " << typeid(*shapes).name() << endl;

        //
        // Afficher la surface.
        cout << setprecision(1) << fixed << " Area :  " << shapes->area() << endl;

        // En fonction du type d'objet, afficher ses dimensions.
        if(typeid(*shapes) == typeid(Triangle))
        {
            cout << " Base:    " << shapes->getX() << endl
                 << " Height:  " << shapes->getY() << endl;
        }

        else if(typeid(*shapes) == typeid(Rectangle))
        {
            cout << " Width:   " << shapes->getX() << endl
                 << " Height:  " << shapes->getY() << endl;
        }

        else if(typeid(*shapes) == typeid(Circle))
        {
            cout << " Diameter: " << shapes->getX() << endl;
        }
        cout << endl;
    }

    //create shapes for comparison purposes
    Triangle t1(2, 3);
    Triangle t2(2, 3);
    Triangle t3(3, 2);
    Rectangle r(2, 3);

    //comparisons
    if(compareShapes(&t1, &t2))
    {
        cout << "t1 and t2 are identical." << endl;
    }

    if(!compareShapes(&t1, &t3))
    {
        cout << "t1 and t3 are different." << endl;
    }

    if(!compareShapes(&t1, &r))
    {
        cout << "t1 et r are different." << endl;
    }

    cout   << " Type:  (*p)   " << typeid(*shapes).name() << endl;

    cout << endl;

    cout << "\nPlease hit ENTER to continue... ";
    cin.get();
    return 0;

}