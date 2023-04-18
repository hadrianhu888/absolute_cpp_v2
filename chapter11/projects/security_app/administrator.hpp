/**
 * @file administrator.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP

#include <stdint.h>

#include "security.hpp"

using namespace std;
using namespace security;

namespace administrator
{
    class Administrator
    {
    private:
        Security m_security;
        uint8_t m_password[MAX_PASSWORD_LENGTH];
        uint8_t m_passwordLength;
        uint8_t m_passwordIndex;

    public:
        Administrator();
        ~Administrator();

        void setPassword(uint8_t *password, uint8_t length);
        void resetPassword();
        bool checkPassword(uint8_t *password, uint8_t length);
        void printPassword();
    };
} // namespace administrator

#endif /* ADMINISTRATOR_H */
