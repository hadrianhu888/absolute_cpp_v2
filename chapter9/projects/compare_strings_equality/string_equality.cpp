/**
 * @file string_equality.cpp
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
bool is_equal_strings(string &str1, string &str2);
bool is_equal_strings_ignore_case(string &str1, string &str2);
bool is_equal_strings_ignore_case_and_punctuation(string &str1, string &str2);

int main(int argc, char **argv)
{
    string str1, str2;
    read_string(str1);
    read_string(str2);
    if (is_equal_strings(str1, str2))
    {
        cout << "The strings are equal." << endl;
    }
    else
    {
        cout << "The strings are not equal." << endl;
    }
    if (is_equal_strings_ignore_case(str1, str2))
    {
        cout << "The strings are equal, ignoring case." << endl;
    }
    else
    {
        cout << "The strings are not equal, ignoring case." << endl;
    }
    if (is_equal_strings_ignore_case_and_punctuation(str1, str2))
    {
        cout << "The strings are equal, ignoring case and punctuation." << endl;
    }
    else
    {
        cout << "The strings are not equal, ignoring case and punctuation." << endl;
    }
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

bool is_equal_strings(string &str1, string &str2)
{
    return str1 == str2;
}

bool is_equal_strings_ignore_case(string &str1, string &str2)
{
    string str1_lower, str2_lower;
    str1_lower = str1;
    str2_lower = str2;
    for (int i = 0; i < str1.length(); i++)
    {
        str1_lower[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.length(); i++)
    {
        str2_lower[i] = tolower(str2[i]);
    }
    return str1_lower == str2_lower;
}

bool is_equal_strings_ignore_case_and_punctuation(string &str1, string &str2)
{
    string str1_lower, str2_lower;
    str1_lower = str1;
    str2_lower = str2;
    for (int i = 0; i < str1.length(); i++)
    {
        str1_lower[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.length(); i++)
    {
        str2_lower[i] = tolower(str2[i]);
    }
    for (int i = 0; i < str1_lower.length(); i++)
    {
        if (ispunct(str1_lower[i]))
        {
            str1_lower.erase(i, 1);
        }
    }
    for (int i = 0; i < str2_lower.length(); i++)
    {
        if (ispunct(str2_lower[i]))
        {
            str2_lower.erase(i, 1);
        }
    }
    return str1_lower == str2_lower;
}

/**
 * @brief 
 * 
 */

// Path: chapter9\projects\compare_strings_equality\string_equality.cpp