#include <iostream>
#include "polynomial.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Polynomial p0;
    cout << "p0: " << p0 << endl;
    cout << "p0 is null: " << boolalpha << p0.isNull() << endl;

    Polynomial p1(3, 2, 0);

    cout << "p1: " << p1 << endl;
    cout << "p1 is null: " << boolalpha << p1.isNull() << endl;

    Polynomial p2(0, 2, 1);
    cout << "p2: " << p2 << endl;

    Polynomial p3(3);
    cout << "p3: " << p3 << endl;

    p3.reset(-2);
    cout << "p3 after reset: " << p3 << endl;

    Polynomial p4 = p3;
    cout << "p4: " << p4 << endl;

    cout << "Current number of instances: " << Polynomial::getInstanceNumber() << endl;

    p0 = p2 = p3;
    cout << "p0: " << p0 << endl;
    cout << "p2: " << p2 << endl;

    p0 += p1;
    cout << "p0: " << p0 << endl;
    cout << "p1: " << p1 << endl;

    Polynomial p5 = p0 + p1;
    cout << "p5: " << p5 << endl;

    cout << "Current number of instances: " << Polynomial::getInstanceNumber() << endl;

    return 0;
}