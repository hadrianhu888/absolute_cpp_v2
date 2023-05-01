/**
 * @file handshake.cpp
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

long int calculateHandShakes(int n);
int main(int argc, char **argv);

int main(int argc, char **argv)
{
    int n;
    cout << "Enter the number of people in the room: ";
    cin >> n;
    cout << "The number of handshakes is " << calculateHandShakes(n) << endl;
    return 0;
}

long int calculateHandShakes(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n - 1 + calculateHandShakes(n - 1);
    }
}
