#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <new>  //so we can use nothrow

#include "node.h"

/*
    [node]
    *pointer*
     ☇      points to
     ∅      null

*/

class LinkedList
{
    public:
        //CONSTRUCTOR
        LinkedList()
        {
            /*
            => is empty by default

                list = {}

            => as the list is empty, they point nowhere

                *head*  *current*  *queue*
                   ☇        ☇         ☇
                    ∅        ∅         ∅
            */

            //initialize the attributes to default values
            size = 0;
            head = current = queue = nullptr;
        }

        LinkedList(const LinkedList & source)
        {
            //initialize the attributes to default values
            size = 0;
            head = current = queue = nullptr;

            //create a temporary pointer who will point on the list head
            Node * tempPointer = source.head;

            //fill current liked list with source linked list
            while(tempPointer != nullptr)
            {
                addEnd(tempPointer->data);
                tempPointer = tempPointer->nextNode;
            }
        }
        //DESTRUCTOR
        //~LinkedList();

        //ADD
        bool addStart(int data)
        {
            /*
                *current*
                    ☇
                [new node]
                     ☇ *next*
                         ☇
                          ∅
            */
            //create a new node -> false if it fails
            current = new (nothrow) Node(data);

            /*
            => node creation failed

                *current*
                   ☇
                    ∅
            */
            //if current points nowhere
            if(current == nullptr) return false;

            /*
                 *current*
                    ☇
                [new node]
                    ☇ *next*
                         ☇
                       *head*
                          ☇ ...



                *head*  *current*
                   ☇       ☇
                  [new node]
                        ☇ *next*
                            ☇ ...
            */
            //current node is the new head node
            current->nextNode = head;
            head = current;

            /*
                list = {}
            =>
                list { node0 }

                *queue*  *head*  *current*
                   ☇       ☇        ☇
                        [new node]
                             ☇ *next*
                                  ☇ ...
            */
            //size = the new node will be alone in the list
            if(size == 0) queue = current;

            //increase size
            ++size;

            return true;
        }

        //bool addPosition(int position, int data);
        bool addEnd(int data)
        {
            /*
                 *current*
                    ☇
                [new node]
                     ☇ *next*
                         ☇
                          ∅
            */
            //create a new node -> false if it fails
            current = new (nothrow) Node(data);

            /*
            => node creation failed

                *current*
                   ☇
                    ∅
            */
            //if current points nowhere
            if(current == nullptr) return false;

            /*
                list = {}
            =>
                list { node0 }

                *queue*  *current*
                    ☇       ☇
                    [new node]
                        ☇ *next*
                            ☇
                             ∅
            */
            //current node is the queue node
            if(queue == nullptr)    //when the list is empty
            {
                queue = current;
            }
            /*
                list = {}
            =>
                list { node0 }

                 *current*
                    ☇
                [new node]
                     ☇ *next*
                         ☇
                          ∅



                *queue*
                    ☇
                 [last node]
                      ☇ *next*
                         ☇
                      *current*
                         ☇
                     [new node]
                          ☇ *next
                              ☇
                                ∅


                *queue*  *current*
                    ☇       ☇
                    [new node]
                        ☇ *next*
                            ☇
                             ∅
            */
            else                    //when list is not empty
            {
                queue->nextNode = current;
                queue = current;
            }

            /*

            *queue*  *head*  *current*
                   ☇       ☇        ☇
                        [new node]
                             ☇ *next*
                                  ☇ ...

            */
            //when the list is empty
            if(size == 0) head = current;

            ++size;

            return true;
        }

        //PEEK
        ///& data : used to return value if exists
        ///bool   : used to know if node exists
        bool peekFirst(int & data)
        {
            if(size != 0 && head != nullptr)
            {
                data = head->data;
                return true;
            }
            return false;
        }

