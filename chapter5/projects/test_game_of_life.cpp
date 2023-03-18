#include <gtest/gtest.h>
#include "game_of_life_new.cpp"

// Test initialization of board with correct dimensions
TEST(GameOfLifeTest, BoardDimensions) {
  vector<vector<int>> board;
  initBoard(board);
  EXPECT_EQ(ROWS, board.size());
  for (int i = 0; i < ROWS; i++) {
    EXPECT_EQ(COLS, board[i].size());
  }
}

// Test if a cell with fewer than two live neighbors dies
TEST(GameOfLifeTest, Underpopulation) {
  vector<vector<int>> board = {
      {0, 1, 0},
      {0, 1, 0},
      {0, 0, 0}
  };
  simulateGeneration(board);
  EXPECT_EQ(0, board[0][1]);
}

// Test if a cell with two or three live neighbors lives on to the next generation
TEST(GameOfLifeTest, Survival) {
  vector<vector<int>> board = {
      {0, 1, 1},
      {1, 1, 0},
      {0, 0, 0}
  };
  simulateGeneration(board);
  EXPECT_EQ(1, board[0][1]);
}

// Test if a cell with more than three live neighbors dies from overcrowding
TEST(GameOfLifeTest, Overcrowding) {
  vector<vector<int>> board = {
      {1, 1, 1},
      {1, 1, 0},
      {0, 0, 0}
  };
  simulateGeneration(board);
  EXPECT_EQ(0, board[0][0]);
}

// Test if a dead cell with exactly three live neighbors becomes a live cell
TEST(GameOfLifeTest, Reproduction) {
  vector<vector<int>> board = {
      {0, 1, 0},
      {1, 1, 0},
      {0, 0, 0}
  };
  simulateGeneration(board);
  EXPECT_EQ(1, board[0][0]);
}
/*
0 0 1 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 
1 0 1 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 
0 0 1 0 1 1 0 0 0 1 0 1 1 0 1 1 0 1 1 0 
1 1 0 0 1 1 0 1 0 0 1 0 0 1 0 0 0 0 0 0 
0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 0 1 1 0 0 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 
*/
