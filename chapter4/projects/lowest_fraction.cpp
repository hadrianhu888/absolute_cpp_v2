/**
 * @file lowest_fraction.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>

using namespace std;
using namespace std::chrono;

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

/**
 * @brief gets the numerator and denominator and returns the lowest fraction in fractional format 
 * 
 */

int numerator;
int denominator;
int gcd(int numerator, int denominator);
int main(int argc, char **argv);

int gcd(int numerator, int denominator)
{
    int gcd = 0;
    int remainder = 0;
    int numerator_temp = 0;
    int denominator_temp = 0;
    if (numerator > denominator)
    {
        numerator_temp = numerator;
        denominator_temp = denominator;
    }
    else
    {
        numerator_temp = denominator;
        denominator_temp = numerator;
    }
    remainder = numerator_temp % denominator_temp;
    while (remainder != 0)
    {
        numerator_temp = denominator_temp;
        denominator_temp = remainder;
        remainder = numerator_temp % denominator_temp;
    }
    gcd = denominator_temp;
    return gcd;
}

int main(int argc, char **argv)
{
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    cout << "The lowest fraction is: " << numerator / gcd(numerator, denominator) << "/" << denominator / gcd(numerator, denominator) << endl;
    return 0;
}