/**
 * @file multiple_exceptions.cpp
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
class NegativeNumber
{
public:
    NegativeNumber() = default;
    NegativeNumber(const T &data) : _data(data)
    {
        try
        {
            if (_data < 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Negative number: " << e << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const NegativeNumber &nn)
    {
        os << "Negative number: " << nn._data << endl;
        return os;
    }
    int getCount() const
    {
        try
        {
            if (_data < 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Negative number: " << e << endl;
        }
        return _data;
    }
private:
    T _data;
};

template <class T>
class DivideByZero
{
public:
    DivideByZero() = default;
    DivideByZero(const T &data) : _data(data)
    {
        try
        {
            if (_data == 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Divide by zero: " << e << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const DivideByZero &dbz)
    {
        os << "Divide by zero: " << dbz._data << endl;
        return os;
    }
    int getCount() const
    {
        try
        {
            if (_data == 0)
            {
                throw _data;
            }
        }
        catch (int e)
        {
            cout << "Divide by zero: " << e << endl;
        }
        return _data;
    }
private:
    T _data;
};

double safeDivide(double num, double denom)
{
    try
    {
        if (denom == 0)
        {
            throw denom;
        }
    }
    catch (double e)
    {
        cout << "Divide by zero: " << e << endl;
    }
    return num / denom;
}

void testFunction(int a) throw(int, char, double)
{
    try
    {
        if (a == 0)
        {
            throw a;
        }
    }
    catch (int e)
    {
        cout << "Caught an int exception.\n";
    }
    catch (char e)
    {
        cout << "Caught a char exception.\n";
    }
    catch (double e)
    {
        cout << "Caught a double exception.\n";
    }
}

int main(int argc, char **argv)
{
    NegativeNumber<int> nn1(-1);
    NegativeNumber<int> nn2(1);
    DivideByZero<int> dbz1(0);
    DivideByZero<int> dbz2(1);
    try
    {
        if (nn1.getCount() < 0)
        {
            throw nn1;
        }
        if (nn2.getCount() < 0)
        {
            throw nn2;
        }
        if (dbz1.getCount() == 0)
        {
            throw dbz1;
        }
        if (dbz2.getCount() == 0)
        {
            throw dbz2;
        }
    }
    catch (NegativeNumber<int> nn)
    {
        cout << nn;
    }
    catch (DivideByZero<int> dbz)
    {
        cout << dbz;
    }
    cout << safeDivide(1, 0) << endl;
    testFunction(0);
    return 0;
}
