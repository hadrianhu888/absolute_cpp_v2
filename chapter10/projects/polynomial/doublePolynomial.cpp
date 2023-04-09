/**
 * @file doublePolynomial.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Polynomial
{
public:
    // Constructor
    Polynomial(const vector<double> &coeffs) : coefficients(coeffs)
    {

    }

    // Overloaded arithmetic operators
    Polynomial operator+(const Polynomial &other) const
    {
        vector<double> result(max(size(), other.size()));
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i < size())
                result[i] += coefficients[i];
            if (i < other.size())
                result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial &other) const
    {
        vector<double> result(max(size(), other.size()));
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i < size())
                result[i] += coefficients[i];
            if (i < other.size())
                result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial &other) const
    {
        vector<double> result(size() + other.size() - 1, 0);
        for (size_t i = 0; i < size(); ++i)
        {
            for (size_t j = 0; j < other.size(); ++j)
            {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    Polynomial operator/(const Polynomial &other) const
    {
        vector<double> quotient;
        Polynomial remainder(*this);

        while (remainder.size() >= other.size())
        {
            double coeff = remainder.coefficients.back() / other.coefficients.back();
            quotient.push_back(coeff);

            Polynomial temp(vector<double>(remainder.size() - other.size() + 1, 0));
            temp.coefficients.back() = coeff;

            remainder = remainder - temp * other;
            remainder.trim();
        }

        return Polynomial(quotient);
    }

    // Overloaded output operator
    friend ostream &operator<<(ostream &os, const Polynomial &poly);

private:
    vector<double> coefficients;

    // Helper function to remove trailing zeros
    void trim()
    {
        while (coefficients.size() > 1 && coefficients.back() == 0)
        {
            coefficients.pop_back();
        }
    }

    // Helper function to get the size of the coefficients vector
    size_t size() const
    {
        return coefficients.size();
    }
};

// Overloaded output operator
ostream &operator<<(ostream &os, const Polynomial &poly)
{
    for (int i = poly.size() - 1; i >= 0; --i)
    {
        if (poly.coefficients[i] != 0)
        {
            if (i == poly.size() - 1)
            {
                os << poly.coefficients[i] << "x^" << i;
            }
            else
            {
                os << " + " << poly.coefficients[i] << "x^" << i;
            }
        }
    }
    return os;
}

int main()
{
    Polynomial p1({1.5, 2.0, 3.5});
    Polynomial p2({4.0, 5.5, 6.0});

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "p1 / p2 = " << p1 / p2 << endl;

    return 0;
}
