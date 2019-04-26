#include <iostream>

#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
    this-> size = 3;

    init();
}

Matrix::Matrix(int size)
{
    this->size = size;
}

Matrix::Matrix(const Matrix & m)
{
    //if both matrices don't have the same size, clear current matrix arrays to have the right size
    if(this->size != m.size)
    {
        deleteMatrix();
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    deleteMatrix();
}

void Matrix::init()
{
    //
    this->matrix = new int * [this->size];

    for (int i = 0; i < size; i++)
    {
        this->matrix[i] = new int[size];
    }

    //
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)
            {
                this->matrix[i][j] = 1;
            }
            else
            {
                this->matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::show() const
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << this->matrix[i][j];
        }
        cout << endl;
    }
}

Matrix Matrix::add(const Matrix & m)
{
    Matrix resultingMatrix;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            resultingMatrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
        }
    }

    return resultingMatrix;
}

void Matrix::deleteMatrix()
{
    for(int i = 0; i < size; i++)
    {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;
}