/**
 * @file new_memory_card_game.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 4;
const int COLS = 4;
const int NUM_CARDS = 8;
const int NUM_FLIPS = 2;

void initDeck(int deck[][COLS], int rows, int cols);
void shuffleDeck(int deck[][COLS], int rows, int cols);
void printDeck(int deck[][COLS], int rows, int cols);
bool isValidFlip(int deck[][COLS], int rows, int cols, int row, int col);
bool isGameOver(int deck[][COLS], int rows, int cols);
bool isInvalidInput(int row, int col);
int main(int argc,char **argv);
void print_game_statistic(int deck[][COLS], int rows, int cols);

int main(int argc,char **argv)
{
    srand(time(NULL));
    int deck[ROWS][COLS];
    int numFlips = 0;
    int flips[NUM_FLIPS][2] = {0}; // store the row and column of the flips
    initDeck(deck, ROWS, COLS);
    shuffleDeck(deck, ROWS, COLS);
    /**
     * @brief print game statistics during game play
     * 
     */
    while (!isGameOver(deck, ROWS, COLS))
    {
        cout << "Current board:" << endl;
        printDeck(deck, ROWS, COLS);
        cout << "Enter row and column of card to flip: ";
        int row, col;
        cin >> row >> col;
        if (isInvalidInput(row, col))
        {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        if (isValidFlip(deck, ROWS, COLS, row, col))
        {
            flips[numFlips][0] = row;
            flips[numFlips][1] = col;
            numFlips++;
            if (numFlips == NUM_FLIPS) // check if two cards have been flipped
            {
                int r1 = flips[0][0];
                int c1 = flips[0][1];
                int r2 = flips[1][0];
                int c2 = flips[1][1];
                if (deck[r1][c1] == deck[r2][c2]) // check if the cards match
                {
                    cout << "Match found!" << endl;
                }
                else // flip the cards back over
                {
                    cout << "No match found." << endl;
                    deck[r1][c1] = 0;
                    deck[r2][c2] = 0;
                }
                numFlips = 0;
            }
        }
        else
        {
            cout << "Invalid flip. Try again." << endl;
            print_game_statistic(deck, ROWS, COLS);
        }
    }
    cout << "Congratulations! You win!" << endl;
    return 0;
}

void initDeck(int deck[][COLS], int rows, int cols)
{
    int cardCount = 1;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            deck[r][c] = cardCount % NUM_CARDS;
            cardCount++;
        }
    }
}

void shuffleDeck(int deck[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows * cols; i++)
    {
        int r1 = rand() % rows;
        int c1 = rand() % cols;
        int r2 = rand() % rows;
        int c2 = rand() % cols;
        int temp = deck[r1][c1];
        deck[r1][c1] = deck[r2][c2];
        deck[r2][c2] = temp;
    }
}

void printDeck(int deck[][COLS], int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (deck[r][c] == 0)
            {
                cout << "X ";
            }
            else
            {
                cout << deck[r][c] << " ";
            }
        }
        cout << endl;
    }
}

bool isValidFlip(int deck[][COLS], int rows, int cols, int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return false;
    }
    if (deck[row][col] == 0)
    {
        return false;
    }
    return true;
}

bool isInvalidInput(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        return true;
    }
    return false;
}

bool isGameOver(int deck[][COLS], int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (deck[r][c] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void print_game_statistic(int deck[][COLS], int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << deck[r][c] << " ";
        }
        cout << endl;
    }
}
