#include <iostream>

#include "time2.h"

using namespace  std;

template <typename T>

void exchange(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;

    cout << "A : " << a << ", B : " << b << endl;
    exchange(a, b);
    cout << "A : " << a << ", B : " << b << endl;

    float c = 3.2;
    float d = 2.5;

    cout << "C : " << c << ", D : " << d << endl;
    exchange(c, d);
    cout << "C : " << c << ", D : " << d << endl;

    Time t1;
    Time t2;
    t1.adjust(2,2,2);
    t2.adjust(3,3,3);

    t1.show();
    t2.show();
    exchange(t1, t2);
    t1.show();
    t2.show();
}