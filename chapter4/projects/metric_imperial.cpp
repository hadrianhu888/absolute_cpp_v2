/**
 * @file metric_imperial.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "metric_imperial.hpp"

/**
* @brief converts feet and inches to meters and centimeters.
    Do this repeatedly until the user enters 0 feet and 0 inches.
*/

double feet2inches(double feet) {
  double inches = feet * INCHES_PER_FOOT;
  return inches;
}

double inches2meters(double inches) {
  double meters = inches * INCH_2_METER;
  return meters;
}

double inches2centimeters(double inches) {
  double centimeters = inches * INCH_2_CENTIMETER;
  return centimeters;
}

double meters2inches(double meters) {
  double inches = meters * METER_2_INCH;
  return inches;
}

double centimeters2inches(double centimeters) {
  double inches = centimeters * CENTIMETER_2_INCH;
  return inches;
}

double check_total_measurement_feet_inches(double feet, double inches) {
  double total_inches = feet2inches(feet) + inches;
  if (total_inches > INCHES_PER_FOOT) {
    double feet = total_inches / INCHES_PER_FOOT;
    double inches = (int)total_inches % INCHES_PER_FOOT;
    cout << "Total measurement: " << feet << " feet and " << inches << " inches"
         << endl;
  }
  return total_inches;
}

double check_total_measurement_meters_centimeters(double meters,
                                                  double centimeters) {
  double total_inches = meters2inches(meters) + centimeters2inches(centimeters);
  if (total_inches > INCHES_PER_FOOT) {
    double feet = total_inches / INCHES_PER_FOOT;
    double inches = (int)total_inches % INCHES_PER_FOOT;
    cout << "Total measurement: " << feet << " feet and " << inches << " inches"
         << endl;
  }
  return total_inches;
}

void display_menu(void) {
  cout << "1. Convert feet and inches to meters and centimeters" << endl;
  cout << "2. Convert meters and centimeters to feet and inches" << endl;
  cout << "3. Quit" << endl;
}

void display_metric_to_imperial_menu(void) {
  cout << "1. Convert feet and inches to meters and centimeters" << endl;
  cout << "2. Convert meters and centimeters to feet and inches" << endl;
  cout << "3. Quit" << endl;
}
void display_imperial_to_metric_menu(void) {
  cout << "1. Convert feet and inches to meters and centimeters" << endl;
  cout << "2. Quit" << endl;
}

char get_user_choice(void) {
  char choice;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}

double imperial_to_metric(char choice) {
  /**
   * @brief only the imperial to metric part should be here
   *
   */
  double feet, inches, meters, centimeters, total_inches;
  switch (choice) {
  case '1':
    cout << "Enter feet: ";
    cin >> feet;
    cout << "Enter inches: ";
    cin >> inches;
    total_inches = check_total_measurement_feet_inches(feet, inches);
    meters = inches2meters(total_inches);
    centimeters = inches2centimeters(total_inches);
    cout << "Total measurement: " << meters << " meters and " << centimeters
         << " centimeters" << endl;
    break;
  default:
    cout << "Invalid choice" << endl;
    break;
  }
  return 0;
}

double metric_to_imperial(char choice) {
  /**
   * @brief only the metric to imperial part should be here
   *
   */
  double feet, inches, meters, centimeters, total_inches;
  switch (choice) {
  case '2':
    cout << "Enter meters: ";
    cin >> meters;
    cout << "Enter centimeters: ";
    cin >> centimeters;
    total_inches =
        check_total_measurement_meters_centimeters(meters, centimeters);
    feet = total_inches / INCHES_PER_FOOT;
    inches = (int)total_inches % INCHES_PER_FOOT;
    cout << "Total measurement: " << feet << " feet and " << inches << " inches"
         << endl;
    break;
  default:
    cout << "Invalid choice" << endl;
    break;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  /**
   * @brief shows the main menu for conversions between imperial and metric
   *
   */
  display_menu();
  char choice;
  choice = get_user_choice();
  while (choice != '3') {
    switch (choice) {
    case '1':
      /**
       * @brief refactor the choices into functions
       *
       */
      display_imperial_to_metric_menu();
      choice = get_user_choice();
      imperial_to_metric(choice);
      break;
    case '2':
      /**
       * @brief refactor the choices into functions
       *
       */
      display_metric_to_imperial_menu();
      choice = get_user_choice();
      metric_to_imperial(choice);
    default:
      cout << "Invalid choice" << endl;
      break;
    }
    display_menu();
    choice = get_user_choice();
  }
  return 0;
}
