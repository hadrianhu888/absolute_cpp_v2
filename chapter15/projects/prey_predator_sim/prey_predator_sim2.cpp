/**
 * @file prey_predator_sim2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

const int GRID_SIZE = 20;
const int PREY_REPRODUCTION_STEPS = 4;
const int PREY_STARVATION_STEPS = 5;
const int PREDATOR_REPRODUCTION_STEPS = 2;
const int PREDATOR_STARVATION_STEPS = 5;

const int MIN_INITIAL_PREY = 30;
const int MAX_INITIAL_PREY = 70;
const int MIN_INITIAL_PREDATORS = 10;
const int MAX_INITIAL_PREDATORS = 40;

const int MIN_INITIAL_ORGANISMS = 30;
const int MAX_INITIAL_ORGANISMS = 70;

const int MIN_PREY_POPULATION = 20;
const int MIN_PREDATOR_POPULATION = 10;

const int FOOD_REPLENISH_STEPS = 20;

enum class Species
{
    EMPTY,
    PREY,
    PREDATOR
};

enum class Season {
    SPRING,
    SUMMER,
    FALL,
    WINTER
};

struct Cell
{
    Species species;
    int stepsToReproduce;
    int stepsToStarve;
    int stepsToStarvation;
    bool hasFood;
    int food;
};

typedef vector<vector<Cell>> Grid;

void spawnFood(Grid &grid, int x, int y)
{
    grid[x][y].hasFood = true;
}

void consumeFood(Grid &grid, int x, int y)
{
    grid[x][y].hasFood = false;
}

void initCell(Cell &cell, Species species)
{
    cell.species = species;
    if (species == Species::PREY)
    {
        cell.stepsToReproduce = PREY_REPRODUCTION_STEPS;
        cell.stepsToStarvation = PREY_STARVATION_STEPS; // Initialize stepsToStarvation for prey
        cell.hasFood = false;
    }
    else if (species == Species::PREDATOR)
    {
        cell.stepsToReproduce = PREDATOR_REPRODUCTION_STEPS;
        cell.stepsToStarvation = PREDATOR_STARVATION_STEPS;
    }
}

void initGrid(Grid &grid)
{
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        vector<Cell> row;
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            row.push_back({Species::EMPTY, 0, 0});
        }
        grid.push_back(row);
    }
}

void printStats(const Grid &grid, Season currentSeason)
{
    int preyCount = 0;
    int predatorCount = 0;
    int foodCount = 0;
    int totalFood = 0;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grid[i][j].species == Species::PREY)
            {
                preyCount++;
                cout << "Prey: " << preyCount << endl;
            }
            else if (grid[i][j].species == Species::PREDATOR)
            {
                predatorCount++;
                cout << "Predator: " << predatorCount << endl;
            }
            else if (grid[i][j].hasFood)
            {
                foodCount++;
                cout << "Food: " << foodCount << endl;
            }
            /**
             * @brief also update the seasons here
             *
             */
            if(preyCount < MIN_PREY_POPULATION) {
                currentSeason = Season::SPRING;
            } else if(preyCount >= MIN_PREY_POPULATION && preyCount < MIN_PREDATOR_POPULATION) {
                currentSeason = Season::SUMMER;
            } else if(preyCount >= MIN_PREDATOR_POPULATION && preyCount < MIN_PREY_POPULATION) {
                currentSeason = Season::FALL;
            } else if(preyCount >= MIN_PREY_POPULATION && preyCount >= MIN_PREDATOR_POPULATION) {
                currentSeason = Season::WINTER;
            }
            totalFood += grid[i][j].food;
        }
    }

    cout << "Season: ";
    switch (currentSeason)
    {
    case Season::SPRING:
        cout << "Spring";
        break;
    case Season::SUMMER:
        cout << "Summer";
        break;
    case Season::FALL:
        cout << "Fall";
        break;
    case Season::WINTER:
        cout << "Winter";
        break;
    }
    cout << endl;
    cout << "Prey: " << preyCount << " | Predator: " << predatorCount << " | Food: " << foodCount << endl;
    cout << string(GRID_SIZE, '=') << endl;
}

