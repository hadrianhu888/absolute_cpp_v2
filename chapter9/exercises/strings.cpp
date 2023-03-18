/**
 * @file strings.cpp
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
int returnStringLength(char *stringVar);
char *CopyStringToStringVariable(char *stringVar, char *stringVar1);

char *CopyStringToStringVariable(char *stringVar, char *stringVar1)
{
    int i = 0;
    while (stringVar1[i] != '\0')
    {
        stringVar[i] = stringVar1[i];
        i++;
    }
    stringVar[i] = '\0';
    return stringVar;
}

int returnStringLength(char *stringVar)
{
    int length = 0;
    while (stringVar[length] != '\0')
    {
        length++;
    }
    return length;
}

int SIZE = 150;

int main(int argc, char **argv)
{
    char myString[] = "Hello";
    char myString1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char myString2[6] = "Hello";
    char myString3[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char myString4[6] = {'H', 'e', 'l', 'l', 'o'};
    cout << myString << endl;
    cout << myString1 << endl;
    cout << myString2 << endl;
    cout << myString3 << endl;
    cout << myString4 << endl;
    char singingString[] = "Singing in the rain";
    cout << singingString << endl;
    strcat_s(singingString, 150, " and dancing in the rain");
    cout << singingString << endl;
    char stringVar[] = "Hello";
    strcat_s(stringVar, 150, " World");
    cout << stringVar << endl;
    int stringLength = returnStringLength(stringVar);
    cout << "The length of the string is: " << stringLength << endl;
    char s[6] = "Hello";
    int s_length = strlen(s);
    cout << "The length of the string is: " << s_length << endl;
    char X_string[] = "Hi there!"; 
    for (int i = 0; i < strlen(X_string); i++)
    {
        cout << X_string[i] << endl;
    }
    char test_String[SIZE]; 
    cout << "Enter a string: ";
    cin.getline(test_String, SIZE);
    cout << "The string you entered is: " << test_String << endl;
    cout << "The length of the string is: " << strlen(test_String) << endl;
    for (int i = 0; i < strlen(test_String); i++)
    {
        cout << test_String[i] << endl;
    }
    char aString[10]; 
    char bString[10];
    char cString[10];
    CopyStringToStringVariable(aString, bString);
    CopyStringToStringVariable(bString, cString);
    CopyStringToStringVariable(cString, aString);
    cout << aString << endl;
    cout << bString << endl;
    cout << cString << endl;
    char song[] = "Singing in the rain";
    char franksSong[] = "Singing in the rain";
    strcpy(song, franksSong);
    cout << song << endl;
    strcat(song, franksSong);
    cout << song << endl;
    char a[80];
    char b[80];
    cout << "Enter a string: ";
    cin.getline(a, 80);
    cout << "Enter another string: ";
    cin.getline(b, 80);
    cout << "The first string is: " << a << endl;
    cout << "The second string is: " << b << endl;
    cout << "The length of the first string is: " << strlen(a) << endl;
    char myTestString[80];
    cout << "Enter a string: ";
    cin.getline(myTestString, 80);
    cout << "The string you entered is: " << myTestString << endl;
    cout << "The length of the string is: " << strlen(myTestString) << endl;
    cout << "End of Input" << endl;
    char symbol; 
    do {
        cout << "Enter a character: ";
        cin >> symbol;
        cout << "The character you entered is: " << symbol << endl;
    } while (symbol != 'q');
    
    return 0;
}

/**
 * @brief 
 * \n has 2 characters. n has one character. "Mary" has 4 characters. "M" has 1 character. "Mary\n" has 5 characters.
 * Declaration is the statement that defines the type of a variable. Definition is the statement that defines the value of a variable.
 * 
 * 
 * 
 * 
 * 
 */