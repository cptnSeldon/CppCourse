#include <iostream>

#include "product.h"
#include "liquor.h"

using namespace std;

int main()
{
    int elements = 10;
    Product * products[elements];

    string productNames[] =
    {
        "Pain",
        "Lait",
        "Chocolat",
        "Cafe",
        "Salade"
     };

    string liquorNames[]  =
    {
        "Vodka",
        "Cervoise",
        "Vin rouge",
        "Amaretto",
        "Cognac"
    };

    float liquorDegrees[5]=
    {
        40,
        2.5,
        12.5,
        20,
        44
    };

    for (int i = 0; i < elements; i+=2)
    {
        products[i]   = new Product(productNames[i/2]);
        products[i+1] = new Liquor(liquorNames[i/2], liquorDegrees[i/2]);
    }


    //
    for(int i = 0 ; i < elements; i++)
    {
        Liquor* liquors = dynamic_cast<Liquor*> (products[i]);

        if (liquors != nullptr)
        {
            cout << liquors->getName() << " (" <<  liquors->getDegree() << ")\n";
        }
        else
        {
            cout << products[i]->getName() << endl;
        }
    }

    for (int i = 0; i < elements; i++)
    {
        delete products[i];
    }

    cout << "\nPlease hit ENTER to continue... ";
    cin.get();

    return 0;
}