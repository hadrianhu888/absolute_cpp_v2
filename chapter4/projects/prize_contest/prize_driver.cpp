/**
 * @file prize_driver.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "common.hpp"
#include "prize_contest.cpp"
#include "prize_contest.hpp"

int prize_contest_main(int argc, char **argv); // function prototype

int main(int argc, char **argv) {
  prize_contest_main(argc, argv);
  return 0;
}

int prize_contest_main(int argc, char **argv) {
  // automatically play the game 10 thousand times
  int win = 0;
  int lose = 0;
  play_10_thousand_games(win, lose);
}
