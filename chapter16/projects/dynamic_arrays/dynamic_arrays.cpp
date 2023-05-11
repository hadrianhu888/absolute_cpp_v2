/**
 * @file dynamic_arrays.cpp
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

namespace DA
{
    template <class T>
    class DynamicArray
    {
    private:
        T *arr;
        int size;
        int capacity;
    public:
        DynamicArray(int capacity = 10);
        ~DynamicArray();
        void add(T x);
        void remove(T x);
        void print();
        bool is_member(T x);
        bool is_subset(DynamicArray<T> &s);
        DynamicArray<T> set_union(DynamicArray<T> &s);
        DynamicArray<T> set_intersection(DynamicArray<T> &s);
        DynamicArray<T> set_difference(DynamicArray<T> &s);
        DynamicArray<T> operator+(DynamicArray<T> &s);
        DynamicArray<T> operator*(DynamicArray<T> &s);
        DynamicArray<T> operator-(DynamicArray<T> &s);
    };
    template <class T>
    DynamicArray<T>::DynamicArray(int capacity)
    {
        this->capacity = capacity;
        arr = new T[capacity];
        size = 0;
    }
    template <class T>
    DynamicArray<T>::~DynamicArray()
    {
        delete[] arr;
    }
    template <class T>
    void DynamicArray<T>::add(T x)
    {
        if (size == capacity)
        {
            cout << "Set is full" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                cout << "Element already exists" << endl;
                return;
            }
        }
        arr[size] = x;
        size++;
    }
    template <class T>
    void DynamicArray<T>::remove(T x)
    {
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
        cout << "Element not found" << endl;
    }
    template <class T>
    void DynamicArray<T>::print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    template <class T>
    bool DynamicArray<T>::is_member(T x)
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
    bool DynamicArray<T>::is_subset(DynamicArray<T> &s)
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
    DynamicArray<T> DynamicArray<T>::set_union(DynamicArray<T> &s)
    {
        DynamicArray<T> temp(capacity + s.capacity);
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
    DynamicArray<T> DynamicArray<T>::set_intersection(DynamicArray<T> &s)
    {
        DynamicArray<T> temp(capacity + s.capacity);
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
    DynamicArray<T> DynamicArray<T>::set_difference(DynamicArray<T> &s)
    {
        DynamicArray<T> temp(capacity + s.capacity);
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
    DynamicArray<T> DynamicArray<T>::operator+(DynamicArray<T> &s)
    {
        return set_union(s);
    }
    template <class T>
    DynamicArray<T> DynamicArray<T>::operator*(DynamicArray<T> &s)
    {
        return set_intersection(s);
    }
    template <class T>
    DynamicArray<T> DynamicArray<T>::operator-(DynamicArray<T> &s)
    {
        return set_difference(s);
    }
}

using namespace DA;

int main(int argc,char **argv)
{
    DynamicArray<int> s1(5);
    DynamicArray<int> s2(5);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.add(4);
    s1.add(5);
    s2.add(4);
    s2.add(5);
    s2.add(6);
    s2.add(7);
    s2.add(8);
    DynamicArray<int> s3 = s1 + s2;
    DynamicArray<int> s4 = s1 * s2;
    DynamicArray<int> s5 = s1 - s2;
    s3.print();
    s4.print();
    s5.print();
    s1.~DynamicArray();
    s2.~DynamicArray();
    s3.~DynamicArray();
    s4.~DynamicArray();
    s5.~DynamicArray();
    return 0;
}
