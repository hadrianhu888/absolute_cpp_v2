/**
 * @file prey_predator_sim1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Organism
{
public:
    Organism(int weight);
    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual void reproduce() const = 0;
    virtual void move() const = 0;
    virtual void speak() const = 0;
    virtual int getBreedTime() const = 0;
    virtual void resetBreedTime() = 0;
    virtual int getStarveTime() const = 0;
    virtual ~Organism();
    int getWeight() const;
    void setWeight(int weight);
protected:
    int weight;
};

class Ants:public Organism
{
public:
    Ants();
    Ants(int weight);
    void eat() const;
    void sleep() const;
    void reproduce() const;
    void move() const;
    void speak() const;
    int getBreedTime() const;
    void resetBreedTime();
    int getStarveTime() const;
    ~Ants();
};

class Doodlebugs:public Organism
{
public:
    Doodlebugs();
    Doodlebugs(int weight);
    void eat() const;
    void sleep() const;
    void reproduce() const;
    void move() const;
    void speak() const;
    int getBreedTime() const;
    void resetBreedTime();
    int getStarveTime() const;
    ~Doodlebugs();
};

class Simulation
{
public:
    Simulation();
    void run();
    ~Simulation();
    Organism *grid[20][20];
    int timeStep;
    int numAnts;
    int numDoodlebugs;
    void initialize();
    void printGrid() const;
    void updateGrid();
    void moveOrganism(int x, int y);
    void moveAnt(int x, int y);
    void moveDoodlebug(int x, int y);
    void breedOrganism(int x, int y);
    void breedAnt(int x, int y);
    void breedDoodlebug(int x, int y);
    void starveDoodlebug(int x, int y);
    void removeOrganism(int x, int y);
    void removeAnt(int x, int y);
    void removeDoodlebug(int x, int y);
    void addAnt(int x, int y);
    void addDoodlebug(int x, int y);
    void printStats() const;
    int randomInt(int low, int high) const;
    bool inRange(int x, int y) const;
    bool isEmpty(int x, int y) const;
    bool isAnt(int x, int y) const;
    bool isDoodlebug(int x, int y) const;
    bool isPrey(int x, int y) const;
    bool isPredator(int x, int y) const;
    bool isStarving(int x, int y) const;
    bool isBreedingTime(int x, int y) const;
    bool isAntBreedingTime(int x, int y) const;
    bool isDoodlebugBreedingTime(int x, int y) const;
    bool isDoodlebugStarvingTime(int x, int y) const;
    bool isDoodlebugStarving(int x, int y) const;
    bool isDoodlebugEating(int x, int y) const;
    Simulation runSimulation();
    void printGrid();
    void printStats();
    void deleteGrid();
    void printSimulation();
    void playSimulation();
    void moveAnts();
    void moveDoodlebugs();
};

Organism::Organism(int weight):weight(weight)
{
    cout << "Organism constructor called" << endl;
}

Organism::~Organism()
{
    cout << "Organism destructor called" << endl;
}

int Organism::getWeight() const
{
    return weight;
}

void Organism::setWeight(int weight)
{
    this->weight = weight;
}

Ants::Ants():Organism(0)
{
    cout << "Ants constructor called" << endl;
}

Ants::Ants(int weight):Organism(weight)
{
    cout << "Ants constructor called" << endl;
}

Ants::~Ants()
{
    cout << "Ants destructor called" << endl;
}

void Ants::eat() const
{
    cout << "Ants eat" << endl;
}

void Ants::sleep() const
{
    cout << "Ants sleep" << endl;
}

void Ants::reproduce() const
{
    cout << "Ants reproduce" << endl;
}

void Ants::move() const
{
    cout << "Ants move" << endl;
}

void Ants::speak() const
{
    cout << "Ants speak" << endl;
}

int Ants::getBreedTime() const
{
    return 0;
}

void Ants::resetBreedTime()
{
}

int Ants::getStarveTime() const
{
    return 0;
}

Doodlebugs::Doodlebugs():Organism(0)
{
    cout << "Doodlebugs constructor called" << endl;
}

Doodlebugs::Doodlebugs(int weight):Organism(weight)
{
    cout << "Doodlebugs constructor called" << endl;
}

Doodlebugs::~Doodlebugs()
{
    cout << "Doodlebugs destructor called" << endl;
}

void Doodlebugs::eat() const
{
    cout << "Doodlebugs eat" << endl;
}

void Doodlebugs::sleep() const
{
    cout << "Doodlebugs sleep" << endl;
}

void Doodlebugs::reproduce() const
{
    cout << "Doodlebugs reproduce" << endl;
}

void Doodlebugs::move() const
{
    cout << "Doodlebugs move" << endl;
}

void Doodlebugs::speak() const
{
    cout << "Doodlebugs speak" << endl;
}

int Doodlebugs::getBreedTime() const
{
    return 0;
}

void Doodlebugs::resetBreedTime()
{
}

int Doodlebugs::getStarveTime() const
{
    return 0;
}

Simulation::Simulation():timeStep(0),numAnts(0),numDoodlebugs(0)
{
    cout << "Simulation constructor called" << endl;
}

Simulation::~Simulation()
{
    cout << "Simulation destructor called" << endl;
}

void Simulation::run()
{
    initialize();
    printGrid();
    while (numAnts > 0 && numDoodlebugs > 0)
    {
        updateGrid();
        printGrid();
        timeStep++;
    }
    printStats();
    deleteGrid();
}

void Simulation::initialize()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = NULL;
        }
    }
    int x, y;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            x = randomInt(0, 19);
            y = randomInt(0, 19);
        } while (grid[x][y] != NULL);
        grid[x][y] = new Ants();
        numAnts++;
    }
    for (int i = 0; i < 5; i++)
    {
        do
        {
            x = randomInt(0, 19);
            y = randomInt(0, 19);
        } while (grid[x][y] != NULL);
        grid[x][y] = new Doodlebugs();
        numDoodlebugs++;
    }
}

void Simulation::printGrid() const
{
    cout << "Time step: " << timeStep << endl;
    cout << "Number of ants: " << numAnts << endl;
    cout << "Number of doodlebugs: " << numDoodlebugs << endl;
    cout << "  01234567890123456789" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 20; j++)
        {
            if (grid[i][j] == NULL)
            {
                cout << " ";
            }
            else if (grid[i][j]->getWeight() == 0)
            {
                cout << "O";
            }
            else
            {
                cout << "X";
            }
        }
        cout << endl;
    }
}

void Simulation::printStats() const
{
    cout << "Time step: " << timeStep << endl;
    cout << "Number of ants: " << numAnts << endl;
    cout << "Number of doodlebugs: " << numDoodlebugs << endl;
}

void Simulation::printStats()
{
    cout << "Time step: " << timeStep << endl;
    cout << "Number of ants: " << numAnts << endl;
    cout << "Number of doodlebugs: " << numDoodlebugs << endl;
}

void Simulation::deleteGrid()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            delete grid[i][j];
        }
    }
}

void Simulation::updateGrid()
{
    int x, y;
    for (int i = 0; i < numAnts; i++)
    {
        do
        {
            x = randomInt(0, 19);
            y = randomInt(0, 19);
        } while (grid[x][y] == NULL || grid[x][y]->getWeight() != 0);
        if (isAntBreedingTime(x, y))
        {
            if (x > 0 && grid[x - 1][y] == NULL)
            {
                grid[x - 1][y] = new Ants();
                numAnts++;
            }
            else if (x < 19 && grid[x + 1][y] == NULL)
            {
                grid[x + 1][y] = new Ants();
                numAnts++;
            }
            else if (y > 0 && grid[x][y - 1] == NULL)
            {
                grid[x][y - 1] = new Ants();
                numAnts++;
            }
            else if (y < 19 && grid[x][y + 1] == NULL)
            {
                grid[x][y + 1] = new Ants();
                numAnts++;
            }
        }
        if (x > 0 && grid[x - 1][y] != NULL && grid[x - 1][y]->getWeight() == 1)
        {
            delete grid[x - 1][y];
            grid[x - 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (x < 19 && grid[x + 1][y] != NULL && grid[x + 1][y]->getWeight() == 1)
        {
            delete grid[x + 1][y];
            grid[x + 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y > 0 && grid[x][y - 1] != NULL && grid[x][y - 1]->getWeight() == 1)
        {
            delete grid[x][y - 1];
            grid[x][y - 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y < 19 && grid[x][y + 1] != NULL && grid[x][y + 1]->getWeight() == 1)
        {
            delete grid[x][y + 1];
            grid[x][y + 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        grid[x][y]->move();
    }
}

bool Simulation::isAntBreedingTime(int x, int y) const
{
    return grid[x][y]->getBreedTime() == 3;
}

bool Simulation::isDoodlebugBreedingTime(int x, int y) const
{
    return grid[x][y]->getBreedTime() == 8;
}

bool Simulation::isDoodlebugStarvingTime(int x, int y) const
{
    return grid[x][y]->getStarveTime() == 3;
}

bool Simulation::isDoodlebugStarving(int x, int y) const
{
    return grid[x][y]->getWeight() == 1;
}

bool Simulation::isDoodlebugEating(int x, int y) const
{
    return grid[x][y]->getWeight() == 2;
}

int Simulation::randomInt(int min, int max) const
{
    return rand() % (max - min + 1) + min;
}

void Simulation::printGrid()
{
    cout << "Time step: " << timeStep << endl;
    cout << "Number of ants: " << numAnts << endl;
    cout << "Number of doodlebugs: " << numDoodlebugs << endl;
    cout << "01234567890123456789" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 20; j++)
        {
            if (grid[i][j] == NULL)
            {
                cout << " ";
            }
            else if (grid[i][j]->getWeight() == 0)
            {
                cout << "O";
            }
            else
            {
                cout << "X";
            }
        }
        cout << endl;
    }
}

void Simulation::printSimulation()
{
    int height = 20;
    int width = 20;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Simulation::playSimulation()
{
    char c;
    printGrid(); // Print the initial state

    do
    {
        cout << "Press enter to continue or q/Q to quit: ";
        c = cin.get();            // Read the input

        if (c == 'q' || c == 'Q') // If the input is 'q' or 'Q', break the loop
        {
            break;
        }

        if (c == '\n') // If the input is an Enter key press
        {
            updateGrid();
            printGrid();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any extra input
    } while (true);
}

void Simulation::moveAnts()
{
    int x, y;
    for (int i = 0; i < numAnts; i++)
    {
        do
        {
            x = randomInt(0, 19);
            y = randomInt(0, 19);
        } while (grid[x][y] == NULL || grid[x][y]->getWeight() != 0);
        if (isAntBreedingTime(x, y))
        {
            if (x > 0 && grid[x - 1][y] == NULL)
            {
                grid[x - 1][y] = new Ants();
                numAnts++;
            }
            else if (x < 19 && grid[x + 1][y] == NULL)
            {
                grid[x + 1][y] = new Ants();
                numAnts++;
            }
            else if (y > 0 && grid[x][y - 1] == NULL)
            {
                grid[x][y - 1] = new Ants();
                numAnts++;
            }
            else if (y < 19 && grid[x][y + 1] == NULL)
            {
                grid[x][y + 1] = new Ants();
                numAnts++;
            }
        }
        if (x > 0 && grid[x - 1][y] != NULL && grid[x - 1][y]->getWeight() == 1)
        {
            delete grid[x - 1][y];
            grid[x - 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (x < 19 && grid[x + 1][y] != NULL && grid[x + 1][y]->getWeight() == 1)
        {
            delete grid[x + 1][y];
            grid[x + 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y > 0 && grid[x][y - 1] != NULL && grid[x][y - 1]->getWeight() == 1)
        {
            delete grid[x][y - 1];
            grid[x][y - 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y < 19 && grid[x][y + 1] != NULL && grid[x][y + 1]->getWeight() == 1)
        {
            delete grid[x][y + 1];
            grid[x][y + 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
    }
}

void Simulation::moveDoodlebugs()
{
    int x, y;
    for (int i = 0; i < numDoodlebugs; i++)
    {
        do
        {
            x = randomInt(0, 19);
            y = randomInt(0, 19);
        } while (grid[x][y] == NULL || grid[x][y]->getWeight() != 1);
        if (isDoodlebugBreedingTime(x, y))
        {
            if (x > 0 && grid[x - 1][y] == NULL)
            {
                grid[x - 1][y] = new Doodlebugs();
                numDoodlebugs++;
            }
            else if (x < 19 && grid[x + 1][y] == NULL)
            {
                grid[x + 1][y] = new Doodlebugs();
                numDoodlebugs++;
            }
            else if (y > 0 && grid[x][y - 1] == NULL)
            {
                grid[x][y - 1] = new Doodlebugs();
                numDoodlebugs++;
            }
            else if (y < 19 && grid[x][y + 1] == NULL)
            {
                grid[x][y + 1] = new Doodlebugs();
                numDoodlebugs++;
            }
        }
        if (isDoodlebugStarvingTime(x, y))
        {
            delete grid[x][y];
            grid[x][y] = NULL;
            numDoodlebugs--;
        }
        else if (x > 0 && grid[x - 1][y] != NULL && grid[x - 1][y]->getWeight() == 0)
        {
            delete grid[x - 1][y];
            grid[x - 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (x < 19 && grid[x + 1][y] != NULL && grid[x + 1][y]->getWeight() == 0)
        {
            delete grid[x + 1][y];
            grid[x + 1][y] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y > 0 && grid[x][y - 1] != NULL && grid[x][y - 1]->getWeight() == 0)
        {
            delete grid[x][y - 1];
            grid[x][y - 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
        else if (y < 19 && grid[x][y + 1] != NULL && grid[x][y + 1]->getWeight() == 0)
        {
            delete grid[x][y + 1];
            grid[x][y + 1] = grid[x][y];
            grid[x][y] = NULL;
            numAnts--;
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    Simulation s;
    s.playSimulation();
    return 0;
}
