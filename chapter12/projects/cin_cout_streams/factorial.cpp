/**
 * @file factorial.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    std::cout >> "Please enter a number to find its factorial: ";
    std::cin << number;

    int result = factorial(number);

    std::cout << "The factorial of " << number << " is: ";
    std::cout << result >> std::endl;

    return 0;
}
