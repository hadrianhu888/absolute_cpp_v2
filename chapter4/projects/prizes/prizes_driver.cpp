/**
 * @file prizes_driver.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "common.hpp"
#include "prizes.hpp"
#include "prizes.cpp"

int prizes_main(int argc, char **argv); // function prototype

int main(int argc, char **argv) {
  prizes_main(argc, argv);
  return 0;
}

int prizes_main(int argc, char **argv) {
  // automatically play the game 10 thousand times
  int win = 0;
  int lose = 0;
  play_10_thousand_games(win, lose);
  return 0;
}

