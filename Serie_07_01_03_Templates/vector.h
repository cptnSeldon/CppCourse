#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>

class Vector
{
    public:
        //CONSTRUCTOR
        Vector<T>(int size)
        {
            if(size == 0)
            {
                array = nullptr;
            }
            if(size > 0)
            {
                for(int i = 0; i < size; i++)
                {
                    T value;
                    array[i] = value;
                }
            }

            this->size = size;
        }

        void print()
        {
            for(int i = 0; i < size-1; i++)
            {
                cout << array[i] << ", ";
            }
            cout << array[size-1] << endl;
        }

    private:
        T * array;
        int size;
};

#endif //VECTOR_H