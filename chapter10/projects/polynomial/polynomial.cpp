/**
 * @file polynomial.cpp
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

class Polynomial {
private:
    vector<double> coeffs;

public:
    Polynomial() {}

    Polynomial(const vector<double>& c) : coeffs(c) {}

    Polynomial operator+(const Polynomial& other) const {
        vector<double> res(max(coeffs.size(), other.coeffs.size()));
        for (int i = 0; i < res.size(); i++) {
            res[i] = (i < coeffs.size() ? coeffs[i] : 0) + (i < other.coeffs.size() ? other.coeffs[i] : 0);
        }
        return Polynomial(res);
    }

    Polynomial operator-(const Polynomial& other) const {
        vector<double> res(max(coeffs.size(), other.coeffs.size()));
        for (int i = 0; i < res.size(); i++) {
            res[i] = (i < coeffs.size() ? coeffs[i] : 0) - (i < other.coeffs.size() ? other.coeffs[i] : 0);
        }
        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<double> res(coeffs.size() + other.coeffs.size() - 1, 0);
        for (int i = 0; i < coeffs.size(); i++) {
            for (int j = 0; j < other.coeffs.size(); j++) {
                res[i+j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(res);
    }

    Polynomial operator/(const Polynomial& other) const {
        vector<double> q, r(coeffs);
        while (r.size() >= other.coeffs.size()) {
            double factor = r.back() / other.coeffs.back();
            q.push_back(factor);
            for (int i = 0; i < other.coeffs.size(); i++) {
                r[r.size() - i - 1] -= factor * other.coeffs[other.coeffs.size() - i - 1];
            }
            while (r.size() > 0 && r.back() == 0) {
                r.pop_back();
            }
        }
        return Polynomial(q);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coeffs.empty()) {
            os << "0";
        } else {
            for (int i = p.coeffs.size() - 1; i >= 0; i--) {
                if (p.coeffs[i] != 0) {
                    if (i != p.coeffs.size() - 1) {
                        os << (p.coeffs[i] > 0 ? " + " : " - ");
                    }
                    os << abs(p.coeffs[i]);
                    if (i > 0) {
                        os << "x";
                        if (i > 1) {
                            os << "^" << i;
                        }
                    }
                }
            }
        }
        return os;
    }
};

int main() {
    Polynomial p1({1, 2, 3});
    Polynomial p2({4, 5, 6});

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "p1 / p2 = " << p1 / p2 << endl;

    Polynomial p3({3, 2, 1});
    cout << "p3 = " << p3 << endl;

    cout << "p1 + p3 = " << p1 + p3 << endl;
    cout << "p1 - p3 = " << p1 - p3 << endl;
    cout << "p1 * p3 = " << p1 * p3 << endl;
    cout << "p1 / p3 = " << p1 / p3 << endl;

    return 0;
}
