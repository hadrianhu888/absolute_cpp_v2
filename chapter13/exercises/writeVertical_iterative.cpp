/**
 * @file writeVertical_iterative.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

void displayVerticalIterative(string word);
void writeAsterisksIteratively(int n);
void writeIntInReverseIteratively(int n);
void writeIntSeparatedByCommasIteratively(int n);
void writeIntReverseSeparatedByCommasIteratively(int n);
int power(int base, int exponent);
int main(int argc, char **argv);

void displayVerticalIterative(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        cout << word[i] << endl;
    }
}

void writeAsterisksIteratively(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
}

void writeIntInReverseIteratively(int n)
{
    while (n > 0)
    {
        cout << n % 10;
        n /= 10;
    }
}

void writeIntSeparatedByCommasIteratively(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (count == 1)
        {
            cout << ",";
            count = 0;
        }
        cout << n % 10;
        n /= 10;
        count++;
    }
}

void writeIntReverseSeparatedByCommasIteratively(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (count == 1)
        {
            cout << ",";
            count = 0;
        }
        cout << n % 10;
        n /= 10;
        count++;
    }
}

int power(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int main(int argc, char **argv)
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    displayVerticalIterative(word);
    writeAsterisksIteratively(5);
    cout << endl;
    writeIntInReverseIteratively(12345);
    cout << endl;
    writeIntSeparatedByCommasIteratively(123456789);
    cout << endl;
    writeIntReverseSeparatedByCommasIteratively(123456789);
    cout << endl;
    cout << power(2, 3) << endl;
    return 0;
}
