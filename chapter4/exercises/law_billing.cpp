/**
 * @file law_billing.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

const double RATE = 150.00;

int main(int argc, char const *argv[]); 
double fee(int hours, double rate = 150.00);

int main(int argc, char const *argv[])
{
    int hours, minutes; 
    double bill; 
    cout << "Welcome to the law office of\n";
    cout << "Dewey, Cheatem, and Howe.\n";
    cout << "Enter the number of minutes you worked.\n";
    cin >> minutes;
    hours = minutes / 60;
    bill = hours * RATE;
    cout << "You worked " << hours << " hours.\n";
    cout << "At $" << RATE << " per hour, your bill is $" << bill << endl;
    return 0;
}

double fee(int hours, double rate)
{
    return hours * rate;
}
