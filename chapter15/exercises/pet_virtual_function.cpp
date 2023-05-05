/**
 * @file pet_virtual_function.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

int main(int argc, char **argv);

class Pet
{
protected:
    string name;

public:
    Pet();
    Pet(string name);
    string getName() const;
    void setName(string name);
    virtual string speak() const = 0; // Make this a pure virtual function
    virtual void print() const = 0;   // Make this a pure virtual function
    virtual ~Pet();                   // Make the destructor virtual
};

class Dog: public Pet
{
    private:
        string breed;
    public:
        Dog();
        Dog(string name, string breed);
        string getBreed() const;
        void setBreed(string breed);
        string speak() const;
        void print() const;
        ~Dog();
};

class Cat: public Pet
{
    private:
        int lives;
    public:
        Cat();
        Cat(string name, int lives);
        int getLives() const;
        void setLives(int lives);
        string speak() const;
        void print() const;
        ~Cat();
};

Pet::Pet()
{
    name = "";
}

Pet::Pet(string name)
{
    this->name = name;
}

string Pet::getName() const
{
    return name;
}

void Pet::setName(string name)
{
    this->name = name;
}

string Pet::speak() const
{
    return "I don't know what to say!";
}

Pet::~Pet()
{
    cout << "Pet destructor" << endl;
}

Dog::Dog()
{
    breed = "";
}

Dog::Dog(string name, string breed): Pet(name)
{
    this->breed = breed;
}

string Dog::getBreed() const
{
    return breed;
}

void Dog::setBreed(string breed)
{
    this->breed = breed;
}

string Dog::speak() const
{
    return "Bark";
}

Dog::~Dog()
{
    cout << "Dog destructor" << endl;
}

void Dog::print() const
{
    cout << "Dog" << endl;
}

Cat::Cat()
{
    lives = 0;
}

Cat::Cat(string name, int lives): Pet(name)
{
    this->lives = lives;
}

int Cat::getLives() const
{
    return lives;
}

void Cat::setLives(int lives)
{
    this->lives = lives;
}

string Cat::speak() const
{
    return "Meow";
}

Cat::~Cat()
{
    cout << "Cat destructor" << endl;
}

void Cat::print() const
{
    cout << "Cat" << endl;
}

int main(int argc, char **argv)
{
    //Pet *p1 = new Pet("Alfred"); // This line is not allowed, since Pet is now an abstract class.
    Pet *p2 = new Dog("Fluffy", "Poodle");
    Pet *p3 = new Cat("Garfield", 9);

    //cout << p1->getName() << " says " << p1->speak() << endl; // Remove this line as well
    cout << p2->getName() << " says " << p2->speak() << endl;
    cout << p3->getName() << " says " << p3->speak() << endl;

    return 0;
    return 0;
}
