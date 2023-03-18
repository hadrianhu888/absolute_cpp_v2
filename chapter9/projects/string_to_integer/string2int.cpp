/**
 * @file string2int.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

using namespace std;

int main(int argc, char **argv);

void read_string(string &str);
void print_string(string &str);
int convert_to_integer(string &str);

int main(int argc, char **argv)
{
    string str;
    read_string(str);
    print_string(str);
    cout << "The string converted to an integer is: " << convert_to_integer(str) << endl;
    return 0;
}

void read_string(string &str)
{
    cout << "Enter a string: ";
    getline(cin, str);
}

void print_string(string &str)
{
    cout << "The string is: " << str << endl;
}

int convert_to_integer(string &str)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

