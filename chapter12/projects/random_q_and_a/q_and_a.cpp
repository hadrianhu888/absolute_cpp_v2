/**
 * @file q_and_a.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

const string ANSWER_FILE_NAME = "answers.txt";

int main(int argc, char **argv);
void getQuestionFromUser(string &question);
string selectRandomAnswerFromAnswerFile(const vector<string> &answers);
int randomNumberGenerator(int min, int max);
void displayRandomAnswer(const string &question, const string &answer);
vector<string> storeAnswersInVector();

void getQuestionFromUser(string &question)
{
    cout << "Ask a yes/no question: ";
    getline(cin, question);
}

string selectRandomAnswerFromAnswerFile(const vector<string> &answers)
{
    int index = randomNumberGenerator(0, answers.size() - 1);
    return answers[index];
}

int randomNumberGenerator(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void displayRandomAnswer(const string &question, const string &answer)
{
    cout << "Your question was: " << question << endl;
    cout << "The answer is: " << answer << endl;
}

vector<string> storeAnswersInVector()
{
    vector<string> answers;
    string answer;
    ifstream answer_file(ANSWER_FILE_NAME);

    if (!answer_file.is_open())
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    while (getline(answer_file, answer))
    {
        answers.push_back(answer);
    }

    return answers;
}

int main(int argc, char **argv)
{
    string question;
    vector<string> answers = storeAnswersInVector();

    srand(time(NULL));

    getQuestionFromUser(question);
    string randomAnswer = selectRandomAnswerFromAnswerFile(answers);
    displayRandomAnswer(question, randomAnswer);

    return 0;
}
