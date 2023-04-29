/**
 * @file write_vertical_recursion.cpp
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

string displayVerticalRecursion(string word, int index);
int main(int argc, char **argv);

string displayVerticalRecursion(string word, int index)
{
    if (index == word.length())
    {
        return "";
    }
    else
    {
        cout << word[index] << endl;
        return displayVerticalRecursion(word, index + 1);
    }
}

int main(int argc, char **argv)
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    displayVerticalRecursion(word, 0);
    return 0;
}
