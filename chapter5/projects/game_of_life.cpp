/**
 * @file game_of_life.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief This program implements the game of life 
 as proposed by John Conway
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

// Global variables
string filename;
int *universe; 
int *new_universe;
int rows;
int columns;
int total_cells;
int alive_cells;
int dead_cells;
int generations;
int generation_count;
int current_generation;
int next_generation;
int current_cell;
int next_cell;
int current_row;
int current_column;
int next_row;
int next_column;
int current_cell_state;
int next_cell_state;
int current_cell_neighbors;
int next_cell_neighbors;
int current_cell_neighbor;
int next_cell_neighbor;
int current_cell_neighbor_row;
int current_cell_neighbor_column;
int next_cell_neighbor_row;
int next_cell_neighbor_column;
int current_cell_neighbor_state;
int next_cell_neighbor_state;
int current_cell_neighbor_index;
int next_cell_neighbor_index;
int current_cell_neighbor_row_index;
int next_cell_neighbor_row_index;
int current_cell_neighbor_column_index;
int next_cell_neighbor_column_index;
int current_cell_neighbor_index_index;
int next_cell_neighbor_index_index;
int current_cell_neighbor_row_index_index;
int next_cell_neighbor_row_index_index;
int current_cell_neighbor_column_index_index;

// Constants

const int MAX_ROWS = 10;
const int MAX_COLUMNS = 10;

// Function prototypes

void read_universe(string filename);
void write_initial_universe(void); 
void random_generation_generator(void); 
void print_random_generation(void);
void read_universe(void); 
void print_universe(void);
void print_alive_cells(void);
void print_dead_cells(void);
void print_generations(void);
void print_generation_count(void);
void print_current_generation(void);
void print_next_generation(void);
void print_current_cell(void);
void print_next_cell(void);
void print_current_row(void);
void print_current_column(void);
void print_next_row(void);
void print_next_column(void);
void print_current_cell_state(void);
void print_next_cell_state(void);
void print_current_cell_neighbors(void);
void print_next_cell_neighbors(void);
void print_current_cell_neighbor(void);
void print_next_cell_neighbor(void);
void print_current_cell_neighbor_row(void);
void print_next_cell_neighbor_row(void);
void print_current_cell_neighbor_column(void);
void print_next_cell_neighbor_column(void);
void print_current_cell_neighbor_state(void);
void print_next_cell_neighbor_state(void);
void print_current_cell_neighbor_index(void);
void print_next_cell_neighbor_index(void);
void print_current_cell_neighbor_row_index(void);
void print_next_cell_neighbor_row_index(void);
void print_current_cell_neighbor_column_index(void);
void get_file_name(void);
void set_file_name(void);
void write_life_to_file(string filename); 
int main(int argc,char **argv); 

// Function definitions

void get_file_name(void)
{
    /**
     * @brief get the file name
     * 
     */
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    read_universe(filename);
}

void set_file_name(void)
{
    /**
     * @brief set the file name
     * 
     */
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    write_life_to_file(filename);
}

void write_life_to_file(string filename)
{
    /**
     * @brief write the life to a file
     * 
     */
    ofstream outfile;
    outfile.open(filename);
    outfile << "Rows: " << rows << endl;
    outfile << "Columns: " << columns << endl;
    outfile << "Generations: " << generations << endl;
    outfile << "Generation count: " << generation_count << endl;
    for (int i = 0; i < total_cells; i++)
    {
        outfile << "Enter the state of cell " << i << ": ";
        outfile << universe[i] << endl;
    }
    outfile.close();
}

void random_generation_generator(void)
{
    /**
     * @brief generate a random generation
     * 
     */
    for (int i = 0; i < total_cells; i++)
    {
        universe[i] = rand() % 2;
    }
    print_random_generation();
}

void print_random_generation(void)
{
    /**
     * @brief print the random generation
     * 
     */
    for (int i = 0; i < total_cells; i++)
    {
        cout << universe[i] << " ";
    }
    cout << endl;
}

void write_initial_universe(void)
{
    /**
     * @brief write the initial universe to the standard output
     * 
     */
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << "Enter the number of generations: ";
    cin >> generations;
    cout << "Enter the generation count: ";
    cin >> generation_count;
    total_cells = rows * columns;
    cout << "Total cells: " << total_cells << endl;
    for (int i = 0; i < total_cells; i++)
    {
        cout << "Enter the state of cell " << i << ": ";
        cin >> universe[i];
    }
    random_generation_generator();
}

void write_universe(void)
{
    /**
     * @brief write the universe to the standard output
     * Input initial rows,columns, generations and generation_count
     */
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << "Enter the number of generations: ";
    cin >> generations;
    cout << "Enter the generation count: ";
    cin >> generation_count;
    total_cells = rows * columns;    
    cout <<  "Total cells: " << total_cells << endl;
}

void read_universe(void)
{
    /**
     * @brief read the universe from the standard input
     * 
     */
    cout << "Rows: " << rows << endl;
    cout << "Columns: " << columns << endl;
    cout << "Generations: " << generations << endl;
    cout << "Generation count: " << generation_count << endl;
    universe = new int[total_cells];
    new_universe = new int[total_cells];
    for (int i = 0; i < total_cells; i++)
    {
        cout << "Enter the state of cell " << i << ": ";
        cin >> universe[i];
    }
    /**
     * @brief start randomly generating new  generations
     * 
     */
    random_generation_generator(); 
}

