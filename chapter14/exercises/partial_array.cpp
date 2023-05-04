/**
 * @file partial_array.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace array_base
{
    class ArrayBase
    {
        private:
            int size;
            int capacity;
        public:
            ArrayBase();
            int setSize(int size);
            void getSize(int size);
            void getCapacity(int capacity);
            int setCapacity(int capacity);
            ~ArrayBase();
    };
}

namespace derived
{
    class PartialArray:public array_base::ArrayBase
    {
        private:
            int *array;
        public:
            int capacity;
            PartialArray();
            int setArray(int *array);
            int getArray(int *array);
            ~PartialArray();
    };
} // namespace derived

namespace partial_derived
{
    class PartialArrayBackup:public derived::PartialArray
    {
        private:
            int *array_backup;
        public:
            PartialArrayBackup();
            int setArrayBackup(int *array_backup);
            int getArrayBackup(int *array_backup);
            ~PartialArrayBackup();
    };
}

array_base::ArrayBase::ArrayBase()
{
    size = 0;
    capacity = 0;
}

int array_base::ArrayBase::setSize(int size)
{
    this->size = size;
    return size;
}

void array_base::ArrayBase::getSize(int size)
{
    cout << "Size: " << size << endl;
}

void array_base::ArrayBase::getCapacity(int capacity)
{
    cout << "Capacity: " << capacity << endl;
}

int array_base::ArrayBase::setCapacity(int capacity)
{
    this->capacity = capacity;
    return capacity;
}

array_base::ArrayBase::~ArrayBase()
{
    cout << "ArrayBase destructor called" << endl;
}

derived::PartialArray::PartialArray()
{
    array = new int[capacity];
}

int derived::PartialArray::setArray(int *array)
{
    this->array = array;
    return *array;
}

int derived::PartialArray::getArray(int *array)
{
    return *array;
}

derived::PartialArray::~PartialArray()
{
    cout << "PartialArray destructor called" << endl;
}

partial_derived::PartialArrayBackup::PartialArrayBackup()
{
    array_backup = new int[capacity];
}

int partial_derived::PartialArrayBackup::setArrayBackup(int *array_backup)
{
    this->array_backup = array_backup;
    return *array_backup;
}

int partial_derived::PartialArrayBackup::getArrayBackup(int *array_backup)
{
    return *array_backup;
}

partial_derived::PartialArrayBackup::~PartialArrayBackup()
{
    cout << "PartialArrayBackup destructor called" << endl;
}

int main(int argc, char **argv)
{
    derived::PartialArray partialArray;
    partialArray.setCapacity(10);
    partialArray.setSize(5);
    partialArray.getCapacity(10);
    partialArray.getSize(5);
    partialArray.setArray(new int[partialArray.capacity]);
    partialArray.getArray(new int[partialArray.capacity]);
    partialArray.~PartialArray();
    partial_derived::PartialArrayBackup partialArrayBackup;
    partialArrayBackup.setCapacity(10);
    partialArrayBackup.setSize(5);
    partialArrayBackup.getCapacity(10);
    partialArrayBackup.getSize(5);
    partialArrayBackup.setArray(new int[partialArrayBackup.capacity]);
    partialArrayBackup.getArray(new int[partialArrayBackup.capacity]);
    partialArrayBackup.setArrayBackup(new int[partialArrayBackup.capacity]);
    partialArrayBackup.getArrayBackup(new int[partialArrayBackup.capacity]);
    partialArrayBackup.~PartialArrayBackup();
    return 0;
}
