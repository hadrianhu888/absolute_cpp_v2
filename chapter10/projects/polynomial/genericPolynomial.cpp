/**
 * @file genericPolynomial.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Polynomial
{
private:
    vector<T> coeffs;

public:
    Polynomial()
    {
    }

    Polynomial(vector<T> coeffs)
    {
        this->coeffs = coeffs;
    }

    int degree() const
    {
        return coeffs.size() - 1;
    }

    T operator[](int i) const
    {
        if (i >= coeffs.size())
        {
            return 0;
        }
        else
        {
            return coeffs[i];
        }
    }

    T& operator[] (int i)
    {
        if (i >= coeffs.size())
        {
            coeffs.resize(i + 1);
        }
        return coeffs[i];
    }

    Polynomial<T> operator+(const Polynomial<T> &other) const
    {
        int d = max(degree(), other.degree());
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= d; i++)
        {
            result_coeffs[i] = (*this)[i] + other[i];
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator-(const Polynomial<T> &other) const
    {
        int d = max(degree(), other.degree());
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= d; i++)
        {
            result_coeffs[i] = (*this)[i] - other[i];
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator -=(const Polynomial<T> &other) const
    {
        int d = max(degree(), other.degree());
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= d; i++)
        {
            result_coeffs[i] = (*this)[i] - other[i];
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator +=(const Polynomial<T> &other) const
    {
        int d = max(degree(), other.degree());
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= d; i++)
        {
            result_coeffs[i] = (*this)[i] + other[i];
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator /=(const Polynomial<T> &other) const
    {
        if (degree() < other.degree())
        {
            return Polynomial<T>();
        }
        int d = degree() - other.degree();
        vector<T> result_coeffs(d + 1);
        Polynomial<T> remainder(*this);
        for (int i = d; i >= 0; i--)
        {
            result_coeffs[i] = remainder[other.degree() + i] / other[other.degree()];
            for (int j = 0; j <= other.degree(); j++)
            {
                remainder[i + j] -= result_coeffs[i] * other[j];
            }
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator *=(const Polynomial<T> &other) const
    {
        int d = degree() + other.degree();
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= degree(); i++)
        {
            for (int j = 0; j <= other.degree(); j++)
            {
                result_coeffs[i + j] += (*this)[i] * other[j];
            }
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator*(const Polynomial<T> &other) const
    {
        int d = degree() + other.degree();
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= degree(); i++)
        {
            for (int j = 0; j <= other.degree(); j++)
            {
                result_coeffs[i + j] += (*this)[i] * other[j];
            }
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> operator/(const Polynomial<T> &other) const
    {
        if (degree() < other.degree())
        {
            return Polynomial<T>();
        }
        int d = degree() - other.degree();
        vector<T> result_coeffs(d + 1);
        Polynomial<T> remainder(*this);
        for (int i = d; i >= 0; i--)
        {
            result_coeffs[i] = remainder[other.degree() + i] / other[other.degree()];
            for (int j = 0; j <= other.degree(); j++)
            {
                remainder[other.degree() + i - j] -= result_coeffs[i] * other[other.degree() - j];
            }
        }
        return Polynomial<T>(result_coeffs);
    }

    Polynomial<T> convertDataTypes(const Polynomial<T> &other) const
    {
        int d = max(degree(), other.degree());
        vector<T> result_coeffs(d + 1);
        for (int i = 0; i <= d; i++)
        {
            result_coeffs[i] = (*this)[i] + other[i];
        }
        return Polynomial<T>(result_coeffs);
    }

    friend ostream &operator<<(ostream &os, const Polynomial<T> &p)
    {
        for (int i = p.degree(); i >= 0; i--)
        {
            if (i < p.degree())
            {
                os << " + ";
            }
            os << p[i];
            if (i > 0)
            {
                os << "x";
                if (i > 1)
                {
                    os << "^" << i;
                }
            }
        }
        return os;
    }
};

int main(int argc, char *argv[])
{
    Polynomial<int> p1({1, 2, 3});
    Polynomial<int> p2({4, 5, 6});

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    Polynomial<int> p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;

    Polynomial<int> p4 = p1 - p2;
    cout << "p1 - p2 = " << p4 << endl;

    Polynomial<int> p5 = p1 * p2;
    cout << "p1 * p2 = " << p5 << endl;

    Polynomial<int> p6 = p1 / p2;
    cout << "p1 / p2 = " << p6 << endl;

    Polynomial<float> p7({1.0, 2.0, 3.0});
    cout << "p1 = " << p7 << endl;

    return 0;
}
