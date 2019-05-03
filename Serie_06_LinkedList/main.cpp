#include <iostream>
#include <iomanip>

#include "linkedlist.h"

using namespace std;

int main()
{
    //TEST 1 : constructor by default
    LinkedList list;

    //TEST 2 : add start
    list.addStart(22);      //22
    list.addStart(26);      //26 22

    //TEST 3 : add end
    list.addEnd(52);        //26 22 52
    list.addEnd(100);       //26 22 52 100

    //TEST 4 : constructor by copy
    LinkedList list2(list); //26 22 52 100

    //TEST 5 : remove first
    list2.removeFirst();    //22 52 100

    //TEST 6 : remove last
    list.removeLast();      //26 22 52

    //TEST 7 : print
    list.print();
    list2.print();

    //TEST 8 : remove all
    list.removeAll();
    list.addEnd(0);

    list.print();

    //TEST 9 : remove last => size = 1
    list.removeLast();

    list.print();

    //TEST 10 : remove methods => size = 0
    list.removeLast();
    list.removeFirst();
    list.removeAll();

    list.addStart(32);

    list.print();

    //TEST 10 : remove first => size = 1
    list.removeFirst();

    list.print();
}