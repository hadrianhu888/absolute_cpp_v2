/**
 * @file check_input.cpp
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

int getInt(int &n);
char *deleteUpper(char *stringVar);
char *deleteLower(char *stringVar);
char *customNewLine(char *stringVar); 
int main(int argc, char **argv);

int getInt(int &n)
{
    char input[80];
    cin.getline(input, 80);
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return 0;
    }
    else
    {
        n = atoi(input);
        return 1;
    }
}

char *deleteUpper(char *stringVar)
{
    int i = 0;
    while (stringVar[i] != '\0')
    {
        if (stringVar[i] >= 'A' && stringVar[i] <= 'Z')
        {
            stringVar[i] = ' ';
        }
        i++;
    }
    return stringVar;
}

char *deleteLower(char *stringVar)
{
    int i = 0;
    while (stringVar[i] != '\0')
    {
        if (stringVar[i] >= 'a' && stringVar[i] <= 'z')
        {
            stringVar[i] = ' ';
        }
        i++;
    }
    return stringVar;
}

char *customNewLine(char *stringVar)
{
    /**
     * @brief use the ignore function to ignore the newline character
     * 
     */
    int i = 0;
    while (stringVar[i] != '\0')
    {
        if (stringVar[i] == '\0') {
        /**
         * @brief ignore new line character
         * 
         */
            cin.ignore(10000, '\n');
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int n; 
    getInt(n);
    do {
        cout << "Enter an integer: ";
        getInt(n);
        cout << "You entered " << n << endl;
    } while (n != 0);
    char c1, c2, c3, c4;
    cout << "Enter four characters: ";
    cin.get(c1);
    cin.get(c2);
    cin.get(c3);
    cin.get(c4);
    cout << "You entered " << c1 << c2 << c3 << c4 << endl;
    char next; 
    int count = 0;
    cout << "Enter a line of text: ";
    cin.get(next);
    while (next != 'q')
    {
        count++;
        cin.get(next);
    }
    cout << "You entered " << count << " characters" << endl;
    char stringVar[80];
    cout << "Enter a line of text: ";
    cin.getline(stringVar, 80);
    cout << "You entered " << stringVar << endl;
    cout << deleteUpper(stringVar) << endl;
    cout << deleteLower(stringVar) << endl;
    cout << "Enter a line of text: " << endl;
    char next1; 
    int count1 = 0;
    cin.get(next1);
    while (next1 != '\n')
    {
        count1++;
        cin.get(next1);
    }
    cout << "You entered " << count1 << " characters" << endl;
    /**
     * @brief test the customNewLine function
     * 
     */
    char stringVar1[80];
    cout << "Enter a line of text: ";
    cin.getline(stringVar1, 80);
    cout << "You entered " << stringVar1 << endl;
    cout << customNewLine(stringVar1) << endl;
    return 0;
}