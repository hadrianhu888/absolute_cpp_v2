/**
 * @file airline_seating.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <ctime>
#include <cstdio>
#include <array>
#include <chrono> 

using namespace std;
using namespace std::chrono;

/**
 * @brief lists out the available seats on an airplane in a 2D array
	Determines if a seat is available or not
	Prints out the available seats
	Prints out the unavailable seats
	Prints out the total number of seats available
 * Ability to book a seat
	* Ability to cancel a seat
	* Ability to print out the seating chart
 */

 // Global variables

int** seating_chart;
int rows;
int columns;
int total_seats;
int available_seats;
int unavailable_seats;
bool seat_taken;
bool seat_available;

// Constants
const int MAX_ROWS = 10;
const int MAX_COLUMNS = 10;

// Function prototypes

void read_seating_chart(string filename); 
void print_seating_chart(void);
void print_available_seats(void);
void print_unavailable_seats(void);
void print_total_seats(void);
void book_seat(void);
void cancel_seat(void);
void print_seating_chart(void);
int main(int argc, char** argv);

void read_seating_chart(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (infile.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	string line;
	int i = 0;
	while (getline(infile, line))
	{
		stringstream ss(line);
		string row;
		int column;
		ss >> row >> column;
		rows = stoi(row);
		columns = column;
		seating_chart = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			seating_chart[i] = new int[columns];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				seating_chart[i][j] = 0;
			}
		}
		i++;
	}
	infile.close();
}

void print_seating_chart(void)
{
	cout << "Seating Chart" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << seating_chart[i][j] << " ";
		}
		cout << endl;
	}
}

void print_available_seats(void)
{
	cout << "Available Seats" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (seating_chart[i][j] == 0)
			{
				cout << "Row: " << i << " Column: " << j << endl;
			}
		}
	}
}

void print_unavailable_seats(void)
{
	cout << "Unavailable Seats" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (seating_chart[i][j] == 1)
			{
				cout << "Row: " << i << " Column: " << j << endl;
			}
		}
	}
}

void print_total_seats(void)
{
	cout << "Total Seats" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Row: " << i << " Column: " << j << endl;
		}
	}
}

void book_seat(void)
{
	int row;
	int column;
	cout << "Enter the row you would like to book: ";
	cin >> row;
	cout << "Enter the column you would like to book: ";
	cin >> column;
	if (seating_chart[row][column] == 0)
	{
		seating_chart[row][column] = 1;
		cout << "Seat booked" << endl;
	}
	else
	{
		cout << "Seat already taken" << endl;
		/**
		 * @brief select another seat
		 *
		*/
		cout << "Select another seat" << endl;
		book_seat();
	}
}

void cancel_seat(void)
{
	int row;
	int column;
	cout << "Enter the row you would like to cancel: ";
	cin >> row;
	cout << "Enter the column you would like to cancel: ";
	cin >> column;
	if (seating_chart[row][column] == 1)
	{
		seating_chart[row][column] = 0;
		cout << "Seat cancelled" << endl;
	}
	else
	{
		cout << "Seat already available" << endl;
	}
}

int main(int argc, char** argv)
{
	string filename;
	cout << "Enter the filename: ";
	cin >> filename;
	read_seating_chart(filename);
	print_seating_chart();
	print_available_seats();
	print_unavailable_seats();
	print_total_seats();
	book_seat();
	cancel_seat();
	print_seating_chart();
	return 0;
}

/**
 * @brief
	Output:
	Enter the filename: seating_chart.txt
	Seating Chart
 *
 */