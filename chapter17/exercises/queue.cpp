/**
 * @file queue.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;
public:
    LinkedList() : head(NULL)
    {
    }

    void insertAtHead(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    T deleteAtHead()
    {
        if (isEmpty())
            throw std::out_of_range("List is empty");

        T data = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return data;
    }

    void print()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

template <class T>
class Queue : public LinkedList<T>
{
public:
    Queue() : LinkedList<T>()
    {
    }
    T isEmpty()
    {
        return this->isEmpty();
    }
    Queue isFull()
    {
        return false;
    }
    Queue peek()
    {
        return this->head->data;
    }
    void enqueue(T data)
    {
        this->insertAtHead(data);
    }
    T remove(T data)
    {
        return this->deleteAtHead();
    }
    T dequeue()
    {
        if (this->isEmpty())
            throw std::out_of_range("Queue is empty");

        Node<T> *temp = this->head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        T data = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        return data;
    }
    ~Queue()
    {
        Node<T> *temp = this->head;
        while (temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.print();
    cout << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << endl;
    queue.~Queue();
    return 0;
}
