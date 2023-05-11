/**
 * @file set.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class Set
{
private:
    T *arr;
    int size;
    int capacity;
public:
    Set(int capacity = 10);
    ~Set();
    void add(T x);
    void remove(T x);
    void print();
    bool is_member(T x);
    bool is_subset(Set<T> &s);
    Set<T> set_union(Set<T> &s);
    Set<T> set_intersection(Set<T> &s);
    Set<T> set_difference(Set<T> &s);
    Set<T> operator+(Set<T> &s);
    Set<T> operator*(Set<T> &s);
    Set<T> operator-(Set<T> &s);
};

template <class T>
Set<T>::Set(int capacity)
{
    this->capacity = capacity;
    arr = new T[capacity];
    size = 0;
}

template <class T>
Set<T>::~Set()
{
    delete[] arr;
}

template <class T>
void Set<T>::add(T x)
{
    if (size == capacity)
    {
        cout << "Set is full" << endl;
        return;
    }
    if (is_member(x))
    {
        cout << x << " is already a member of the set" << endl;
        return;
    }
    arr[size] = x;
    size++;
}

template <class T>
void Set<T>::remove(T x)
{
    if (!is_member(x))
    {
        cout << x << " is not a member of the set" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            return;
        }
    }
}

template <class T>
void Set<T>::print()
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

template <class T>
bool Set<T>::is_member(T x)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool Set<T>::is_subset(Set<T> &s)
{
    for (int i = 0; i < s.size; i++)
    {
        if (!is_member(s.arr[i]))
        {
            return false;
        }
    }
    return true;
}

template <class T>
Set<T> Set<T>::set_union(Set<T> &s)
{
    Set<T> temp(capacity + s.capacity);
    for (int i = 0; i < size; i++)
    {
        temp.add(arr[i]);
    }
    for (int i = 0; i < s.size; i++)
    {
        temp.add(s.arr[i]);
    }
    return temp;
}

template <class T>
Set<T> Set<T>::set_intersection(Set<T> &s)
{
    Set<T> temp(capacity + s.capacity);
    for (int i = 0; i < size; i++)
    {
        if (s.is_member(arr[i]))
        {
            temp.add(arr[i]);
        }
    }
    return temp;
}

template <class T>
Set<T> Set<T>::set_difference(Set<T> &s)
{
    Set<T> temp(capacity + s.capacity);
    for (int i = 0; i < size; i++)
    {
        if (!s.is_member(arr[i]))
        {
            temp.add(arr[i]);
        }
    }
    return temp;
}

template <class T>
Set<T> Set<T>::operator+(Set<T> &s)
{
    return set_union(s);
}

template <class T>
Set<T> Set<T>::operator*(Set<T> &s)
{
    return set_intersection(s);
}

template <class T>
Set<T> Set<T>::operator-(Set<T> &s)
{
    return set_difference(s);
}

int main()
{
    Set<int> s1(5);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(4);
    s1.add(5);
    s1.print();
    s1.remove(3);
    s1.print();
    cout << s1.is_member(3) << endl;
    cout << s1.is_member(4) << endl;
    Set<int> s2(5);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s2.add(6);
    s2.add(7);
    s2.print();
    cout << s1.is_subset(s2) << endl;
    cout << s2.is_subset(s1) << endl;
    Set<int> s3 = s1 + s2;
    s3.print();
    Set<int> s4 = s1 * s2;
    s4.print();
    Set<int> s5 = s1 - s2;
    s5.print();
    return 0;
}
