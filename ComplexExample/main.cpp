#include "complex.h"

using namespace std;

int main()
{
    Complex c1(1, 2);   //utilisation du constructeur paramétrique
    Complex c2(2, 3);
    Complex c3;         //utilisation du constructeur par défaut
    Complex c4 = 5;     //utilisation du constructeur de conversion
    Complex c5 = c4;    //utilisation du constructeur par recopie

    c1.show();          //utilisation de la méthode de classe
    c2.show();
    c3.show();
    cout << c4;         //utilisation de la surcharge de <<

    c3 = c1.add(c2);    //utilisation de la méthode de classe
    cout << c3;

    c3 = c1 + c2;       //utilisation de la surcharge de +
    cout << c3;

    c3 = c1 - c2;       //utilisation de la surcharge de -
    cout << c3;

    c3 = c2;            //utilisation de la surcharge de =
    cout << c3;

    return 0;
}