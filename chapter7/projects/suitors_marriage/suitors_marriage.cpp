/**
 * @file suitors_marriage.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

/**
 * @brief the princess assigns numbers to n suitors and eliminates every mth suitor
 * in this case m = 3
 * use a vector to iterate through te suitors and start from the first suitor and then eliminate every mth suitor iteratively until only one suitor is left
 */

const int M = 3;

int main(int argc, char **argv);

class Suitors_Marriage
{
    private:
        int suitors;
        int eliminated;
        int winner;
    public:
        Suitors_Marriage(int suitors);
        void print();
        int getSuitors();
        void setSuitors(int suitors);
        int getEliminated();
        void setEliminated(int eliminated);
        int getWinner();
        void setWinner(int winner);
        void eliminate();
        void eliminate(int suitors, int eliminated);
        void findWinner();
        void findWinner(int suitors, int eliminated);
};

Suitors_Marriage::Suitors_Marriage(int suitors)
{
    this->suitors = suitors;
}

void Suitors_Marriage::print()
{
    cout << "suitors = " << suitors << endl;
    cout << "eliminated = " << eliminated << endl;
    cout << "winner = " << winner << endl;
}

int Suitors_Marriage::getSuitors()
{
    return suitors;
}

void Suitors_Marriage::setSuitors(int suitors)
{
    this->suitors = suitors;
}

int Suitors_Marriage::getEliminated()
{
    return eliminated;
}

void Suitors_Marriage::setEliminated(int eliminated)
{
    this->eliminated = eliminated;
}

int Suitors_Marriage::getWinner()
{
    return winner;
}

void Suitors_Marriage::setWinner(int winner)
{
    this->winner = winner;
}

void Suitors_Marriage::eliminate()
{
    vector<int> suitors_vector;
    for (int i = 1; i <= suitors; i++)
    {
        suitors_vector.push_back(i);
    }
    int eliminated = 0;
    int winner = 0;
    int i = 0;
    while (suitors_vector.size() > 1)
    {
        if (i == suitors_vector.size())
        {
            i = 0;
        }
        if (eliminated == M - 1)
        {
            suitors_vector.erase(suitors_vector.begin() + i);
            eliminated = 0;
        }
        else
        {
            eliminated++;
            i++;
        }
    }
    winner = suitors_vector[0];
    cout << "The winner is " << winner << endl;
}

void Suitors_Marriage::eliminate(int suitors, int eliminated)
{
    vector<int> suitors_vector;
    for (int i = 1; i <= suitors; i++)
    {
        suitors_vector.push_back(i);
    }
    int i = 0;
    while (suitors_vector.size() > 1)
    {
        if (i == suitors_vector.size())
        {
            i = 0;
        }
        if (eliminated == M - 1)
        {
            suitors_vector.erase(suitors_vector.begin() + i);
            eliminated = 0;
        }
        else
        {
            eliminated++;
            i++;
        }
    }
    winner = suitors_vector[0];
    cout << "The winner is " << winner << endl;
}

void Suitors_Marriage::findWinner()
{
    vector<int> suitors_vector;
    for (int i = 1; i <= suitors; i++)
    {
        suitors_vector.push_back(i);
    }
    int eliminated = 0;
    int winner = 0;
    int i = 0;
    while (suitors_vector.size() > 1)
    {
        if (i == suitors_vector.size())
        {
            i = 0;
        }
        if (eliminated == M - 1)
        {
            suitors_vector.erase(suitors_vector.begin() + i);
            eliminated = 0;
        }
        else
        {
            eliminated++;
            i++;
        }
    }
    winner = suitors_vector[0];
    cout << "The winner is " << winner << endl;
}

void Suitors_Marriage::findWinner(int suitors, int eliminated)
{
    vector<int> suitors_vector;
    for (int i = 1; i <= suitors; i++)
    {
        suitors_vector.push_back(i);
    }
    int i = 0;
    while (suitors_vector.size() > 1)
    {
        if (i == suitors_vector.size())
        {
            i = 0;
        }
        if (eliminated == M - 1)
        {
            suitors_vector.erase(suitors_vector.begin() + i);
            eliminated = 0;
        }
        else
        {
            eliminated++;
            i++;
        }
    }
    winner = suitors_vector[0];
    cout << "The winner is " << winner << endl;
}

int main(int argc, char **argv)
{
    int suitors;
    cout << "Enter the number of suitors: ";
    cin >> suitors;
    Suitors_Marriage suitors_marriage(suitors);
    suitors_marriage.eliminate();
    suitors_marriage.findWinner();
    return 0;
}