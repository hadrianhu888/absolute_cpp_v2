/**
 * @file doubleNode.cpp
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

template <class T>
class DoubleNode
{
    public:
        DoubleNode(){} // Default constructor
        DoubleNode(T data = 0, DoubleNode *next = NULL, DoubleNode *previous = NULL) : data(data), next(next), previous(previous)
        {
            this->data = data;
            this->next = next;
            this->previous = previous;
        }
        T getData() const { return data; }
        DoubleNode *getNext() const { return next; }
        DoubleNode *getPrevious() const { return previous; }
        void setData(T data) { this->data = data; }
        void setNext(DoubleNode *next) { this->next = next; }
        void setPrevious(DoubleNode *previous) { this->previous = previous; }
    private:
        T data;
        DoubleNode *next;
        DoubleNode *previous;
};

template <class T>
DoubleNode<T> *head = NULL;

template <class T>
DoubleNode<T>* sort(DoubleNode<T> *head)
{
    DoubleNode<T> *temp = head;
    DoubleNode<T> *temp2 = head;
    while (temp != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp->getData() > temp2->getData())
            {
                T tempData = temp->getData();
                temp->setData(temp2->getData());
                temp2->setData(tempData);
            }
            temp2 = temp2->getNext();
        }
        temp = temp->getNext();
    }
    return head;
}

template <class T>
void printList(DoubleNode<T> *head)
{
    DoubleNode<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

template <class T>
void insertNode(DoubleNode<T> *head, T data)
{
    DoubleNode<T> *temp = head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    DoubleNode<T> *newNode = new DoubleNode<T>(data);
    temp->setNext(newNode);
    newNode->setPrevious(temp);
}

template <class T>
void deleteNode(DoubleNode<T> *head, T data)
{
    DoubleNode<T> *temp = head;
    while (temp->getNext() != NULL)
    {
        if (temp->getData() == data)
        {
            temp->getPrevious()->setNext(temp->getNext());
            temp->getNext()->setPrevious(temp->getPrevious());
            delete temp;
            break;
        }
        temp = temp->getNext();
    }
}

template <class T>
void deleteNodeAfter(DoubleNode<T> *head, T data)
{
    DoubleNode<T> *temp = head;
    while (temp->getNext() != NULL)
    {
        if (temp->getData() == data)
        {
            DoubleNode<T> *temp2 = temp->getNext();
            temp->setNext(temp2->getNext());
            temp2->getNext()->setPrevious(temp);
            delete temp2;
            break;
        }
        temp = temp->getNext();
    }
}

/* typedef struct DoublyLinkedIntNodePtr
{
    int data;
    DoublyLinkedIntNodePtr *next;
    DoublyLinkedIntNodePtr *back;
} DoublyLinkedIntNode; */

class DoublyLinkedIntNodePtr
{
public:
    explicit DoublyLinkedIntNodePtr(int data = 0,
                                    DoublyLinkedIntNodePtr *next = nullptr,
                                    DoublyLinkedIntNodePtr *back = nullptr)
        : data(data), next(next), back(back)
    {
    }
    int getData() const
    {
        return data;
    }
    DoublyLinkedIntNodePtr *getNext() const
    {
        return next;
    }
    DoublyLinkedIntNodePtr *getBack() const
    {
        return back;
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(DoublyLinkedIntNodePtr *next)
    {
        this->next = next;
    }
    void setBack(DoublyLinkedIntNodePtr *back)
    {
        this->back = back;
    }

private:
    int data;
    DoublyLinkedIntNodePtr *next;
    DoublyLinkedIntNodePtr *back;
};

void insert(DoublyLinkedIntNodePtr *afterMe, int theData)
{
    DoublyLinkedIntNodePtr *newNode = new DoublyLinkedIntNodePtr(theData);
    newNode->setNext(afterMe->getNext());
    newNode->setBack(afterMe);
    if (afterMe->getNext() != nullptr)
    {
        afterMe->getNext()->setBack(newNode);
    }
    afterMe->setNext(newNode);
}

void print(DoublyLinkedIntNodePtr *node)
{
    while (node != nullptr)
    {
        cout << node->getData() << " ";
        node = node->getNext();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    DoubleNode<int> *head = new DoubleNode<int>(1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    insertNode(head, 8);
    insertNode(head, 9);
    insertNode(head, 10);
    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 14);
    insertNode(head, 15);
    insertNode(head, 16);
    insertNode(head, 17);
    insertNode(head, 18);
    insertNode(head, 19);
    insertNode(head, 20);
    insertNode(head, 21);
    insertNode(head, 22);
    insertNode(head, 23);
    insertNode(head, 24);
    insertNode(head, 25);
    insertNode(head, 26);
    insertNode(head, 27);
    insertNode(head, 28);
    insertNode(head, 29);
    insertNode(head, 30);
    insertNode(head, 31);
    insertNode(head, 32);
    insertNode(head, 33);
    insertNode(head, 34);
    insertNode(head, 35);
    insertNode(head, 36);
    insertNode(head, 37);
    insertNode(head, 38);
    insertNode(head, 39);
    insertNode(head, 40);
    insertNode(head, 41);
    insertNode(head, 42);
    insertNode(head, 43);
    insertNode(head, 44);
    insertNode(head, 45);
    insertNode(head, 46);
    insertNode(head, 47);
    insertNode(head, 48);
    insertNode(head, 49);
    insertNode(head, 50);
    insertNode(head, 51);
    insertNode(head, 52);
    insertNode(head, 53);
    insertNode(head, 54);
    insertNode(head, 55);
    insertNode(head, 56);
    insertNode(head, 57);
    insertNode(head, 58);
    insertNode(head, 59);
    insertNode(head, 60);
    for(int i = 0; i < 60; i++)
    {
        cout << head->getData() << " ";
        head = head->getNext();
    }
    cout << endl;
    head = sort(head);
    for(int i = 0; i < 60; i++)
    {
        cout << head->getData() << " ";
        head = head->getNext();
    }
    cout << endl;
    deleteNodeAfter(head, 1);
    deleteNodeAfter(head, 2);
    deleteNodeAfter(head, 3);
    cout << endl;
    for (int i = 0; i < 57; i++)
    {
        cout << head->getData() << " ";
        head = head->getNext();
    }
    cout << endl;
    printList(head);
    DoublyLinkedIntNodePtr node;
    node.setData(1);
    insert(&node, 2);
    insert(&node, 3);
    insert(&node, 4);
    insert(&node, 5);
    insert(&node, 6);
    insert(&node, 7);
    insert(&node, 8);
    print(&node);
    return 0;
}

/**
 * @brief For a large array and a large list holding the same types of objects,
 * inserting a new object at a known location into the middle of a linked list
 * comapred to insertion into an array is much faster. This is because the array
 * insertion algorithm must shift all of the elements after the insertion point.
 * The linked list insertion algorithm only needs to change the pointers of the
 * nodes before and after the insertion point.
 */

/**
 * @brief A doubly linked list allows us to implement
 * a deleteNodeBefore function. This function would be
 * similar to the deleteNodeAfter function, but it would
 * delete the node before the node passed in as a parameter.
 *
 */

/**
 * @brief A singly linked list does not allow us to implement
 * a deleteNodeBefore function. This is because we cannot
 * access the node before the node passed in as a parameter.
 * We can only access the node after the node passed in as
 * a parameter.
 *
 */
