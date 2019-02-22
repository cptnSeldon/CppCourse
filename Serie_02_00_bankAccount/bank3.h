#include <iostream>

using namespace std;

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