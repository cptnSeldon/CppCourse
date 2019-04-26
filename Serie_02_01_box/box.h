#include <iostream>
#include <iomanip>

using namespace std;

class Box
{
    private:
        //attributes
        int positionX;
        int positionY;
        int width;
        int height;
        char symbol;

    public:
        //constructor
        Box(void);

        //methods
        void setPosition(int, int);
        void setSize(int, int);
        void setSymbol(char);
        void translate(int, int);
        void showBox(void);
};
