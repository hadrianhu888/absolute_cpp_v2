/**
 * @file gender_neutral.cpp
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
string **replace_sexist_words = new string *[2]; // array of words to replace

void get_text(string &str);
void print_text(string &str);
int check_text_length(string &str);
string replace_sexist_phrases(string &str);
string replacement_string(string &str);
void print_replacement_string(string &str);
string find_sexist_words(string &str);
string capitalize_first_letter_in_string(string &str);
string check_capitalization_of_new_sentences(string &str);
string preserveCapitalizationAfterPeriod(string &str);
string search_gender_words(string &str);
string replace_gendered_words(string &str);
int main(int argc, char **argv);

void get_text(string &str)
{
    cout << "Enter a string: ";
    getline(cin, str);
}

string search_gender_words(string &str)
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
            if (word == "he" || word == "He")
            {
                new_str += "they ";
            }
            else if (word == "she" || word == "She")
            {
                new_str += "they ";
            }
            else if (word == "him" || word == "Him")
            {
                new_str += "them ";
            }
            else if (word == "her" || word == "Her")
            {
                new_str += "them ";
            }
            else if (word == "woman" || word == "man")
            {
                new_str += "person ";
            }
            else
            {
                new_str += word + " ";
            }
            word = "";
        }
    }
    return new_str;
}

string replace_gendered_words(string &str)
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
            if (word == "he" || word == "He")
            {
                new_str += "they ";
            }
            else if (word == "she" || word == "She")
            {
                new_str += "they ";
            }
            else if (word == "him" || word == "Him")
            {
                new_str += "them ";
            }
            else if (word == "her" || word == "Her")
            {
                new_str += "them ";
            }
            else if (word == "woman" || word == "man")
            {
                new_str += "person ";
            }
            else
            {
                new_str += word + " ";
            }
            word = "";
        }
    }
    return new_str;
}

string preserveCapitalizationAfterPeriod(string &str)
{
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            new_str += str[i];
            new_str += toupper(str[i + 1]);
        }
        else
        {
            new_str += str[i];
        }
    }
    return new_str;
}

void print_text(string &str)
{
    cout << "The text is: " << str << endl;
}

int check_text_length(string &str)
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
    return count + 1;
}

string replace_sexist_phrases(string &str)
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
            if (word == "he" || word == "He")
            {
                new_str += "they ";
            }
            else if (word == "she" || word == "She")
            {
                new_str += "they ";
            }
            else if (word == "him" || word == "Him")
            {
                new_str += "them ";
            }
            else if (word == "her" || word == "Her")
            {
                new_str += "them ";
            }
            else if (word == "woman" || word == "man")
            {
                new_str += "person ";
            }
            else
            {
                new_str += word + " ";
            }
            word = "";
        }
    }
    return new_str;
}

string replacement_string(string &str)
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
            if (word == "he" || word == "He")
            {
                new_str += "they ";
            }
            else if (word == "she" || word == "She")
            {
                new_str += "they ";
            }
            else if (word == "him" || word == "Him")
            {
                new_str += "them ";
            }
            else if (word == "her" || word == "Her")
            {
                new_str += "them ";
            }
            else if (word == "woman" || word == "man")
            {
                new_str += "person ";
            }
            else
            {
                new_str += word + " ";
            }
            word = "";
        }
    }
    return new_str;
}

string find_sexist_words(string &str)
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
            if (word == "he" || word == "He")
            {
                new_str += "they ";
            }
            else if (word == "she" || word == "She")
            {
                new_str += "they ";
            }
            else if (word == "him" || word == "Him")
            {
                new_str += "them ";
            }
            else if (word == "her" || word == "Her")
            {
                new_str += "them ";
            }
            else if (word == "woman" || word == "man")
            {
                new_str += "person ";
            }
            else
            {
                new_str += word + " ";
            }
            word = "";
        }
    }
    return new_str;
}


string capitalize_first_letter_in_string(string &str)
{
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            new_str += toupper(str[i]);
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
}

string check_capitalization_of_new_sentences(string &str)
{
    string new_str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            new_str += str[i];
            new_str += toupper(str[i + 1]);
        }
        else
        {
            new_str += str[i];
        }
    }
    return new_str;
}

int main(int argc, char **argv)
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    print_text(str);
    check_text_length(str);
    /**
     * @brief find and replace gendered words. 
     * Capitalize the first letter of each new sentence. 
     * 
     */
    string new_str = replace_sexist_phrases(str);
    new_str = capitalize_first_letter_in_string(new_str);
    new_str = check_capitalization_of_new_sentences(new_str);
    print_replacement_string(new_str);
    return 0;
}


