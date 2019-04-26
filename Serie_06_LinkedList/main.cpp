#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    //TEST 1 : constructor by default
    LinkedList list;

    cout << list.size << endl;
    cout << list.head << endl;
    cout << list.current << endl;
    cout << list.queue << endl;
}