        bool peekPosition(int position, int & value) const
        {
            if(position < 0 || position >= size) return false;

            Node * pointerOnCurrent = head;

            for(int i = 0; i < position; i++)
            {
                pointerOnCurrent = pointerOnCurrent->nextNode;
            }

            value = pointerOnCurrent->data;

            return true;
        }

        bool peekLast(int & data)
        {
            if(size != 0 && queue != nullptr)
            {
                data = queue->data;
                return true;
            }
            return false;
        }

        //REMOVE : something is wrong, to check
        void removeFirst()
        {
            if(size == 0)
            {
                if(queue != nullptr)
                {
                    queue = nullptr;
                }

                cout << "already empty list (remove last)" << endl;
                return;
            }

            if(size > 0)
            {
            /*
                *temp*
                    ☇
                  *head*
                    ☇
                [1st node]
                     ☇ *next*
                         ☇
                          [2nd node]
                              ☇
                               ...
            */
                Node * temp = head;
            /*
                *temp*
                    ☇
                [1st node]
                     ☇ *next*   *head*
                         ☇        ☇
                          [2nd node]
                              ☇
                               ...
            */
                head = head->nextNode;
            /*
                *temp*
                    ☇
                [1st node]
                     ☇ *next*
                        ☇
                         ∅


                        *head*
                         ☇
                          [2nd node]
                              ☇
                               ...
            */
                temp->nextNode = nullptr;
            /*
                *head*
                  ☇
                [2nd node]
                    ☇
                    ...
            */
                delete temp;

                --size;
            }
        }

        //void removeAt(int position);
        void removeLast()
        {
            if(size == 0)
            {
                cout << "already empty list (remove last)" << endl;
                return;
            }

            if(size > 0)
            {
                if(size == 1)
                {
                    delete head;
                    queue = head = nullptr;
                }
                else
                {
                    /*
                        *head* *temp*
                            ☇    ☇
                        [1st node]
                            ☇ *next*
                                ☇
                                ...
                    */
                    Node * temp = head;

                    /*
                    => until :

                        *temp*
                            ☇
                        [n-1 node]
                            ☇ *next*  *queue*
                                ☇       ☇
                                 [n node]
                    */
                    for(int i = 0; i < size-1; i++)
                    {
                        temp = temp->nextNode;
                    }

                    /*
                        *temp* *queue*
                            ☇   ☇
                        [n-1 node]
                            ☇ *next*
                                ☇
                                 [n node]
                    */

                    queue = temp;

                   /*
                        *queue*
                           ☇
                        [n-1 node]
                            ☇ *next*  *temp*
                                ☇       ☇
                                 [n node]
                    */
                    temp = queue->nextNode;

                    /*
                        *queue*
                           ☇
                        [n-1 node]
                            ☇ *next*
                                ☇
                                 ∅


                                *temp*
                                ☇
                                 [n node]
                    */
                    queue->nextNode = nullptr;

                    /*
                        *queue*
                           ☇
                        [n-1 node]
                            ☇ *next*
                                ☇
                                 ∅
                    */
                    delete temp;
                }
                --size;
            }
        }
        void removeAll()
        {
            if(size == 0)
            {
                cout << "already empty list (remove all)" << endl;
                return;
            }
            while(size > 0)
            {
                removeFirst();
            }
        }

        //
        int getSize() { return size; }

        void print()
        {

            if(size == 0)
            {
                cout << "empty list (print)" << endl;
                return;
            }

            int value;
            bool test = false;

            for(int i = 0; i < size-1; i++)
            {
                test = peekPosition(i, value);
                if(test == true)
                {
                    cout << "[" << i << ": " << value << "], ";
                }
            }

            test = peekPosition(size-1, value);
            if(test == true)
            {
                cout << "[" << size-1 << ": " << value << "]" << endl;
            }
        }

        //OPERATOR OVERLOAD : =

    //private:
        int size;
        Node * head;
        Node * queue;
        Node * current;
};

#endif //LINKED_LIST_H