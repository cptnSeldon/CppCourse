#include "triangle.h"
#include "rectangle.h"
#include "circle.h"

int main()
{
    Figure *figures[3];

    figures[0] = new Circle();
    figures[1] = new Triangle();
    figures[2] = new Rectangle();

    for(int i = 0; i < 3; i++)
    {
        figures[i]->show();
        figures[i]->translate(1, 1);
        figures[i]->show();
    }

    for(int i = 0; i < 3; i++)
    {
        delete figures[i];
    }

    return 0;
}