/**
 * @file string_anagrams.cpp
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
bool is_anagram(string &str1, string &str2);

int main(int argc, char **argv)
{
    string str1, str2;
    read_string(str1);
    read_string(str2);
    if (is_anagram(str1, str2))
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
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

bool is_anagram(string &str1, string &str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[str2.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

