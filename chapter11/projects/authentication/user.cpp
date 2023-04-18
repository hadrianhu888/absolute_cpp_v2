/**
 * @file user.cpp
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
#include "user.h"

using namespace std;

namespace authenticate
{
    void inputUserName(void)
    {
        do
        {
            cout << "Enter your username: ";
            cin >> username;
        }
        while (!isValid_UserName(username));
    }
    string getUserName(void)
    {
        return username;
    }
}; // namespace authenticate
