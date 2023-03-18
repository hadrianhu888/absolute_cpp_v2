/**
 * @file weight_length.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "weight_length.hpp"

void show_menu(void) {
  cout << "Choose between weight and length conversion: " << endl;
  cout << "1. Weight" << endl;
  cout << "2. Length" << endl;
  cout << "3. Exit" << endl;
}

void show_weight_menu(void) {
  cout << "Choose between weight conversion: " << endl;
  cout << "1. Pounds to kilograms" << endl;
  cout << "2. Kilograms to pounds" << endl;
  cout << "3. Grams to ounces" << endl;
  cout << "4. Ounces to grams" << endl;
  cout << "5. Exit" << endl;
}

void show_length_menu(void) {
  cout << "Choose between length conversion: " << endl;
  cout << "1. Inches to centimeters" << endl;
  cout << "2. Centimeters to inches" << endl;
  cout << "3. Feet to meters" << endl;
  cout << "4. Meters to feet" << endl;
  cout << "5. Exit" << endl;
}

void show_metric_menu(void) {
  cout << "Choose between metric conversion: " << endl;
  cout << "1. Inches to centimeters" << endl;
  cout << "2. Centimeters to inches" << endl;
  cout << "3. Exit" << endl;
}

void show_imperial_menu(void) {
  cout << "Choose between imperial conversion: " << endl;
  cout << "1. Feet to meters" << endl;
  cout << "2. Meters to feet" << endl;
  cout << "3. Exit" << endl;
}

int main_test(int argc, char **argv) {
  /**
   * @brief choose between weight and length conversion
   * value of 1 means weight conversion
   * value of 2 means length conversion
   */
  show_menu();
  cin >> choice;
  switch (choice) {
  case 1:
    show_weight_menu();
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter the weight in pounds: ";
      cin >> pounds;
      cout << "The weight in kilograms is: " << pounds2kg(pounds) << endl;
      break;
    case 2:
      cout << "Enter the weight in kilograms: ";
      cin >> kg;
      cout << "The weight in pounds is: " << kg2pounds(kg) << endl;
      break;
    case 3:
      cout << "Enter the weight in grams: ";
      cin >> gm;
      cout << "The weight in ounces is: " << gm2ounce(gm) << endl;
      break;
    case 4:
      cout << "Enter the weight in ounces: ";
      cin >> ounce;
      cout << "The weight in grams is: " << ounce2gm(ounce) << endl;
      break;
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
    break;
  }
  return 0;
}
