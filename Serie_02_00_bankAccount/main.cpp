#include "bank.h"

int main()
{
    BankAccount myBankAccount;

    myBankAccount.init();
    myBankAccount.show();

    myBankAccount.withdraw(100);
    myBankAccount.show();

    myBankAccount.deposit(100);
    myBankAccount.show();

    myBankAccount.withdraw(200);
    myBankAccount.show();

    myBankAccount.withdraw(20);
    myBankAccount.show();

    cout << "Press on any key to quit the program." << endl;

    cin.clear();
    cin.get();

    return 0;
}