#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <cstring>

using namespace std;

class Chain
{
    public:
        //CONSTRUCTORS
        ///default
        Chain();
        ///parameterized
        Chain(char * text);
        ///copy
        Chain(const Chain & other);

        //DESTRUCTOR
        ~Chain();

        //INSIDE METHODS
        int getLength() { return this->length; }

        //OPERATOR OVERLOAD
        /// =
        Chain & operator=(const Chain & other);
        /// ==
        bool operator==(Chain & other) const;
        /// []
        char & operator[](int index) const;
        //FRIEND FUNCTIONS
        /// +
        friend Chain operator+(const Chain & a, const Chain & b);
        /// <<
        friend ostream & operator<<(ostream & stream, const Chain & text);

    private:
        char * text;
        int length;
};

#endif //CHAIN_H