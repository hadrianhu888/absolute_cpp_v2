/**
 * @file memory_card_game.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */#include <iostream>
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

#define BOARD_SIZE 4
#define MAX_CARDS 16
#define MAX_SUITS 4
#define MAX_CARDS_PER_SUIT 4
#define MAX_CARDS_PER_BOARD 8

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

/**
 * @brief 
 * Set up a memory card game. The game should have a 4x4 grid of cards. Each card has a number on it. The numbers are 1-8, and each number appears twice. The player should be able to click on two cards. If the cards match, they should stay face up. If they don't match, they should flip back over. The game is over when all the cards are face up.
 */

/**
 * @brief setup basjc variables and data structures
 * 
 */

typedef struct cards {
    string card;
    bool is_matched;
} cards;

typedef struct suite {
    string suite;
    vector<string> cards;
} suite;

typedef struct deck{ 
    vector<suite> suites;
} deck;

/**
 * @brief 
 * 
 * @param deck 
 * @param board 
 * @param player 
 * @param card 
 * @return true 
 * @return false 
 */

/**
 * @brief basic function prototypes 
 * 
 */

/**
 * @brief 2D array for the board
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

int board[BOARD_SIZE][BOARD_SIZE];

/**
 * @brief 2D array for whether the card is flipped or not
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

bool flipped[BOARD_SIZE][BOARD_SIZE];

/**
 * @brief 2D array for whether the card is matched or not
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

bool matched[BOARD_SIZE][BOARD_SIZE];

/**
 * @brief basic function prototypes
 * 
 */

void print_board(void);
bool is_valid_move(int, int);
int flip_card(int, int);
bool is_game_over(void);
int get_random_number(int, int);
void init_board(void);
void init_flipped(void);
void init_matched(void);
void init_deck(deck *);
void init_suites(deck *);
void print_card_value(int, int);
int get_random_card_value(deck *);
int main(int argc, char **argv); 

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

int get_random_card_value(deck *)
{
    int card_value = get_random_number(1, MAX_CARDS_PER_BOARD);
    return card_value;
}

void print_card_value(int, int)
{
    /**
     * @brief random row and column
     * 
     */
    int row, col;
    row = get_random_number(0, BOARD_SIZE - 1);
    col = get_random_number(0, BOARD_SIZE - 1);
    /**
     * @brief 
     * 
     */
    cout << board[row][col] << endl;
}

void print_board(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (flipped[i][j]) {
                cout << board[i][j] << " ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

bool is_valid_move(int row, int col)
{
    if (row < 0 || row >= BOARD_SIZE) {
        return false;
    }
    if (col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (flipped[row][col]) {
        return false;
    }
    return true;
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

int flip_card(int row, int col)
{
    if (!is_valid_move(row, col)) {
        return -1;
    }
    flipped[row][col] = true;
    /**
     * @brief show value of flipped cards
     * select a random card from the deck
     */
    int card_value = rand() % 8 + 1;
    print_card_value(row, col);
    return card_value; 
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

bool is_game_over(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!matched[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

int get_random_number(int min, int max)
{
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

void init_board(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

void init_flipped(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            flipped[i][j] = false;
        }
    }
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

void init_matched(void)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            matched[i][j] = false;
        }
    }
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

void init_deck(deck *deck)
{
    init_suites(deck);
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

void init_suites(deck *deck)
{
    for (int i = 0; i < MAX_SUITS; i++) {
        suite suite;
        suite.suite = "suite" + to_string(i);
        for (int j = 0; j < MAX_CARDS_PER_SUIT; j++) {
            suite.cards.push_back("card" + to_string(j));
        }
        deck->suites.push_back(suite);
    }
}

/**
 * @brief 
 * 
 * @param deck 
 * @param card 
 * @return true 
 * @return false 
 */

int main(int argc, char **argv)
{
    deck deck;
    init_deck(&deck);
    init_board();
    init_flipped();
    init_matched();
    int row, col;
    while (!is_game_over()) {
        print_board();
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter col: ";
        cin >> col;
        flip_card(row, col);
    }
    print_board();
    cout << "You win!" << endl;
    return 0;
}