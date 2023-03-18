/**
 * @file driver.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "common.hpp"
#include "lengths.cpp"
#include "lengths.hpp"
#include "weights.cpp"
#include "weights.hpp"

void menu(void) {
  cout << "1. Lengths" << endl;
  cout << "2. Weights" << endl;
  cout << "3. Quit" << endl;
}

void length(void) {
  double feet, meters, inches, meters2;
  cout << "Enter a length in feet: ";
  cin >> feet;
  meters = feet2meters(feet);
  cout << feet << " feet is " << meters << " meters" << endl;
  cout << "Enter a length in inches: ";
  cin >> inches;
  meters2 = inches2meters(inches);
  cout << inches << " inches is " << meters2 << " meters" << endl;
}

void weight(void) {
  double pounds, kg, gm, ounce;
  cout << "Enter a weight in pounds: ";
  cin >> pounds;
  kg = pounds2kg(pounds);
  cout << pounds << " pounds is " << kg << " kilograms" << endl;
  cout << "Enter a weight in grams: ";
  cin >> gm;
  ounce = gm2ounce(gm);
  cout << gm << " grams is " << ounce << " ounces" << endl;
}

void quit(void) { cout << "Goodbye!" << endl; }

int main(int argc, char **argv) {
  int choice;
  do {
    menu();
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      length();
      break;
    case 2:
      weight();
      break;
    case 3:
      quit();
      break;
    default:
      cout << "Invalid choice" << endl;
    }
  } while (choice != 3);
  return 0;
}
