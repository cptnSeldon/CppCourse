#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

//TODO 1 : unsigned int ** array -> check memcopy
/////TODO 2 : rgb -> grayscale
/////TODO 3 : overload = if same code
//TODO 4 : convert to ASCII art
/////TODO 5 : histogram - create image - updated : values printed in a file

class Image
{
    private:
        //ATTRIBUTES
        string code;
        int columns, rows;
        int dataSize;
        int whiteMaxValue;
        unsigned int *** matrix;
        unsigned int * array;

        //METHODS
        ///clearance
        void Clear()
        {
            columns = 0;
            rows = 0;
            whiteMaxValue = -1;

            ClearMatrix();
            ClearArray();
        }

        void ClearMatrix()
        {
            /*if(matrix != NULL)
            {*/
                cout << "CLEAR IMAGE" << endl;
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        delete matrix[i][j];
                        matrix[i][j] = NULL;
                    }
                    delete matrix[i];
                    matrix[i] = NULL;
                }
                delete matrix;
                matrix = NULL;
            /*}
            else
            {
                cout << "Image matrix is empty" << endl;
            }*/
        }

        void ClearArray()
        {
            /*if(array != NULL)
            {*/
                delete array;
                array = NULL;
            /*}
            else
            {
                cout << "Image array is empty" << endl;
            }*/
        }

        ///initialization
        void InitializeMatrix()
        {
            cout << "INITIALIZE IMAGE MATRIX" << endl;

            matrix = new unsigned int **[columns];

            for(int i = 0; i < columns; i++)
            {
                matrix[i] = new unsigned int *[rows];

                for(int j = 0; j < rows; j++)
                {
                    matrix[i][j] = new unsigned int[dataSize];

                    for(int k = 0; k < dataSize; k++)
                    {
                        matrix[i][j][k] = 0;
                    }
                }
            }
        }

        void InitializeArray()
        {
            unsigned int size = columns * rows * dataSize;

            array = new unsigned int[size];

            for(int i = 0; i < size; i++)
            {
                array[i] = 0;
            }
        }

        //conversion
        void FromMatrixToArray()
        {
            cout << "FROM MATRIX TO ARRAY" << endl;

            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    for(int k = 0; k < dataSize; k++)
                    {
                        array[(i + rows * columns) + (j * dataSize + k)] = matrix[i][j][k];
                    }
                }
            }
        }

        void FromArrayToMatrix()
        {
            cout << "FROM MATRIX TO ARRAY" << endl;

            for(int i = 0; i < columns; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    for(int k = 0; k < dataSize; k++)
                    {
                        matrix[i][j][k] = array[(i + rows * columns) + (j * dataSize + k)] ;
                    }
                }
            }
        }

        ///input
        void LoadImageToMatrix(string & filename)
        {
            whiteMaxValue = -1;
            dataSize = 1;

            fstream inputfile;

            inputfile.open(filename.c_str(), fstream::in | fstream::binary);

            try
            {
                cout << "OPENING : "<< filename <<endl;

                inputfile >> code;
                inputfile >> columns >> rows;

                //black and white
                if(!(code == "P1" || code == "P4")) inputfile >> whiteMaxValue;
                //color : rgb
                if(code == "P3" ||code == "P6") dataSize = 3;

                InitializeMatrix();

                //Populate matrix
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        for(int k = 0; k < dataSize; k++)
                        {
                            unsigned int s;
                            inputfile >> s;
                            matrix[i][j][k] = s;
                        }
                    }
                }

                inputfile.close();
            }
            catch (std::ifstream::failure e)
            {
                std::cerr << "Exception opening/reading/closing file\n";
            }
        }

        void LoadImageToArray(string & filename)
        {
            whiteMaxValue = -1;
            dataSize = 1;

            fstream inputfile;

            inputfile.open(filename.c_str(), fstream::in | fstream::binary);

            try
            {
                cout << "OPENING : "<< filename <<endl;

                inputfile >> code;
                inputfile >> columns >> rows;

                //black and white
                if(!(code == "P1" || code == "P4")) inputfile >> whiteMaxValue;
                //color : rgb
                if(code == "P3" ||code == "P6") dataSize = 3;

                InitializeArray();

                //Populate array
                for(int i = 0; i < columns * rows * dataSize; i++)
                {
                    unsigned int s;
                    inputfile >> s;
                    array[i] = s;
                }

                inputfile.close();
            }
            catch (std::ifstream::failure e)
            {
                std::cerr << "Exception opening/reading/closing file\n";
            }
        }

    public:
        //CONSTRUCTORS
        ///parameterized : load image
        Image(string filename)
        {
            cout << "NEW IMAGE..." << endl;
            LoadImageToMatrix(filename);
            LoadImageToArray(filename);
        }
        //DESTRUCTOR
        ~Image()
        {
            cout << "DESTROY IMAGE..." << endl;
            Clear();
        }

        //METHODS
        ///output
        void WriteImageFromMatrix(string & filename)
        {
            cout << "WRITE IMAGE : " << filename << endl;

            fstream outputFile;

            try
            {
                //clear file
                outputFile.open(filename.c_str(), fstream::out | fstream::trunc);

                //header
                outputFile << code << "\n";
                outputFile << columns << " " << rows << "\n";
                if(!(code == "P1" || code == "P4")) outputFile << whiteMaxValue<< "\n";

                //matrix
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        for(int k = 0; k < dataSize; k++)
                        {
                            outputFile << matrix[i][j][k];
                            if(j < rows - 1 || k != dataSize -1) outputFile << " ";
                        }
                    }
                    outputFile << "\n";
                }

                outputFile.close();
            }
            catch (std::ifstream::failure e)
            {
                std::cerr << "Exception opening/reading/closing file\n";
            }
            catch(std::exception const& e)
            {
                cout << "There was an error: " << e.what() << endl;
            }
        }

        void WriteImageFromArray(string & filename)
        {
            cout << "WRITE IMAGE : " << filename << endl;

            fstream outputFile;

            try
            {
                //clear file
                outputFile.open(filename.c_str(), fstream::out | fstream::trunc);

                //header
                outputFile << code << "\n";
                outputFile << columns << " " << rows << "\n";
                if(!(code == "P1" || code == "P4")) outputFile << whiteMaxValue<< "\n";

                //matrix
                for(int i = 0; i < columns * rows * dataSize; i++)
                {
                    outputFile << array[i];
                    outputFile << " ";
                }

                outputFile.close();
            }
            catch (std::ifstream::failure e)
            {
                std::cerr << "Exception opening/reading/closing file\n";
            }
            catch(std::exception const& e)
            {
                cout << "There was an error: " << e.what() << endl;
            }
        }

        ///OPERATIONS
        //inversion
        void Inverse()
        {
            InverseFromArray();
            InverseFromMatrix();
        }
        void InverseFromMatrix()
        {
            cout << "INVERSE IMAGE..." << endl;

            if(matrix == NULL) cout << "INVERSE: matrix is null." << endl;
            else
            {
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        for(int k = 0; k < dataSize; k++)
                        {
                            if(code == "P1" || code == "P4") matrix[i][j][k] = (matrix[i][j][k] == 0) ? 1 : 0;
                            else matrix[i][j][k] = ~matrix[i][j][k]%256;
                        }
                    }
                }
            }
        }

        void InverseFromArray()
        {
            cout << "INVERSE IMAGE..." << endl;

            if(matrix == NULL) cout << "INVERSE: matrix is null." << endl;
            else
            {
                for(int i = 0; i < columns * rows * dataSize; i++)
                {
                    if(code == "P1" || code == "P4") array[i] = (array[i] == 0) ? 1 : 0;
                    else array[i] = ~array[i]%256;
                }
            }
        }

        void ColorToGrayscaleFromMatrix()
        {
            if(code == "P3" || code =="P6")
            {
                cout << "RGB TO GRAYSCALE..." << endl;

                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        unsigned int r = matrix[i][j][0];
                        unsigned int g = matrix[i][j][1];
                        unsigned int b = matrix[i][j][2];

                        unsigned int linearIntensity = (0.2126f * r + 0.7152f * g + 0.0722 * b);

                        matrix[i][j][0] = linearIntensity;
                        matrix[i][j][1] = linearIntensity;
                        matrix[i][j][2] = linearIntensity;
                    }
                }
            }
            else
            {
                cout << "Warning : this is not a ppm image (rgb)." << endl;
            }
        }

        ///max
        void SetMax(unsigned int max)
        {
            SetMaxFromArray(max);
            SetMaxFromMatrix(max);
        }

        void SetMaxFromMatrix(unsigned int max)
        {
            if(code == "P1" || code == "P4") cout << "SET MAX : black and white image.." << endl;
            else
            {
                if(matrix == NULL) cout << "SET MAX: matrix is null." << endl;
                else
                {
                    cout << "SET MAXIMUM SHADE TO : " << max << endl;

                    whiteMaxValue = max;

                    for(int i = 0; i < columns; i++)
                    {
                        for(int j = 0; j < rows; j++)
                        {
                            for(int k = 0; k < dataSize; k++)
                            {
                                matrix[i][j][k] = (matrix[i][j][k] > max) ? max : matrix[i][j][k];
                            }
                        }
                    }
                }
            }
        }

        void SetMaxFromArray(unsigned int max)
        {
            if(code == "P1" || code == "P4") cout << "SET MAX : black and white image.." << endl;
            else
            {
                if(matrix == NULL) cout << "SET MAX: matrix is null." << endl;
                else
                {
                    cout << "SET MAXIMUM SHADE TO : " << max << endl;

                    whiteMaxValue = max;

                    for(int i = 0; i < columns * rows * dataSize; i++)
                    {
                        array[i] = (array[i] > max) ? max : array[i];
                    }
                }
            }
        }

        //min
        void SetMin(unsigned int min)
        {
            SetMinFromArray(min);
            SetMinFromMatrix(min);
        }

        void SetMinFromMatrix(unsigned int min)
        {
            if(code == "P1" || code == "P4") cout << "SET MAX : black and white image.." << endl;
            else
            {
                if(matrix == NULL) cout << "SET MIN: matrix is null." << endl;
                else
                {
                    cout << "SET MINIMUM SHADE TO : " << min << endl;

                    for(int i = 0; i < columns; i++)
                    {
                        for(int j = 0; j < rows; j++)
                        {
                            for(int k = 0; k < dataSize; k++)
                            {
                                matrix[i][j][k] = (matrix[i][j][k] < min) ? min : matrix[i][j][k];
                            }
                        }
                    }
                }
            }
        }

        void SetMinFromArray(unsigned int min)
        {
            if(code == "P1" || code == "P4") cout << "SET MAX : black and white image.." << endl;
            else
            {
                if(matrix == NULL) cout << "SET MIN: matrix is null." << endl;
                else
                {
                    cout << "SET MINIMUM SHADE TO : " << min << endl;

                    for(int i = 0; i < columns * rows * dataSize; i++)
                    {
                        array[i] = (array[i] < min) ? min : array[i];
                    }
                }
            }
        }

        void Histogram(string & filename)
        {
            if(matrix == NULL) cout << "HISTOGRAM: matrix is null." << endl;
            else
            {
                cout << "WRITING HISTOGRAM..." << endl;

                unsigned int ** histogram;
                int shade;

                if(code == "P1" || code == "P4") shade = 2;
                else shade = 256;

                histogram = new unsigned int * [dataSize];

                for(int i = 0; i < dataSize; i++)
                {
                    histogram[i] = new unsigned int[shade];
                }

                //Initialize
                for(int i = 0; i < dataSize; i++)
                {
                    for(int j = 0; j < shade; j++)
                    {
                        histogram[i][j] = 0;
                    }
                }

                //put the values in the matrix
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        for(int k = 0; k < dataSize; k++)
                        {
                            histogram[k][matrix[i][j][k]]++;
                        }
                    }
                }

                fstream outputFile;
                try
                {
                    //clear file
                    outputFile.open(filename.c_str(), fstream::out | fstream::trunc);

                    //header
                    outputFile << "P1" << "\n";
                    outputFile << shade << " " << rows * columns << "\n";

                    //matrix
                    for(int i = 0; i < dataSize; i++)
                    {
                        if(i == 0 && dataSize > 1) outputFile << "RED" << "\n";
                        if(i == 2 && dataSize > 1) outputFile << "GREEN" << "\n";
                        if(i == 3 && dataSize > 1) outputFile << "BLUE" << "\n";

                        for(int j = 0; j < shade; j++)
                        {
                            if(histogram[i][j] != 0)
                            {
                                outputFile << j;
                                outputFile << " : ";
                                outputFile << histogram[i][j];
                                outputFile << "\n";
                            }
                        }
                    }

                    outputFile.close();
                }
                catch (std::ifstream::failure e)
                {
                    std::cerr << "Exception opening/reading/closing file\n";
                }
                catch(std::exception const& e)
                {
                    cout << "There was an error: " << e.what() << endl;
                }
            }
        }

        //OVERLOAD
        Image & operator=(const Image & other)
        {
            if(&other == this)
            {
                cout << "These images are the same !" << endl;
                return *this;
            }
            else if(code != other.code)
            {
                cout << "The images don't have the same format !" << endl;
            }
            else
            {
                cout << "Overload = !" << endl;

                Clear();

                columns = other.columns;
                rows = other.rows;
                whiteMaxValue = other.whiteMaxValue;

                InitializeMatrix();

                //copy to matrix
                for(int i = 0; i < columns; i++)
                {
                    for(int j = 0; j < rows; j++)
                    {
                        for(int k = 0; k < dataSize; k++)
                        {
                            matrix[i][j][k] = other.matrix[i][j][k];
                        }
                    }
                }

                //copy to array
                InitializeArray();

                for(int i = 0; i < columns * rows * dataSize; i++)
                {
                    array[i] = other.array[i];
                }
            }
        }
};