/**
 * @file four_letter_word.cpp
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

string text; // text to be read from command line
string replacement_word = "love"; // word to replace four letter words with

void get_text(string &str);
void print_text(string &str);
void check_word_length(string &str);
string replace_four_letter_words(string &str);
string replacement_string(string &str);
void print_replacement_string(string &str);
string capitalize_first_letter_in_string(string &str);
int main(int argc, char **argv);

void get_text(string &str)
{
    cout << "Enter a string: ";
    getline(cin, str);
}

void print_text(string &str)
{
    cout << "The text is: " << str << endl;
}

void check_word_length(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    cout << "The number of words in the text is: " << count + 1 << endl;
}

string replace_four_letter_words(string &str)
{
    string word;
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            word += str[i];
        }
        else
        {
            if (word.length() == 4)
            {
                new_str += replacement_word;
                new_str += ' ';
            }
            else
            {
                new_str += word;
                new_str += ' ';
            }
            word = "";
        }
    }
    if (word.length() == 4)
    {
        new_str += replacement_word;
    }
    else
    {
        new_str += word;
    }
    return new_str;
}

string replacement_string(string &str)
{
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            new_str += replacement_word;
            new_str += ' ';
        }
        else
        {
            new_str += str[i];
        }
    }
    return new_str;
}

void print_replacement_string(string &str)
{
    cout << "The replacement string is: " << str << endl;
    cout << "The replacement string with first letter capitalized is: " << capitalize_first_letter_in_string(str) << endl;
}

string capitalize_first_letter_in_string(string &str)
{
    string new_str;
    new_str += toupper(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        new_str += str[i];
    }
    return new_str;
}

int main(int argc, char **argv)
{
    get_text(text);
    print_text(text);
    check_word_length(text);
    text = replace_four_letter_words(text);
    print_replacement_string(text);
    return 0;
}

