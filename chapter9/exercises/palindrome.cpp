/**
 * @file palindrome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);
bool isPalindrome(string &stringVar);
string returnPalindrome(string &stringVar);
string print(string &stringVar);
string removePunctuation(string &stringVar);
string removeSpaces(string &stringVar);
string toLower(string &stringVar);

int main(int argc, char **argv)
{
    string stringVar;
    cout << "Enter a string: ";
    getline(cin, stringVar);
    stringVar = removePunctuation(stringVar);
    stringVar = removeSpaces(stringVar);
    stringVar = toLower(stringVar);
    if (isPalindrome(stringVar))
    {
        cout << "The string is a palindrome" << endl;
    }
    else
    {
        cout << "The string is not a palindrome" << endl;
    }
    cout << "The palindrome is: " << returnPalindrome(stringVar) << endl;
    cout << "The string is: " << print(stringVar) << endl;
    return 0;
}

bool isPalindrome(string &stringVar)
{
    string stringVarCopy = stringVar;
    reverse(stringVarCopy.begin(), stringVarCopy.end());
    if (stringVar == stringVarCopy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string returnPalindrome(string &stringVar)
{
    string stringVarCopy = stringVar;
    reverse(stringVarCopy.begin(), stringVarCopy.end());
    return stringVarCopy;
}

string print(string &stringVar)
{
    return stringVar;
}

string removePunctuation(string &stringVar)
{
    string stringVarCopy = stringVar;
    /**
     * @brief don't use remove_if 
     * 
     */
    while (stringVarCopy.find_first_of(".,;:!?") != string::npos)
    {
        stringVarCopy.erase(stringVarCopy.find_first_of(".,;:!?"), 1);
    }
    return stringVarCopy;
}

string removeSpaces(string &stringVar)
{
    string stringVarCopy = stringVar;
    while (stringVarCopy.find_first_of(" ") != string::npos)
    {
        stringVarCopy.erase(stringVarCopy.find_first_of(" "), 1);
    }
    return stringVarCopy;
}

string toLower(string &stringVar)
{
    string stringVarCopy = stringVar;
    transform(stringVarCopy.begin(), stringVarCopy.end(), stringVarCopy.begin(), ::tolower);
    return stringVarCopy;
}

// Path: chapter9\exercises\palindrome.cpp
