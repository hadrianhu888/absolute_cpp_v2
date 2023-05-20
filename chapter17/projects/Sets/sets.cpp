/**
 * @file sets.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template<class T>
class Set
{
private:
    T *_data;
    int _size;
    int _capacity;
public:
    Set();
    Set(const Set &rhs);
    Set(const T *arr, int size);
    ~Set() { delete [] _data; }
    const Set &operator=(const Set &rhs);
    void insert(const T &data);
    void erase(const T &data);
    bool contains(const T &data) const;
    int size() const { return _size; }
    bool isEmpty() const { return _size == 0; }
    void makeEmpty() { _size = 0; }
    void print() const;
    void copy(const Set &rhs);
    void resize(int newCapacity);
    T cardinality() const;
    Set union_(const Set &rhs) const;
    Set intersection(const Set &rhs) const;
    Set difference(const Set &rhs) const;
    Set symmetricDifference(const Set &rhs) const;
    bool isSubset(const Set &rhs) const;
    bool isProperSubset(const Set &rhs) const;
    bool isDisjoint(const Set &rhs) const;
    bool isEqual(const Set &rhs) const;
    bool operator==(const Set &rhs) const;
    bool operator!=(const Set &rhs) const;
    Set operator+(const Set &rhs) const;
    Set operator*(const Set &rhs) const;
    Set operator-(const Set &rhs) const;
    Set operator^(const Set &rhs) const;
    template <typename U>
    friend istream &operator>>(istream &is, const Set<U> &rhs);
    template <typename U>
    friend ostream &operator<<(ostream &os, const Set<U> &rhs);
};

template<class T>
Set<T>::Set()
{
    _data = new T[1];
    _size = 0;
    _capacity = 1;
}

template<class T>
Set<T>::Set(const Set &rhs)
{
    _data = new T[rhs._capacity];
    _size = rhs._size;
    _capacity = rhs._capacity;
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = rhs._data[i];
    }
}

template<class T>
Set<T>::Set(const T *arr, int size)
{
    _data = new T[size];
    _size = size;
    _capacity = size;
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = arr[i];
    }
}

template<class T>
const Set<T> &Set<T>::operator=(const Set &rhs)
{
    if (this != &rhs)
    {
        delete [] _data;
        _data = new T[rhs._capacity];
        _size = rhs._size;
        _capacity = rhs._capacity;
        for (int i = 0; i < _size; ++i)
        {
            _data[i] = rhs._data[i];
        }
    }
    return *this;
}

template<class T>
void Set<T>::insert(const T &data)
{
    if (!contains(data))
    {
        if (_size == _capacity)
        {
            resize(_capacity * 2);
        }
        _data[_size++] = data;
    }
}

template<class T>
void Set<T>::erase(const T &data)
{
    if (contains(data))
    {
        int i;
        for (i = 0; i < _size; ++i)
        {
            if (_data[i] == data)
            {
                break;
            }
        }
        for (; i < _size - 1; ++i)
        {
            _data[i] = _data[i + 1];
        }
        --_size;
    }
}

template<class T>
bool Set<T>::contains(const T &data) const
{
    for (int i = 0; i < _size; ++i)
    {
        if (_data[i] == data)
        {
            return true;
        }
    }
    return false;
}

template<class T>
void Set<T>::print() const
{
    cout << "{ ";
    for (int i = 0; i < _size; ++i)
    {
        cout << _data[i] << " ";
    }
    cout << "}" << endl;
}

template<class T>
void Set<T>::copy(const Set &rhs)
{
    delete [] _data;
    _data = new T[rhs._capacity];
    _size = rhs._size;
    _capacity = rhs._capacity;
    for (int i = 0; i < _size; ++i)
    {
        _data[i] = rhs._data[i];
    }
}

template<class T>
void Set<T>::resize(int newCapacity)
{
    T *temp = new T[newCapacity];
    for (int i = 0; i < _size; ++i)
    {
        temp[i] = _data[i];
    }
    delete [] _data;
    _data = temp;
    _capacity = newCapacity;
}

template<class T>
T Set<T>::cardinality() const
{
    return _size;
}

template<class T>
Set<T> Set<T>::union_(const Set &rhs) const
{
    Set<T> result;
    for (int i = 0; i < _size; ++i)
    {
        result.insert(_data[i]);
    }
    for (int i = 0; i < rhs._size; ++i)
    {
        result.insert(rhs._data[i]);
    }
    return result;
}

template<class T>
Set<T> Set<T>::intersection(const Set &rhs) const
{
    Set<T> result;
    for (int i = 0; i < _size; ++i)
    {
        if (rhs.contains(_data[i]))
        {
            result.insert(_data[i]);
        }
    }
    return result;
}

template<class T>
Set<T> Set<T>::difference(const Set &rhs) const
{
    Set<T> result;
    for (int i = 0; i < _size; ++i)
    {
        if (!rhs.contains(_data[i]))
        {
            result.insert(_data[i]);
        }
    }
    return result;
}

template<class T>
Set<T> Set<T>::symmetricDifference(const Set &rhs) const
{
    Set<T> result;
    for (int i = 0; i < _size; ++i)
    {
        if (!rhs.contains(_data[i]))
        {
            result.insert(_data[i]);
        }
    }
    for (int i = 0; i < rhs._size; ++i)
    {
        if (!contains(rhs._data[i]))
        {
            result.insert(rhs._data[i]);
        }
    }
    return result;
}

template<class T>
bool Set<T>::isSubset(const Set &rhs) const
{
    for (int i = 0; i < _size; ++i)
    {
        if (!rhs.contains(_data[i]))
        {
            return false;
        }
    }
    return true;
}

template<class T>
bool Set<T>::isProperSubset(const Set &rhs) const
{
    return isSubset(rhs) && _size < rhs._size;
}

template<class T>
bool Set<T>::isDisjoint(const Set &rhs) const
{
    for (int i = 0; i < _size; ++i)
    {
        if (rhs.contains(_data[i]))
        {
            return false;
        }
    }
    return true;
}

template<class T>
bool Set<T>::operator==(const Set &rhs) const
{
    return isSubset(rhs) && rhs.isSubset(*this);
}

template<class T>
bool Set<T>::operator!=(const Set &rhs) const
{
    return !(*this == rhs);
}

template<class T>
Set<T> Set<T>::operator+(const Set &rhs) const
{
    return union_(rhs);
}

template<class T>
Set<T> Set<T>::operator*(const Set &rhs) const
{
    return intersection(rhs);
}

template<class T>
Set<T> Set<T>::operator-(const Set &rhs) const
{
    return difference(rhs);
}

template<class T>
Set<T> Set<T>::operator^(const Set &rhs) const
{
    return symmetricDifference(rhs);
}

template <class T>
istream &operator>>(istream &is, Set<T> &rhs)
{
    T data;
    while (is >> data)
    {
        rhs.insert(data);
    }
    return is;
}

template <class T>
ostream &operator<<(ostream &os, const Set<T> &rhs)
{
    rhs.print();
    return os;
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    /**
     * @brief test Set class
     *
     */
    Set<int> s1;
    s1.insert(1);
    s1.cardinality();
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    Set<int> s2;
    s2.insert(4);
    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(1);
    Set<int> s3 = s1.union_(s2);
    s3.print();
    Set<int> s4 = s1.intersection(s2);
    s4.print();
    Set<int> s5 = s1.difference(s2);
    s5.print();
    Set<int> s6 = s1.symmetricDifference(s2);
    s6.print();
    cout << s1.isSubset(s2) << endl;
    cout << s1.isProperSubset(s2) << endl;
    cout << s1.isDisjoint(s2) << endl;
    cout << (s1 == s2) << endl;
    cout << (s1 != s2) << endl;
    Set<int> s7 = s1 + s2;
    s7.print();
    Set<int> s8 = s1 * s2;
    s8.print();
    Set<int> s9 = s1 - s2;
    s9.print();
    Set<int> s10 = s1 ^ s2;
    s10.print();
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << s9 << endl;
    cout << s10 << endl;
    return 0;
}
