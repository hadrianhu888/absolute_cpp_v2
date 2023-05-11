/**
 * @file pair.cpp
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

template <class T1, class T2>
class Pair
{
public:
    Pair();
    Pair(T1 first, T2 second);
    T1 getFirst() const;
    T2 getSecond() const;
    void setFirst(T1 first);
    void setSecond(T2 second);
    ~Pair();
    auto addUp(T1 first, T2 second)
    {
        return first + second;
    }
    auto addUp(const Pair<T1, T2> &p1, const Pair<T1, T2> &p2)
    {
        return p1.first + p1.second + p2.first + p2.second;
    }
    auto addUp(const Pair<T1,T2> &p1)
    {
        return p1.first + p1.second;
    }
private:
    T1 first;
    T2 second;
};

template <class T1, class T2>
Pair<T1, T2>::Pair() : first(0), second(0)
{
    cout << "Pair constructor called" << endl;
}

template <class T1, class T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : first(first), second(second)
{
    cout << "Pair constructor called" << endl;
}

template <class T1, class T2>
T1 Pair<T1, T2>::getFirst() const
{
    return first;
}

template <class T1, class T2>
T2 Pair<T1, T2>::getSecond() const
{
    return second;
}

template <class T1, class T2>
void Pair<T1, T2>::setFirst(T1 first)
{
    this->first = first;
}

template <class T1, class T2>
void Pair<T1, T2>::setSecond(T2 second)
{
    this->second = second;
}

template <class T1, class T2>
Pair<T1, T2>::~Pair()
{
    cout << "Pair destructor called" << endl;
}

int main()
{
    Pair<int, double> p1(1, 2.5);
    Pair<int, double> p2(3, 4.5);
    Pair<int, double> p3(5, 6.5);
    cout << p1.addUp(7, 8.5) << endl;
    cout << p1.addUp(p2) << endl;
    cout << p1.addUp(p2, p3) << endl;
    cout << p1.addUp(7, 8.5) << endl;
    return 0;
}
