/**
 * @file file_open_parse.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp_v1/common.hpp" // common header file

using namespace std;

int main(int argc, char **argv);

/**
 * @brief Read from questions.txt and parse the data
 * 
 */

vector <string> titles;
vector <string> questions;
vector <string> answers;
vector <int> points;

fstream fp; 
string line = "";
int len = 0;
int point_int = 0;

void open_file(void);
void parse_file(void);
void close_file(void);
void parse_titles(void);
void parse_questions(void);
void parse_answers(void);
void parse_points(void);
void print_outputs(void);

int main(int argc, char **argv)
{
    open_file();
    parse_file();
    close_file();
    parse_titles();
    parse_questions();
    parse_answers();
    parse_points();
    print_outputs();
    return 0;
}

void open_file(void)
{
    fp.open("questions.txt", ios::in);
    if (!fp)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void parse_file(void)
{
    while (getline(fp, line))
    {
        len = line.length();
        if (len > 0)
        {
            titles.push_back(line);
            getline(fp, line);
            questions.push_back(line);
            getline(fp, line);
            answers.push_back(line);
            getline(fp, line);
            points.push_back(stoi(line));
        }
    }
}

void close_file(void)
{
    fp.close();
}

void parse_titles(void)
{
    cout << "Titles:" << endl;
    for (int i = 0; i < titles.size(); i++)
    {
        cout << titles[i] << endl;
    }
    cout << endl;
}

void parse_questions(void)
{
    cout << "Questions:" << endl;
    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
    cout << endl;
}

void parse_answers(void)
{
    cout << "Answers:" << endl;
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
    cout << endl;
}

void parse_points(void)
{
    cout << "Points:" << endl;
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i] << endl;
    }
    cout << endl;
}

void print_outputs(void)
{
    cout << "Output:" << endl;
    for (int i = 0; i < titles.size(); i++)
    {
        cout << titles[i] << endl;
        cout << questions[i] << endl;
        cout << answers[i] << endl;
        cout << points[i] << endl;
    }
}   

// Path: chapter9\projects\new_trivia_game\file_open_parse.hpp