/**
 * @file prey_predator_food_sim.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

const int GRID_SIZE = 20;
const char EMPTY = ' ';
const char PREDATOR = 'X';
const char PREY = 'O';
const char FOOD = 'Z';

const int MAX_FOOD_SUMMER = 100;
const int MAX_FOOD_FALL = 50;
const int MAX_FOOD_WINTER = 25;
const int MAX_FOOD_SPRING = 75;

enum Season
{
    SPRING,
    SUMMER,
    FALL,
    WINTER
};

struct Cell
{
    char content;
    int prey, predator, food;
};

typedef std::vector<std::vector<Cell>> Grid;

void initGrid(Grid &grid);
void updateGrid(Grid &grid, Season season);
void displayGrid(const Grid &grid);
Season returnRandomSeason (void);
Season getNextSeason(Season current);
int getMaxFood(Season season);
void saveSimulation(const Grid &grid, int run);
int main(int argc, char *argv[]);

Season returnRandomSeason(void)
{
    // Return a random season.
    int season = rand() % 4;
    switch(season)
    {
        case 0:
            return SPRING;
        case 1:
            return SUMMER;
        case 2:
            return FALL;
        case 3:
            return WINTER;
    }
}

    void initGrid(Grid &grid)
{
    // Initialize the grid with random contents.
    Season RandomSeason = returnRandomSeason();
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j].content = EMPTY;
            grid[i][j].prey = rand() % 20;
            grid[i][j].predator = rand() % 20;
            grid[i][j].food = rand() % getMaxFood(RandomSeason);
        }
    }
    // show symbols for each cell
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(grid[i][j].prey > 0)
            {
                grid[i][j].content = PREY;
            }
            else if(grid[i][j].predator > 0)
            {
                grid[i][j].content = PREDATOR;
            }
            else if(grid[i][j].food > 0)
            {
                grid[i][j].content = FOOD;
            }
        }
    }
}

void updateGrid(Grid &grid, Season season)
{
    // Update the grid based on the current season.
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            if(grid[i][j].content == PREY)
            {
                // Update the prey.
            }
            else if(grid[i][j].content == PREDATOR)
            {
                // Update the predator.
            }
            else if(grid[i][j].content == FOOD)
            {
                // Update the food.
            }
        }
    }
}

void displayGrid(const Grid &grid)
{
    // Display the grid to the console.
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            std::cout << grid[i][j].content;
        }
        std::cout << std::endl;
    }
}

Season getNextSeason(Season current)
{
    // Get the next season in the cycle.
    switch(current)
    {
        case SPRING:
            return SUMMER;
        case SUMMER:
            return FALL;
        case FALL:
            return WINTER;
        case WINTER:
            return SPRING;
    }
}

int getMaxFood(Season season)
{
    // Return the maximum amount of food for the given season.
    switch(season)
    {
        case SPRING:
            return MAX_FOOD_SPRING;
        case SUMMER:
            return MAX_FOOD_SUMMER;
        case FALL:
            return MAX_FOOD_FALL;
        case WINTER:
            return MAX_FOOD_WINTER;
    }
}

void saveSimulation(const Grid &grid, int run)
{
    // Save the current state of the grid to a file.
    std::ofstream fout;
    std::string filename = "simulation" + std::to_string(run) + ".txt";
    fout.open(filename);
    if(fout.fail())
    {
        std::cout << "Error opening file " << filename << std::endl;
        exit(1);
    }
    else if (fout.is_open())
    {
        fout << std::setw(5) << " ";
        for(int i = 0; i < GRID_SIZE; i++)
        {
            for(int j = 0; j < GRID_SIZE; j++)
            {
                fout << std::setw(5) << grid[i][j].content;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    int run = 0;
    Season season = SPRING;
    Grid grid(GRID_SIZE, std::vector<Cell>(GRID_SIZE));

    initGrid(grid);
    displayGrid(grid);

    while (true)
    {
        char input;
        std::cin.get(input);
        if (input == 'Q' || input == 'q')
            break;

        updateGrid(grid, season);
        displayGrid(grid);

        saveSimulation(grid, run);
        run++;

        season = getNextSeason(season);
    }

    return 0;
}
