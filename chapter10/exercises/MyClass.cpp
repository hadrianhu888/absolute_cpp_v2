/**
 * @file MyClass.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

class MyClass
{
private:
    int *a;
    int capacity;
    int used;
public:
    MyClass();
    MyClass(int capacityValue);
    MyClass(const MyClass& pfaObject);
    void addElement(int element);
    bool full() const;
    int getCapacity() const;
    int getNumberUsed() const;
    void emptyArray();
    int& operator[](int index);
    MyClass& operator =(const MyClass& rightSide);
    ~MyClass();
};

void testMyClass(void);

MyClass::MyClass()
{
    capacity = 50;
    used = 0;
    a = new int[capacity];
}

MyClass::MyClass(int capacityValue)
{
    if (capacityValue < 1)
    {
        cout << "Capacity of the array must be positive. Creating an array of size 50." << endl;
        capacity = 50;
    }
    else
    {
        capacity = capacityValue;
    }
    used = 0;
    a = new int[capacity];
}

MyClass::MyClass(const MyClass& pfaObject)
{
    capacity = pfaObject.capacity;
    used = pfaObject.used;
    a = new int[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

void MyClass::addElement(int element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArray." << endl;
        exit(0);
    }
    a[used] = element;
    used++;
}

bool MyClass::full() const
{
    return (capacity == used);
}

int MyClass::getCapacity() const
{
    return capacity;
}

int MyClass::getNumberUsed() const
{
    return used;
}

void MyClass::emptyArray()
{
    used = 0;
}

int& MyClass::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArray." << endl;
        exit(0);
    }
    return a[index];
}

MyClass& MyClass::operator =(const MyClass& rightSide)
{
    if (capacity != rightSide.capacity)
    {
        delete [] a;
        a = new int[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
    {
        a[i] = rightSide.a[i];
    }
    return *this;
}

MyClass::~MyClass()
{
    cout << "Destructor called.\n\n";
    delete[] a;
}

void testMyClass(void)
{
    MyClass a(25);
    int i;
    for (i = 0; i < 10; i++)
    {
        a.addElement(i);
    }
    MyClass b(a);
    for (i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    MyClass c;
    c = a;
    for (i = 0; i < 10; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main()
{
    testMyClass();
    return 0;
}
