#include <iostream>

using namespace std;

int Minimum(int a, int b)
{
    return a < b ? a : b;
}

double Minimum(double a, double b)
{
    return a < b ? a : b;
}

void printExercise04()
{
    cout << "Minimum(5, 6) : " << Minimum(5, 6)
         << "\nMinimum(2.1, 3.2) : " << Minimum(2.1, 3.2) << endl;

    //To call Minimum(7.0, 3) : delete int Minimum(int a, int b).
}