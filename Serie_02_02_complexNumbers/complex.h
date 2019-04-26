
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    private:
        //ATTRIBUTES
        int real;
        int imaginary;

    public:
        //CONSTRUCTOR
        Complex();
        Complex(int, int);

        //FUNCTIONS
        int getReal(void) const { return real; };
        int getImaginary(void) const { return imaginary; };;
        Complex add(const Complex &) const; //reference on passed complex -> avoids copying the whole object
        void show();
};

#endif COMPLEX_H