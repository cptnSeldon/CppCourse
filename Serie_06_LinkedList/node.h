#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    ///Linked List is allowed to use this class
    //friend class LinkedList;

    public:
        //DESTRUCTOR
        ~Node()
        {
            delete nextNode;
            nbNodes--;
        }

        //ATTRIBUTES
        ///prevents memory leaks
        static int nbNodes;

    private:
        //CONSTRUCTOR
        Node(int data)
        {
            this->data = data;
            nextNode = nullptr;
            nbNodes++;
        }
        Node(int data, Node * nextNode)
        {
            this->data = data;
            this->nextNode = nextNode;
            nbNodes++;
        }

        //ATTRIBUTES
        int data;
        Node * nextNode;
};

int Node::nbNodes = 0;

#endif //NODE_H