/**
 * @file triangle_area.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "triangle_area.hpp"

double get_parameter_a(double a)
{
    return a;
}

double get_parameter_b(double b)
{
    return b;
}

double get_parameter_c(double c)
{
    return c;
}

void set_parameters(double a, double b, double c) {
    double parameter = 0;
    /**
    * @brief get each parameter by name from the user - a, b, c
    *
    */
    cout << "Enter the parameter a: ";
    cin >> a;
    cout << "Enter the parameter b: ";
    cin >> b;
    cout << "Enter the parameter c: ";
    cin >> c;
}

double get_semi_perimeter(double a, double b, double c)
{
    double s = 0;
    s = (a + b + c) / 2;
    return s;
}

double set_semi_perimeter(double s)
{
    return s;
}

double get_area(double s, double a, double b, double c)
{
    double area = 0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

void print_area(double area)
{
    cout << "The area of the triangle is: " << area << endl;
}

void print_semi_perimeter(double s)
{
    cout << "The semi-perimeter of the triangle is: " << s << endl;
}

void print_parameters(double a, double b, double c)
{
    cout << "The parameters of the triangle are: " << a << ", " << b << ", " << c << endl;
}

int main(int argc, char** argv)
{
    double a, b, c, s, area; 
    set_parameters(a, b, c);
    s = get_semi_perimeter(a, b, c);
    area = get_area(s, a, b, c);
    print_parameters(a, b, c);
    print_semi_perimeter(s);
    print_area(area);
    return 0;
}