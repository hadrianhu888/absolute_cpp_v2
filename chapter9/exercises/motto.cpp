/**
 * @file motto.cpp
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

string motto; 
string firstName; 
string lastName;
string fullName;
string middleName;
string middleInitial;
string firstNameInitial;
string lastNameInitial;
string initials;
string firstNameUpper;
string lastNameUpper;

int main(int argc, char **argv)
{
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your middle name: ";
    cin >> middleName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your motto: ";
    cin.ignore();
    getline(cin, motto);
    fullName = firstName + " " + middleName + " " + lastName;
    middleInitial = middleName.substr(0, 1);
    firstNameInitial = firstName.substr(0, 1);
    lastNameInitial = lastName.substr(0, 1);
    initials = firstNameInitial + middleInitial + lastNameInitial;
    firstNameUpper = firstName;
    lastNameUpper = lastName;
    transform(firstNameUpper.begin(), firstNameUpper.end(), firstNameUpper.begin(), ::toupper);
    transform(lastNameUpper.begin(), lastNameUpper.end(), lastNameUpper.begin(), ::toupper);
    cout << "Your motto is: " << motto << endl;
    cout << "Your full name is: " << fullName << endl;
    cout << "Your initials are: " << initials << endl;
    cout << "Your first name is: " << firstNameUpper << endl;
    cout << "Your last name is: " << lastNameUpper << endl;
    return 0;
}
