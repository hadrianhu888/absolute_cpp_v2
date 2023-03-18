/**
 * @file delete_repeats.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;
using namespace std::chrono;

/**
 * @brief Deletes repeated letters in a string
 *
 */

string input_string;
string output_string;
char letter2delete;

void read_string(void);
void delete_repeats(char letter);
void print_string(void);
int main(int argc, char **argv);
void get_letter(void);

void read_string(void) {
  cout << "Enter a string: ";
  getline(cin, input_string);
}

void delete_repeats(char letter) {
  for (int i = 0; i < input_string.length(); i++) {
    if (input_string[i] == letter) {
      input_string.erase(i, 1);
      i--;
    }
  }
}

void print_string(void) {
  cout << "The string without repeated letters is: " << input_string << endl;
}

void get_letter(void) {
  cout << "Enter a letter to delete: ";
  cin >> letter2delete;
}

int main(int argc, char **argv) {
  read_string();
  get_letter();
  delete_repeats(letter2delete);
  print_string();
  return 0;
}
