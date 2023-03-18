/**
 * @file triangle_area.hpp
 * @author Hadrian Hu (hadrian.hu@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TRIANGLE_AREA_HPP
#define TRIANGLE_AREA_HPP

#ifdef __cplusplus

#include <iostream> // for cin and cout
#include <cstdlib> // for atoi
#include <cmath> // for pow
#include <cassert> // for assert
#include <cmath> // for pow
#include <ccomplex> // for complex

using namespace std;

double get_parameter_a(double a);
double get_parameter_b(double b);
double get_parameter_c(double c);
void set_parameters(double a, double b, double c);
double get_semi_perimeter(double a, double b, double c);
double set_semi_perimeter(double s);
double get_area(double s, double a, double b, double c);
void print_area(double area);
void print_semi_perimeter(double s);
void print_parameters(double a, double b, double c);
int main(int argc, char** argv);

#endif 
#endif 