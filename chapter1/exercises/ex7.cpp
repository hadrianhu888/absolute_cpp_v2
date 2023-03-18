/**
 * @file ex7.cpp
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
    /**
     * @brief 
     * 
     */
    double c = 20; 
    double f = 0; 
    /**
     * @brief the original output before the corrections to syntax
     * 
     */
    f = (9/5)*c+32.0; 
    cout << f << endl; 
    /**
     * @brief the intended program output after the corrections to syntax
     * 
     */
    f = ((9/5)+c)+32.0; 
    cout << f << endl; 
    return 0;
    /**
     * @brief f = 52
     * the multiplication takes place first, then the addition 
     * 
     */
}

