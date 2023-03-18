/**
 * @file user_name_formats.cpp
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

string firstName; 
string middleName;
string lastName;

int main(int argc, char **argv);

class Name
{
    private:
        string firstName;
        string middleName;
        string lastName;
        string fullName;
        string initials;
    public:
        Name(string firstName, string middleName, string lastName);
        void setFirstName(string firstName);
        void setMiddleName(string middleName);
        void setLastName(string lastName);
        void get_name(string &firstName, string &middleName, string &lastName);
        void print_name(Name &name);
        string getFirstName();
        string getMiddleName();
        string getLastName();
        string getFullName();
        string getInitials();
        string capitalize(string str);
        string toLower(string str);
        string toUpper(string str);
        string trim(string str);
        string add_space_period_for_each_initial(string str);
        string print_formal_initials(string str);
        string get_initials(string str);
        string only_abbreviate_middle_name(string str);
        string print_formal_full_name_abbreviated_middle_name(string str);
};

Name::Name(string firstName, string middleName, string lastName)
{
    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
    this->fullName = firstName + " " + middleName + " " + lastName;
    this->initials = get_initials(firstName) + get_initials(middleName) + get_initials(lastName);
}

void Name::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Name::setMiddleName(string middleName)
{
    this->middleName = middleName;
}

void Name::setLastName(string lastName)
{
    this->lastName = lastName;
}

string Name::getFirstName()
{
    return this->firstName;
}

string Name::getMiddleName()
{
    return this->middleName;
}

string Name::getLastName()
{
    return this->lastName;
}

string Name::getFullName()
{
    return this->fullName;
}

string Name::getInitials()
{
    return this->initials;
}

void Name::get_name(string &firstName, string &middleName, string &lastName)
{
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your middle name: ";
    cin >> middleName;
    cout << "Enter your last name: ";
    cin >> lastName;
}

void Name:: print_name(Name &name)
{
    cout << "Your name is " << name.getFullName() << endl;
    cout << "Your initials are " << name.getInitials() << endl;
}

string Name:: capitalize(string str)
{
    str[0] = toupper(str[0]);
    return str;
}

string Name:: toLower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

string Name:: toUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

string Name:: trim(string str)
{
    int i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    str = str.substr(i, str.length() - i);
    i = str.length() - 1;
    while (str[i] == ' ')
    {
        i--;
    }
    str = str.substr(0, i + 1);
    return str;
}

string Name:: get_initials(string str)
{
    str = capitalize(str);
    str = trim(str);
    return str.substr(0, 1);
    /**
     * @brief add comma and space after each initial
     * 
     */
    
}

string Name::add_space_period_for_each_initial(string str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        temp += str[i];
        temp += ". ";
    }
    return temp;
}

string Name::print_formal_initials(string str)
{
    str = toUpper(str);
    str = trim(str);
    str = add_space_period_for_each_initial(str);
    return str;
}

string Name::only_abbreviate_middle_name(string str)
{
    str = capitalize(str);
    str = trim(str);
    return str.substr(0, 1) + ".";
}

string Name::print_formal_full_name_abbreviated_middle_name(string str)
{
    str = capitalize(str); 
    str = trim(str);
    int i = 0;
    while (str[i] != ' ')
    {
        i++;
    }
    str = str.substr(0, i + 1) + only_abbreviate_middle_name(str.substr(i + 1, str.length() - i));
    /**
     * @brief also print the full last name
     * 
     */
    str = str + " " + capitalize(lastName);
    return str;
}

int main(int argc, char **argv)
{
    Name name("John", "Paul", "Jones");
    name.print_name(name);
    cout << "Your initials are " << name.print_formal_initials(name.getInitials()) << endl;
    cout << "Your name is " << name.print_formal_full_name_abbreviated_middle_name(name.getFullName()) << endl;
    return 0;
}