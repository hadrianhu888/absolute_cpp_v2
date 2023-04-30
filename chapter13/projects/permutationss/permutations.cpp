/**
 * @file permutations.cpp
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

void permutations(string str);
int permutations(string str, int n);

int main(int argc, char **argv);

void permutations(string str)
{
    if (str.length() == 1)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string shorter = str.substr(0, i) + str.substr(i + 1);
            permutations(shorter);
        }
    }
}

int permutations(string str, int n)
{
    if (str.length() == 1)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            string shorter = str.substr(0, i) + str.substr(i + 1);
            permutations(shorter);
        }
    }
}

int main(int argc, char **argv)
{
    permutations("abcd");
    permutations("abcd", 2);
    return 0;
}
