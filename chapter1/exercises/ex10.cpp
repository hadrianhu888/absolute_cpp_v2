/**
 * @file ex10.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cstdio> 

using namespace std; 

int main(int argc, char ** argv) {
    double value = 0.0; 
    cout <<  "Enter a number: "; 
    cin >> value; 
    printf("The number is %.3f\n\n", value);
    value = value; 
    cout << "The number is " << cout.precision(3) << value << endl; 
    return 0;
}

