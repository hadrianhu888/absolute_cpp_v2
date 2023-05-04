/**
 * @file pets.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

class Pet
{
protected:
    string name;
    float weight;
    float height;
    int birth_year;

public:
    Pet(const string& name, float weight, float height, int birth_year)
        : name(name), weight(weight), height(height), birth_year(birth_year) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    float getWeight() const { return weight; }
    void setWeight(float weight) { this->weight = weight; }

    float getHeight() const { return height; }
    void setHeight(float height) { this->height = height; }

    int getBirthYear() const { return birth_year; }
    void setBirthYear(int birth_year) { this->birth_year = birth_year; }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: " << height << endl;
        cout << "Birth year: " << birth_year << endl;
    }
    ~Pet() {}
};

class Dog:public Pet
{
protected:
    string breed;
    string color;
    string owner_name;
public:
    Dog(const string& name, float weight, float height, int birth_year, const string& breed, const string& color, const string& owner_name)
        : Pet(name, weight, height, birth_year), breed(breed), color(color), owner_name(owner_name) {}

    const string& getBreed() const { return breed; }
    void setBreed(const string& breed) { this->breed = breed; }

    const string& getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    const string& getOwnerName() const { return owner_name; }
    void setOwnerName(const string& owner_name) { this->owner_name = owner_name; }

    virtual void print() const {
        Pet::print();
        cout << "Breed: " << breed << endl;
        cout << "Color: " << color << endl;
        cout << "Owner name: " << owner_name << endl;
    }
    ~Dog() {}
};

class Cat:public Pet
{
protected:
    string breed;
    string color;
    string owner_name;
public:
    Cat(const string& name, float weight, float height, int birth_year, const string& breed, const string& color, const string& owner_name)
        : Pet(name, weight, height, birth_year), breed(breed), color(color), owner_name(owner_name) {}

    const string& getBreed() const { return breed; }
    void setBreed(const string& breed) { this->breed = breed; }

    const string& getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    const string& getOwnerName() const { return owner_name; }
    void setOwnerName(const string& owner_name) { this->owner_name = owner_name; }

    virtual void print() const {
        Pet::print();
        cout << "Breed: " << breed << endl;
        cout << "Color: " << color << endl;
        cout << "Owner name: " << owner_name << endl;
    }
    ~Cat() {}
};

class Bird:public Pet
{
protected:
    string species;
    string color;
    string owner_name;
public:
    Bird(const string& name, float weight, float height, int birth_year, const string& species, const string& color, const string& owner_name)
        : Pet(name, weight, height, birth_year), species(species), color(color), owner_name(owner_name) {}

    const string& getSpecies() const { return species; }
    void setSpecies(const string& species) { this->species = species; }

    const string& getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    const string& getOwnerName() const { return owner_name; }
    void setOwnerName(const string& owner_name) { this->owner_name = owner_name; }

    virtual void print() const {
        Pet::print();
        cout << "Species: " << species << endl;
        cout << "Color: " << color << endl;
        cout << "Owner name: " << owner_name << endl;
    }
    ~Bird() {}
};

class Rock:public Pet
{
protected:
    string color;
public:
    Rock(const string& name, float weight, float height, int birth_year, const string& color)
        : Pet(name, weight, height, birth_year), color(color) {}

    const string& getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    virtual void print() const {
        Pet::print();
        cout << "Color: " << color << endl;
    }
    ~Rock() {}
};

int main(int argc, char **argv)
{
    Pet pet("Pet", 0.0, 0.0, 0);
    Dog dog("Dog", 0.0, 0.0, 0, "Dog", "Black", "Dog Owner");
    Cat cat("Cat", 0.0, 0.0, 0, "Cat", "White", "Cat Owner");
    Bird bird("Bird", 0.0, 0.0, 0, "Bird", "Red", "Bird Owner");
    Rock rock("Rock", 0.0, 0.0, 0, "Rock");

    pet.print();
    cout << endl;
    dog.print();
    cout << endl;
    cat.print();
    cout << endl;
    bird.print();
    cout << endl;
    rock.print();
    cout << endl;

    return 0;
}
