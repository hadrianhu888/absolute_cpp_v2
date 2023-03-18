/**
 * @file parse_questions.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

using namespace std;

typedef struct Question
{
    string question;
    string answer;
    int points;
} Questions;

int main(int argc, char **argv);
void read_questions_file(string file_name, vector<Questions> &questions);
void print_questions(vector<Questions> questions);
void parse_questions(string line, Questions &question);
void parse_answers(string line, Questions &question);
void print_questions(vector<Questions> questions);
void print_answers(vector<Questions> questions);

int main(int argc, char **argv)
{
    vector<Questions> questions;
    string file_name = "F:/GitHubRepos/absolute_cpp/chapter9/projects/trivia_game/questions.txt";
    read_questions_file(file_name, questions);
    print_questions(questions);
    print_answers(questions);
    return 0;
}

void read_questions_file(string file_name, vector<Questions> &questions)
{
    ifstream in_stream;
    string line;
    Questions question;
    in_stream.open(file_name);
    if (in_stream.fail())
    {
        cout << "Error opening file " << file_name << endl;
        exit(1);
    }
    while (getline(in_stream, line))
    {
        if (line.find("Question:") != string::npos)
        {
            parse_questions(line, question);
        }
        else if (line.find("Answer:") != string::npos)
        {
            parse_answers(line, question);
            questions.push_back(question);
        }
    }
    in_stream.close();
}

void parse_questions(string line, Questions &question)
{
    /**
     * @brief questions end with a ? mark. 
     * 
     */
    while (line.find("?") == string::npos)
    {
        question.question += line + " ";
    }
}

void parse_answers(string line, Questions &question)
{
    question.answer = line.substr(7);
}

void print_questions(vector<Questions> questions)
{
    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i].question << endl;
    }
}

void print_answers(vector<Questions> questions)
{
    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i].answer << endl;
    }
}

// Path: chapter9\projects\trivia_game\parse_questions.cpp
