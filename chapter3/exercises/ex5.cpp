/**
 * @file ex5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath>
#include <cstring>

using namespace std; 

int SumThreeNumbers(int a, int b, int c); 
char ReturnPOrN(double num); 

int SumThreeNumbers (int a, int b, int c) {
    return (a + b + c); 
}

char ReturnPOrN(double num) {
    if (num >= 0) {
        return 'P'; 
    } else {
        return 'N';
    }
}

int main(int argc, char ** argv) {
    cout << SumThreeNumbers(1,2,3) << endl; 
    cout << ReturnPOrN(-1) << endl; 
    cout << ReturnPOrN(1) << endl; 
    /**
     * @brief another function call can exist inside another function 
     * self-defined or user-defined functions normally require a header file and source file before it can be called. 
     * The predefined functions just need to call the proper header files or hpp files.
     */
    return 0;
}
