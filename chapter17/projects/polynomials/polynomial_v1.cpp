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
public:
    vector<T> coefficients;

    int degree() const
    {
        int deg = 0;
        for (int i = 0; i < coefficients.size(); ++i)
        {
            if (coefficients[i] != 0)
            {
                deg = i;
            }
        }
        return deg;
    }

    Polynomial() : coefficients({0})
    {
    }
    Polynomial(int degree, const vector<T> &coeffs) : coefficients(coeffs)
    {
        coefficients.resize(degree + 1);
    }
    Polynomial(const Polynomial &poly) : coefficients(poly.coefficients)
    {
    }
    Polynomial &operator=(const Polynomial &poly)
    {
        coefficients = poly.coefficients;
        return *this;
    }

    Polynomial operator+(const Polynomial &poly) const
    {
        const int max_degree = max(degree(), poly.degree());
        vector<T> result_coeffs(max_degree + 1, 0);

        for (int i = 0; i <= degree(); i++)
            result_coeffs[i] += coefficients[i];

        for (int i = 0; i <= poly.degree(); i++)
            result_coeffs[i] += poly.coefficients[i];

        return Polynomial(max_degree, result_coeffs);
    }

    Polynomial operator-(const Polynomial &poly) const
    {
        int max_degree = max(degree(), poly.degree());
        vector<T> result_coeffs(max_degree + 1, 0);

        for (int i = 0; i <= degree(); i++)
            result_coeffs[i] += coefficients[i];

        for (int i = 0; i <= poly.degree(); i++)
            result_coeffs[i] -= poly.coefficients[i];

        return Polynomial(max_degree, result_coeffs);
    }

    Polynomial operator*(const Polynomial &poly) const
    {
        int max_degree = degree() + poly.degree();
        vector<T> result_coeffs(max_degree + 1, 0);

        for (int i = 0; i <= degree(); i++)
        {
            for (int j = 0; j <= poly.degree(); j++)
            {
                result_coeffs[i + j] += coefficients[i] * poly.coefficients[j];
            }
        }

        return Polynomial(max_degree, result_coeffs);
    }

    friend istream &operator>>(istream &in, Polynomial &poly)
    {
        int deg;
        in >> deg;
        poly.coefficients.resize(deg + 1);
        for (int i = deg; i >= 0; i--)
        {
            in >> poly.coefficients[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &poly)
    {
        for (int i = poly.degree(); i >= 0; i--)
        {
            if (poly.coefficients[i] != 0)
            {
                if (i != poly.degree())
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
};

template <class T>
pair<Polynomial<T>, Polynomial<T>> divide(const Polynomial<T> &a, const Polynomial<T> &b)
{
    if (b.degree() == 0 && b.coefficients[0] == 0)
    {
        throw std::invalid_argument("Division by zero polynomial");
    }

    Polynomial<T> quotient;
    Polynomial<T> remaining = a;

    while (remaining.degree() >= b.degree())
    {
        int new_degree = remaining.degree() - b.degree();
        T coeff = remaining.coefficients[remaining.degree()] / b.coefficients[b.degree()];

        vector<T> new_coeff(new_degree + 1, 0);
        new_coeff[new_degree] = coeff;

        Polynomial<T> temp(new_degree, new_coeff);

        quotient = quotient + temp;
        remaining = remaining - (temp * b);
    };

    return {
        quotient, remaining
    };
}

template<class T>
void sum(const Polynomial<T> &p1, const Polynomial<T> &p2)
{
    cout << p1 + p2 << endl;
}

template<class T>
void difference(const Polynomial<T> &p1, const Polynomial<T> &p2)
{
    cout << p1 - p2 << endl;
}

template<class T>
void product(const Polynomial<T> &p1, const Polynomial<T> &p2)
{
    cout << p1 * p2 << endl;
}

template<class T>
void quotient(const Polynomial<T> &p1, const Polynomial<T> &p2)
{
    cout << divide(p1, p2).first << endl;
}

template<class T>
void remainder(const Polynomial<T> &p1, const Polynomial<T> &p2)
{
    cout << divide(p1, p2).second << endl;
}

template<class T>
void derivative(const Polynomial<T> &p1)
{
    vector<T> result_coeffs(p1.degree(), 0);
    for (int i = 1; i <= p1.degree(); i++)
    {
        result_coeffs[i - 1] = p1.coefficients[i] * i;
    }
    cout << Polynomial<T>(p1.degree() - 1, result_coeffs) << endl;
}

template<class T>
void integral(const Polynomial<T> &p1)
{
    vector<T> result_coeffs(p1.degree() + 2, 0);
    for (int i = 0; i <= p1.degree(); i++)
    {
        result_coeffs[i + 1] = p1.coefficients[i] / (i + 1);
    }
    cout << Polynomial<T>(p1.degree() + 1, result_coeffs) << endl;
}

template<class T>
void displayCorrectIntegralCoefficients(const Polynomial<T> &p1)
{
    vector<T> result_coeffs(p1.degree() + 2, 0);
    for (int i = 0; i <= p1.degree(); i++)
    {
        result_coeffs[i + 1] = p1.coefficients[i] / (i + 1);
    }
    cout << Polynomial<T>(p1.degree() + 1, result_coeffs) << endl;
}

template<class T>
void print(void)
{
    cout << "Enter the degree and coefficients for the first polynomial: " << endl;
    Polynomial<T> p1;
    cin >> p1;
    cout << "Enter the degree and coefficients for the second polynomial: " << endl;
    Polynomial<T> p2;
    cin >> p2;
    cout << "First Polynomial: " << p1 << endl;
    cout << "Second Polynomial: " << p2 << endl;
    cout << "Sum: " << p1 + p2 << endl;
    cout << "Difference: " << p1 - p2 << endl;
    cout << "Product: " << p1 * p2 << endl;
    cout << "Quotient: " << divide(p1, p2).first << endl;
    cout << "Remainder: " << divide(p1, p2).second << endl;
    cout << "Derivative of first polynomial: ";
    derivative(p1);
    cout << "Derivative of second polynomial: ";
    derivative(p2);
    cout << "Integral of first polynomial: ";
    integral(p1);
    cout << "Integral of second polynomial: ";
    integral(p2);
}

int main()
{
    print<int>();
    return 0;
}
