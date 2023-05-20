/**
 * @file Stacks_exceptions.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);

template <class T>
class Stack
{
    private:
        T *_Stack;
        int _top;
        int _size;
    public:
        Stack(int size = 10);
        ~Stack();
        void push(const T &data);
        T pop();
        bool empty() const;
        bool full() const;
        void clear();
        void print() const;
};

template <class T>
Stack<T>::Stack(int size)
{
    _size = size;
    _Stack = new T[_size];
    _top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] _Stack;
}

template <class T>
void Stack<T>::push(const T &data)
{
    try
    {
        if (full())
        {
            throw _top;
        }
    }
    catch (int e)
    {
        cout << "Stack is full: " << e << endl;
    }
    _Stack[++_top] = data;
}

template <class T>
T Stack<T>::pop()
{
    try
    {
        if (empty())
        {
            throw _top;
        }
    }
    catch (int e)
    {
        cout << "Stack is empty: " << e << endl;
    }
    return _Stack[_top--];
}

template <class T>
bool Stack<T>::empty() const
{
    return (_top == -1);
}

template <class T>
bool Stack<T>::full() const
{
    return (_top == _size - 1);
}

template <class T>
void Stack<T>::clear()
{
    _top = -1;
}

template <class T>
void Stack<T>::print() const
{
    for (int i = 0; i <= _top; i++)
    {
        cout << _Stack[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    return 0;
}
