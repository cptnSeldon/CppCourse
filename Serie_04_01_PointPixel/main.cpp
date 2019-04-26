#include "pixel.h"

int main()
{
    Pixel p1("black", 0, 0, 0);

    p1.show();

    p1.setColour(255, 0, 0);

    p1.show();

    p1.setColour(50, 50, 50);

    p1.show();

    return 0;
}