#include <iostream>

using namespace std;

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

        //constructor : parameterized
        /*BankAccount(float amount_ = 0)
        {
            amount = amount_;
        }*/

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