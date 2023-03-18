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

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

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

FILE *fp;
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
    fp = fopen("questions.txt", "r");
    if (fp == NULL)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void parse_file(void)
{
    while (getline(&line, &len, fp) != -1)
    {
        cout << line << endl;
    }
}

void close_file(void)
{
    fclose(fp);
}

void parse_titles(void) {
    while(getline(&line, &len, fp) != -1)
    {
        titles.push_back(line);
    }
}

void parse_questions(void) {
    while(getline(&line, &len, fp) != -1)
    {
        questions.push_back(line);
    }
}

void parse_answers(void) {
    while(getline(&line, &len, fp) != -1)
    {
        answers.push_back(line);
    }
}

void parse_points(void) {
    while(getline(&line, &len, fp) != -1)
    {
        point_int = stoi(line);
        points.push_back(point_int);
    }
}

void print_outputs(void) {
    for (int i = 0; i < titles.size(); i++)
    {
        cout << titles[i] << endl;
        cout << questions[i] << endl;
        cout << answers[i] << endl;
        cout << points[i] << endl;
    }
}

