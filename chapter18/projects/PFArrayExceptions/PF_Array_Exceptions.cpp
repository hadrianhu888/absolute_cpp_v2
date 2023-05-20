/**
 * @file PF_Array_Exceptions.cpp
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

template <class T>
class PFArray
{
    private:
        T *a;
        int capacity;
        int used;
    public:
        PFArray(int size = 50);
        PFArray(const PFArray<T> &pfa);
        PFArray &operator=(const PFArray<T> &rightSide);
        void addElement(const T &element);
        bool full() const { return (capacity == used); }
        int getCapacity() const { return capacity; }
        int getNumberUsed() const { return used; }
        void emptyArray() { used = 0; }
        T &operator[](int index);
        ~PFArray() { delete [] a; }
};

template <class T>
PFArray<T>::PFArray(int size) : capacity(size), used(0)
{
    try
    {
        if (size <= 0)
        {
            throw size;
        }
    }
    catch (int e)
    {
        cout << "Invalid size: " << e << endl;
    }
    a = new T[size];
}

template <class T>
PFArray<T>::PFArray(const PFArray<T> &pfa) : capacity(pfa.getCapacity()), used(pfa.getNumberUsed())
{
    try
    {
        if (capacity < used)
        {
            throw capacity;
        }
    }
    catch (int e)
    {
        cout << "Capacity is less than number used: " << e << endl;
    }
    a = new T[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfa.a[i];
    }
}

template <class T>
PFArray<T> &PFArray<T>::operator=(const PFArray<T> &rightSide)
{
    try
    {
        if (capacity < rightSide.used)
        {
            throw capacity;
        }
    }
    catch (int e)
    {
        cout << "Capacity is less than number used: " << e << endl;
    }
    if (capacity != rightSide.capacity)
    {
        delete [] a;
        a = new T[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
    {
        a[i] = rightSide.a[i];
    }
    return *this;
}

template <class T>
void PFArray<T>::addElement(const T &element)
{   try
    {
        if (used >= capacity)
        {
            throw capacity;
        }
        a[used] = element;
        used++;
    }
    catch (int e)
    {
        cout << "Attempt to exceed capacity in PFArray.\n";
        exit(0);
    }
}

template <class T>
T &PFArray<T>::operator[](int index)
{
    try
    {
        if (index >= used)
        {
            throw index;
        }
    }
    catch (int e)
    {
        cout << "Illegal index in PFArray.\n";
        exit(0);
    }
    return a[index];
}

int main(int argc, char const *argv[])
{
    PFArray<int> a(10);
    for (int i = 0; i < 10; i++)
    {
        a.addElement(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    PFArray<int> b = a;
    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    PFArray<int> c(20);
    c = a;
    for (int i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
