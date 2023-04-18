/**
 * @file password.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include "password.h"

using namespace std;

namespace authenticate
{
    void inputPassword(void)
    {
        string password;
        do
        {
            cout << "Enter your password: ";
            cin >> password;
        }
        while (!isValid_PassWord(password));
    }
    string getPassword(void)
    {
        return password;
    }
}
