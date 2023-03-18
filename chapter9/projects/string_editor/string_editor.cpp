/**
 * @file string_editor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

using namespace std;

void get_string(string &str);
void find_string_errors(string &str);
void correct_string_errors(string &str);
void make_lower_case_other_than_first_letter(string &str);
void remove_extra_spaces(string &str);
void remove_extra_punctuation(string &str);
void check_sentence_end_period(string &str);
int main(int argc, char **argv); 

/**
 * @brief create functions to read a string from the user,
 * correct any excessive spaces, and make sure the english grammar and capitalization are correct.
 */

void get_string(string &str)
{
    cout << "Enter a string: ";
    getline(cin, str);
}

void find_string_errors(string &str)
{
    // find excessive spaces
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i, 1);
            i--;
        }
    }

    // find capitalization errors
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        else if (str[i] == '.' && str[i + 2] >= 'a' && str[i + 2] <= 'z')
        {
            str[i + 2] = str[i + 2] - 32;
        }
    }
}

void correct_string_errors(string &str)
{
    find_string_errors(str);
    make_lower_case_other_than_first_letter(str);
    remove_extra_punctuation(str);
    check_sentence_end_period(str);
    remove_extra_spaces(str);
}

void make_lower_case_other_than_first_letter(string &str)
{
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

void remove_extra_spaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i, 1);
            i--;
        }
    }
}

void remove_extra_punctuation(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.' && str[i + 1] == '.')
        {
            str.erase(i, 1);
            i--;
        }
    }
}

void check_sentence_end_period(string &str)
{
    if (str[str.length() - 1] != '.')
    {
        str += '.';
    }
}

int main(int argc, char **argv)
{
    string str;
    get_string(str);
    correct_string_errors(str);
    cout << "The corrected string is: " << str << endl;
    return 0;
}