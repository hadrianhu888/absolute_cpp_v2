/**
 * @file security.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <stdint.h>
#include <iostream>

using namespace std;

#define MAX_PASSWORD_LENGTH 8

namespace security
{
    class Security
    {
    private:
        uint8_t m_password[MAX_PASSWORD_LENGTH];
        uint8_t m_passwordLength;
        uint8_t m_passwordIndex;

    public:
        Security();
        ~Security();

        void setPassword(uint8_t *password, uint8_t length);
        void resetPassword();
        bool checkPassword(uint8_t *password, uint8_t length);
        void printPassword();
    };
} // namespace security

#endif /* SECURITY_H */