void read_universe(string filename)
{
    ifstream infile;
    infile.open(filename);
    if (infile.fail())
    {
        cout << "Error opening file " << filename << endl;
        exit(1);
    }
    infile >> rows;
    infile >> columns;
    infile >> generations;
    infile >> generation_count;
    total_cells = rows * columns;
    universe = new int[total_cells];
    new_universe = new int[total_cells];
    for (int i = 0; i < total_cells; i++)
    {
        infile >> universe[i];
    }
    infile.close();
}

void print_universe(void)
{
    cout << "Universe:" << endl;
    for (int i = 0; i < total_cells; i++)
    {
        cout << universe[i] << " ";
        if ((i + 1) % columns == 0)
        {
            cout << endl;
        }
    }
}

void print_alive_cells(void)
{
    alive_cells = 0;
    for (int i = 0; i < total_cells; i++)
    {
        if (universe[i] == 1)
        {
            alive_cells++;
        }
    }
    cout << "Alive cells: " << alive_cells << endl;
}

void print_dead_cells(void)
{
    dead_cells = 0;
    for (int i = 0; i < total_cells; i++)
    {
        if (universe[i] == 0)
        {
            dead_cells++;
        }
    }
    cout << "Dead cells: " << dead_cells << endl;
}

void print_generations(void)
{
    cout << "Generations: " << generations << endl;
}

void print_generation_count(void)
{
    cout << "Generation count: " << generation_count << endl;
}

void print_current_generation(void)
{
    cout << "Current generation: " << current_generation << endl;
}

void print_next_generation(void)
{
    cout << "Next generation: " << next_generation << endl;
}

void print_current_cell(void)
{
    cout << "Current cell: " << current_cell << endl;
}

void print_next_cell(void)
{
    cout << "Next cell: " << next_cell << endl;
}

void print_current_row(void)
{
    cout << "Current row: " << current_row << endl;
}

void print_current_column(void)
{
    cout << "Current column: " << current_column << endl;
}

void print_next_row(void)
{
    cout << "Next row: " << next_row << endl;
}

void print_next_column(void)
{
    cout << "Next column: " << next_column << endl;
}

void print_current_cell_state(void)
{
    cout << "Current cell state: " << current_cell_state << endl;
}

void print_next_cell_state(void)
{
    cout << "Next cell state: " << next_cell_state << endl;
}

void print_current_cell_neighbors(void)
{
    cout << "Current cell neighbors: " << current_cell_neighbors << endl;
}

void print_next_cell_neighbors(void)
{
    cout << "Next cell neighbors: " << next_cell_neighbors << endl;
}

void print_current_cell_neighbor(void)
{
    cout << "Current cell neighbor: " << current_cell_neighbor << endl;
}

void print_next_cell_neighbor(void)
{
    cout << "Next cell neighbor: " << next_cell_neighbor << endl;
}

void print_current_cell_neighbor_row(void)
{
    cout << "Current cell neighbor row: " << current_cell_neighbor_row << endl;
}

void print_next_cell_neighbor_row(void)
{
    cout << "Next cell neighbor row: " << next_cell_neighbor_row << endl;
}

void print_current_cell_neighbor_column(void)
{
    cout << "Current cell neighbor column: " << current_cell_neighbor_column << endl;
}

void print_next_cell_neighbor_column(void)
{
    cout << "Next cell neighbor column: " << next_cell_neighbor_column << endl;
}

void print_current_cell_neighbor_state(void)
{
    cout << "Current cell neighbor state: " << current_cell_neighbor_state << endl;
}

void print_next_cell_neighbor_state(void)
{
    cout << "Next cell neighbor state: " << next_cell_neighbor_state << endl;
}

void print_current_cell_neighbor_index(void)
{
    cout << "Current cell neighbor index: " << current_cell_neighbor_index << endl;
}

void print_next_cell_neighbor_index(void)
{
    cout << "Next cell neighbor index: " << next_cell_neighbor_index << endl;
}

void print_current_cell_neighbor_row_index(void)
{
    cout << "Current cell neighbor row index: " << current_cell_neighbor_row_index << endl;
}

void print_next_cell_neighbor_row_index(void)
{
    cout << "Next cell neighbor row index: " << next_cell_neighbor_row_index << endl;
}

void print_current_cell_neighbor_column_index(void)
{
    cout << "Current cell neighbor column index: " << current_cell_neighbor_column_index << endl;
}

int main(int argc,char **argv)
{
    get_file_name();
    set_file_name();
    write_initial_universe();
    read_universe(); 
    print_universe();
    print_alive_cells();
    print_dead_cells();
    print_generations();
    print_generation_count();
    print_current_generation();
    print_next_generation();
    print_current_cell();
    print_next_cell();
    print_current_row();
    print_current_column();
    print_next_row();
    print_next_column();
    print_current_cell_state();
    print_next_cell_state();
    print_current_cell_neighbors();
    print_next_cell_neighbors();
    print_current_cell_neighbor();
    print_next_cell_neighbor();
    print_current_cell_neighbor_row();
    print_next_cell_neighbor_row();
    print_current_cell_neighbor_column();
    print_next_cell_neighbor_column();
    print_current_cell_neighbor_state();
    print_next_cell_neighbor_state();
    print_current_cell_neighbor_index();
    print_next_cell_neighbor_index();
    print_current_cell_neighbor_row_index();
    print_next_cell_neighbor_row_index();
    print_current_cell_neighbor_column_index();
    write_life_to_file(filename);
    return 0;
}

