/**
 * @file PFArray.cpp
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

class PFArray
{
private:
    int *a;
    int capacity;
    int used;
public:
    PFArray();
    PFArray(int capacityValue);
    PFArray(const PFArray& pfaObject);
    void addElement(int element);
    bool full() const;
    int getCapacity() const;
    int getNumberUsed() const;
    void emptyArray();
    int& operator[](int index);
    PFArray& operator =(const PFArray& rightSide);
    PFArray& PFArrayCopy(const PFArray& pdfaObject);
    ~PFArray();
};
void testPFArray(void);

PFArray::PFArray()
{
    capacity = 50;
    used = 0;
    a = new int[capacity];
}

PFArray::PFArray(int capacityValue)
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

PFArray::PFArray(const PFArray& pfaObject)
{
    capacity = pfaObject.capacity;
    used = pfaObject.used;
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
        cout << "Attempt to exceed capacity in PFArray." << endl;
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
        cout << "Illegal index in PFArray." << endl;
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

PFArray& PFArray::PFArrayCopy(const PFArray& pdfaObject)
{
    capacity = pdfaObject.capacity;
    used = pdfaObject.used;
    a = new int[capacity];
    for (int i = 0; i < used; i++)
    {
        a[i] = pdfaObject.a[i];
    }
}

PFArray::~PFArray()
{
    delete [] a;
}

void testPDFArray(void)
{
    PFArray pfa1(10);
    cout << "Capacity of pfa1 is " << pfa1.getCapacity() << endl;
    cout << "Number of elements in pfa1 is " << pfa1.getNumberUsed() << endl;
    pfa1.addElement(1);
    pfa1.addElement(2);
    pfa1.addElement(3);
    pfa1.addElement(4);
    pfa1.addElement(5);
    pfa1.addElement(6);
    pfa1.addElement(7);
    pfa1.addElement(8);
    pfa1.addElement(9);
    pfa1.addElement(10);
    pfa1.addElement(11);
    cout << "Capacity of pfa1 is " << pfa1.getCapacity() << endl;
    cout << "Number of elements in pfa1 is " << pfa1.getNumberUsed() << endl;
    cout << "Element 0 of pfa1 is " << pfa1[0] << endl;
    cout << "Element 1 of pfa1 is " << pfa1[1] << endl;
    cout << "Element 2 of pfa1 is " << pfa1[2] << endl;
    cout << "Element 3 of pfa1 is " << pfa1[3] << endl;
    cout << "Element 4 of pfa1 is " << pfa1[4] << endl;
    cout << "Element 5 of pfa1 is " << pfa1[5] << endl;
    cout << "Element 6 of pfa1 is " << pfa1[6] << endl;
    cout << "Element 7 of pfa1 is " << pfa1[7] << endl;
    cout << "Element 8 of pfa1 is " << pfa1[8] << endl;
    cout << "Element 9 of pfa1 is " << pfa1[9] << endl;
    cout << "Element 10 of pfa1 is " << pfa1[10] << endl;
    cout << "Element 11 of pfa1 is " << pfa1[11] << endl;
    pfa1.emptyArray();
    cout << "Capacity of pfa1 is " << pfa1.getCapacity() << endl;
    cout << "Number of elements in pfa1 is " << pfa1.getNumberUsed() << endl;
    PFArray pfa2;
    cout << "Capacity of pfa2 is " << pfa2.getCapacity() << endl;
    cout << "Number of elements in pfa2 is " << pfa2.getNumberUsed() << endl;
    pfa2.addElement(1);
    pfa2.addElement(2);
    pfa2.addElement(3);
    pfa2.addElement(4);
    //copy to pfa1
    pfa1 = pfa2;
    cout << "Capacity of pfa1 is " << pfa1.getCapacity() << endl;
    //use copy method
    pfa1.PFArrayCopy(pfa2);
    cout << "Capacity of pfa1 is " << pfa1.getCapacity() << endl;
}

int main(int argc, char **argv)
{
    testPDFArray();
    return 0;
}
/**
 * A destructor is a member function that is called automatically when an object is destroyed.
 * A destructor is called when an object is destroyed, either by the end of its lifetime or by a delete expression.
 * A destructor does not take any arguments and does not return a value.
 * A destructor should delete the object from memory.
 *  No overloaded assignment operator is provided for the PFArray class. This is because the default assignment operator is sufficient for this class.
 * The default assignment operator is sufficient for this class because the PFArray class does not have any dynamically allocated memory.
 * The overload is not needed for the destructor either because, as mentioned above, the default destructor is sufficient for this class.
*/
