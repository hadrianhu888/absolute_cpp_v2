/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "security.cpp"
#include "user.cpp"
#include "administrator.cpp"

#include <iostream>

using namespace std;
using namespace security;
using namespace administrator;
using namespace user;

int main(int argc, char const *argv[]);

int main(int argc, char const *argv[])
{
    cout << "main()" << endl;
    User user;
    Administrator administrator;

    uint8_t password[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t passwordLength = 8;

    user.setPassword(password, passwordLength);
    administrator.setPassword(password, passwordLength);

    user.printPassword();
    administrator.printPassword();

    return 0;
}

// Path: chapter11\projects\security_app\main.cpp
