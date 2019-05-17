#include <iostream>

using namespace std;

template <typename T>

T sum(T array[], int size)
{
    if(size < 0)
    {
        cout << "can't be negative" << endl;
    }

    if(size == 1)
    {
        return array[0];
    }

    T sum = array[0];

    for(int i = 1; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int ti[] = {3, 5, 2, 1} ;
    float tf [] = {2.5, 3.2, 1.8} ;
    char tc[] = { 'a', 'e', 'i', 'o', 'u' } ;

    cout << sum (ti, 4) << "\n"  ;          // int
    cout << sum (tf, 3) << "\n"  ;          // float
    cout << sum (tc, 5) << "\n"  ;          // char

	return 0;
}