#ifndef H_PIXEL
#define H_PIXEL

#include <iostream>
#include <iomanip>
#include "point3.h"

using namespace std;

//initialize counter to 0 one time
int Point::counter = 0;

class Pixel : Point
{
    public:
        //CONSTRUCTOR
        ///default
        Pixel() : Point("point", 1, 1), colour(0) {}
        ///parameterized
        Pixel(string name, int x, int y, int colour = 0) : Point(name= "", x = 0, y = 0) { this->colour = colour; }

        //METHODS
        ///GETTER   : https://math.stackexchange.com/questions/1635999/algorithm-to-convert-integer-to-3-variables-rgb
        int getR() { return colour / (256 * 256); }
        int getG() { return (colour / 256) % 256; }
        int getB() { return colour % 256; }
        void getHexadecimal() { cout << hex << "hexadecimal=" << colour << dec;}
        ///SETTER
        ///TODO : check overflow
        void setColour(int r, int g, int b) { if ((0 <= r && r <= 255) && (0 <= g && g <= 255) && (0 <= b && b <= 255)) this->colour = 256 * 256 * r + 256* g + b; }
        ///print
        void show() { cout << name << "(" << x << ", " << y << ")" << ", colour int=" << colour << ", r=" << getR() << ", g=" << getG() << ", b=" << getB() << ", "; getHexadecimal(); cout << endl; }

    private:
        int colour; //0-255 blue, 0-255 green, 0-255 red
};

#endif //H_PIXEL