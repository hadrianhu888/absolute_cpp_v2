/**
 * @file driver.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DRIVER_HPP
#define DRIVER_HPP

#include "common.hpp"
#include "lengths.cpp"
#include "lengths.hpp"
#include "weights.cpp"
#include "weights.hpp"

// main driver functions to switch between the two programs of either length of
// weight conversion

void menu(void);                 // function prototype
void length(void);               // function prototype
void weight(void);               // function prototype
void quit(void);                 // function prototype
int main(int argc, char **argv); // function prototype

#endif /* DRIVER_HPP */