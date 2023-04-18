/**
 * @file security.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "security.hpp"

#include <iostream>

using namespace std;
using namespace security;

security::Security::Security()
{
    cout << "Security::Security()" << endl;
}

security::Security::~Security()
{
    cout << "Security::~Security()" << endl;
}

void security::Security::setPassword(uint8_t *password, uint8_t length)
{
    cout << "Security::setPassword()" << endl;
    m_passwordLength = length;
    m_passwordIndex = 0;
    for (uint8_t i = 0; i < length; i++)
    {
        m_password[i] = password[i];
    }
}

void security::Security::resetPassword()
{
    cout << "Security::resetPassword()" << endl;
    m_passwordIndex = 0;
}

bool security::Security::checkPassword(uint8_t *password, uint8_t length)
{
    cout << "Security::checkPassword()" << endl;
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

    return true;
}

void security::Security::printPassword()
{
    cout << "Security::printPassword()" << endl;
    for (uint8_t i = 0; i < m_passwordLength; i++)
    {
        cout << m_password[i] << " ";
    }
    cout << endl;
}

// Path: chapter11\projects\security_app\security.h