void printGrid(const Grid &grid)
{
    int numPrey = 0;
    int numPredators = 0;
    int numFood = 0;
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grid[i][j].species == Species::PREY)
            {
                cout << "O";
            }
            else if (grid[i][j].species == Species::PREDATOR)
            {
                cout << "X";
            }
            else if (grid[i][j].hasFood)
            {
                cout << "$"; // Food symbol
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << string(GRID_SIZE, '-') << endl;
    cout << endl;
    cout << string(GRID_SIZE, '-') << endl;
    cout << "Predators: " << numPredators << ", Prey: " << numPrey << ", Food: " << numFood << endl;
    cout << endl;
}

void spawnPrey(Grid &grid, int x, int y)
{
    grid[x][y] = {Species::PREY, PREY_REPRODUCTION_STEPS, 0};
}

void spawnPredator(Grid &grid, int x, int y)
{
    grid[x][y] = {Species::PREDATOR, PREDATOR_REPRODUCTION_STEPS, PREDATOR_STARVATION_STEPS};
}

void updateCell(Grid &grid, int x, int y, Grid &newGrid)
{
    auto &cell = grid[x][y];

    if (cell.species == Species::EMPTY)
    {
        return;
    }

    int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
    int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
    vector<int> availableMoves;
    vector<int> availablePrey;

    for (int i = 0; i < 9; ++i)
    {
        int newX = (x + dx[i] + GRID_SIZE) % GRID_SIZE;
        int newY = (y + dy[i] + GRID_SIZE) % GRID_SIZE;
        if (cell.species == Species::PREY && newGrid[newX][newY].species == Species::EMPTY)
        {
            availableMoves.push_back(i);
        }
        else if (cell.species == Species::PREDATOR)
        {
            if (newGrid[newX][newY].species == Species::PREY)
            {
                availablePrey.push_back(i);
            }
            else if (newGrid[newX][newY].species == Species::EMPTY)
            {
                availableMoves.push_back(i);
            }
        }
    }

    if (cell.species == Species::PREDATOR && !availablePrey.empty())
    {
        availableMoves = availablePrey;
    }

    if (availableMoves.empty())
    {
        return;
    }

    if (cell.species == Species::PREY)
    {
        if (cell.stepsToStarvation == 0)
        { // Check if prey should starve
            newGrid[x][y].species = Species::EMPTY;
            return;
        }
        else
        {
            cell.stepsToStarvation--; // Decrease steps to starvation for prey
        }
    }

    int moveIndex = availableMoves[rand() % availableMoves.size()];
    int newX = (x + dx[moveIndex] + GRID_SIZE) % GRID_SIZE;
    int newY = (y + dy[moveIndex] + GRID_SIZE) % GRID_SIZE;

    if (cell.species == Species::PREY)
    {
        if (--cell.stepsToReproduce <= 0)
        {
            spawnPrey(newGrid, newX, newY);
            cell.stepsToReproduce = PREY_REPRODUCTION_STEPS;
        }
        else
        {
            newGrid[newX][newY] = cell;
        }
    }
    else if (cell.species == Species::PREDATOR)
    {
        if (newGrid[newX][newY].species == Species::PREY)
        {
            cell.stepsToStarve = PREDATOR_STARVATION_STEPS;
            if (--cell.stepsToReproduce <= 0)
            {
                spawnPredator(newGrid, newX, newY);
                cell.stepsToReproduce = PREDATOR_REPRODUCTION_STEPS;
            }
            else
            {
                newGrid[newX][newY] = cell;
            }
        }
        else if (newGrid[newX][newY].species == Species::EMPTY)
        {
            if (--cell.stepsToStarve <= 0)
            {
                return;
            }
            if (--cell.stepsToReproduce <= 0)
            {
                spawnPredator(newGrid, newX, newY);
                cell.stepsToReproduce = PREDATOR_REPRODUCTION_STEPS;
            }
            else
            {
                newGrid[newX][newY] = cell;
            }
        }
    }
    if (cell.species == Species::PREY)
    {
        if (cell.stepsToStarvation == 0)
        {
            newGrid[x][y].species = Species::EMPTY;
            return;
        }
        else
        {
            if (grid[newX][newY].hasFood)
            {
                cell.stepsToStarvation = PREY_STARVATION_STEPS;
                consumeFood(grid, newX, newY);
            }
            else
            {
                cell.stepsToStarvation--;
            }
        }
    }
}
void replenishFood(Grid &grid, int foodCount)
{
    int placedFood = 0;
    while (placedFood < foodCount)
    {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y].species == Species::EMPTY && !grid[x][y].hasFood)
        {
            spawnFood(grid, x, y);
            placedFood++;
        }
    }
}

