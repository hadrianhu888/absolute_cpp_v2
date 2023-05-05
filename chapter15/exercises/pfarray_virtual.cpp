/**
 * @file pfarray_virtual.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

int main(int argc, char **argv);

class PFArray
{
    protected:
        double *a;
        int capacity;
        int used;
    public:
        PFArray();
        PFArray(int capacityValue);
        PFArray(const PFArray& pfaObject);
        void addElement(double element);
        bool full() const { return (capacity == used); }
        int getCapacity() const { return capacity; }
        int getNumberUsed() const { return used; }
        void emptyArray() { used = 0; }
        double& operator[](int index);
        PFArray& operator =(const PFArray& rightSide);
        virtual ~PFArray();
};

class PFArrayDBak: public PFArray
{
    private:
        double *b;
    public:
        PFArrayDBak();
        PFArrayDBak(int capacityValue);
        PFArrayDBak(const PFArrayDBak& pfaObject);
        void backup();
        void restore();
        PFArrayDBak& operator =(const PFArrayDBak& rightSide);
        virtual ~PFArrayDBak();
};

PFArray::PFArray(): capacity(50), used(0)
{
    a = new double[capacity];
}

PFArray::PFArray(int capacityValue): capacity(capacityValue), used(0)
{
    a = new double[capacity];
}

PFArray::PFArray(const PFArray& pfaObject): capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new double[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}

void PFArray::addElement(double element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArray.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

double& PFArray::operator[](int index)
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
        a = new double[rightSide.capacity];
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

PFArrayDBak::PFArrayDBak(): PFArray(), b(NULL)
{
}

PFArrayDBak::PFArrayDBak(int capacityValue): PFArray(capacityValue)
{
    b = new double[capacity];
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak& pfaObject): PFArray(pfaObject.getCapacity())
{
    b = new double[capacity];
    for (int i = 0; i < used; i++)
    {
        b[i] = pfaObject.b[i];
    }
}

void PFArrayDBak::backup()
{
    for (int i = 0; i < used; i++)
    {
        b[i] = a[i];
    }
}

void PFArrayDBak::restore()
{
    for (int i = 0; i < used; i++)
    {
        a[i] = b[i];
    }
}

PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak& rightSide)
{
    PFArray::operator =(rightSide);
    if (capacity != rightSide.capacity)
    {
        delete [] b;
        b = new double[rightSide.capacity];
    }
    for (int i = 0; i < used; i++)
    {
        b[i] = rightSide.b[i];
    }
    return *this;
}

PFArrayDBak::~PFArrayDBak()
{
    delete [] b;
}

int main(int argc, char **argv)
{
    PFArrayDBak a(10);
    for (int i = 0; i < 10; i++)
    {
        a.addElement(i);
    }
    a.backup();
    a.emptyArray();
    for (int i = 0; i < 10; i++)
    {
        a.addElement(i + 10);
    }
    a.restore();
    for (int i = 0; i < a.getNumberUsed(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

/**
 * @brief One cannot statically cast a PFArrayDBak object to a PFArray object
 * because PFArrayDBak is not a PFArray. PFArrayDBak is a PFArrayDBak.
 *
 */
