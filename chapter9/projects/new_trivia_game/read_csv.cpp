/**
 * @file read_csv.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc,char  **argv) {
    std::ifstream csvfile("input.csv");
    std::string line;

    // Read the first line of the CSV file to get the column names
    std::getline(csvfile, line);
    std::stringstream ss(line);
    std::string colname;
    std::vector<std::string> cols;
    while (std::getline(ss, colname, ',')) {
        cols.push_back(colname);
        std::cout << colname << " ";
    }
    std::cout << std::endl;

    // Read the rest of the lines in the CSV file and print their columns
    while (std::getline(csvfile, line)) {
        std::stringstream ss(line);
        std::string value;
        int i = 0;
        while (std::getline(ss, value, ',')) {
            std::cout << cols[i] << ": " << value << " ";
            i++;
        }
        std::cout << std::endl;
    }
    /**
     * @brief store the questions, answers, and scores in three vectors
     * 
     */
    std::vector<std::string> questions;
    std::vector<std::string> answers;
    std::vector<int> scores;
    while (std::getline(csvfile, line)) {
        std::stringstream ss(line);
        std::string value;
        int i = 0;
        while (std::getline(ss, value, ',')) {
            std::cout << cols[i] << ": " << value << " ";
            i++;
        }
        std::cout << std::endl;
    }
    /**
     * @brief print the questions, answers, and scores in three vectors
     * 
     */
    for (int i = 0; i < questions.size(); i++) {
        std::cout << questions[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < answers.size(); i++) {
        std::cout << answers[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < scores.size(); i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    /**
     * @brief list the number of questions 
     * 
     */
    while(std::getline(csvfile, line)) {
        std::stringstream ss(line);
        std::string value;
        int i = 0;
        while (std::getline(ss, value, ',')) {
            std::cout << cols[i] << ": " << value << " ";
            i++;
        }
        std::cout << std::endl;
    }
    std::cout << "\n\nThe number of questions is: " << questions.size() << std::endl;
    
    return 0;
}

