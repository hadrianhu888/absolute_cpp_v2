/**
 * @file user.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef USER_HPP
#define USER_HPP

#include <stdint.h>

#include "security.hpp"
#include "administrator.hpp"

using namespace std;
using namespace security;
using namespace administrator;

namespace user
{
    class User
    {
    private:
        Security m_security;
        Administrator m_administrator;
        uint8_t m_password[MAX_PASSWORD_LENGTH];
        uint8_t m_passwordLength;
        uint8_t m_passwordIndex;

    public:
        User();
        ~User();

        void setPassword(uint8_t *password, uint8_t length);
        void resetPassword();
        bool checkPassword(uint8_t *password, uint8_t length);
        void printPassword();
    };
} // namespace user

#endif /* USER_H */
