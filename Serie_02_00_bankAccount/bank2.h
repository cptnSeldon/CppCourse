#include <iostream>

using namespace std;

#ifndef BANK2_H
#define BANK2_H

class BankAccount2
{
    private:
        //attribute
        float amount;

    public:
        //constructor : default
        BankAccount2(void);

        /** Functions */
        void init(void);

        void withdraw(float);

        void deposit(float);

        void show(void);
};

BankAccount2::BankAccount2()
{
    BankAccount2::init();
}

void BankAccount2::init()
{
    amount = 0;
}

void BankAccount2::withdraw(float amountToWithdraw)
{
    if(amountToWithdraw < amount && amountToWithdraw > 0)
    {
        amount -= amountToWithdraw;
    }
}

void BankAccount2::deposit(float amountToDeposit)
{
    if(amountToDeposit > 0)
    {
        amount += amountToDeposit;
    }
}

void BankAccount2::show()
{
    cout << "The amount on your bak account is : "
            << amount <<endl;
}

#endif BANK2_H