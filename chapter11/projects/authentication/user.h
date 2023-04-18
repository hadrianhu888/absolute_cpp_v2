/**
 * @file user.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

namespace
{
    const int MAX_USERNAME_LENGTH = 20;
    string username;
    bool isValid_UserName (string username)
    {
        if (username.length() > MAX_USERNAME_LENGTH)
        {
            return false;
        }
        return true;
    }
}

#endif /*USER_H*/
