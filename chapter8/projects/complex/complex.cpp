/**
 * @file complex.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Complex 
{
    private: 
        double real;
        double imaginary;
        const int complex = 1;
    public: 
        Complex();
        Complex(double real, double imaginary);
        ~Complex();
        double get_real();
        double get_imaginary();
        void set_real(double real);
        void set_imaginary(double imaginary);
        void input();
        void output();
        void print();
        Complex conjugate();
        friend Complex operator+(Complex c1, Complex c2);
        friend Complex operator-(Complex c1, Complex c2);
        friend Complex operator*(Complex c1, Complex c2);
        friend Complex operator/(Complex c1, Complex c2);
        friend bool operator==(Complex c1, Complex c2);
        friend bool operator!=(Complex c1, Complex c2);
        friend bool operator<(Complex c1, Complex c2);
        friend bool operator<=(Complex c1, Complex c2);
        friend bool operator>(Complex c1, Complex c2);
        friend bool operator>=(Complex c1, Complex c2);
        friend ostream& operator<<(ostream& out, Complex c);
        friend istream& operator>>(istream& in, Complex& c);
        friend Complex operator+=(Complex& c1, Complex c2);
        friend Complex operator-=(Complex& c1, Complex c2);
        friend Complex operator++(Complex& c);
        friend Complex operator++(Complex& c, int);
        friend Complex operator--(Complex& c);
        friend Complex operator--(Complex& c, int);
        Complex operator=(Complex c);
        Complex operator/=(Complex c);
        Complex operator*=(Complex c);
        Complex operator%=(Complex c);
};

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

Complex::Complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex()
{
}

Complex Complex::conjugate()
{
    Complex c;
    c.real = real;
    c.imaginary = -imaginary;
    return c;
}

double Complex::get_real()
{
    return real;
}

double Complex::get_imaginary()
{
    return imaginary;
}

void Complex::set_real(double real)
{
    this->real = real;
}

void Complex::set_imaginary(double imaginary)
{
    this->imaginary = imaginary;
}

void Complex::input()
{
    cout << "Enter the real part: ";
    cin >> real;
    cout << "Enter the imaginary part: ";
    cin >> imaginary;
}

void Complex::output()
{
    cout << real << " + " << imaginary << "i" << endl;
}

void Complex::print()
{
    cout << "Real: " << real << endl;
    cout << "Imaginary: " << imaginary << endl;
}

Complex operator+(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;
    return c;
}

Complex operator-(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real - c2.real;
    c.imaginary = c1.imaginary - c2.imaginary;
    return c;
}

Complex operator*(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real * c2.real;
    c.imaginary = c1.imaginary * c2.imaginary;
    return c;
}

Complex operator/(Complex c1, Complex c2)
{
    Complex c;
    c.real = c1.real / c2.real;
    c.imaginary = c1.imaginary / c2.imaginary;
    return c;
}

bool operator==(Complex c1, Complex c2)
{
    return (c1.real == c2.real && c1.imaginary == c2.imaginary);
}

bool operator!=(Complex c1, Complex c2)
{
    return !(c1 == c2);
}

bool operator<(Complex c1, Complex c2)
{
    return (c1.real < c2.real && c1.imaginary < c2.imaginary);
}

bool operator<=(Complex c1, Complex c2)
{
    return (c1.real <= c2.real && c1.imaginary <= c2.imaginary);
}

bool operator>(Complex c1, Complex c2)
{
    return (c1.real > c2.real && c1.imaginary > c2.imaginary);
}

bool operator>=(Complex c1, Complex c2)
{
    return (c1.real >= c2.real && c1.imaginary >= c2.imaginary);
}

ostream& operator<<(ostream& out, Complex c)
{
    out << c.real << " + " << c.imaginary << "i" << endl;
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.real >> c.imaginary;
    return in;
}

Complex operator+=(Complex& c1, Complex c2)
{
    c1.real += c2.real;
    c1.imaginary += c2.imaginary;
    return c1;
}

Complex operator-=(Complex& c1, Complex c2)
{
    c1.real -= c2.real;
    c1.imaginary -= c2.imaginary;
    return c1;
}

Complex operator++(Complex& c)
{
    c.real++;
    c.imaginary++;
    return c;
}

Complex operator++(Complex& c, int)
{
    Complex temp = c;
    c.real++;
    c.imaginary++;
    return temp;
}

Complex operator--(Complex& c)
{
    c.real--;
    c.imaginary--;
    return c;
}

Complex operator--(Complex& c, int)
{
    Complex temp = c;
    c.real--;
    c.imaginary--;
    return temp;
}

Complex Complex::operator=(Complex c)
{
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}

Complex Complex::operator/=(Complex c)
{
    real /= c.real;
    imaginary /= c.imaginary;
    return *this;
}

Complex Complex::operator*=(Complex c)
{
    real *= c.real;
    imaginary *= c.imaginary;
    return *this;
}

int main(int argc, char **argv)
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3;
    Complex c4; 
    c3 = c1 + c2;
    c3.output();
    c3 = c1 - c2;
    c3.output();
    if (c1 == c2)
    {
        cout << "c1 and c2 are equal" << endl;
    }
    else
    {
        cout << "c1 and c2 are not equal" << endl;
    }
    if (c1 != c2)
    {
        cout << "c1 and c2 are not equal" << endl;
    }
    else
    {
        cout << "c1 and c2 are equal" << endl;
    }
    if (c1 < c2)
    {
        cout << "c1 is less than c2" << endl;
    }
    else
    {
        cout << "c1 is not less than c2" << endl;
    }
    if (c1 <= c2)
    {
        cout << "c1 is less than or equal to c2" << endl;
    }
    else
    {
        cout << "c1 is not less than or equal to c2" << endl;
    }
    if (c1 > c2)
    {
        cout << "c1 is greater than c2" << endl;
    }
    else
    {
        cout << "c1 is not greater than c2" << endl;
    }
    if (c1 >= c2)
    {
        cout << "c1 is greater than or equal to c2" << endl;
    }
    else
    {
        cout << "c1 is not greater than or equal to c2" << endl;
    }
    cout << c1;
    cout << c2;
    cout << c1;
    ++c1;
    cout << c1;
    c1++;
    cout << c1;
    --c1;
    cout << c1;
    c1--;
    cout << c1;
    c1 += c2;
    cout << c1;
    c1 -= c2;
    cout << c1;
    c1 *= c2;
    cout << c1;
    c1 /= c2;
    cout << c1;
    c3 = c1 * c2;
    c4 = c1 / c2;
    cout << c3; 
    cout << c4;
    /**
     * @brief test conjugate
     * 
     */
    c1.conjugate();
    cout << c1.conjugate() << endl;
    return 0;
}

