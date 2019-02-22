#include "bank3.h"

BankAccount3::BankAccount3()
{
    init();
};

void BankAccount3::init()
{
    amount = 0;
}

void BankAccount3::withdraw(float amountToWithdraw)
{
    if(amountToWithdraw < amount && amountToWithdraw > 0)
    {
        amount -= amountToWithdraw;
    }
}

void BankAccount3::deposit(float amountToDeposit)
{
    if(amountToDeposit > 0)
    {
        amount += amountToDeposit;
    }
}

void BankAccount3::show()
{
    cout << "The amount on your bak account is : "
            << amount <<endl;
}