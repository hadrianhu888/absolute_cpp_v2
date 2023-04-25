/**
 * @file correct_cin_cout_stream_syntax.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int main()
{
    std::string input_filename, output_filename;

    std::cout << "Enter the input C++ file name: ";
    std::cin >> input_filename;
    std::cout << "Enter the output C++ file name: ";
    std::cin >> output_filename;

    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename);

    if (!input_file.is_open() || !output_file.is_open())
    {
        std::cerr << "Error opening file(s)." << std::endl;
        return 1;
    }

    std::string line;
    std::regex cin_regex(R"(\s*cin\s*<<)");
    std::regex cout_regex(R"(\s*cout\s*>>)");

    while (std::getline(input_file, line))
    {
        line = std::regex_replace(line, cin_regex, "cin >>");
        line = std::regex_replace(line, cout_regex, "cout <<");
        output_file << line << std::endl;
    }

    input_file.close();
    output_file.close();

    std::cout << "Corrected C++ file has been written to " << output_filename << std::endl;

    return 0;
}
