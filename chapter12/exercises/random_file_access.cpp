/**
 * @file random_file_access.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    fstream rwStream("stuff", ios::in|ios::out);
    rwStream << "Hello" << endl;
    rwStream << "World" << endl;
    rwStream << 123 << endl;
    rwStream << 123.456 << endl;
    rwStream.close();
    return 0;
}
