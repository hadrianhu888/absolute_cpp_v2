/**
 * @file trivia_game_1.cpp
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

vector<string> questions; // vector of questions
vector<string> answers; // vector of answers
vector<int> points; // vector of points

void start_game(void);
void ask_question(void);
void get_answer(void);
void show_score(void);
void store_scores(void);
void read_scores(void);
void get_max_score(void);
int get_current_question(void);
string get_question(vector<string> questions, int current_question);
void generate_new_questions(void);
void generate_new_answers(void);
string check_questions_answers(vector<string> questions, vector<string> answers, int current_question);

class Trivia 
{
    private:
        string question;
        string answer;
        int points;
    public:
        Trivia(string question, string answer, int points);
        string get_question();
        string get_answer();
        int get_points();
        int set_question_answer_points(Trivia trivia, string question, string answer, int points);
};

int score; 
int current_question;
vector<Trivia> trivia;
int scores[10];

Trivia::Trivia(string question, string answer, int points)
{
    this->question = question;
    this->answer = answer;
    this->points = points;
}

string Trivia::get_question()
{
    return question;
}

string Trivia::get_answer()
{
    return answer;
}

int Trivia::get_points()
{
    return points;
}

int Trivia::set_question_answer_points(Trivia trivia, string question, string answer, int points)
{
    trivia.question = question;
    trivia.answer = answer;
    trivia.points = points;
    return 0;
}

int main(int argc, char **argv)
{
    start_game();
    return 0;
}

void start_game(void)
{
    ifstream in_stream;
    string file_name;
    string question;
    string answer;
    int points;
    int num_questions;
    int current_question;
    int score;
    int max_score;
    vector<Trivia> trivia;

    cout << "Enter the name of the trivia file: ";
    cin >> file_name;
    in_stream.open(file_name.c_str());
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    in_stream >> num_questions;
    in_stream.ignore(10000, ' ');
    for (int i = 0; i < num_questions; i++)
    {
        getline(in_stream, question);
        getline(in_stream, answer);
        in_stream >> points;
        in_stream.ignore(10000, ' ');
        trivia.push_back(Trivia(question, answer, points));
    }
    in_stream.close();
    current_question = 0;
    score = 0;
    while (current_question < num_questions)
    {
        ask_question();
        get_answer();
        show_score();
        current_question++;
    }
    store_scores();
    read_scores();
    get_max_score();
}

void ask_question(void)
{
    cout << trivia[current_question].get_question() << endl;
}

void get_answer(void)
{
    string user_answer;
    cout << "Your answer: ";
    getline(cin, user_answer);
    if (user_answer == trivia[current_question].get_answer())
    {
        score += trivia[current_question].get_points();
    }
}

void show_score(void)
{
    cout << "Your score is " << score << endl;
}

void store_scores(void)
{
    ofstream out_stream;
    string file_name;
    cout << "Enter the name of the output file: ";
    cin >> file_name;
    out_stream.open(file_name.c_str());
    if (out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    out_stream << score << endl;
    out_stream.close();
}

void read_scores(void)
{
    ifstream in_stream;
    string file_name;
    int score;
    vector<int> scores;
    cout << "Enter the name of the input file: ";
    cin >> file_name;
    in_stream.open(file_name.c_str());
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    while (in_stream >> score)
    {
        scores.push_back(score);
    }
    in_stream.close();
}

void get_max_score(vector<int> scores)
{
    int max_score;
    max_score = scores[0];
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i] > max_score)
        {
            max_score = scores[i];
        }
    }
    cout << "The highest score is " << max_score << endl;
}

int get_current_question(void)
{
    return current_question;
}

int get_score(void)
{
    return score;
}

string get_question(vector<string> questions, int current_question)
{
    return questions[current_question];
}

void generate_new_questions(void)
{
    string question;
    cout << "Enter a new question: ";
    getline(cin, question);
    questions.push_back(question);
}

void generate_new_answers(void)
{
    string answer;
    cout << "Enter the answer to the question: ";
    getline(cin, answer);
    answers.push_back(answer);
}

string check_questions_answers(vector<string> questions, vector<string> answers, int current_question)
{
    string user_answer;
    cout << "Your answer: ";
    getline(cin, user_answer);
    if (user_answer == answers[current_question])
    {
        score += points[current_question];
    }
    return user_answer;
}



