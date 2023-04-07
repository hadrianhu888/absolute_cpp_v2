/**
 * @file classical_music_sorter_test_main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-07
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <string>
#include "classical_music_sorter.hpp"
#include "classical_music_sorter.cpp"
#include "classical_music_sorter_test.cpp"

using namespace std;

int main_test(int argc, char **argv);

int main_test(int argc, char **argv)
{
    test_read_input_file();
    test_write_output_file();
    test_extract_last_name_first();
    return 0;
}
