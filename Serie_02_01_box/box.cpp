#include <iostream>
#include <iomanip>
#include "box.h"

//constructor
Box::Box()
{
    setPosition(0, 0);
    setSize(1, 1);
    setSymbol('A');
}

//methods
void Box::setPosition(int x, int y)
{
    positionX = x;
    positionY = y;
}

void Box::setSize(int w, int h)
{
    width = w;
    height = h;
}

void Box::setSymbol(char s)
{
    symbol = s;
}
void Box::translate(int x, int y)
{
    positionX += x;
    positionY += y;
}

void Box::showBox()
{
    string s = "";

    //  AAAA
    for(int i = 0; i < width; i++)
    {
        s += symbol;
    }

    //  .
    //  .
    for(int j = 0; j < positionY - 1; j++)
    {
        cout << "." << endl;
    }

    //  ....AAAA
    for(int k = 0; k < height; k++)
    {
        cout << setfill('.') << setw(positionX + width - 1) << right
         << s << endl;
    }
}