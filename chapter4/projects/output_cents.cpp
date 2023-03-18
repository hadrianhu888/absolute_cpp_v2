/**
 * @file output_cents.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "output_cents.hpp"

/**
 * @brief minimize the amount of each coin denomination used. 
 * 
 * @param coinValue 
 * @param number 
 * @param amountLeft 
 */

void computeCoin(int coinValue, int& number, int &amountLeft) {
    number = amountLeft / coinValue;
    amountLeft = amountLeft % coinValue;
}

void outputCents(int cents) {
    int pennies, dimes, quarters;
    computeCoin(25, quarters, cents);
    computeCoin(10, dimes, cents);
    computeCoin(1, pennies, cents);
    outputQuarters(quarters);
    outputDimes(dimes);
    outputPennies(pennies);
}

void outputDimes(int dimes) {
    cout << dimes << " dimes" << endl;
}

void outputPennies(int pennies) {
    cout << pennies << " pennies" << endl;
}

void outputQuarters(int quarters) {
    cout << quarters << " quarters" << endl;
}

bool check_input_less_than_100(int cents) {
    bool result = false;
    if (cents > 0 && cents < 100) {
        result = true;
    } else {
        result = false;
    }
    return result; 
}

int main(int argc, char const *argv[]) {
    /**
    * @brief use a loop to continue to ask the user for input until the user
    * enters a value of 0 or less. Also checks if the amount is within 0 < cents < 100
    *
    */
    int cents;
    while (true) {
        cout << "Enter an amount in cents less than a dollar." << endl;
        cin >> cents;
        if (check_input_less_than_100(cents)) {
            outputCents(cents);
        } else {
            cout << "The amount must be between 0 and 100, inclusive." << endl;
        }
        if (cents <= 0) break;
        cout << endl;
    }
    return 0;
}

