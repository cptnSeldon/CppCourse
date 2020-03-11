#include <iostream>

using namespace std;

/*void Polynomial(double a = 0, double b = 0, double c = 0, double d = 0, double e = 0)
{
    if(e != 0) cout << setprecision(1) << showpos << e << noshowpos << " x^5 ";
    if(d != 0) cout << setprecision(1) << showpos << d << noshowpos << " x^4 ";
    if(c != 0) cout << setprecision(1) << showpos << c << noshowpos << " x^3 ";
    if(b != 0) cout << setprecision(1) << showpos << b << noshowpos << " x^2 ";
    if(a != 0) cout << setprecision(1) << showpos << a << noshowpos << " x.";

    cout << noshowpos << endl;
}*/

void Polynomial(double a, double b, double c, double d, double e)
{
    if(e != 0) cout << setprecision(1) << showpos << e << noshowpos << " x^5 ";
    if(d != 0) cout << setprecision(1) << showpos << d << noshowpos << " x^4 ";
    if(c != 0) cout << setprecision(1) << showpos << c << noshowpos << " x^3 ";
    if(b != 0) cout << setprecision(1) << showpos << b << noshowpos << " x^2 ";
    if(a != 0) cout << setprecision(1) << showpos << a << noshowpos << " x.";

    cout << noshowpos << endl;
}

void Polynomial(double a, double b, double c)
{
    if(c != 0) cout << setprecision(1) << showpos << c << noshowpos << " x^3 ";
    if(b != 0) cout << setprecision(1) << showpos << b << noshowpos << " x^2 ";
    if(a != 0) cout << setprecision(1) << showpos << a << noshowpos << " x.";

    cout << noshowpos << endl;
}

void printExercise03()
{
    Polynomial(3, -5, 0, 7.1, 2);
    Polynomial(2, -3, 4);
}