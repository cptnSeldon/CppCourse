#include <iostream>
#include <iomanip>

using namespace std;

void printExercise07()
{
    int primeNumbers[] = { 1, 2, 3, 5, 7, 11, 13 };
    int copied[] = { 0, 0, 0, 0, 0, 0, 0 };
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

    for(int& element : primeNumbers)
    {
        cout << element << " ";
    }
    cout << endl;

    //copy array 1 in array 2
    int i=0 ;

    for(int& element : primeNumbers)
    {
        copied[i++] = element;
    }

    cout << "Copied array : " << endl;

    for(int& element : copied)
    {
        cout << element << " ";
    }
    cout << endl;
}