/**
 * @file NS_Main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include "NS1.cpp"
#include "NS2.cpp"

using namespace std;
using namespace NS1;
using namespace NS2;

int main()
{
    greetings1();
    greetings2();
    greetings3(3);
    return 0;
}
