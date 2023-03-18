/**
 * @file memory_matching_cards.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <map>
#include <set>
#include <cstring>

using namespace std;
using namespace std::chrono;

const int MAX = 4;
const int MAX_CARDS = 16;
const int MAX_SUITS = 4;
const int MAX_CARDS_PER_SUIT = 4;
const int MAX_CARDS_PER_BOARD = 8;
const int MAX_CARDS_PER_PLAYER = 8;
const int MAX_PLAYERS = 2;
const int MAX_CARDS_PER_DECK = 8;

/**
 * @brief each turn prints a random card from the deck (1 to 8)
 * 
 */

typedef struct cards {
    string card;
    bool is_matched;
} cards;
typedef  struct board {
    cards card;
    bool is_matched;
} board;
typedef struct suite {
    string suite;
    vector<string> cards;
} suite;
typedef struct deck{ 
    vector<suite> suites;
} deck;
/**
 * @brief Create a classic deck of cards 
 * 
 * @param board 
 */

/******************************
* Start with a four by four board 
*  Initialize empty cells with stars
*  Shuffle the board
* Shuffle the cards (max value of cards are up to eight). 
*

****************************/
typedef struct classic_deck {
    vector<string> cards;
} classic_deck;
void printBoard(const vector<string> &board);
void shuffleBoard(vector<string> &board);
void initializeBoard(vector<string> &board);
void shuffle_cards(vector<string> &cards);
void print_cards(const vector<string> &cards);
void initialize_cards(vector<string> &cards);
void select_random_cards(vector<string> &cards);
int select_random_row(const vector <string> &board);
int select_random_column(const vector <string> &board);
int select_random_cell_on_game_board(const vector <string> &board);
void print_card_string_values(const vector<string> &cards);
int main(int argc, char **argv); // main function prototype

int select_random_row(const vector <string> &board)
{
    //random row
    int row = rand() % MAX;
    return row;
}

int select_random_column(const vector <string> &board)
{
    //random column
    int column = rand() % MAX;
    return column;
}

int select_random_cell_on_game_board(const vector <string> &board)
{
    int random_cell = rand() % MAX_CARDS;
    return random_cell;
}

void printBoard(const vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << board[i] << " ";
        if ((i + 1) % 4 == 0)
        {
            cout << endl;
        }
    }
}

void shuffleBoard(vector<string> &board)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(board.begin(), board.end(), std::default_random_engine(seed));
}

void initializeBoard(vector<string> &board)
{
    for (int i = 0; i < MAX_CARDS; i++)
    {
        board.push_back("*");
    }
}

void shuffle_cards(vector<string> &cards)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

void print_cards(const vector<string> &cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i] << " ";
    }
    cout << endl;
}

void initialize_cards(vector<string> &cards)
{
    for (int i = 0; i < MAX_CARDS_PER_DECK; i++)
    {
        cards.push_back(to_string(i + 1));
    }
}

void select_random_cards(vector<string> &cards)
{
    vector<string> selected_cards;
    /**
     * @brief There are only two cards selected at any time in the game 
     * select random locations on the board -rows and columns
     * 
     */
    int random_card = rand() % MAX_CARDS_PER_DECK;
    selected_cards.push_back(cards[random_card]);
    selected_cards.push_back(cards[random_card]);
    /**
     * @brief random location on the board
     * 
     */
    for (int i = 0; i < MAX_CARDS_PER_BOARD; i++)
    {
        int random_card = rand() % MAX_CARDS_PER_DECK;
        selected_cards.push_back(cards[random_card]);
    }
    cards = selected_cards;
}

void print_card_string_values(const vector<string> &cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    vector<string> board;
    vector<string> cards;
    initializeBoard(board);
    initialize_cards(cards);
    shuffle_cards(cards);
    select_random_cards(cards);
    print_card_string_values(cards);
    shuffleBoard(board);
    printBoard(board);
    return 0;
}

