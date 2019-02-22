#include <iostream>
#include <iomanip>

using namespace std;

void printExercise01()
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
            << setw(10) << left << dec
            << 128
            << endl;

    cout << setfill('.')
            << setw(25) << left << boolalpha
            << true
            << setw(10) << left
            << false
            << endl;
}