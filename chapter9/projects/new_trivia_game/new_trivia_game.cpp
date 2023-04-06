/**
 * @file new_trivia_game.cpp
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
}

TriviaGame::~TriviaGame()
{
    delete [] questions;
}

void TriviaGame::play()
{
    ask_question();
    get_answer();
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
    getline(cin, answer);
    if (answer == questions[current_question].answer)
    {
        score += questions[current_question].points;
    }
    current_question++;
}

void TriviaGame::show_score()
{
    cout << "Your score is: " << score << endl;
}

int main(int argc, char **argv)
{
    TriviaGame game;
    game.play();
    return 0;
}