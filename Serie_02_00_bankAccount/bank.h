#include <iostream>

using namespace std;

#ifndef BANK1_H
#define BANK1_H

class BankAccount
{
    private:
        //attribute
        float amount;

    public:
        //constructor : default
        BankAccount()
        {
            init();
        }

        /** Functions */
        void init()
        {
            amount = 0;
        }

        void withdraw(float amountToWithdraw)
        {
            if(amountToWithdraw < amount && amountToWithdraw > 0)
            {
                amount -= amountToWithdraw;
            }
        }

        void deposit(float amountToDeposit)
        {
            if(amountToDeposit > 0)
            {
                amount += amountToDeposit;
            }
        }

        void show()
        {
            cout << "The amount on your bak account is : "
                 << amount <<endl;
        }
};

#endif BANK1_H