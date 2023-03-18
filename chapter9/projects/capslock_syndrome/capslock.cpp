/**
 * @file capslock.cpp
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
bool contains_capslock_syndrome(string &str);
string correct_capslock_syndrome(string &str);
string capitalize_start_of_first_word_of_each_sentence(string &str);
bool is_end_of_sentence(char ch);
bool is_start_of_sentence(string &str, int index);

int main(int argc, char **argv)
{
	string str;
	read_string(str);
	print_string(str);
	if (contains_capslock_syndrome(str))
	{
		cout << "The string contains capslock syndrome." << endl;
		cout << "Correcting capslock syndrome..." << endl;
		correct_capslock_syndrome(str);
		print_string(str);
	}
	else
	{
		cout << "The string does not contain capslock syndrome." << endl;
	}
	cout << "Capitalizing the start of the first word of each sentence..." << endl;
	capitalize_start_of_first_word_of_each_sentence(str);
	print_string(str);
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

bool contains_capslock_syndrome(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			return true;
		}
	}
	return false;
}

string correct_capslock_syndrome(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
	return str;
}

string capitalize_start_of_first_word_of_each_sentence(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0)
		{
			str[i] = toupper(str[i]);
		}
		else if (str[i] == '.' && str[i + 1] == ' ')
		{
			str[i + 2] = toupper(str[i + 2]);
		}
	}
	return str;
}

bool is_end_of_sentence(char ch)
{
	if (ch == '.' || ch == '!' || ch == '?')
	{
		return true;
	}
	return false;
}

bool is_start_of_sentence(string & str, int index)
{
	if (str[index] == '.' && str[index + 1] == ' ')
	{
		return true;
	}
	return false;
}

// Path: chapter9\projects\capslock_syndrome\capslock.cpp