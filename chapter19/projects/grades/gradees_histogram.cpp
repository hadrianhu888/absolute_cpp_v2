/**
 * @file gradees_histogram.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("grades.txt"); // replace with your file name
    if (!infile.is_open())
    {
        std::cerr << "Unable to open file grades.txt";
        exit(1); // terminate with error
    }

    std::vector<int> histogram(10, 0); // 10 buckets for the histogram
    int grade;
    while (infile >> grade)
    {
        if (grade == 100)
        {
            ++histogram.back(); // assign 100 to the last bucket
        }
        else
        {
            ++histogram[grade / 10]; // increment the count in the appropriate bucket
        }
    }

    infile.close();

    // print the histogram
    for (int i = 0; i < 9; ++i)
    { // adjust for the new bucket
        std::cout << i * 10 << "-" << (i + 1) * 10 << ": ";
        std::cout << std::string(histogram[i], '*') << "\n";
    }
    std::cout << "90-100: " << std::string(histogram.back(), '*') << "\n";

    return 0;
}
