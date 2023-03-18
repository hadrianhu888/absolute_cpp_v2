/**
 * @file password_protection.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PASSWORD_PROTECTION_HPP
#define PASSWORD_PROTECTION_HPP

#ifdef __cplusplus

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <new>
#include <initializer_list>
#include <tuple>
#include <array>
#include <regex>
#include <chrono>
#include <random>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono; 

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::uniform_int_distribution<int> distribution(1,100);

extern string user_passcode;
extern string user_pin; 
extern string user_obfuscated_pin;
extern string user_obfuscated_passcode;
extern string user_passcode_confirmation;
extern string user_obfuscated_passcode_confirmation;
extern string user_name;
extern string user_email;
extern int user_pin_length;
extern string user_pin_confirmation;
extern string user_obfuscated_pin_confirmation;


void get_user_name(void);
void get_user_email(void);
void get_user_passcode(void);
void get_user_passcode_confirmation(void);
void obfuscate_passcode(void);
void obfuscate_passcode_confirmation(void);
void print_user_name(void);
void print_user_email(void);
void print_user_passcode(void);
void print_user_passcode_confirmation(void);
void print_user_obfuscated_passcode(void);
void print_user_obfuscated_passcode_confirmation(void);
void get_user_pin(void);
void get_user_pin_confirmation(void);
void obfuscate_pin(void);
void obfuscate_pin_confirmation(void);
void print_user_pin(void);
void print_user_pin_confirmation(void);
void print_user_obfuscated_pin(void);
void print_user_obfuscated_pin_confirmation(void);
void print_user_name_and_email(void);
void print_user_name_and_email_and_passcode(void);
void print_user_name_and_email_and_pin(void);
void print_user_name_and_email_and_pin_and_passcode(void);

/**
 * @brief function to randomly generate a challenge PIN that is different each time 
 * 
 */
int generate_challenge_pin_(void);
int get_pin_length(void);
string generate_challenge_pin(void);
string generate_challenge_passcode(void);
string generate_challenge_passcode_confirmation(void);
string generate_challenge_pin_confirmation(void);

int password_pin_protection_main(int argc, char **argv);
int main(int argc, char **argv);

#endif // __cplusplus
#endif // PASSWORD_PROTECTION_HPP