/**
 * @file integer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class MyInteger
{
    private:
        int value;
    public:
        MyInteger();
        MyInteger(int value);
        void set_value(int value);
        int get_value();
        friend bool operator==(MyInteger i1, MyInteger i2);
        friend bool operator!=(MyInteger i1, MyInteger i2);
        friend bool operator<(MyInteger i1, MyInteger i2);
        friend bool operator<=(MyInteger i1, MyInteger i2);
        friend bool operator>(MyInteger i1, MyInteger i2);
        friend bool operator>=(MyInteger i1, MyInteger i2);
        friend ostream& operator<<(ostream& out, MyInteger i);
        friend istream& operator>>(istream& in, MyInteger& i);
        MyInteger operator[](int index);
        MyInteger operator+(int index);
        MyInteger operator-(int index);
        MyInteger operator++();
        MyInteger operator++(int);   
        MyInteger operator--();
        MyInteger operator--(int);
};

MyInteger::MyInteger()
{
    value = 0;
}

MyInteger::MyInteger(int value)
{
    this->value = value;
}

void MyInteger::set_value(int value)
{
    this->value = value;
}

int MyInteger::get_value()
{
    return value;
}

bool operator==(MyInteger i1, MyInteger i2)
{
    return i1.value == i2.value;
}

bool operator!=(MyInteger i1, MyInteger i2)
{
    return i1.value != i2.value;
}

bool operator<(MyInteger i1, MyInteger i2)
{
    return i1.value < i2.value;
}

bool operator<=(MyInteger i1, MyInteger i2)
{
    return i1.value <= i2.value;
}

bool operator>(MyInteger i1, MyInteger i2)
{
    return i1.value > i2.value;
}

bool operator>=(MyInteger i1, MyInteger i2)
{
    return i1.value >= i2.value;
}

ostream& operator<<(ostream& out, MyInteger i)
{
    out << i.value;
    return out;
}

istream& operator>>(istream& in, MyInteger& i)
{
    in >> i.value;
    return in;
}

MyInteger MyInteger::operator[](int index)
{
    return MyInteger(value + index);
}

MyInteger MyInteger::operator+(int index)
{
    return MyInteger(value + index);
}

MyInteger MyInteger::operator-(int index)
{
    return MyInteger(value - index);
}

MyInteger MyInteger::operator++()
{
    value++;
    return *this;
}

MyInteger MyInteger::operator++(int)
{
    MyInteger temp = *this;
    value++;
    return temp;
}

MyInteger MyInteger::operator--()
{
    value--;
    return *this;
}

MyInteger MyInteger::operator--(int)
{
    MyInteger temp = *this;
    value--;
    return temp;
}

int main(int argc, char **argv)
{
    MyInteger i1(5);
    MyInteger i2(5);
    MyInteger i3(6);
    vector<MyInteger> v;
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << "i1 == i2: " << (i1 == i2) << endl;
    cout << "i1 != i2: " << (i1 != i2) << endl;
    cout << "i1 < i2: " << (i1 < i2) << endl;
    cout << "i1 <= i2: " << (i1 <= i2) << endl;
    cout << "i1 > i2: " << (i1 > i2) << endl;
    cout << "i1 >= i2: " << (i1 >= i2) << endl;
    cout << "i1 + 5: " << (i1 + 5) << endl;
    cout << "i1 - 5: " << (i1 - 5) << endl;
    cout << "++i1: " << (++i1) << endl;
    cout << "i1++: " << (i1++) << endl;
    cout << "i1: " << i1 << endl;
    cout << "--i1: " << (--i1) << endl;
    cout << "i1--: " << (i1--) << endl;
    cout << "i1: " << i1 << endl;
    /**
     * @brief test the [] operator
     * 
     */
    cout << "i1[5]: " << i1[5] << endl;
    return 0;
}