/**
 * @file polynomials.cpp
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

class Polynomial
{
private:
    int degree;
    double *coefficients;
    public:
    Polynomial(int degree);
    Polynomial();
    Polynomial(int coefficients, int degree);
    Polynomial(const Polynomial &poly);
    ~Polynomial();
    Polynomial &operator=(const Polynomial &poly);
    Polynomial operator+(const Polynomial &poly) const;
    Polynomial operator-(const Polynomial &poly) const;
    Polynomial operator*(const Polynomial &poly) const;
    Polynomial operator/(const Polynomial &poly) const;
    friend ostream &operator<<(ostream &out, const Polynomial &poly);
    friend istream &operator>>(istream &in, Polynomial &poly);
};

Polynomial::Polynomial(int degree)
{
    this->degree = degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coefficients[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &poly)
{
    degree = poly.degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coefficients[i] = poly.coefficients[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] coefficients;
}

Polynomial::Polynomial()
{
    degree = 0;
    coefficients = new double[degree + 1];
    coefficients[0] = 0;
}

Polynomial::Polynomial(int coefficients, int degree)
{
    this->degree = degree;
    this->coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        this->coefficients[i] = coefficients;
    }
}

Polynomial &Polynomial::operator=(const Polynomial &poly)
{
    if (this != &poly)
    {
        delete[] coefficients;
        degree = poly.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = poly.coefficients[i];
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &poly) const
{
    Polynomial temp(max(degree, poly.degree));
    for (int i = 0; i <= min(degree, poly.degree); i++)
    {
        temp.coefficients[i] = coefficients[i] + poly.coefficients[i];
    }
    for (int i = min(degree, poly.degree) + 1; i <= max(degree, poly.degree); i++)
    {
        if (degree > poly.degree)
        {
            temp.coefficients[i] = coefficients[i];
        }
        else
        {
            temp.coefficients[i] = poly.coefficients[i];
        }
    }
    return temp;
}

Polynomial Polynomial::operator-(const Polynomial &poly) const
{
    Polynomial temp(max(degree, poly.degree));
    for (int i = 0; i <= min(degree, poly.degree); i++)
    {
        temp.coefficients[i] = coefficients[i] - poly.coefficients[i];
    }
    for (int i = min(degree, poly.degree) + 1; i <= max(degree, poly.degree); i++)
    {
        if (degree > poly.degree)
        {
            temp.coefficients[i] = coefficients[i];
        }
        else
        {
            temp.coefficients[i] = -poly.coefficients[i]; // Note the negation here
        }
    }
    return temp;
}


Polynomial Polynomial::operator*(const Polynomial &poly) const
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

Polynomial Polynomial::operator/(const Polynomial &poly) const
{
    Polynomial temp(degree - poly.degree);
    Polynomial remainder(*this);
    for (int i = 0; i <= temp.degree; i++)
    {
        temp.coefficients[i] = remainder.coefficients[i] / poly.coefficients[0];
        for (int j = 0; j <= poly.degree; j++)
        {
            remainder.coefficients[i + j] -= temp.coefficients[i] * poly.coefficients[j];
        }
    }
    return temp;
}

ostream &operator<<(ostream &out, const Polynomial &poly)
{
    for (int i = poly.degree; i >= 0; i--)
    {
        if (poly.coefficients[i] != 0)
        {
            out << poly.coefficients[i];
            if (i != 0)
            {
                out << "x^" << i;
            }
            if (i > 0)
            {
                out << " + ";
            }
        }
    }
    return out;
}

istream &operator>>(istream &in, Polynomial &poly)
{
    for (int i = 0; i <= poly.degree; i++)
    {
        in >> poly.coefficients[i];
    }
    return in;
}

int main(int argc, char **argv)
{
    Polynomial p1(3);
    Polynomial p2(2);
    cin >> p1;
    cin >> p2;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 + p2 << endl;
    cout << p1 - p2 << endl;
    cout << p1 * p2 << endl;
    cout << p1 / p2 << endl;
    return 0;
}
