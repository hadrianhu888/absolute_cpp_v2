/**
 * @file DoublyLinkedList.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace DoublyLinkedList
{
    class IntNode
    {
        public:
            IntNode(){} // Default constructor
            IntNode(IntNode * next, IntNode * previous) { this->next = next; this->previous = previous;}
            IntNode(int data = 0, IntNode *next = NULL, IntNode *previous = NULL) : data(data), next(next), previous(previous)
            {
                this->data = data;
                this->next = next;
                this->previous = previous;
            }
            int getData() const { return data; }
            IntNode *getNext() const { return next; }
            IntNode *getPrevious() const { return previous; }
            void setData(int data) { this->data = data; }
            void setNext(IntNode *next) { this->next = next; }
            void setPrevious(IntNode *previous) { this->previous = previous; }
        private:
            int data;
            IntNode *next;
            IntNode *previous;
    };
}

using namespace DoublyLinkedList;

int main(int argc, char const *argv[]);

IntNode *head = NULL;

IntNode* sort(IntNode *head)
{
    IntNode *temp = head;
    IntNode *temp2 = head;
    while (temp != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp->getData() > temp2->getData())
            {
                int tempData = temp->getData();
                temp->setData(temp2->getData());
                temp2->setData(tempData);
            }
            temp2 = temp2->getNext();
        }
        temp = temp->getNext();
    }
    return head;
}

void printList(IntNode *head)
{
    IntNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

void printListReverse(IntNode *head)
{
    IntNode *temp = head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getPrevious();
    }
    cout << endl;
}

void insertNode(IntNode *&head, int data)
{
    IntNode *newNode = new IntNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        IntNode *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setPrevious(temp);
    }
}

void deleteNode(IntNode *&head, int data)
{
    IntNode *temp = head;
    IntNode *temp2 = head;
    while (temp != NULL)
    {
        if (temp->getData() == data)
        {
            if (temp == head)
            {
                head = head->getNext();
                head->setPrevious(NULL);
                delete temp;
                break;
            }
            else
            {
                temp2->setNext(temp->getNext());
                temp->getNext()->setPrevious(temp2);
                delete temp;
                break;
            }
        }
        temp2 = temp;
        temp = temp->getNext();
    }
}

int main(int argc, char const *argv[])
{
    //test all functions and methods
    insertNode(head, 5);
    insertNode(head, 3);
    insertNode(head, 7);
    insertNode(head, 1);
    insertNode(head, 9);
    insertNode(head, 2);
    for (int i = 0; i < 10; i++)
    {
        insertNode(head, rand() % 10);
    }
    printList(head);
    printListReverse(head);
    deleteNode(head, 5);
    printList(head);
    printListReverse(head);
    deleteNode(head, 2);
    printList(head);
    printListReverse(head);
    deleteNode(head, 9);
    printList(head);
    printListReverse(head);
    //sort
    sort(head);
    return 0;
}

// advantages of doubly linked list
// 1. can be traversed in both directions
// 2. can be accessed in both directions
// 3. can be inserted and deleted in both directions
// 4. can be sorted in both directions
// 5. can be reversed in both directions
// 6. can be used to implement stacks and queues
// 7. can be used to implement circular lists
// 8. can be used to implement doubly linked lists
// 9. can be used to implement binary trees
// 10. can be used to implement hash tables
// 11. can be used to implement skip lists
// 12. can be used to implement adjacency lists
// 13. can be used to implement graphs

// disadvantages of doubly linked list
// 1. requires more memory than singly linked list
// 2. requires more time to insert and delete nodes than singly linked list
// 3. requires more time to traverse than singly linked list
// 4. requires more time to sort than singly linked list
// 5. requires more time to reverse than singly linked list
// 6. requires more time to access nodes than singly linked list
// 7. requires more time to implement stacks and queues than singly linked list
// 8. requires more time to implement circular lists than singly linked list
// 9. requires more time to implement doubly linked lists than singly linked list
// 10. requires more time to implement binary trees than singly linked list
// 11. requires more time to implement hash tables than singly linked list
// 12. requires more time to implement skip lists than singly linked list
// 13. requires more time to implement adjacency lists than singly linked list
