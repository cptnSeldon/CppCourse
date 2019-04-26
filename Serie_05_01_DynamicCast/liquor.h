#ifndef LIQUOR_H
#define LIQUOR_H

#include <string>

#include "product.h"

using namespace std;

class Liquor : public Product
{
    public:
        Liquor(const string _name, float _degree) : Product(_name), degree(_degree) {}
        float getDegree() const { return degree; }

    protected:
        string name;
        float degree;
};

#endif //LIQUOR_H