/**
 * @file pin_protection.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pin_protection.hpp"

string PIN; 
int *pin; 
int *randomized_int_pin; 
int pin_length; 

int string2int(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

string int2string(int num) {
    string str = "";
    while (num > 0) {
        str = (char)(num % 10 + '0') + str;
        num /= 10;
    }
    return str;
}

string obfuscate_pin(string pin) {
    string obfuscated_pin = "";
    for (int i = 0; i < pin.length(); i++) {
        obfuscated_pin += int2string(distribution(generator));
    }
    return obfuscated_pin;
}

string deobfuscate_pin(string pin) {
    string deobfuscated_pin = "";
    for (int i = 0; i < pin.length(); i++) {
        deobfuscated_pin += int2string(pin[i] - '0');
    }
    return deobfuscated_pin;
}

void randomize_int_pin(int *pin) {
    for (int i = 0; i < PIN.length(); i++) {
        pin[i] = distribution(generator);
    }
}

int main_pin(int argc,char **argv) {
    cout << "Enter your PIN: ";
    cin >> PIN;
    pin_length = PIN.length();
    pin = new int[pin_length];
    randomized_int_pin = new int[pin_length];
    randomize_int_pin(pin);
    randomize_int_pin(randomized_int_pin);
    cout << "Your PIN is: " << PIN << endl;
    cout << "Your obfuscated PIN is: " << obfuscate_pin(PIN) << endl;
    cout << "Your deobfuscated PIN is: " << deobfuscate_pin(obfuscate_pin(PIN)) << endl;
    cout << "Your randomized PIN is: ";
    for (int i = 0; i < pin_length; i++) {
        cout << pin[i];
    }
    cout << endl;
    cout << "Your randomized PIN is: ";
    for (int i = 0; i < pin_length; i++) {
        cout << randomized_int_pin[i];
    }
    cout << endl;
    return 0;
}

// Path: chapter5\projects\pin_protection\pin_protection.hpp

