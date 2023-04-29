/**
 * @file read_trivia_questions.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string fileName = "trivia_questions.txt";

class TrivialGame
{
private:
    string question;
    string answer;
    int points;

public:
    TrivialGame();
    TrivialGame(string question, string answer, int points);
    void setQuestion(string question);
    void setAnswer(string answer);
    void setPoints(int points);
    string getQuestion();
    string getAnswer();
    int getPoints();
    ~TrivialGame();
};

TrivialGame::TrivialGame()
{
    question = "";
    answer = "";
    points = 0;
}

TrivialGame::TrivialGame(string question, string answer, int points)
{
    this->question = question;
    this->answer = answer;
    this->points = points;
}

void TrivialGame::setQuestion(string question)
{
    this->question = question;
}

void TrivialGame::setAnswer(string answer)
{
    this->answer = answer;
}

void TrivialGame::setPoints(int points)
{
    this->points = points;
}

string TrivialGame::getQuestion()
{
    return question;
}

string TrivialGame::getAnswer()
{
    return answer;
}

int TrivialGame::getPoints()
{
    return points;
}

TrivialGame::~TrivialGame()
{
}

void openFile(ifstream &file)
{
    file.open(fileName.c_str());
    while (file.fail())
    {
        cout << "Error opening file. Try again: ";
        cin >> fileName;
        file.open(fileName.c_str());
    }
}

void storeQuestions(ifstream &file, vector<TrivialGame> &trivialGames)
{
    string line;
    string question, answer;
    int points;
    while (getline(file, line))
    {
        if (line.find("<") != string::npos && line.find(">") != string::npos)
        {
            // Remove angle brackets
            line = line.substr(line.find("<") + 1, line.find(">") - 1);

            if (line.find("Answer:") != string::npos)
            {
                answer = line.substr(line.find("Answer:") + 8);
            }
            else if (line.find("Points:") != string::npos)
            {
                points = stoi(line.substr(line.find("Points:") + 8));
                trivialGames.push_back(TrivialGame(question, answer, points));
            }
            else
            {
                question = line;
            }
        }
    }
}
void displayScore(int points)
{
    cout << "Total points: " << points << endl << endl;
}

bool getUserAnswer(TrivialGame &trivialGame, string &userAnswer)
{
    cout << trivialGame.getQuestion() << endl;
    cout << "Answer (enter 'q' or 'Q' to quit): ";
    getline(cin, userAnswer);

    if (userAnswer == "q" || userAnswer == "Q")
    {
        return false;
    }

    return true;
}

void storeHighScores(int points)
{
    ofstream file;
    file.open("high_scores.txt", ios::app);
    file << points << endl;
    file.close();
}

int resetScoresPerNewGame(int points)
{
    cout << "Would you like to reset the high scores? (y/n): ";
    char resetScores;
    cin >> resetScores;
    if (resetScores == 'y' || resetScores == 'Y')
    {
        ofstream file;
        file.open("high_scores.txt");
        file.close();
        points = 0;
    }
    return points;
}

void appendHighScoresToFile(vector<int> &highScores)
{
    ofstream file;
    file.open("high_scores.txt", ios::app);
    for (int i = 0; i < highScores.size(); i++)
    {
        file << highScores[i] << endl;
    }
    file.close();
}

int main()
{
    ifstream file;
    openFile(file);

    vector<TrivialGame> trivialGames;
    storeQuestions(file, trivialGames);
    file.close();

    vector<int> highScores;

    srand(time(NULL));
    string userAnswer;
    int totalPoints = 0;

    while (true)
    {
        int randomQuestion = rand() % trivialGames.size();
        TrivialGame currentQuestion = trivialGames[randomQuestion];

        if (!getUserAnswer(currentQuestion, userAnswer))
        {
            break;
        }

        if (userAnswer == currentQuestion.getAnswer())
        {
            cout << "Correct!" << endl;
            int pointsEarned = currentQuestion.getPoints();
            totalPoints += pointsEarned;
            cout << "Points earned: " << pointsEarned << endl;
        }
        else
        {
            cout << "Incorrect!" << endl;
            cout << "The correct answer is: " << currentQuestion.getAnswer() << endl;
        }

        displayScore(totalPoints);
    }

    cout << "Thanks for playing! Your final score is: " << totalPoints << endl;

    storeHighScores(totalPoints);
    appendHighScoresToFile(highScores);

    totalPoints = resetScoresPerNewGame(totalPoints);

    return 0;
}
