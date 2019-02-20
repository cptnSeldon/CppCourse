#pragma region Slides
    #pragma region In Out
/*
        -----------------------------------------------------------
        cin >>              : extract stream                    p16
        cout <<             : insert  stream
        endl;               : end of line
        -----------------------------------------------------------
        << dec <<           : base change                       p18
        << oct <<           : base change
        << hex <<           : base change
        << [no]uppercase << : upper/lower case
        << [no]showpos <<   : show +
        << boolalpha <<     : show boolean

        example : cout << hex << showpos << n << endl;
        -----------------------------------------------------------
        setprecision(int)   : set decimal precision             p19
        setw(int)           : set character number
        setfill(char)       : set filler (character)
        -----------------------------------------------------------
        >>                  : setting + test                    p20

        example : if ((cin >> n) == 0) cout << "fail" << endl;
        -----------------------------------------------------------
        istream& ignore (streamsize n = 1, int delim = EOF);    p21
            : reset in- buffer -> #include <limits>
        -----------------------------------------------------------
        cin.fail()          : in stream fail                    p22
        cin.clear()         : reset control bit - OK
        cin.eof()           : end in stream
        example :
            while ( !(cin >> n) || n < 1 || n > 6)
            {
                if (cin.fail())
                {
                    cout << "Incorrect input" << endl;
                    cin.clear;
                    cin.ignore(256, '\n');
                }
                else
                {
                    cout << "Invalid number" << endl;
                }
            }
*/
#pragma endregion In Out
    #pragma region Parameters
    /*
        -----------------------------------------------------------
            VALUE                                               p26
                void function(int n) {..}
                function(n);
            POINTER - ADDRESS
                void function(int * n) {..}
                function(&n);
            REFERENCE - ADDRESS -> managed by compiler
                void function(int & n) {..}
                function(n)
            REFERENCE ON A CONST
                void function(const int & n) {..}
                function(n);
        -----------------------------------------------------------
        example :
            void swap(int & a, int & b)
            {
                int t;
                t = a; a = b; b = t;
            }
        -----------------------------------------------------------
        example :
            int x;
            int & function() { return x; }
            int main()
            {
                x = 100;
                /// 100
                function() = 200
                /// 200
            }
    */
    #pragma endregion Parameters
    #pragma region Override
    /*
        -----------------------------------------------------------
        int function(int a, int b);
        int function(int a, int b, int c);
        -----------------------------------------------------------
    */
    #pragma endregion Override
    #pragma region Dynamic Allocation
    /*
        -----------------------------------------------------------
        new type    =>      malloc(sizeof(type))

        double * ptr;
        ptr = new double;
        delete ptr;
        -----------------------------------------------------------
        int * tab = nullptr;
        tab = new int[10];
        delete []tab;
    */
    #pragma endregion Dynamic Allocation
    #pragma region String
    /*
        -----------------------------------------------------------
        - safer than char *
        - auto/dynamic management of array size
        - = + += << >> [] operators
        - management and manipulation by using :
            size(), capacity(), find(), erase(), insert()
        - #include <string>
    */
    #pragma endregion String
    #pragma region Misc
    /*
        -----------------------------------------------------------
        C++11
            auto

            alignas - alignof
            char16_t - char32_t
            constexpr
            decltype -> iterators + templates
            noexcept
            nullptr
            static_assert
            thread_local
        -----------------------------------------------------------
    */
    #pragma endregion Misc
#pragma endregion Slides

//https://gist.github.com/BaReinhard/c8dc7feb8b0882d13a0cac9ab0319547

#include "00.h"

int main()
{
    //Ex 1
    Format();

    cout << endl;

    //Ex 2
    int dividend = 37;
    int divisor = 2;
    int remainderA;
    int remainderB;

    int qA = Divide(dividend, divisor, remainderA);
    int qB = Divide(dividend, divisor, remainderB);
    array<int, 2> tab = Divide(dividend, divisor);

    cout << dividend << " / " << divisor
         << " = " << qA << ", remains : " << remainderA << endl;

    cout << dividend << " / " << divisor
         << " = " << qB << ", remains : " << remainderB << endl;

    cout << dividend << " / " << divisor
         << " = " << tab[0] << ", remains : " << tab[1] << endl;
    cout << endl;

    //Ex 3
    Polynomial(1, 2, -3.5, 4, 5);
    Polynomial(1, 2, 3);

    cout << endl;

    //Ex 4
    cout << "Minimum(5, 6) : " << Minimum(5, 6)
         << "\nMinimum(2.1, 3.2) : " << Minimum(2.1, 3.2) << endl;

    cout << endl << endl;

    //Ex 5
    RoomManager();

    //Ex 6
    int a = 3;
    cout << a << endl;

    int &r = a;
    r++;
    cout << a << endl << endl;

    //Ex 7
    int primeNumbers[] = { 1, 2, 3, 5, 7, 11, 13 };
    int copied[7] = { 0, 0, 0, 0, 0, 0, 0 };
    int arraySize = sizeof(primeNumbers) / sizeof(int);

    //range based
    cout << "Range-based for : " << endl;
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

    cout << "Copy : " << endl;
    for(int& elem : copied)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Press on any key to quit the program." << endl;

    cin.clear();
    cin.get();
    return 0;
}