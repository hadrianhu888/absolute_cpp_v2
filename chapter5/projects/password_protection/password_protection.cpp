/**
 * @file password_protection.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "password_protection.hpp"
/**
 * @brief import password_protection.hpp variables 
 * 
 */

using namespace std;
using namespace std::chrono;

string user_passcode;
string user_pin;
string user_obfuscated_pin;
string user_obfuscated_passcode;
string challenge_pin; 
string challenge_passcode;
string challenge_obfuscated_pin;
string challenge_obfuscated_passcode;


/**
 * @brief define and implement prototyped functions
 * 
*/ 

int get_pin_length(void)
{
    return user_pin.length();
}

int user_passcode_length(void)
{
    return user_passcode.length();
}

/**
 * @brief define and implement prototyped functions
 * 
 */

void get_user_passcode(void)
{
    cout << "Enter your passcode: ";
    cin >> user_passcode;
    cout << "Your passcode is: " << user_passcode << endl;
}

void get_user_pin(void)
{
    cout << "Enter your pin: ";
    cin >> user_pin;
    cout << "Your pin is: " << user_pin << endl;
}

void obfuscate_user_pin(void)
{
    user_obfuscated_pin = user_pin;
    for (int i = 0; i < user_obfuscated_pin.length(); i++)
    {
        user_obfuscated_pin[i] = '*';
    }
    cout << "Your obfuscated pin is: " << user_obfuscated_pin << endl;
}

void obfuscate_user_passcode(void)
{
    user_obfuscated_passcode = user_passcode;
    for (int i = 0; i < user_obfuscated_passcode.length(); i++)
    {
        user_obfuscated_passcode[i] = '*';
    }
    cout << "Your obfuscated passcode is: " << user_obfuscated_passcode << endl;
}

void print_user_pin(void)
{
    cout << "Your pin is: " << user_pin << endl;
}

void print_user_passcode(void)
{
    cout << "Your passcode is: " << user_passcode << endl;
}

void print_user_obfuscated_pin(void)
{
    cout << "Your obfuscated pin is: " << user_obfuscated_pin << endl;
}

void print_user_obfuscated_passcode(void)
{
    cout << "Your obfuscated passcode is: " << user_obfuscated_passcode << endl;
}

void print_user_obfuscated_pin_and_passcode(void)
{
    cout << "Your obfuscated pin is: " << user_obfuscated_pin << endl;
    cout << "Your obfuscated passcode is: " << user_obfuscated_passcode << endl;
}

void print_user_pin_and_passcode(void)
{
    cout << "Your pin is: " << user_pin << endl;
    cout << "Your passcode is: " << user_passcode << endl;
}

void print_user_obfuscated_pin_and_passcode_and_clear(void)
{
    cout << "Your obfuscated pin is: " << user_obfuscated_pin << endl;
    cout << "Your obfuscated passcode is: " << user_obfuscated_passcode << endl;
    user_obfuscated_pin.clear();
    user_obfuscated_passcode.clear();
}

void print_user_pin_and_passcode_and_clear(void)
{
    cout << "Your pin is: " << user_pin << endl;
    cout << "Your passcode is: " << user_passcode << endl;
    user_pin.clear();
    user_passcode.clear();
}

void print_user_obfuscated_pin_and_passcode_and_clear_and_exit(void)
{
    cout << "Your obfuscated pin is: " << user_obfuscated_pin << endl;
    cout << "Your obfuscated passcode is: " << user_obfuscated_passcode << endl;
    user_obfuscated_pin.clear();
    user_obfuscated_passcode.clear();
    exit(0);
}

int generate_challenge_pin_(void)
{
    srand(time(0));
    int challenge_pin = rand() % 10000;
    return challenge_pin;
}

int generate_challenge_passcode_(void)
{
    srand(time(0));
    int challenge_passcode = rand() % 10000;
    return challenge_passcode;
}

void print_challenge_pin_(void)
{
    cout << "Your challenge pin is: " << challenge_pin << endl;
}

void print_challenge_passcode_(void)
{
    cout << "Your challenge passcode is: " << challenge_passcode << endl;
}

string generate_challenge_pin(void)
{
    srand(time(0));
    int challenge_pin = rand() % 10000;
    string challenge_pin_string = to_string(challenge_pin);
    return challenge_pin_string;
}
string generate_challenge_passcode(void)
{
    srand(time(0));
    int challenge_passcode = rand() % 10000;
    string challenge_passcode_string = to_string(challenge_passcode);
    return challenge_passcode_string;
}
string generate_challenge_passcode_confirmation(void)
{
    srand(time(0));
    int challenge_passcode = rand() % 10000;
    string challenge_passcode_string = to_string(challenge_passcode);
    return challenge_passcode_string;
}
string generate_challenge_pin_confirmation(void)
{
    srand(time(0));
    int challenge_pin = rand() % 10000;
    string challenge_pin_string = to_string(challenge_pin);
    return challenge_pin_string;
}

int password_pin_protection_main(int argc, char **argv)
{
    cout << "Welcome to the password and pin protection program" << endl;
    cout << "Please enter your pin and passcode" << endl;
    get_user_pin();
    get_user_passcode();
    obfuscate_user_pin();
    obfuscate_user_passcode();
    print_user_obfuscated_pin_and_passcode();
    print_user_obfuscated_pin_and_passcode_and_clear();
    print_user_obfuscated_pin_and_passcode_and_clear_and_exit();
    return 0;
}

int main(int argc, char **argv)
{
    cout << "Welcome to the password and pin protection program" << endl;
    cout << "Please enter your pin and passcode" << endl;
    get_user_pin();
    get_user_passcode();
    obfuscate_user_pin();
    obfuscate_user_passcode();
    print_user_obfuscated_pin_and_passcode();
    print_user_obfuscated_pin_and_passcode_and_clear();
    print_user_obfuscated_pin_and_passcode_and_clear_and_exit();
    return 0;
}

