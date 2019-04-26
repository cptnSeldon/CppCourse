#ifndef LINKED_LIST_H
//#define LINKED_LIST_H

#include "node.h"

class LinkedList
{
    public:
        //CONSTRUCTOR
        LinkedList();
        LinkedList(const LinkedList & other);
        //DESTRUCTOR
        ~LinkedList();

        //ADD
        bool addStart(int data);
        bool addPosition(int position, int data);
        bool addEnd(int data);

        //PEEK
        ///& data : used to return value if exists
        ///bool   : used to know if node exists
        bool peekFirst(int & data);
        bool peekPosition(int position, int & data);
        bool peakLast(int & data);

        //REMOVE
        void removeFirst();
        void removeAt(int position);
        void removeLast();
        void removeAll();

        //
        int getSize();

        //OPERATOR OVERLOAD : =

    private:
        int size;
        Node * head;
        Node * queue;
        Node * current;
};

#endif //LINKED_LIST_H