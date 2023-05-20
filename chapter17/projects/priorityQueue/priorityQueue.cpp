/**
 * @file priorityQueue.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template<class T>
class PriorityQueue
{
private:
    typedef struct Node
    {
        T _data;
        Node *_next;

        Node(const T &data, Node *next = NULL) : _data(data), _next(next) {}
    } Node;

    Node *_front;
    Node *_rear;
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue &rhs);
    ~PriorityQueue();
    const PriorityQueue &operator=(const PriorityQueue &rhs);
    void copy(const PriorityQueue &rhs);
    void makeEmpty();
    void enqueue(const T &data);
    void dequeue();
    bool isEmpty() const;
    void print() const;
};

template<class T>
PriorityQueue<T>::PriorityQueue() : _front(NULL), _rear(NULL) {}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &rhs) : _front(NULL), _rear(NULL)
{
    copy(rhs);
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
    makeEmpty();
}

template<class T>
const PriorityQueue<T> &PriorityQueue<T>::operator=(const PriorityQueue &rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        copy(rhs);
    }
    return *this;
}

template<class T>
void PriorityQueue<T>::copy(const PriorityQueue &rhs)
{
    Node *p = rhs._front;
    while (p != NULL)
    {
        enqueue(p->_data);
        p = p->_next;
    }
}

template<class T>
void PriorityQueue<T>::makeEmpty()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

template<class T>
void PriorityQueue<T>::enqueue(const T &data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        _front = newNode;
        _rear = newNode;
    }
    else
    {
        Node *p = _front;
        Node *q = NULL;
        while (p != NULL && p->_data < data)
        {
            q = p;
            p = p->_next;
        }
        if (p == NULL)
        {
            _rear->_next = newNode;
            _rear = newNode;
        }
        else if (p == _front)
        {
            newNode->_next = _front;
            _front = newNode;
        }
        else
        {
            newNode->_next = p;
            q->_next = newNode;
        }
    }
}

template<class T>
void PriorityQueue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        Node *p = _front;
        _front = _front->_next;
        delete p;
        if (_front == NULL)
        {
            _rear = NULL;
        }
    }
}

template<class T>
bool PriorityQueue<T>::isEmpty() const
{
    return _front == NULL;
}

template<class T>
void PriorityQueue<T>::print() const
{
    Node *p = _front;
    while (p != NULL)
    {
        cout << p->_data << " ";
        p = p->_next;
    }
    cout << endl;
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    PriorityQueue<int> pq;
    pq.enqueue(3);
    pq.enqueue(1);
    pq.enqueue(2);
    pq.enqueue(5);
    pq.enqueue(4);
    pq.print();
    pq.dequeue();
    pq.print();
    pq.dequeue();
    pq.print();
    pq.dequeue();
    pq.print();
    pq.dequeue();
    pq.print();
    pq.dequeue();
    pq.print();
    pq.dequeue();
    pq.print();
    pq.~PriorityQueue();
    return 0;
}
