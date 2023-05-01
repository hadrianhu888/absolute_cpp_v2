/**
 * @file needle_haystack.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main(int argc, char **argv);
int findNeedleInHaystack(const string &needle, const string &haystack);

int main(int argc, char **argv)
{
    string needle, haystack;
    cout << "Enter the needle: ";
    cin >> needle;
    cout << "Enter the haystack: ";
    cin >> haystack;
    cout << "The needle is at index " << findNeedleInHaystack(needle, haystack) << endl;
    return 0;
}

int findNeedleInHaystack(const string &needle, const string &haystack)
{
    if (haystack.length() < needle.length())
    {
        return -1;
    }
    else if (haystack.substr(0, needle.length()) == needle)
    {
        return 0;
    }
    else
    {
        int index = findNeedleInHaystack(needle, haystack.substr(1));
        if (index == -1)
        {
            return -1;
        }
        else
        {
            return index + 1;
        }
    }
}
