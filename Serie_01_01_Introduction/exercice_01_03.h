#include <iostream>

using namespace std;

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

void printExercise03()
{
    Polynomial(3, -5, 0, 7.1, 2);
    Polynomial(2, -3, 4);
}