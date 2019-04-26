#include "rectangle.h"

//CONSTRUCTORS
///default
Rectangle::Rectangle() : upLeft(Point()), downRight(Point())
{
    //upLeft = Point();
    //downRight = Point();
}
///parameterized
Rectangle::Rectangle(Point upLeft, Point downRight)
{
    /*
        .->
        |
        ˇ
        (x_up,y_up)
        .___________.
         <----X----> ^
                     |

                     Y

                     |
                     ˇ
        .___________.
                    (x_down,y_down)

        X = x_down-x_up
        Y = y_down-y_up
    */
    //test : x_up < x_down => ok,  y_up < y_down => ok
    if (upLeft.x < downRight.x && upLeft.y < downRight.y)
     {
        this->upLeft = upLeft;
        this->downRight = downRight;
     }
     else
     {
        this->upLeft = downRight;
        this->downRight = upLeft;
     }
}
///copy
Rectangle::Rectangle(const Rectangle & other)
{
    this->upLeft = other.upLeft;
    this->downRight = other.downRight;
}
//FUNCTIONS
///getters : maths functions
int Rectangle::getPerimeter()
{
    /*
        .->
        |
        ˇ
        (x_up,y_up)
        .___________.
         <----X----> ^
                     |

                     Y

                     |
                     ˇ
        .___________.
                    (x_down,y_down)

        X = x_down-x_up
        Y = y_down-y_up
    */

   return (downRight.x - upLeft.x) * 2 + (downRight.y - upLeft.y) * 2;

}
int Rectangle::getArea()
{
    return (downRight.x - upLeft.x) * (downRight.y - upLeft.y);
}
///print graphic result
void Rectangle::show()
{
    char character = 'x';
    //window : 25 lines for 80 caracters max

    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            if(j >= upLeft.x && i >= upLeft.y && j <= downRight.x && i <= downRight.y)
            {
                cout << character;
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }

}
///translation of rectangle
void Rectangle::translate(int x, int y)
{
    this->upLeft.x += x;
    this->upLeft.y += y;
    this->downRight.x += x;
    this->downRight.y += y;
}
///check if a point is inside the current rectangle
bool Rectangle::contains(Point & other)
{
    /*
        .->
        |
        ˇ
        (x_up,y_up)
        .___________.
         <----X----> ^
                     |

                     Y

                     |
                     ˇ
        .___________.
                    (x_down,y_down)

        X = x_down-x_up
        Y = y_down-y_up
    */

    if(other.x < this->upLeft.x && other.x > this->downRight.x &&
        other.y < this->upLeft.y && other.y > this->downRight.y)
    {
        return false;
    }
    else
    {
        return true;
    }
}