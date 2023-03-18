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

