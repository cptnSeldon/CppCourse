#include <iostream>
#include <iomanip>
#include <ostream>
#include <stdlib.h>

using namespace std;

//Ex e1
void Format()
{
    cout << setfill('.')
            << setw(25) << right
            << "Colonne 1"
            << setw(10) << left
            << "Colonne 2."
            << endl;

    cout << setprecision(3) << fixed
            << setw(25) << left
            << 158.82589
            << setw(10) << left
            << 456.10288
            << endl;

    cout << setfill('.')
            << setw(25) << left << hex << uppercase
            << 255
            << setw(10) << left << oct
            << 128
            << endl;

    cout << setfill('.')
            << setw(25) << left << boolalpha
            << true
            << setw(10) << left
            << false
            << endl;
}

//Ex 2
int Divide(int dividend, int divisor, int & remainder)
{
    if(divisor == 0)
    {
        cout << "Undefined" << endl;
        exit(0);
    }

    remainder = dividend % divisor;

    return dividend / divisor;
}

int Divide(int dividend, int divisor, int * remainder)
{
    if(divisor == 0)
    {
        cout << "Undefined" << endl;
        exit(0);
    }

    * remainder = dividend % divisor;

    return dividend / divisor;
}

//dividend, divisor, remainder
array<int, 2> Divide(int dividend, int divisor)
{
    if(divisor == 0)
    {
        cout << "Undefined" << endl;
        exit(0);
    }

    array<int, 2> tab;

    tab[0] = dividend / divisor;
    tab[1] = dividend % divisor;

    return tab;
}

//Ext 3
void Polynomial(double a = 0, double b = 0, double c = 0, double d = 0, double e = 0)
{
    /*
    if(e != 0) cout << setprecision(1) << e << showpos << " x^5 ";
    if(d != 0) cout << setprecision(1) << d << showpos << " x^4 ";
    if(c != 0) cout << setprecision(1) << c << showpos << " x^3 ";
    if(b != 0) cout << setprecision(1) << b << showpos << " x^2 ";
    if(a != 0) cout << setprecision(1) << a << showpos << " x.";

    cout << noshowpos << endl;
    */

    int degree = 0;

    if (a) cout << setprecision(1) << a << "x^" << showpos << degree++ << " ";
    if (b) cout << setprecision(1) << b << "x^" << showpos << degree++ << " ";
    if (c) cout << setprecision(1) << c << "x^" << showpos << degree++ << " ";
    if (d) cout << setprecision(1) << d << "x^" << showpos << degree++ << " ";
    if (e) cout << setprecision(1) << e << "x^" << showpos << degree++ << " ";

    cout << noshowpos << endl;
}

//Ex 4
int Minimum(int a, int b)
{
    return a < b ? a : b;
}

double Minimum(double a, double b)
{
    return a < b ? a : b;
}

//Ex 5
struct Room
{
    //attributes
    string name;
    int length;
    int width;
    int height;

    //constructor
    Room() {}

    //constructor
    Room(string name_, int length_, int width_, int height_)
    {
        name = name_;
        length = length_;
        width = width_;
        height = height_;
    }

    //getter
    int GetSurfaceFloor()
    {
        return width * length;
    }

    int GetSurfaceWalls()
    {
        return (2 * length + 2 * width) * height;
    }

    int GetVolume()
    {
        return length * width * height;
    }
};

void RoomManager()
{
    Room r = Room("room", 2, 4, 6);

    int floor = r.GetSurfaceFloor();
    int walls = r.GetSurfaceWalls();
    int volume = r.GetVolume();

    cout << r.name << ", [l ,w, g] : "
         << r.length << ", "
         << r.width << ", "
         << r.height << endl;

    cout << "Floor surface : " << floor << endl;
    cout << "Wall surface : " << walls << endl;
    cout << "Volume : " << volume << endl;
}