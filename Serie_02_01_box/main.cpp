#include "box.h"

int main()
{
    Box box;
    box.setPosition(7, 3);
    box.setSize(4, 3);
    box.setSymbol('A');
    box.showBox();

    box.translate(10, 5);
    box.showBox();

    cout << "Press on any key to quit the program." << endl;

    cin.clear();
    cin.get();
    return 0;
}