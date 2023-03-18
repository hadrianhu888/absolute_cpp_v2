/**
 * @file fraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Fraction
{
    public:
        Fraction creator(int newNumerator, int newDenominator);
        Fraction display_fraction();
        void setNumerator(int newNumerator);
        void setDenominator(int newDenominator);
        int getNumerator();
        int getDenominator();
        void lowest_terms();
        Fraction add(Fraction f2);
        Fraction subtract(Fraction f2);
        Fraction multiply(Fraction f2);
        Fraction divide(Fraction f2);
        float toDecimal();
        Fraction to_Mixed();
        void print();
        Fraction print_fraction(int numerator, int denominator);
        Fraction destructor();
    private:
        int numerator;
        int denominator;
        float decimal_form; 
};

int public_numerator; 
int public_denominator; 

int main(int argc,char **argv);

Fraction Fraction::creator(int newNumerator, int newDenominator)
{
    Fraction f;
    f.numerator = newNumerator;
    f.denominator = newDenominator;
    return f;
}
Fraction Fraction::display_fraction()
{
    Fraction f;
    f.numerator = public_numerator;
    f.denominator = public_denominator;
    return f;
}
void Fraction::setNumerator(int newNumerator)
{
    numerator = newNumerator;
}
void Fraction::setDenominator(int newDenominator)
{
    denominator = newDenominator;
}
int Fraction::getNumerator()
{
    return numerator;
}
int Fraction::getDenominator()
{
    return denominator;
}
void Fraction::lowest_terms()
{
    int gcd = 1;
    int j = min(numerator, denominator);
    for (int i = 1; i <= j; i++)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            gcd = i;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::add(Fraction f2)
{
    Fraction f3;
    f3.numerator = numerator * f2.denominator + denominator * f2.numerator;
    f3.denominator = denominator * f2.denominator;
    f3.lowest_terms();
    return f3;
}

Fraction Fraction::subtract(Fraction f2)
{
    Fraction f3;
    f3.numerator = numerator * f2.denominator - denominator * f2.numerator;
    f3.denominator = denominator * f2.denominator;
    f3.lowest_terms();
    return f3;
}

Fraction Fraction::multiply(Fraction f2)
{
    Fraction f3;
    f3.numerator = numerator * f2.numerator;
    f3.denominator = denominator * f2.denominator;
    f3.lowest_terms();
    return f3;
}

Fraction Fraction::divide(Fraction f2)
{
    Fraction f3;
    f3.numerator = numerator * f2.denominator;
    f3.denominator = denominator * f2.numerator;
    f3.lowest_terms();
    return f3;
}

float Fraction::toDecimal()
{
    decimal_form = (float)numerator / denominator;
    return decimal_form;
}

Fraction Fraction::to_Mixed()
{
    Fraction f;
    f.numerator = numerator / denominator;
    f.denominator = numerator % denominator;
    return f;
}

void Fraction::print() {
  cout << numerator << "/" << denominator << endl;
} 
Fraction Fraction::destructor()
{
    Fraction f;
    f.numerator = 0;
    f.denominator = 0;
    return f;
}

Fraction Fraction::print_fraction(int numerator, int denominator)
{
    Fraction f;
    f.numerator = numerator;
    f.denominator = denominator;
    cout << f.numerator << "/" << f.denominator << endl;
    return f;
}

int main(int argc,char **argv)
{
    Fraction f1, f2, f3;
    f1.creator(1, 2);
    f2.creator(1, 4);
    f3 = f1.add(f2);
    f3.print();
    f3 = f1.subtract(f2);
    f3.print();
    f3 = f1.multiply(f2);
    f3.print();
    f3 = f1.divide(f2);
    f3.print();
    f3.toDecimal();
    cout << f3.toDecimal() << endl;
    f3 = f3.to_Mixed();
    f3.print();
    f3.destructor();
    f3.print();
    return 0;
}