#include <iostream>
#include <cstdlib>

using namespace std;

//Using reference
int divide(int dividend, int divisor, int & remainder)
{
    if(divisor == 0)
    {
        cout << "Undefined" << endl;
        exit(0);
    }

    remainder = dividend % divisor;

    return dividend / divisor;
}

//Using pointer
int divide(int dividend, int divisor, int * remainder)
{
    if(divisor == 0)
    {
        cout << "Undefined" << endl;
        exit(0);
    }

    * remainder = dividend % divisor;

    return dividend / divisor;
}

//Using array
array<int, 2> divide(int dividend, int divisor)
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

//Main
void printExercise02()
{
    int dividend = 37;
    int divisor = 2;
    int remainderA;
    int remainderB;

    int qA = divide(dividend, divisor, remainderA);
    int qB = divide(dividend, divisor, remainderB);
    array<int, 2> tab = divide(dividend, divisor);

    cout << dividend << " / " << divisor
         << " = " << qA << ", remains : " << remainderA << endl;

    cout << dividend << " / " << divisor
         << " = " << qB << ", remains : " << remainderB << endl;

    cout << dividend << " / " << divisor
         << " = " << tab[0] << ", remains : " << tab[1] << endl;
}