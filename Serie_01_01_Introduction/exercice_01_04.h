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
    cout << "Minimum(7, 3) : " << Minimum(7, 3)
         //<< "\nMinimum(7.0, 3) : " << Minimum(7.0, 3)
         //<< "\nMinimum(7, 3.0) : " << Minimum(7, 3.0)
         << "\nMinimum(7.0, 3.0) : " << Minimum(7.0, 3.0)
         << endl;

    //To call Minimum(7.0, 3) : delete int Minimum(int a, int b) -> type conflict
}