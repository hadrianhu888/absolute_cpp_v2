/**
 * @file lb_oz_2_kg_gm.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "lb_oz_2_kg_gm.hpp"

float pounds2kg(float pounds) { return pounds * POUND_2_KG; }

float kg2pounds(float kg) { return kg * KG_2_POUND; }

float gm2ounce(float gm) { return gm * GM_2_OUNCE; }

float ounce2gm(float ounce) { return ounce * OUNCE_2_GM; }

int main(int argc, char const *argv[]) {
  float pounds = 0.0;
  float kg = 0.0;
  float gm = 0.0;
  float ounce = 0.0;

  cout << "Enter the weight in pounds: ";
  cin >> pounds;
  cout << "Enter the weight in kilograms: ";
  cin >> kg;
  cout << "Enter the weight in grams: ";
  cin >> gm;
  cout << "Enter the weight in ounces: ";
  cin >> ounce;

  cout << "The weight in kilograms is: " << pounds2kg(pounds) << endl;
  cout << "The weight in pounds is: " << kg2pounds(kg) << endl;
  cout << "The weight in grams is: " << gm2ounce(gm) << endl;
  cout << "The weight in ounces is: " << ounce2gm(ounce) << endl;

  return 0;
}