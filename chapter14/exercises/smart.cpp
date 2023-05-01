/**
 * @file smart.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Smart
{
public:
    Smart(int n);
    ~Smart();
    int getNumber() const;
    void setNumber(int n);
    Smart(const Smart &other);
    Smart &operator=(const Smart &other);
private:
    int *ptr;
};

class Crazy:public Smart
{
public:
    Crazy(int n);
    ~Crazy();
    int getNumber() const;
    void setNumber(int n);
    Crazy(const Crazy &other);
    Crazy &operator=(const Crazy &other);
    bool isCrazy() const;
private:
    int *ptr;
};

class SmartBut:public Crazy
{
public:
    SmartBut(int n);
    ~SmartBut();
    int getNumber() const;
    void setNumber(int n);
    SmartBut(const SmartBut &other);
    SmartBut &operator=(const SmartBut &other);
    bool isCrazy() const;
private:
    int *ptr;
};

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    Smart s1(1);
    Smart s2(2);
    s1 = s2;
    s1.setNumber(3);
    cout << s1.getNumber() << endl;
    cout << s2.getNumber() << endl;
    Crazy c1(1);
    Crazy c2(2);
    c1 = c2;
    c1.setNumber(3);
    cout << c1.getNumber() << endl;
    cout << c2.getNumber() << endl;
    cout << c2.isCrazy() << endl;
    SmartBut sb1(1);
    SmartBut sb2(2);
    sb1 = sb2;
    sb1.setNumber(3);
    cout << sb1.getNumber() << endl;
    cout << sb2.getNumber() << endl;
    cout << sb2.isCrazy() << endl;
    return 0;
}

Smart::Smart(int n)
{
    ptr = new int;
    *ptr = n;
}

Smart::~Smart()
{
    delete ptr;
}

int Smart::getNumber() const
{
    return *ptr;
}

void Smart::setNumber(int n)
{
    *ptr = n;
}

Smart::Smart(const Smart &other)
{
    ptr = new int;
    *ptr = *other.ptr;
}

Smart &Smart::operator=(const Smart &other)
{
    if (this != &other)
    {
        *ptr = *other.ptr;
    }
    return *this;
}

Crazy::Crazy(int n):Smart(n)
{
    ptr = new int;
    *ptr = n;
}

Crazy::~Crazy()
{
    delete ptr;
}

int Crazy::getNumber() const
{
    return *ptr;
}

void Crazy::setNumber(int n)
{
    *ptr = n;
}

Crazy::Crazy(const Crazy &other):Smart(other)
{
    ptr = new int;
    *ptr = *other.ptr;
}

Crazy &Crazy::operator=(const Crazy &other)
{
    if (this != &other)
    {
        *ptr = *other.ptr;
    }
    return *this;
}

bool Crazy::isCrazy() const
{
    return true;
}

SmartBut::SmartBut(int n):Crazy(n)
{
    ptr = new int;
    *ptr = n;
}

SmartBut::~SmartBut()
{
    delete ptr;
}

int SmartBut::getNumber() const
{
    return *ptr;
}

void SmartBut::setNumber(int n)
{
    *ptr = n;
}

SmartBut::SmartBut(const SmartBut &other):Crazy(other)
{
    ptr = new int;
    *ptr = *other.ptr;
}

SmartBut &SmartBut::operator=(const SmartBut &other)
{
    if (this != &other)
    {
        *ptr = *other.ptr;
    }
    return *this;
}

bool SmartBut::isCrazy() const
{
    return false;
}

// int main(int argc, char **argv);s
