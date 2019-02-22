#include <iostream>
#include <iomanip>

using namespace std;

void printExercise07()
{
    int primeNumbers[] = { 1, 2, 3, 5, 7, 11, 13 };
    int copied[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int arraySize = sizeof(primeNumbers) / sizeof(int);

    //normal for loop
    cout << "Normal for loop : " << endl;
    for (int i=0; i < arraySize ; i++)
    {
        cout << primeNumbers[i] << " ";
    }
    cout << endl;

    //range based   -> use at least C++11
    cout << "Range-based for loop : " << endl;

    for(int& elem : primeNumbers)
    {
        cout << elem << " ";
    }
    cout << endl;

    //copy array 1 in array 2
    int i=0 ;

    for(int& elem : primeNumbers)
    {
        copied[i++] = elem;
    }

    cout << "Copied array : " << endl;

    for(int& elem : copied)
    {
        cout << elem << " ";
    }
    cout << endl;
}