Season getNextSeason(Season currentSeason, int steps)
{
    int current = static_cast<int>(currentSeason);
    int next = (current + steps) % 4;
    return static_cast<Season>(next);
    switch (currentSeason)
    {
    case Season::SPRING:
        return Season::SUMMER;
    case Season::SUMMER:
        return Season::FALL;
    case Season::FALL:
        return Season::WINTER;
    case Season::WINTER:
        return Season::SPRING;
    }
}

int getFoodCountForSeason(Season season)
{
    switch (season)
    {
    case Season::SPRING:
        return 50;
    case Season::SUMMER:
        return 40;
    case Season::FALL:
        return 30;
    case Season::WINTER:
        return 10;
    }
}

void populateGridRandomly(Grid &grid)
{
    int organismCount = rand() % (MAX_INITIAL_ORGANISMS - MIN_INITIAL_ORGANISMS + 1) + MIN_INITIAL_ORGANISMS;

    int placedPrey = 0;
    int placedPredators = 0;
    while (placedPrey < organismCount || placedPredators < organismCount)
    {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y].species == Species::EMPTY)
        {
            if (placedPrey < organismCount)
            {
                spawnPrey(grid, x, y);
                placedPrey++;
            }
            else if (placedPredators < organismCount)
            {
                spawnPredator(grid, x, y);
                placedPredators++;
            }
        }
    }
}
char getInput()
{
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}

void addOrganism(Grid &grid, char input)
{
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    switch (input)
    {
    case 'p':
        spawnPrey(grid, x, y);
        break;
    case 'P':
        spawnPredator(grid, x, y);
        break;
    }
}

void maintainPopulation(Grid &grid)
{
    int preyCount = 0;
    int predatorCount = 0;

    // Count current prey and predator populations
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            if (grid[i][j].species == Species::PREY)
            {
                preyCount++;
            }
            else if (grid[i][j].species == Species::PREDATOR)
            {
                predatorCount++;
            }
        }
    }

    // Add prey if the population is too low
    while (preyCount < MIN_PREY_POPULATION)
    {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y].species == Species::EMPTY)
        {
            spawnPrey(grid, x, y);
            preyCount++;
        }
    }

    // Add predators if the population is too low
    while (predatorCount < MIN_PREDATOR_POPULATION)
    {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y].species == Species::EMPTY)
        {
            spawnPredator(grid, x, y);
            predatorCount++;
        }
    }
}

void updateGrid(Grid &grid)
{
    Grid newGrid;
    Grid updatedGrid = grid;
    initGrid(newGrid);
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            updatedGrid[i][j].food = grid[i][j].food;
            /**
             * @brief Construct a new update Cell object
             *
             */
            updateCell(grid, i, j, newGrid);
        }
    }
    grid = newGrid;

    // Maintain prey and predator populations after updating the grid
    maintainPopulation(grid);
}

void printGrid(const Grid &grid, Season currentSeason)
{
    printStats(grid, currentSeason);

    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            switch (grid[i][j].species)
            {
            case Species::EMPTY:
                cout << '.';
                break;
            case Species::PREY:
                cout << 'O';
                break;
            case Species::PREDATOR:
                cout << 'X';
                break;
            }
        }
        cout << endl;
    }
    cout << string(GRID_SIZE, '-') << endl;
}

int main()
{
    srand(time(nullptr));
    Grid grid;
    initGrid(grid);

    populateGridRandomly(grid);

    Season currentSeason = static_cast<Season>(rand() % 4);
    int stepCounter = 0;

    while (true)
    {
        printGrid(grid, currentSeason); // Pass currentSeason to printGrid
        updateGrid(grid);

        char input = getInput();
        if (input == 'q' || input == 'Q')
        {
            break;
        }
        else
        {
            addOrganism(grid, input);
        }

        stepCounter++;

        if (stepCounter % 10 == 0)
        {
            currentSeason = getNextSeason(currentSeason, 1);
        }

        Sleep(500);
        if (stepCounter % FOOD_REPLENISH_STEPS == 0)
        {
            currentSeason = getNextSeason(currentSeason,1);
            int foodCount = getFoodCountForSeason(currentSeason);
            replenishFood(grid, foodCount);
        }

        printStats(grid, currentSeason); // Added printStats here
    }

    return 0;
}
