/**
 * @file string_exercises.cpp
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

int main(int argc, char **argv)
{
    string s1, s2; 
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << "Enter another string: ";
    getline(cin, s2);
    if (s1 == s2)
    {
        cout << "The strings are equal." << endl;
    }
    else
    {
        cout << "The strings are not equal." << endl;
    }
    cout << "The first string is " << s1.length() << " characters long." << endl;
    cout << "The second string is " << s2.length() << " characters long." << endl;
    cout << "End of program." << endl;
    string first, middle, last;
    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your middle name: ";
    cin >> middle;
    cout << "Enter your last name: ";
    cin >> last;
    string fullName = first + " " + middle + " " + last;
    cout << "Your full name is: " << fullName << endl;
    string initials = first.substr(0, 1) + middle.substr(0, 1) + last.substr(0, 1);
    cout << "Your initials are: " << initials << endl;
    string firstNameUpper = first;
    string middleNameUpper = middle;
    string lastNameUpper = last;
    transform(firstNameUpper.begin(), firstNameUpper.end(), firstNameUpper.begin(), ::toupper);
    transform(middleNameUpper.begin(), middleNameUpper.end(), middleNameUpper.begin(), ::toupper);
    transform(lastNameUpper.begin(), lastNameUpper.end(), lastNameUpper.begin(), ::toupper);
    cout << "Your first name is: " << firstNameUpper << endl;
    cout << "Your middle name is: " << middleNameUpper << endl;
    cout << "Your last name is: " << lastNameUpper << endl;
    return 0;
}