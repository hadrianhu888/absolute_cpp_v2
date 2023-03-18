/**
 * @file primes.cpp
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

class Primes
{
    private:
        int *primes;
        int size;
        int capacity;
        void resize();
    public:
        Primes();
        Primes(int capacity);
        ~Primes();
        void add(int prime);
        void print();
        int get_size();
        int get_capacity();
        int get_prime(int index);
        void set_prime(int index, int prime);
        friend Primes operator+(Primes p1, Primes p2);
        friend bool operator==(Primes p1, Primes p2);
        friend bool operator!=(Primes p1, Primes p2);
        friend bool operator<(Primes p1, Primes p2);
        friend bool operator<=(Primes p1, Primes p2);
        friend bool operator>(Primes p1, Primes p2);
        friend bool operator>=(Primes p1, Primes p2);
};

Primes::Primes()
{
    primes = new int[10];
    size = 0;
    capacity = 10;
}

Primes::Primes(int capacity)
{
    primes = new int[capacity];
    size = 0;
    this->capacity = capacity;
}

Primes::~Primes()
{
    delete [] primes;
}

void Primes::resize()
{
    int *temp = new int[capacity * 2];
    for (int i = 0; i < size; i++)
    {
        temp[i] = primes[i];
    }
    delete [] primes;
    primes = temp;
    capacity *= 2;
}

void Primes::add(int prime)
{
    if (size == capacity)
    {
        resize();
    }
    primes[size] = prime;
    size++;
}

void Primes::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << primes[i] << " ";
    }
    cout << endl;
}

int Primes::get_size()
{
    return size;
}

int Primes::get_capacity()
{
    return capacity;
}

int Primes::get_prime(int index)
{
    return primes[index];
}

void Primes::set_prime(int index, int prime)
{
    primes[index] = prime;
}

Primes operator+(Primes p1, Primes p2)
{
    Primes p3(p1.get_capacity() + p2.get_capacity());
    for (int i = 0; i < p1.get_size(); i++)
    {
        p3.add(p1.get_prime(i));
    }
    for (int i = 0; i < p2.get_size(); i++)
    {
        p3.add(p2.get_prime(i));
    }
    return p3;
}

bool operator==(Primes p1, Primes p2)
{
    if (p1.get_size() != p2.get_size())
    {
        return false;
    }
    for (int i = 0; i < p1.get_size(); i++)
    {
        if (p1.get_prime(i) != p2.get_prime(i))
        {
            return false;
        }
    }
    return true;
}

bool operator!=(Primes p1, Primes p2)
{
    return !(p1 == p2);
}

bool operator<(Primes p1, Primes p2)
{
    if (p1.get_size() < p2.get_size())
    {
        return true;
    }
    else if (p1.get_size() > p2.get_size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < p1.get_size(); i++)
        {
            if (p1.get_prime(i) < p2.get_prime(i))
            {
                return true;
            }
            else if (p1.get_prime(i) > p2.get_prime(i))
            {
                return false;
            }
        }
        return false;
    }
}

bool operator<=(Primes p1, Primes p2)
{
    return (p1 < p2 || p1 == p2);
}

bool operator>(Primes p1, Primes p2)
{
    return !(p1 <= p2);
}

bool operator>=(Primes p1, Primes p2)
{
    return !(p1 < p2);
}

int main(int argc, char **argv)
{
    Primes p1(5);
    p1.add(2);
    p1.add(3);
    p1.add(5);
    p1.add(7);
    p1.add(11);
    p1.print();
    Primes p2(5);
    p2.add(13);
    p2.add(17);
    p2.add(19);
    p2.add(23);
    p2.add(29);
    p2.print();
    Primes p3 = p1 + p2;
    p3.print();
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cout << (p1 < p2) << endl;
    cout << (p1 <= p2) << endl;
    cout << (p1 > p2) << endl;
    cout << (p1 >= p2) << endl;
    return 0;
}
