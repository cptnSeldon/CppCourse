#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
    private:
        int size;
        int ** matrix;

        //initialization method
        /*
            1 0 0
            0 1 0
            0 0 1
        */
        void init();

    public:
        //constructors
        Matrix();
        Matrix(int size);
        Matrix(const Matrix & m);

        //destructor
        ~Matrix();

        //print method
        void show() const;
        //addition method
        Matrix add(const Matrix & m);
        ///delete matrix : used several times
        void deleteMatrix();

};
#endif MATRIX_H