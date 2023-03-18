/**
 * @file trivia.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

int easy_points = 10;
int medium_points = 20;
int hard_points = 30;

using namespace std;

int main(int argc, char **argv);

class TriviaGame
{
    private:
        string question;
        string *questions[1000];
        string answer;
        int points;
    public:
        TriviaGame();
        ~TriviaGame();
        TriviaGame(string question, string answer, int points);
        void set_question(string question);
        void set_answer(string answer);
        void set_points(int points);
        string get_question();
        string generate_random_question();
        string get_answer();
        string set_answer();
        int get_points(int points);
        int set_points();
        int sum_total_points();
        void display_points();
        void display();
};

int main(int argc, char **argv)
{
    TriviaGame trivia;
    /**
     * @brief display the question, answer, and points
     * Play the game until the player presses q
     * 
     */
    cout << "Welcome to the trivia game!" << endl;
    cout << "Press q to quit." << endl;
    cout << "Press any key to continue." << endl;
    char choice;
    cin >> choice;
    while (choice != 'q')
    {
        trivia.display();
        cout << "Press q to quit." << endl;
        cout << "Press any key to continue." << endl;
        cin >> choice;
    }
}

TriviaGame::TriviaGame()
{
    question = "What is the capital of the United States?";
    answer = "Washington, D.C.";
    points = 10;
}

TriviaGame::~TriviaGame()
{
}

TriviaGame::TriviaGame(string question, string answer, int points)
{
    this->question = question;
    this->answer = answer;
    this->points = points;
}

void TriviaGame::set_question(string question)
{
    this->question = question;
}

void TriviaGame::set_answer(string answer)
{
    this->answer = answer;
}

void TriviaGame::set_points(int points)
{
    this->points = points;
}

string TriviaGame::get_question()
{
    return question;
}

string TriviaGame::generate_random_question()
{
    /**
     * @brief randomly generate a question
     * 
     */
    string questions[][1000] = {"What is the capital of the United States?", "Washington, D.C.", "What is the capital of Canada?", "Ottawa", "What is the capital of Mexico?", "Mexico City", "What is the capital of Brazil?", "Brasilia", "What is the capital of Argentina?", "Buenos Aires", "What is the capital of Australia?", "Canberra", "What is the capital of China?", "Beijing", "What is the capital of India?", "New Delhi", "What is the capital of Japan?", "Tokyo", "What is the capital of Russia?", "Moscow", "What is the capital of South Africa?", "Pretoria", "What is the capital of Spain?", "Madrid", "What is the capital of the United Kingdom?", "London", "What is the capital of the United Arab Emirates?", "Abu Dhabi", "What is the capital of"};
    /**
     * @brief select a random question
     * 
     */
    int q = rand() % 1000;
    return questions[0][q];
}

string TriviaGame::get_answer()
{
    return answer;
}

string TriviaGame::set_answer()
{
    /**
     * @brief set the answer
     * 
     */
    return answer;
}

int TriviaGame::get_points(int points)
{
    return points;
}

int TriviaGame::set_points()
{
    /**
     * @brief set the points
     * 
     */
    return points;
}

int TriviaGame::sum_total_points()
{
    /**
     * @brief sum the total points
     * 
     */
    return points = points; 
}

void TriviaGame::display_points() {
    /**
   * @brief display the points
   *
   */
    //ask the user for the answer
    string user_answer;
    cout << "Answer: ";
    cin >> user_answer;
    //check if the answer is correct
    if (user_answer == answer)
    {
        cout << "Correct!" << endl;
    }
    else
    {
        cout << "Incorrect!" << endl;
    }
    //display the points
    if (points == easy_points)
    {
        cout << "Points: " << points << endl;
    }
    else if (points == medium_points)
    {
        cout << "Points: " << points << endl;
    }
    else if (points == hard_points)
    {
        cout << "Points: " << points << endl;
    }
    else
    {
        cout << "Points: " << points << endl;
    }
    points += points;
    cout << "Points: " << points << endl;
} 

void TriviaGame::display()
{
    /**
     * @brief display the question, answer, and points
     * 
     */
    cout << "Question: " << question << endl;
}

// Path: chapter9\projects\trivia_game\trivia.cpp