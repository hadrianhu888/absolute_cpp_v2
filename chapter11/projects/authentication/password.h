/**
 * @file password.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>

using namespace std;

namespace
{
    const int MAX_PASSWORD_LENGTH = 20;
    string password;
    bool isValid_PassWord (string password)
    {
        if (password.length() > MAX_PASSWORD_LENGTH)
        {
            return false;
        }
        return true;
    }
}

#endif /* PASSWORD_H */
