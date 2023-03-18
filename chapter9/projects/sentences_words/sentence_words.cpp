/**
 * @file sentence_words.cpp
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
int count_words(string &str);
int count_letters(string &str);
int count_punctuation(string &str);
int count_spaces(string &str);
int *letter_frequency(string &str);
int *word_frequency(string &str);
int *punctuation_frequency(string &str);
void print_letter_frequency(int *arr);
void print_word_frequency(string &str);
void print_punctuation_frequency(int *arr);
void display_letter_frequency_graph(int *arr);
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

int count_words(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_letters(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

int count_punctuation(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int count_spaces(string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int *letter_frequency(string &str)
{
    int *arr = new int[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            arr[str[i] - 97]++;
        }
    }
    return arr;
}

int *word_frequency(string &str)
{
    int *arr = new int[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            arr[str[i] - 97]++;
        }
    }
    return arr;
}

int *punctuation_frequency(string &str)
{
    int *arr = new int[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
        {
            arr[str[i] - 97]++;
        }
    }
    return arr;
}

void print_letter_frequency(int *arr)
{
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 97) << " : " << arr[i] << endl;
    }
}

void print_word_frequency(string &str)
{
    int *arr = new int[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            arr[str[i] - 97]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 97) << " : " << arr[i] << endl;
    }
}

void print_punctuation_frequency(int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        cout << (char)(i + 97) << " : " << arr[i] << endl;
    }
}

void display_letter_frequency_graph(int *arr)
{
    /**
     * @brief only display letters that exist in the text string from the user. Discard those that are not in the string. 
     * 
     */
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            cout << (char)(i + 97) << " : ";
            for (int j = 0; j < arr[i]; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}

int main(int argc, char **argv)
{
    string str;
    get_string(str);
    cout << "Number of words: " << count_words(str) << endl;
    cout << "Number of letters: " << count_letters(str) << endl;
    cout << "Number of punctuation: " << count_punctuation(str) << endl;
    cout << "Number of spaces: " << count_spaces(str) << endl;
    cout << "Letter frequency: " << endl;
    print_letter_frequency(letter_frequency(str));
    cout << "Word frequency: " << endl;
    print_word_frequency(str);
    cout << "Punctuation frequency: " << endl;
    print_punctuation_frequency(punctuation_frequency(str));
    cout << "Letter frequency graph: " << endl;
    display_letter_frequency_graph(letter_frequency(str));
    return 0;
}

