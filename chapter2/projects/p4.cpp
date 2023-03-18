/**
 * @file p4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <cmath> 

using namespace std; 

int initial = 0; 
int final = 0; 

bool checkPrime (int num); 
void printPrimeNumbersInRange(int start, int end); 

bool checkPrime(int num) {
    bool flag = true; 
    if ((num == 0) || (num == 1)) {
        flag = false; 
    } else {
        for (int i = 2; i < num; i++) {
            if(num % i == 0) {
                flag = false; 
                break; 
            }
        }
    }
     if (flag == true) {
        cout << num << " is a prime number." << endl; 
    } else {
        cout << num << " is not a prime number." << endl; 
    }
    return flag; 
}

void printPrimeNumbersInRange(int start, int end) {
    bool isPrime = true;
    for (int i = start; i < end; i++) {
        if (true == checkPrime(i)) { 
            cout << i << endl; 
        }
    }
}

int main(int argc, char ** argv) {
    /**
     * @brief get intial and final values for printing out primes 
     * 
     */
    cout << "Input initial and final values for printing primes: "; 
    cin >> initial; 
    cin >> final; 
    printPrimeNumbersInRange(initial, final); 
    return 0; 
}
