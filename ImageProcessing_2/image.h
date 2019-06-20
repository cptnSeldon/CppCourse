#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "bitmap.h"

using namespace std;

template <class IMAGE_TYPE>

class Image
{
    private:
        //ATTRIBUTES
        string code;
        unsigned int columns, rows;
        int maxWhite;
        IMAGE_TYPE **matrix;

        ///INITIALIZE
        void InitializeMatrix()
        {
            cout << "Matrix initialized" << endl;

            matrix = new IMAGE_TYPE *[columns];

            for(int i = 0; i < columns; i ++)
            {
                matrix[i] = new IMAGE_TYPE [rows];

                for(int j = 0; j < rows; j++)
                {
                    matrix[i][j] = (IMAGE_TYPE) (i+j);
                }
            }
        }

        ///CLEAR
        void Clear()
        {
            cout << "Matrix cleared" << endl;

            //DELETE MATRIX
            for(int i = 0; i < columns; i++)
            {
                delete matrix[i];
                matrix[i] = NULL;
            }
            delete matrix;
            matrix = NULL;

            //INITIALIZE ATTRIBUTES
            code = "";
            columns = rows = 0;
            maxWhite = -1;
        }

    public:
        //METHODS
        ///CONSTRUCTOR
        Image(string _code, int _columns, int _rows, int _maxWhite) : code(_code), columns(_columns), rows(_rows), maxWhite(_maxWhite)
        {
            cout << "Image created" << endl;
            InitializeMatrix();
        }

        ///DESTRUCTOR
        ~Image()
        {
            cout << "Image destroyed" << endl;
            Clear();
        }


        //IO
        ///PRINT
        void PrintInConsole()
        {
            cout << code << endl
                 << columns << "x" << rows
                 << endl;

            if(maxWhite != -1)
                cout << maxWhite << endl;

            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    //print input
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        //LOAD IMAGE
        void LoadImage(string filename)
        {
            fstream input;

            input.open(filename.c_str(), fstream::in);

            input >> code;
            input >> columns >> rows;

            //black and white
            if(!(code == "P1" ||code == "P2")) input >> maxWhite;

            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    getline(input, s);

                    cout << s << endl;
                }
            }
        }

        //WRITE IMAGE
        void WriteImage(string filename) { }

};

#endif //IMAGE_H