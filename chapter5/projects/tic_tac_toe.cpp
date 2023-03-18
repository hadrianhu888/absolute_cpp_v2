/**
 * @file tic_tac_toe.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Play a game of tic_tac_coe on a 3x3 board. 
    * 
    * Simulate 1000 games of tic_tac_toe and print the number of times each player wins.
 * 
 */

#include <iostream>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector> 
#include <string>

using namespace std;
using namespace std::chrono;

#define ARRAY_SIZE 3 
#define GAMES_PLAYED 10000

int board[ARRAY_SIZE][ARRAY_SIZE];
int player1_wins = 0;
int player2_wins = 0;
char X ='X'; 
char O ='O'; 
float player1_win_percentage = 0.0;
float player2_win_percentage = 0.0;
float player1_lose_percentage = 0.0;
float player2_lose_percentage = 0.0;

void clear_board(int board[ARRAY_SIZE][ARRAY_SIZE]);
void display_board(int board[ARRAY_SIZE][ARRAY_SIZE]);
void play__game(int board[ARRAY_SIZE][ARRAY_SIZE]);
void play_1_000_games(int board[ARRAY_SIZE][ARRAY_SIZE]);
void draw_X(int board[ARRAY_SIZE][ARRAY_SIZE],int row,int col);
void draw_O(int board[ARRAY_SIZE][ARRAY_SIZE],int row,int col);
void check_for_winner(int board[ARRAY_SIZE][ARRAY_SIZE]);
void check_for_loser(int board[ARRAY_SIZE][ARRAY_SIZE]);
int main(int argc,char **argv);

void clear_board(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void draw_X(int board[ARRAY_SIZE][ARRAY_SIZE],int row,int col) {
    board[row][col] = X;
}

void draw_O(int board[ARRAY_SIZE][ARRAY_SIZE],int row,int col) {
    board[row][col] = O; 
}

void check_for_winner(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    // Check for horizontal wins
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            player1_wins++;
        }
        if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
            player2_wins++;
        }
    }
    // Check for vertical wins
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
            player1_wins++;
        }
        if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2) {
            player2_wins++;
        }
    }
    // Check for diagonal wins
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        player1_wins++;
    }
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        player2_wins++;
    }
    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        player1_wins++;
    }
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        player2_wins++;
    }
}

void check_for_loser(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    // Check for horizontal wins
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            player2_wins++;
        }
        if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
            player1_wins++;
        }
    }
    // Check for vertical wins
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
            player2_wins++;
        }
        if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2) {
            player1_wins++;
        }
    }
    // Check for diagonal wins
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        player2_wins++;
    }
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        player1_wins++;
    }
    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        player2_wins++;
    }
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        player1_wins++;
    }
}

void play_game(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    int r; 
    int c;
    int turn = 0;
    int winner = 0;
    int loser = 0;
    // Play the game
    while (winner == 0 && loser == 0) {
        if (turn == 0) {
            // Player 1's turn
            cout << "Player 1's turn" << endl;
            cout << "Enter a row: ";
            cin >> r;
            cout << "Enter a column: ";
            cin >> c;
            draw_X(board,r,c);
            display_board(board);
            check_for_winner(board);
            if (player1_wins > 0) {
                winner = 1;
            }
            turn = 1;
        } else {
            // Player 2's turn
            cout << "Player 2's turn" << endl;
            cout << "Enter a row: ";
            cin >> r;
            cout << "Enter a column: ";
            cin >> c;
            draw_O(board,r,c);
            display_board(board);
            check_for_winner(board);
            if (player2_wins > 0) {
                winner = 1;
            }
            turn = 0;
        }
    }
}

void play_1_000_games(int board[ARRAY_SIZE][ARRAY_SIZE]) {
    for (int i = 0; i < 1000; i++) {
        play_game(board);
        clear_board(board);
    }
}

int main(int argc,char **argv) {
    int board[ARRAY_SIZE][ARRAY_SIZE];
    clear_board(board);
    play_1_000_games(board);
    cout << "Player 1 wins: " << player1_wins << endl;
    cout << "Player 2 wins: " << player2_wins << endl;
    return 0;
}