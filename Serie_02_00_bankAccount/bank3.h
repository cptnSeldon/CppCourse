#include <iostream>

using namespace std;

#ifndef BANK3_H
#define BANK3_H

class BankAccount3
{
    private:
        //attribute
        float amount;

    public:
        //constructor : default
        BankAccount3(void);

        /** Functions */
        void init(void);

        void withdraw(float);

        void deposit(float);

        void show(void);
};

#endif BANK3_H