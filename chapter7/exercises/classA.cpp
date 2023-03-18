/**
 * @file classA.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

const int x = 17; 
class A
{
    private:
        int x;
    public:
        A(int x);
        int f() const; 
        int g(const A& x); 
        void print();
};

int main(int argc, char **argv) {
    A a(5);
    A c(10);
    a.print();
    c.print();
    cout << "a.f() = " << a.f() << endl;
    cout << "a.g(a) = " << a.g(a) << endl;
    /**
    * @brief test the const functions
    *
    */
    const A b(10);
    c.print();
    cout << "b.f() = " << b.f() << endl;
    cout << "b.g(a) = " << c.g(a) << endl;
    return 0;
}


A::A(int x)
{
    this->x = x;
}

void A::print()
{
    cout << "x = " << x << endl;
}

int A::f() const
{
    return x;
}

int A::g(const A& x)
{
    return x.x;
}

// Path: chapter7\exercises\classB.cpp