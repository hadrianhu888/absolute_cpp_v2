/**
 * @file cheers_recursion.cpp
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

void cheersRecursion(string word, int index);
void writeAsterisksRecursively(int n);
void writeIntInReverseRecursively(int n);
void writeIntSeparatedByCommasRecursively(int n);
void writeIntReverseSeparatedByCommasRecursively(int n);
int main(int argc, char **argv);

void cheersRecursion(string word, int index)
{
    if (index == word.length())
    {
        return;
    }
    else
    {
        cout << "Give me a " << word[index] << "!" << endl;
        cheersRecursion(word, index + 1);
        cout << "Give me a " << word[index] << "!" << endl;
    }
}

void writeAsterisksRecursively(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        cout << "*";
        writeAsterisksRecursively(n - 1);
    }
}

void writeIntInReverseRecursively(int n)
{
    if (n < 10)
    {
        cout << n;
    }
    else
    {
        cout << n % 10;
        writeIntInReverseRecursively(n / 10);
    }
}

void writeIntSeparatedByCommasRecursively(int n)
{
    if (n < 1000)
    {
        cout << n;
    }
    else
    {
        writeIntSeparatedByCommasRecursively(n / 10);
        cout << "," << setw(3) << setfill('0') << n % 10;
    }
}

void writeIntReverseSeparatedByCommasRecursively(int n)
{
    if (n < 10)
    {
        cout << n;
    }
    else
    {
        cout << n % 10 << ",";
        writeIntReverseSeparatedByCommasRecursively(n / 10);
    }
}

int main(int argc, char **argv)
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cheersRecursion(word, 0);
    writeAsterisksRecursively(word.length());
    cout << endl;
    writeIntInReverseRecursively(123456789);
    cout << endl;
    writeIntSeparatedByCommasRecursively(123456789);
    cout << endl;
    writeIntReverseSeparatedByCommasRecursively(123456789);
    cout << endl;
    return 0;
}
