/**
 * @file stacks.cpp
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

    T peekHead()
    {
        if (isEmpty())
            throw std::out_of_range("List is empty");
        return head->data;
    }
};

template <class T>
class Stack : public LinkedList<T>
{
public:
    Stack() : LinkedList<T>()
    {
    }
    T copy()
    {
        return this->head->data;
    }
    void push(T data)
    {
        this->insertAtHead(data);
    }

    T pop()
    {
        return this->deleteAtHead();
    }

    T peek()
    {
        return this->peekHead();
    }
    T isEmpty()
    {
        return this->LinkedList<T>::isEmpty();
    }
    Stack(const Stack &stack)
    {
        this->head = stack.head;
    }
    ~Stack()
    {
        while (!this->isEmpty())
        {
            this->pop();
        }
        cout << "Stack destroyed" << endl;
    }
};

template <class T>
void deleteStackElement(T data)
{
    Stack<T> stack;
    while (!stack.isEmpty())
    {
        if (stack.peek() == data)
        {
            stack.pop();
        }
        else
        {
            stack.push(stack.pop());
        }
    }
    while (!stack.isEmpty())
    {
        stack.push(stack.pop());
    }
    cout << "Element deleted" << endl;
}

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl; // Outputs: 3
    cout << stack.pop() << endl; // Outputs: 2
    cout << stack.pop() << endl; // Outputs: 1
    deleteStackElement(1);
    stack.~Stack();
    Stack<int> stack2(stack);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    cout << stack2.pop() << endl; // Outputs: 3
    cout << stack2.pop() << endl; // Outputs: 2
    cout << stack2.pop() << endl; // Outputs: 1
    stack2.~Stack();
    return 0;
}
