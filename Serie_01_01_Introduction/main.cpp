//https://gist.github.com/BaReinhard/c8dc7feb8b0882d13a0cac9ab0319547

#include "exercice_01_01.h"
#include "exercice_01_02.h"
#include "exercice_01_03.h"
#include "exercice_01_04.h"
#include "exercice_01_05.h"
#include "exercice_01_07.h"

int main()
{
    //Ex 1
    cout << "Exercise 1 : format streams" << endl;
    cout << "---------------------------" << endl;
    printExercise01();

    cout << endl;

    //Ex 2
    cout << "Exercise 2 : division - parameter (use reference, pointer, array)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    printExercise02();

    cout << endl;

    //Ex 3
    cout << "Exercise 3 : polynomial" << endl;
    cout << "-----------------------" << endl;
    printExercise03();

    cout << endl;

    //Ex 4
    cout << "Exercise 4 : calculate minimum" << endl;
    cout << "------------------------------" << endl;
    printExercise04();

    cout << endl;

    //Ex 5
    cout << "Exercise 5 : struct example" << endl;
    cout << "---------------------------" << endl;
    printExercise05();

    cout << endl;

    //Ex 7
    cout << "Exercise 7 : range-based for loop" << endl;
    cout << "---------------------------------" << endl;
    printExercise07();

    cout << endl;

    /*
    cout << "Press on any key to quit the program." << endl;
    cin.clear();
    cin.get();
    */
    return 0;
}