/**
 * @file administrator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "security.hpp"
#include "administrator.hpp"

#include <iostream>

using namespace std;
using namespace security;
using namespace administrator;

administrator::Administrator::Administrator()
{
    cout << "Administrator::Administrator()" << endl;
}

administrator::Administrator::~Administrator()
{
    cout << "Administrator::~Administrator()" << endl;
}

void administrator::Administrator::setPassword(uint8_t *password, uint8_t length)
{
    cout << "Administrator::setPassword()" << endl;
    m_passwordLength = length;
    m_passwordIndex = 0;
    for (uint8_t i = 0; i < length; i++)
    {
        m_password[i] = password[i];
    }
}

void administrator::Administrator::resetPassword()
{
    cout << "Administrator::resetPassword()" << endl;
    m_passwordIndex = 0;
}

bool administrator::Administrator::checkPassword(uint8_t *password, uint8_t length)
{
    cout << "Administrator::checkPassword()" << endl;
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

void administrator::Administrator::printPassword()
{
    cout << "Administrator::printPassword()" << endl;
    for (uint8_t i = 0; i < m_passwordLength; i++)
    {
        cout << m_password[i] << " ";
    }
    cout << endl;
}

// Path: chapter11\projects\security_app\main.cpp
