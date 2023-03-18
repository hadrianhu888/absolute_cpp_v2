/**
 * @file new_trivia_game.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

using namespace std;

int main(int argc, char **argv);

typedef struct Question
{
    string question;
    string answer;
    int points;
} Questions; 

class TriviaGame
{
    private:
        Question *questions;
        int num_questions;
        int current_question;
        int score;
    public:
        TriviaGame();
        ~TriviaGame();
        void play();
        void ask_question();
        void get_answer();
        void show_score();
}; 

TriviaGame::TriviaGame()
{
    num_questions = 0;
    current_question = 0;
    score = 0;
    questions = NULL;
}

TriviaGame::~TriviaGame()
{
    if (questions != NULL)
    {
        delete [] questions;
    }
}

void TriviaGame::play()
{
    ifstream in_stream;
    string file_name;
    string question;
    string answer;
    int points;
    int i;

    cout << "Enter the name of the trivia file: ";
    cin >> file_name;
    in_stream.open(file_name.c_str());
    if (in_stream.fail())
    {
        cout << "Input file opening failed. Program terminates!" << endl;
        exit(1);
    }

    in_stream >> num_questions;
    questions = new Question[num_questions];
    for (i = 0; i < num_questions; i++)
    {
        in_stream >> question;
        in_stream >> answer;
        in_stream >> points;
        questions[i].question = question;
        questions[i].answer = answer;
        questions[i].points = points;
    }
    in_stream.close();

    while (current_question < num_questions)
    {
        ask_question();
        get_answer();
    }
    show_score();
}

void TriviaGame::ask_question()
{
    cout << questions[current_question].question << endl;
}

void TriviaGame::get_answer()
{
    string answer;
    cout << "Enter your answer: ";
    cin >> answer;
    if (answer == questions[current_question].answer)
    {
        score += questions[current_question].points;
        cout << "Correct!" << endl;
    }
    else
    {
        cout << "Incorrect!" << endl;
    }
    current_question++;
}

void TriviaGame::show_score()
{
    cout << "Your score is " << score << endl;
}

int main(int argc, char **argv)
{
    TriviaGame game;
    game.play();
    return 0;
}

// Path: chapter9\projects\trivia_game\trivia_game.cpp


