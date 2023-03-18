/**
 * @file pig_latin.cpp
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
bool contains_pig_latin(string &str);
string convert_to_pig_latin(string &str);
string convert_to_english(string &str);
bool is_vowel(char ch);
bool is_end_of_sentence(char ch);

int main(int argc, char **argv)
{
    string str;
    read_string(str);
    print_string(str);
    if (contains_pig_latin(str))
    {
        cout << "The string contains pig latin." << endl;
        cout << "Converting to English..." << endl;
        convert_to_english(str);
        print_string(str);
    }
    else
    {
        cout << "The string does not contain pig latin." << endl;
        cout << "Converting to pig latin..." << endl;
        convert_to_pig_latin(str);
        print_string(str);
    }
    /**
     * @brief check end of sentence condition
     * 
     */
    if (is_end_of_sentence(str[str.length() - 1]))
    {
        cout << "The string ends with a sentence terminator." << endl;
    }
    else
    {
        cout << "The string does not end with a sentence terminator." << endl;
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

bool contains_pig_latin(string &str)
{
    return false;
}

string convert_to_pig_latin(string &str)
{
    /**
     * @brief move consonants to the end of the word
     * 
     */
    if (is_vowel(str[0]))
    {
        str += "way";
    }
    else
    {
        str += str[0];
        str += "ay";
        str.erase(0, 1);
    }
    return str;
}

string convert_to_english(string &str)
{
    return str;
}

bool is_vowel(char ch)
{
    return false;
}

bool is_end_of_sentence(char ch)
{
    return false;
}

// Path: chapter9\projects\pig_latin\pig_latin.cpp