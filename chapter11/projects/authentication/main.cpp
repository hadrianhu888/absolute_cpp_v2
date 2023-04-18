/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "password.cpp"
#include "user.cpp"
#include <iostream>
#include <string>

using namespace std;
using namespace authenticate;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    string password;
    string username;
    inputUserName();
    inputPassword();
    cout << "Welcome" << endl;
    return 0;
}
