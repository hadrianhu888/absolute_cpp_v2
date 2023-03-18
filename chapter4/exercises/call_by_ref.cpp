/**
 * @file call_by_ref.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

void getNumbers(int &input1, int &input2, int &output1, int &output2);
void swapNumbers(int &input1, int &input2, int &output1, int &output2);
void showResults(int output1, int output2);
int main(int argc, char **argv);

int main(int argc, char **argv) {
  int firstNum, secondNum, firstNumSwap, secondNumSwap;
  firstNum = atoi(argv[1]);
  secondNum = atoi(argv[2]);
  getNumbers(firstNum, secondNum, firstNumSwap, secondNumSwap);
  swapNumbers(firstNum, secondNum, firstNumSwap, secondNumSwap);
  showResults(firstNumSwap, secondNumSwap);
  return 0;
}

void getNumbers(int &input1, int &input2, int &output1, int &output2) {
  cout << "Enter two numbers: ";
  cin >> input1 >> input2;
  output1 = input1;
  output2 = input2;
}

void swapNumbers(int &input1, int &input2, int &output1, int &output2) {
  output1 = input2;
  output2 = input1;
}

void showResults(int output1, int output2) {
  cout << "The numbers in reverse order are: " << output1 << " " << output2
       << endl;
}