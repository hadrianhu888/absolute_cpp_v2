/**
 * @file reverse_array.cpp
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

void reverseArrayInBounds(string str, int start, int end);
void reverseArrayInBoundsIterative(string str, int start, int end);
void reverseString(string str);
int main(int argc, char **argv);

void reverseArrayInBounds(string str, int start, int end)
{
    if (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverseArrayInBounds(str, start + 1, end - 1);
    }
    else
    {
        cout << str << endl;
    }
}

void reverseArrayInBoundsIterative(string str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    cout << str << endl;
}

void reverseString(string str)
{
    reverseArrayInBounds(str, 0, str.length() - 1);
}

int main(int argc, char **argv)
{
    reverseArrayInBounds("abcd", 0, 3);
    reverseArrayInBoundsIterative("abcd", 0, 3);
    reverseString("abcd");
    return 0;
}
