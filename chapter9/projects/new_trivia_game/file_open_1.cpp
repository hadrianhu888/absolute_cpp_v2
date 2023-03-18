/**
 * @file file_open_parse.cpp
 * @brief Read from questions.txt and parse the data.
 * @version 0.2
 * @date 2023-03-17
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief function prototypes here
 * 
 */

int main(int argc, char **argv);
std::ifstream(open_file(const std::string& filepath));
void print_file_contents(std::ifstream& ifs);
void parse_titles(std::vector<std::string>& titles, std::ifstream& ifs);
void parse_questions(int qCount, std::vector<std::string>& questions, 
                    std::vector<std::string>& answers, std::vector<int>& points, std::ifstream& ifs);
void print_outputs(const std::vector<std::string>& titles,
        const std::vector<std::string>& questions,
        const std::vector<std::string>& answers,
        const std::vector<int>& points);

// Improved: Create a function that returns an open file stream instead
std::ifstream open_file(const std::string& filepath) {
    std::ifstream ifs(filepath);
    if (!ifs) {
        throw std::runtime_error("Error opening file");
    }
    return ifs;
}

void print_file_contents(std::ifstream& ifs) {
    std::string line;
    while (getline(ifs, line))
    {
        std::cout << line << std::endl;
    }
}

// Improved: Add error handling to check the number of lines equals the number of titles
void parse_titles(std::vector<std::string>& titles, std::ifstream& ifs)
{
    std::string line;
    while (getline(ifs, line))
    {
        titles.push_back(line);
    }

    if (titles.empty() || titles.size() % 4 != 0) {
        throw std::runtime_error("Incorrect format of input file.");
    }
}

// Improved: parse question, answer, and point data until qCount reaches the desired number of questions
void parse_questions(int qCount, std::vector<std::string>& questions, 
                    std::vector<std::string>& answers, std::vector<int>& points, std::ifstream& ifs)
{
    int qNo = 0; // count number of questions parsed
    std::string line;
    while (qNo != qCount && getline(ifs, line))
    {
        switch (qNo % 4) {
            case 0:
                questions.push_back(line);
                break;
            case 1:
                answers.push_back(line);
                break;
            case 2:
                try {
                    points.push_back(std::stoi(line));
                }
                catch (const std::invalid_argument&) {
                    throw std::runtime_error("Invalid point value at question " + std::to_string(qNo/4));
                }
                break;
            default:
                // skip titles"
                break;
        }
        qNo++;
    }

    if (qNo != qCount) {
        throw std::runtime_error("Incorrect format of input file.");
    }
}

void print_outputs(const std::vector<std::string>& titles,
        const std::vector<std::string>& questions,
        const std::vector<std::string>& answers,
        const std::vector<int>& points)
{
    // print all the questions with details
}

int main(int argc, char **argv)
{
    // Improved: Add error handling to check the number of command line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    // Improved: Add error handling to check the number of questions is a positive integer
    int qCount = 0;
    try {
        qCount = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument&) {
        std::cerr << "Invalid number of questions" << std::endl;
        return 1;
    }

    // Improved: Add error handling to check the number of questions is a positive integer
    if (qCount <= 0) {
        std::cerr << "Invalid number of questions" << std::endl;
        return 1;
    }

    // Improved: Add error handling to check the number of questions is a positive integer
    std::vector<std::string> titles;
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::vector<int> points;

    // Improved: Add error handling to check the number of questions is a positive integer
    try {
        auto ifs = open_file("questions.txt");
        parse_titles(titles, ifs);
        parse_questions(qCount, questions, answers, points, ifs);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    print_outputs(titles, questions, answers, points);

    return 0;
}
