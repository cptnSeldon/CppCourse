#include "bank.h"
#include "bank2.h"
#include "bank3.h"

int main()
{
    //bank.h
    cout << "BANK.h : " << endl;
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

    //bank2.h
    cout << "BANK2.h : " << endl;
    BankAccount2 myBankAccount2;

    myBankAccount2.init();
    myBankAccount2.show();

    myBankAccount2.withdraw(100);
    myBankAccount2.show();

    myBankAccount2.deposit(100);
    myBankAccount2.show();

    myBankAccount2.withdraw(200);
    myBankAccount2.show();

    myBankAccount2.withdraw(20);
    myBankAccount2.show();

    //bank2.h
    cout << "BANK3.h : " << endl;
    BankAccount3 BankAccount3;

    BankAccount3.init();
    BankAccount3.show();

    BankAccount3.withdraw(100);
    BankAccount3.show();

    BankAccount3.deposit(100);
    BankAccount3.show();

    BankAccount3.withdraw(200);
    BankAccount3.show();

    BankAccount3.withdraw(20);
    BankAccount3.show();

    cout << "Press on any key to quit the program." << endl;

    cin.clear();
    cin.get();

    return 0;
}