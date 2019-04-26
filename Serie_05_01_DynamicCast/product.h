#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    public:
        Product(const string _name) : name(_name) { }
        virtual~Product() {}
        string getName() { return name; }

    protected:
        string name;
};

#endif //PRODUCT_H