/**
 * @file parse_csv.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp_v1/common.hpp" // common header file

using namespace std;

int main(int argc, char **argv);

class CSVParser
{
    private:
        fstream fp;
        string line;
        int len;
        int point_int;
        vector <string> titles;
        vector <string> questions;
        vector <string> answers;
        vector <int> points;
    public:
        void open_file(void);
        void parse_file(void);
        void close_file(void);
        void parse_titles(void);
        void parse_questions(void);
        void parse_answers(void);
        void parse_points(void);
        void print_outputs(void);
        void print_csv_data(void); 
        int countLines(void);
        vector <string> storeQuestions(void);
        vector <string> storeAnswers(void);
        vector <int> storePoints(void);
        void printQuestions(vector <string> questions);
        void printAnswers(vector <string> answers);
        void printPoints(vector <int> points);
};

int main(int argc, char **argv)
{
    CSVParser csv_parser;
    csv_parser.open_file();
    csv_parser.parse_file();
    csv_parser.close_file();
    csv_parser.parse_titles();
    csv_parser.parse_questions();
    csv_parser.parse_answers();
    csv_parser.parse_points();
    csv_parser.print_csv_data();
    csv_parser.print_outputs();
    csv_parser.printQuestions(csv_parser.storeQuestions());
    csv_parser.printAnswers(csv_parser.storeAnswers());
    csv_parser.printPoints(csv_parser.storePoints());

    return 0;
}

void CSVParser::open_file(void)
{
    fp.open("questions.txt", ios::in);
    if (!fp)
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void CSVParser::parse_file(void)
{
    getline(fp, line);
    len = line.length();
    for (int i = 0; i < len; i++)
    {
        if (line[i] == ',')
        {
            line[i] = ' ';
        }
    }
}

void CSVParser::close_file(void)
{
    fp.close();
}

void CSVParser::parse_titles(void)
{
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        titles.push_back(word);
    }
}

void CSVParser::parse_questions(void)
{
    getline(fp, line);
    len = line.length();
    for (int i = 0; i < len; i++)
    {
        if (line[i] == ',')
        {
            line[i] = ' ';
        }
    }
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        questions.push_back(word);
    }
}

void CSVParser::parse_answers(void)
{
    getline(fp, line);
    len = line.length();
    for (int i = 0; i < len; i++)
    {
        if (line[i] == ',')
        {
            line[i] = ' ';
        }
    }
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        answers.push_back(word);
    }
}

void CSVParser::parse_points(void)
{
    getline(fp, line);
    len = line.length();
    for (int i = 0; i < len; i++)
    {
        if (line[i] == ',')
        {
            line[i] = ' ';
        }
    }
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
        point_int = stoi(word);
        points.push_back(point_int);
    }
}

void CSVParser::print_outputs(void)
{
    for (int i = 0; i < titles.size(); i++)
    {
        cout << titles[i] << " " << questions[i] << " " << answers[i] << " " << points[i] << endl;
    }
    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
    for(int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
    for(int i = 0; i < points.size(); i++)
    {
        cout << points[i] << endl;
    }
}

int CSVParser::countLines(void)
{
    int count = 0;
    while (getline(fp, line))
    {
        count++;
    }
    return count-1;
}

void CSVParser::print_csv_data(void)
{
    cout << line << endl;
}

vector<string> CSVParser::storeQuestions(void)
{
    //store questions in the vector
    for (int i = 0; i < questions.size(); i++)
    {
        questions.push_back(questions[i]);
    }
    return questions; 
}

vector<string> CSVParser::storeAnswers(void)
{
    for(int i = 0; i < answers.size(); i++)
    {
        answers.push_back(answers[i]);
    }
    return answers;
}

vector<int> CSVParser::storePoints(void)
{
    for(int i = 0; i < points.size(); i++)
    {
        points.push_back(points[i]);
    }
    return points; 
}

void CSVParser::printQuestions(vector<string> questions)
{
    for (int i = 0; i < questions.size(); i++)
    {
        cout << questions[i] << endl;
    }
}

void CSVParser::printAnswers(vector<string> answers)
{
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << endl;
    }
}

void CSVParser::printPoints(vector<int> points)
{
    for (int i = 0; i < points.size(); i++)
    {
        cout << points[i] << endl;
    }
}







// Path: chapter9\projects\new_trivia_game\new_trivia_game.cpp


