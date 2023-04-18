/**
 * @file user.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "user.hpp"

#include <iostream>

using namespace std;
using namespace security;
using namespace user;

user::User::User()
{
    cout << "User::User()" << endl;
}

user::User::~User()
{
    cout << "User::~User()" << endl;
}

void user::User::setPassword(uint8_t *password, uint8_t length)
{
    cout << "User::setPassword()" << endl;
    m_passwordLength = length;
    m_passwordIndex = 0;
    for (uint8_t i = 0; i < length; i++)
    {
        m_password[i] = password[i];
    }
}

void user::User::resetPassword()
{
    cout << "User::resetPassword()" << endl;
    m_passwordIndex = 0;
}

bool user::User::checkPassword(uint8_t *password, uint8_t length)
{
    cout << "User::checkPassword()" << endl;
    if (length != m_passwordLength)
    {
        return false;
    }

    for (uint8_t i = 0; i < length; i++)
    {
        if (password[i] != m_password[i])
        {
            return false;
        }
    }
}

void user::User::printPassword()
{
    cout << "User::printPassword()" << endl;
    for (uint8_t i = 0; i < m_passwordLength; i++)
    {
        cout << m_password[i] << " ";
    }
    cout << endl;
}

// Path: chapter11\projects\security_app\user.hpp
