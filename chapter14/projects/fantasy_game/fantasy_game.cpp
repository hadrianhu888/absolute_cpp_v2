/**
 * @file fantasy_game.cpp
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

class Creature
{
protected:
    string name;
    int level;
public:
    Creature(const string& name, int level)
        : name(name), level(level) {}

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getLevel() const { return level; }
    void setLevel(int level) { this->level = level; }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
    }
    ~Creature() {}
};

class Human:public Creature
{
protected:
    int strength;
    int magic;
    int stamina;
    int health;
public:
    Human(const string& name, int level, int strength, int magic, int stamina, int health)
        : Creature(name, level), strength(strength), magic(magic), stamina(stamina), health(health) {}

    int getStrength() const { return strength; }
    void setStrength(int strength) { this->strength = strength; }

    int getMagic() const { return magic; }
    void setMagic(int magic) { this->magic = magic; }

    int getStamina() const { return stamina; }
    void setStamina(int stamina) { this->stamina = stamina; }

    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }

    virtual void print() const override {
        Creature::print();
        cout << "Strength: " << strength << endl;
        cout << "Magic: " << magic << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Health: " << health << endl;
    }
    virtual int dealDamage() const {
        return strength + magic;
    }
    ~Human() {}
};

class Demon:public Creature
{
protected:
    int strength;
    int magic;
    int stamina;
    int health;
public:
    Demon(const string& name, int level, int strength, int magic, int stamina, int health)
        : Creature(name, level), strength(strength), magic(magic), stamina(stamina), health(health) {}

    int getStrength() const { return strength; }
    void setStrength(int strength) { this->strength = strength; }

    int getMagic() const { return magic; }
    void setMagic(int magic) { this->magic = magic; }

    int getStamina() const { return stamina; }
    void setStamina(int stamina) { this->stamina = stamina; }

    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }

    virtual void print() const override {
        Creature::print();
        cout << "Strength: " << strength << endl;
        cout << "Magic: " << magic << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Health: " << health << endl;
    }
    virtual int dealDamage() const {
        return strength + magic;
    }
    ~Demon() {}
};

class Elf:public Creature
{
protected:
    int strength;
    int magic;
    int stamina;
    int health;
public:
    Elf(const string& name, int level, int strength, int magic, int stamina, int health)
        : Creature(name, level), strength(strength), magic(magic), stamina(stamina), health(health) {}

    int getStrength() const { return strength; }
    void setStrength(int strength) { this->strength = strength; }

    int getMagic() const { return magic; }
    void setMagic(int magic) { this->magic = magic; }

    int getStamina() const { return stamina; }
    void setStamina(int stamina) { this->stamina = stamina; }

    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }

    virtual void print() const override {
        Creature::print();
        cout << "Strength: " << strength << endl;
        cout << "Magic: " << magic << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Health: " << health << endl;
    }
    virtual int dealDamage() const {
        return strength + magic;
    }
    ~Elf() {}
};

class Cyberdemon:public Demon
{
protected:
    int strength;
    int magic;
    int stamina;
    int health;
public:
    Cyberdemon(const string& name, int level, int strength, int magic, int stamina, int health)
        : Demon(name, level, strength, magic, stamina, health) {}

    int getStrength() const { return strength; }
    void setStrength(int strength) { this->strength = strength; }

    int getMagic() const { return magic; }
    void setMagic(int magic) { this->magic = magic; }

    int getStamina() const { return stamina; }
    void setStamina(int stamina) { this->stamina = stamina; }

    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }

    virtual void print() const override {
        Demon::print();
        cout << "Strength: " << strength << endl;
        cout << "Magic: " << magic << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Health: " << health << endl;
    }
    virtual int dealDamage() const {
        return strength + magic;
    }
    ~Cyberdemon() {}
};

class Balrog:public Demon
{
protected:
    int strength;
    int magic;
    int stamina;
    int health;
public:
    Balrog(const string& name, int level, int strength, int magic, int stamina, int health)
        : Demon(name, level, strength, magic, stamina, health) {}

    int getStrength() const { return strength; }
    void setStrength(int strength) { this->strength = strength; }

    int getMagic() const { return magic; }
    void setMagic(int magic) { this->magic = magic; }

    int getStamina() const { return stamina; }
    void setStamina(int stamina) { this->stamina = stamina; }

    int getHealth() const { return health; }
    void setHealth(int health) { this->health = health; }

    virtual void print() const override {
        Demon::print();
        cout << "Strength: " << strength << endl;
        cout << "Magic: " << magic << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Health: " << health << endl;
    }
    ~Balrog() {}
};

int main()
{
    Human h("Human", 1, 1, 1, 1, 1);
    h.print();
    h.dealDamage();
    cout << endl;

    Demon d("Demon", 1, 1, 1, 1, 1);
    d.print();
    d.dealDamage();
    cout << endl;

    Elf e("Elf", 1, 1, 1, 1, 1);
    e.print();
    e.dealDamage();
    cout << endl;

    Cyberdemon c("Cyberdemon", 1, 1, 1, 1, 1);
    c.print();
    c.dealDamage();
    cout << endl;

    Balrog b("Balrog", 1, 1, 1, 1, 1);
    b.print();
    b.dealDamage();
    cout << endl;

    return 0;
}
