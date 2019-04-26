#include "chain.h"

#include <iomanip>

int main()
{
    Chain c1;
    Chain c2("Hello");
    Chain c3 = "World";

    c1 = c2 + " " + c3;

    cout << c2 << " : " << c2.getLength() <<endl;
    cout << c3 << " : " << c3.getLength() <<endl;
    cout << c1 << " : " << c1.getLength() <<endl;

    cout << c1[2] << endl;

    bool test = c2 == c3;

    cout << boolalpha << (c2 == c3) << endl;

    cout << (c1 + c2);

    return 0;
}

/*
    REFERENCES
    - http://www.cplusplus.com/reference/cstring/strlen/
    - http://www.cplusplus.com/reference/cstring/strcpy/
*/