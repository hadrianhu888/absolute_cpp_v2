/**
 * @file new_fraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

#include <iostream>


using namespace std;

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);
    friend bool operator==(const Fraction& a, const Fraction& b);
    friend bool operator!=(const Fraction& a, const Fraction& b);
    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator<=(const Fraction& a, const Fraction& b);
    friend bool operator>=(const Fraction& a, const Fraction& b);
    friend void swap(Fraction& a, Fraction& b);
    friend void print_fractions(const Fraction* fractions, int size);
private:
    int m_numerator;
    int m_denominator;

    void reduce();
};

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.m_numerator << "/" << f.m_denominator;
    return out;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
    Fraction result(a.m_numerator * b.m_denominator + b.m_numerator * a.m_denominator,
                    a.m_denominator * b.m_denominator);
    result.reduce();
    return result;
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    Fraction result(a.m_numerator * b.m_denominator - b.m_numerator * a.m_denominator,
                    a.m_denominator * b.m_denominator);
    result.reduce();
    return result;
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    Fraction result(a.m_numerator * b.m_numerator, a.m_denominator * b.m_denominator);
    result.reduce();
    return result;
}

Fraction operator/(const Fraction& a, const Fraction& b) {
    Fraction result(a.m_numerator * b.m_denominator, a.m_denominator * b.m_numerator);
    result.reduce();
    return result;
}

bool operator==(const Fraction& a, const Fraction& b) {
    return a.m_numerator * b.m_denominator == b.m_numerator * a.m_denominator;
}

bool operator!=(const Fraction& a, const Fraction& b) {
    return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b) {
    return a.m_numerator * b.m_denominator < b.m_numerator * a.m_denominator;
}

bool operator>(const Fraction& a, const Fraction& b) {
    return b < a;
}

bool operator<=(const Fraction& a, const Fraction& b) {
    return !(b < a);
}

bool operator>=(const Fraction& a, const Fraction& b) {
    return !(a < b);
}

void swap(Fraction& a, Fraction& b) {
    using std::swap;
    swap(a.m_numerator, b.m_numerator);
    swap(a.m_denominator, b.m_denominator);
}

void print_fractions(const Fraction* fractions, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << fractions[i] << std::endl;
    }
}

void Fraction::reduce() {
    int gcd = 1;
    for (int i = 1; i <= m_numerator && i <= m_denominator; i++) {
        if (m_numerator % i == 0 && m_denominator % i == 0) {
            gcd = i;
        }
    }
    m_numerator /= gcd;
    m_denominator /= gcd;
}

int main(int argc, char** argv) {
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c = a + b;
    std::cout << c << std::endl;
    Fraction d = a - b;
    std::cout << d << std::endl;
    Fraction e = a * b;
    std::cout << e << std::endl;
    Fraction f = a / b;
    std::cout << f << std::endl;
    Fraction g(1, 2);
    Fraction h(1, 2);
    std::cout << (g == h) << std::endl;
    std::cout << (g != h) << std::endl;
    std::cout << (g < h) << std::endl;
    std::cout << (g > h) << std::endl;
    std::cout << (g <= h) << std::endl;
    std::cout << (g >= h) << std::endl;
    Fraction i(1, 2);
    Fraction j(1, 3);
    swap(i, j);
    std::cout << i << std::endl;
    std::cout << j << std::endl;
    Fraction k[3] = {Fraction(1, 2), Fraction(1, 3), Fraction(1, 4)};
    print_fractions(k, 3);
    return 0;
}