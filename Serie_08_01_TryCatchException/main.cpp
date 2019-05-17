#include <iostream>

#include "error.h"

using namespace std;

void positive(int value);
void inferior(int value, int maximum);
void superior(int value, int minimum);

int main()
{
    int min = 10;
    int max = 100;

    try
    {
        int n;

        cout << "Enter int value : " << endl;
        cin >> n;

        positive(n);
        inferior(n, max);
        superior(n, min);

        cout << "Correct value entered." << endl;
    }
    catch(const Error & error)
    {
        cout << "Incorrect value " << error.what() << endl;
    }
    //DEFAULT
    catch(...)
    {
        cout << "Unknown error." << endl;
    }
    cout << endl;

    return 0;
}

void positive(int value)
{
    if(value < 0) throw Error("Error : value is not positive.");

    cout << "Entered value is positive." << endl;
}
void inferior(int value, int maximum)
{
    if(value < maximum) throw Error("Error : value is not inferior.");

    cout << "Entered value is inferior to " << maximum << endl;
}
void superior(int value, int minimum)
{
    if(value < minimum) throw Error("Error : value is not superior");

    cout << "Entered value is superior to " << minimum << endl;
}