#include <iostream>
#include "node.h"

using namespace std;

int main()
{
    Node nodeA(1);
    Node nodeB(1, &nodeA);

    cout << nodeA.data << endl;
    cout << nodeA.nbNodes << endl;
    cout << nodeA.nextNode << endl;
    //cout << nodeA.nextNode->data << endl;

    cout << nodeB.data << endl;
    cout << nodeB.nbNodes << endl;
    cout << nodeB.nextNode << endl;
    cout << nodeB.nextNode->data << endl;
}