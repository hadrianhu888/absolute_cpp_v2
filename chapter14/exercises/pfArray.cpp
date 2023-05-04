/**
 * @file pfArray.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "pfArray.h"

using namespace std;
using namespace pfarray;
using namespace pfarray_derived;

PFArray::PFArray() : capacity(50), used(0)
{
    a = new int[capacity];
}

PFArray::PFArray(int capacityValue) : capacity(capacityValue), used(0)
{
    a = new int[capacity];
}

PFArray::PFArray(const PFArray &pfaObject) : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new int[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

void PFArray::addElement(int element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArray.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

bool PFArray::full() const
{
    return (capacity == used);
}

int PFArray::getCapacity() const
{
    return capacity;
}

int PFArray::getNumberUsed() const
{
    return used;
}

void PFArray::emptyArray()
{
    used = 0;
}

int& PFArray::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArray.\n";
        exit(0);
    }
    return a[index];
}

PFArray& PFArray::operator =(const PFArray& rightSide)
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

PFArray::~PFArray()
{
    delete [] a;
}

PFArrayD::PFArrayD() : PFArray()
{
    capacity = 50;
}

PFArrayD::PFArrayD(int capacityValue) : PFArray(capacityValue)
{
    capacity = capacityValue;
}

PFArrayD::PFArrayD(const PFArrayD &pfaObject) : PFArray(pfaObject)
{
    capacity = pfaObject.getCapacity();
}

void PFArrayD::addElement(int element)
{
    if (getNumberUsed() == getCapacity())
    {
        int *temp = new int[getCapacity() * 2];
        for (int i = 0; i < getCapacity(); i++)
        {
            temp[i] = a[i];
        }
        delete [] a;
        a = temp;
        capacity *= 2;
    }
    PFArray::addElement(element);
}

int PFArrayD::getCapacity() const
{
    return capacity;
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
    PFArray::operator =(rightSide);
    capacity = rightSide.capacity;
    return *this;
}

PFArrayD::~PFArrayD()
{
    delete [] a;
}
