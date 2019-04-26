#include "complex.h"

Complex::Complex() : real(0), imaginary(0) { }

Complex::Complex(int real = 0, int imaginary = 0)
{
    this->real = real;
    this->imaginary = imaginary;
}

Complex Complex::add(const Complex & toAdd) const   //reference on passed complex -> avoids copying the whole object
{
    int r = real + toAdd.real;
    int i = imaginary + toAdd.imaginary;

    return Complex(r, i);
}

void Complex::show()
{
    cout << real << showpos << imaginary << "i" << noshowpos << endl;
}