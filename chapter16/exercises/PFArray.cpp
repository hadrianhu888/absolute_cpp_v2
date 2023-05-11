/**
 * @file PFArray.cpp
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
class PFArray
{
public:
    PFArray();
    PFArray(int capacityValue);
    PFArray(const PFArray<T> &pfaObject);
    void addElement(T element);
    bool full() const;
    int getCapacity() const;
    int getNumberUsed() const;
    void emptyArray();
    T& operator[](int index);
    PFArray<T>& operator=(const PFArray<T> &rightSide);
    void sort();
    void search(T element);
    ~PFArray();
private:
    T *a;
    int capacity;
    int used;
};

template <class T>
PFArray<T>::PFArray() : capacity(50), used(0)
{
    a = new T[capacity];
}

template <class T>
PFArray<T>::PFArray(int capacityValue) : capacity(capacityValue), used(0)
{
    a = new T[capacity];
}

template <class T>
PFArray<T>::PFArray(const PFArray<T> &pfaObject) : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new T[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

template <class T>
void PFArray<T>::addElement(T element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArray.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

template <class T>
bool PFArray<T>::full() const
{
    return (capacity == used);
}

template <class T>
int PFArray<T>::getCapacity() const
{
    return capacity;
}

template <class T>
int PFArray<T>::getNumberUsed() const
{
    return used;
}

template <class T>
void PFArray<T>::emptyArray()
{
    used = 0;
}

template <class T>
T& PFArray<T>::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArray.\n";
        exit(0);
    }
    return a[index];
}

template <class T>
PFArray<T>& PFArray<T>::operator=(const PFArray<T> &rightSide)
{
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
void PFArray<T>::sort()
{
    int startScan, minIndex;
    T minValue;

    for (startScan = 0; startScan < (used - 1); startScan++)
    {
        minIndex = startScan;
        minValue = a[startScan];
        for (int index = startScan + 1; index < used; index++)
        {
            if (a[index] < minValue)
            {
                minValue = a[index];
                minIndex = index;
            }
        }
        a[minIndex] = a[startScan];
        a[startScan] = minValue;
    }
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < used; i++)
    {
        cout << a[i] << " ";
    }
}

template <class T>
void PFArray<T>::search(T element)
{
    int first = 0;
    int last = used - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (a[middle] == element)
        {
            found = true;
            position = middle;
        }
        else if (a[middle] > element)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    if (position == -1)
    {
        cout << "The number " << element << " was not found in the array." << endl;
    }
    else
    {
        cout << "The number " << element << " was found in the array." << endl;
    }
}

template <class T>
PFArray<T>::~PFArray()
{
    delete [] a;
}

template <class T>
class PFArrayDBak : public PFArray<T>
{
public:
    PFArrayDBak();
    PFArrayDBak(int capacityValue);
    PFArrayDBak(const PFArrayDBak<T> &pfaObject);
    void backup();
    void restore();
    PFArrayDBak<T>& operator=(const PFArrayDBak<T> &rightSide);
    ~PFArrayDBak();
private:
    T *b;
    int usedB;
};

template <class T>
PFArrayDBak<T>::PFArrayDBak() : PFArray<T>(), usedB(0)
{
    b = new T[PFArray<T>::getCapacity()];
}

template <class T>
PFArrayDBak<T>::PFArrayDBak(int capacityValue) : PFArray<T>(capacityValue), usedB(0)
{
    b = new T[PFArray<T>::getCapacity()];
}

template <class T>
PFArrayDBak<T>::PFArrayDBak(const PFArrayDBak<T> &pfaObject) : PFArray<T>(pfaObject), usedB(pfaObject.usedB)
{
    b = new T[PFArray<T>::getCapacity()];
    for (int i = 0; i < usedB; i++)
    {
        b[i] = pfaObject.b[i];
    }
}

template <class T>
void PFArrayDBak<T>::backup()
{
    usedB = PFArray<T>::getNumberUsed();
    for (int i = 0; i < usedB; i++)
    {
        b[i] = PFArray<T>::operator[](i);
    }
}

template <class T>
void PFArrayDBak<T>::restore()
{
    PFArray<T>::emptyArray();
    for (int i = 0; i < usedB; i++)
    {
        PFArray<T>::addElement(b[i]);
    }
}

template <class T>
PFArrayDBak<T>& PFArrayDBak<T>::operator=(const PFArrayDBak<T> &rightSide)
{
    PFArray<T>::operator=(rightSide);
    if (usedB != rightSide.usedB)
    {
        delete [] b;
        b = new T[rightSide.usedB];
    }
    usedB = rightSide.usedB;
    for (int i = 0; i < usedB; i++)
    {
        b[i] = rightSide.b[i];
    }
    return *this;
}

template <class T>
PFArrayDBak<T>::~PFArrayDBak()
{
    delete [] b;
}



int main(int argc, char **argv)
{
    PFArray<int> a(10);
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    a.addElement(4);
    a.addElement(5);
    a.addElement(6);
    a.addElement(7);
    a.addElement(8);
    a.addElement(9);
    a.addElement(10);
    a.sort();
    a.search(5);
    a.search(11);
    PFArrayDBak<int> b(10);
    b.addElement(1);
    b.addElement(2);
    b.addElement(3);
    b.addElement(4);
    b.addElement(5);
    b.addElement(6);
    b.addElement(7);
    b.addElement(8);
    b.addElement(9);
    b.addElement(10);
    b.backup();
    b.addElement(11);
    b.addElement(12);
    b.addElement(13);
    b.addElement(14);
    b.addElement(15);
    b.sort();
    b.search(5);
    /**
     * @brief call destructor
     *
     */
    a.~PFArray();
    return 0;
}
