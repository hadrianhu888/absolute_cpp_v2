/**
 * @file prey_predator_sim.cpp
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

class Animal
{
public:
    Animal(int weight);
    virtual void eat() const = 0;
    virtual void sleep() const = 0;
    virtual void reproduce() const = 0;
    virtual void move() const = 0;
    virtual void speak() const = 0;
    virtual ~Animal();
protected:
    int weight;
};

class Predator : public Animal
{
public:
    Predator(int weight);
    void eat() const;
    void sleep() const;
    void reproduce() const;
    void move() const;
    void speak() const;
    ~Predator();
};

class Prey : public Animal
{
public:
    Prey(int weight);
    void eat() const;
    void sleep() const;
    void reproduce() const;
    void move() const;
    void speak() const;
    ~Prey();
};

class Simulation
{
public:
    Simulation();
    void run();
    ~Simulation();
private:
    Animal* animalArray[10];
    int numPredators;
    int numPrey;
};

class Environment : public Simulation
{
public:
    Environment();
    void run();
    ~Environment();
private:
    Animal* animalArray[10];
    int numPredators;
    int numPrey;
};

int main(int argc, char **argv);
string draw20By20Grid();
void drawPredator(Animal* predator);
void drawPrey(Animal* prey);
void drawEmpty();
void simulateOneStep(Animal* animalArray[], int numPredators, int numPrey);
void simulateGame(Animal* animalArray[], int numPredators, int numPrey);
void incrementGameSteps(int& steps);
void updateSimulation(Animal* animalArray[], int numPredators, int numPrey);
void simulatePreyPredatorDynamicsInGame(Animal* animalArray[], int numPredators, int numPrey);

Animal::Animal(int weight) : weight(weight)
{
    cout << "Animal constructor called" << endl;
}

Animal::~Animal()
{
    cout << "Animal destructor called" << endl;
}

Predator::Predator(int weight) : Animal(weight)
{
    cout << "Predator constructor called" << endl;
}

void Predator::eat() const
{
    cout << "Predator eat" << endl;
}

void Predator::sleep() const
{
    cout << "Predator sleep" << endl;
}

void Predator::reproduce() const
{
    cout << "Predator reproduce" << endl;
}

void Predator::move() const
{
    cout << "Predator move" << endl;
}

void Predator::speak() const
{
    cout << "Predator speak" << endl;
}

Predator::~Predator()
{
    cout << "Predator destructor called" << endl;
}

Prey::Prey(int weight) : Animal(weight)
{
    cout << "Prey constructor called" << endl;
}

void Prey::eat() const
{
    cout << "Prey eat" << endl;
}

void Prey::sleep() const
{
    cout << "Prey sleep" << endl;
}

void Prey::reproduce() const
{
    cout << "Prey reproduce" << endl;
}

void Prey::move() const
{
    cout << "Prey move" << endl;
}

void Prey::speak() const
{
    cout << "Prey speak" << endl;
}

Prey::~Prey()
{
    cout << "Prey destructor called" << endl;
}

Simulation::Simulation()
{
    cout << "Simulation constructor called" << endl;
    numPredators = 0;
    numPrey = 0;
    for (int i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
        {
            animalArray[i] = new Predator(rand() % 100);
            numPredators++;
        }
        else
        {
            animalArray[i] = new Prey(rand() % 100);
            numPrey++;
        }
    }
}

void Simulation::run()
{
    for (int i = 0; i < 10; i++)
    {
        animalArray[i]->eat();
        animalArray[i]->sleep();
        animalArray[i]->reproduce();
        animalArray[i]->move();
        animalArray[i]->speak();
    }
}

Simulation::~Simulation()
{
    cout << "Simulation destructor called" << endl;
    for (int i = 0; i < 10; i++)
    {
        delete animalArray[i];
    }
}

Environment::Environment()
{
    cout << "Environment constructor called" << endl;
    numPredators = 0;
    numPrey = 0;
    for (int i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
        {
            animalArray[i] = new Predator(rand() % 100);
            numPredators++;
        }
        else
        {
            animalArray[i] = new Prey(rand() % 100);
            numPrey++;
        }
    }
}

void Environment::run()
{
    for (int i = 0; i < 10; i++)
    {
        animalArray[i]->eat();
        animalArray[i]->sleep();
        animalArray[i]->reproduce();
        animalArray[i]->move();
        animalArray[i]->speak();
    }
}

Environment::~Environment()
{
    cout << "Environment destructor called" << endl;
    for (int i = 0; i < 10; i++)
    {
        delete animalArray[i];
    }
}

string draw20By20Grid()
{
    string grid = "";
    for (int i = 0; i < 20; i++)
    {
        grid += "|";
        for (int j = 0; j < 20; j++)
        {
            grid += " ";
        }
        grid += "|\n";
    }
    return grid;
}
void drawPredator(Animal *predator)
{
    cout << "<>" << endl;
}
void drawPrey(Animal *prey)
{
    cout << "><" << endl;
}
void drawEmpty()
{
    cout << "  " << endl;
}
void simulateOneStep(Animal *animalArray[], int numPredators, int numPrey)
{
    string grid = draw20By20Grid();
    for (int i = 0; i < numPredators; i++)
    {
        drawPredator(animalArray[i]);
    }
    for (int i = 0; i < numPrey; i++)
    {
        drawPrey(animalArray[i]);
    }
    cout << grid << endl;
}
void simulateGame(Animal *animalArray[], int numPredators, int numPrey)
{
    for (int i = 0; i < 10; i++)
    {
        simulateOneStep(animalArray, numPredators, numPrey);
    }
}

void incrementGameSteps(int &steps)
{
    steps++;
}
void updateSimulation(Animal *animalArray[], int numPredators, int numPrey)
{
    for (int i = 0; i < numPredators; i++)
    {
        animalArray[i]->move();
    }
    for (int i = 0; i < numPrey; i++)
    {
        animalArray[i]->move();
    }
}

void simulatePreyPredatorDynamicsInGame(Animal *animalArray[], int numPredators, int numPrey)
{
    int steps = 0;
    while (steps < 10)
    {
        simulateOneStep(animalArray, numPredators, numPrey);
        updateSimulation(animalArray, numPredators, numPrey);
        incrementGameSteps(steps);
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    Animal *animalArray[10];
    int numPredators = 0;
    int numPrey = 0;
    for (int i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
        {
            animalArray[i] = new Predator(rand() % 100);
            numPredators++;
        }
        else
        {
            animalArray[i] = new Prey(rand() % 100);
            numPrey++;
        }
    }
    simulateGame(animalArray, numPredators, numPrey);
    return 0;
}
