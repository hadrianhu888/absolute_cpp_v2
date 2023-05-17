/**
 * @file polynomial_v1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template <class T>
class Polynomial
{
    public:
        int degree;
        T *coefficients;
        Polynomial(int degree);
        Polynomial() {};
        Polynomial(int coefficients, int degree)
        {
            this->degree = degree;
            this->coefficients = new T[degree + 1];
            for (int i = 0; i <= degree; i++)
            {
                this->coefficients[i] = coefficients;
            }
        }
        Polynomial(const Polynomial &poly);
        ~Polynomial();
        Polynomial &operator=(const Polynomial &poly);
        Polynomial operator+(const Polynomial &poly) const;
        Polynomial operator-(const Polynomial &poly) const;
        Polynomial operator*(const Polynomial &poly) const;
        Polynomial operator/(const Polynomial &poly) const;
        friend ostream &operator<<(ostream &out, const Polynomial &poly)
        {
            for (int i = poly.degree; i >= 0; i--)
            {
                if (poly.coefficients[i] != 0)
                {
                    if (i != poly.degree)
                    {
                        out << " ";
                    }
                    out << poly.coefficients[i];
                    if (i != 0)
                    {
                        out << "x";
                        if (i != 1)
                        {
                            out << "^" << i;
                        }
                    }
                }
            }
            return out;
        }
        friend istream &operator>>(istream &in, Polynomial &poly)
        {
            for (int i = 0; i <= poly.degree; i++)
            {
                in >> poly.coefficients[i];
            }
            return in;
        }
        void display()
        {
            for (int i = degree; i >= 0; i--)
            {
                if (coefficients[i] != 0)
                {
                    if (i != degree)
                    {
                        cout << " ";
                    }
                    cout << coefficients[i];
                    if (i != 0)
                    {
                        cout << "x";
                        if (i != 1)
                        {
                            cout << "^" << i;
                        }
                    }
                }
            }
        }
};

template <class T>
Polynomial<T>::Polynomial(int degree)
{
    this->degree = degree;
    coefficients = new T[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coefficients[i] = 0;
    }
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial &poly)
{
    degree = poly.degree;
    coefficients = new T[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coefficients[i] = poly.coefficients[i];
    }
}

template <class T>
Polynomial<T>::~Polynomial()
{
    delete[] coefficients;
}

template <class T>
Polynomial<T> &Polynomial<T>::operator=(const Polynomial &poly)
{
    if (this != &poly)
    {
        delete[] coefficients;
        degree = poly.degree;
        coefficients = new T[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = poly.coefficients[i];
        }
    }
    return *this;
}

template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial &poly) const
{
    Polynomial<T> temp(max(degree, poly.degree));
    for (int i = 0; i <= degree; i++)
    {
        temp.coefficients[i] += coefficients[i];
    }
    for (int i = 0; i <= poly.degree; i++)
    {
        temp.coefficients[i] += poly.coefficients[i];
    }
    return temp;
}

template <class T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial &poly) const
{
    Polynomial temp(max(degree, poly.degree));
    for (int i = 0; i <= degree; i++)
    {
        temp.coefficients[i] += coefficients[i];
    }
    for (int i = 0; i <= poly.degree; i++)
    {
        temp.coefficients[i] -= poly.coefficients[i];
    }
    return temp;
}

template <class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial &poly) const
{
    Polynomial temp(degree + poly.degree);
    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= poly.degree; j++)
        {
            temp.coefficients[i + j] += coefficients[i] * poly.coefficients[j];
        }
    }
    return temp;
}

template <class T>
Polynomial<T> Polynomial<T>::operator/(const Polynomial &poly) const
{
    Polynomial temp(degree - poly.degree);
    for (int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= poly.degree; j++)
        {
            temp.coefficients[i - j] += coefficients[i] / poly.coefficients[j];
        }
    }
    return temp;
}

template <class T>
ostream &operator<<(ostream &out, const Polynomial<T> &poly)
{
    for (int i = poly.degree; i >= 0; i--)
    {
        if (poly.coefficients[i] != 0)
        {
            if (i != poly.degree)
            {
                out << " + ";
            }
            if (i == 0)
            {
                out << poly.coefficients[i];
            }
            else if (i == 1)
            {
                out << poly.coefficients[i] << "x";
            }
            else
            {
                out << poly.coefficients[i] << "x^" << i;
            }
        }
    }
    return out;
}

template <class T>
istream &operator>>(istream &in, Polynomial<T> &poly)
{
    in >> poly.degree;
    delete[] poly.coefficients;
    poly.coefficients = new T[poly.degree + 1];
    for (int i = poly.degree; i >= 0; i--)
    {
        in >> poly.coefficients[i];
    }
    return in;
}

template <class T>
ostream &operator<< (ostream &out, Polynomial<T> &poly)
{
    for (int i = poly.degree; i >= 0; i--)
    {
        if (poly.coefficients[i] != 0)
        {
            if (i != poly.degree)
            {
                out << " + ";
            }
            if (i == 0)
            {
                out << poly.coefficients[i];
            }
            else if (i == 1)
            {
                out << poly.coefficients[i] << "x";
            }
            else
            {
                out << poly.coefficients[i] << "x^" << i;
            }
        }
    }
    return out;
}

int main()
{
    Polynomial<int> p1, p2;
    cin >> p1 >> p2;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 + p2 << endl;
    cout << p1 - p2 << endl;
    cout << p1 * p2 << endl;
    cout << p1 / p2 << endl;
    p1.display();
    p2.display();
    return 0;
}
