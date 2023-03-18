/**
 * @file hot_dog_stands.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int numberOfHotDogStalls; //global variable

int main(int argc, char **argv);

class Hot_Dog_Stand
{
    private:
        int id;
        double price;
        double total_revenue;
        int hot_dogs_sold;
    public:
        Hot_Dog_Stand(int id, int hot_dogs_sold);
        void justSold();
        int numberOfHotDogStands();
        void print();
        int getId();
        void setId(int id);
        int getHotDogsSold();
        void setHotDogsSold(int hot_dogs_sold);
        int totalHotDogsSold();
        double averageHotDogsSold();
        double averageHotDogsSold(int total_hot_dogs_sold);
        double maxHotDogsSold();
        double maxHotDogsSold(int total_hot_dogs_sold);
        double minHotDogsSold();
        double minHotDogsSold(int total_hot_dogs_sold);
        double getTotalRevenue();
        void setTotalRevenue(double total_revenue);
};

Hot_Dog_Stand::Hot_Dog_Stand(int id, int hot_dogs_sold)
{
    this->id = id;
    this->hot_dogs_sold = hot_dogs_sold;
}

void Hot_Dog_Stand::justSold()
{
    hot_dogs_sold++;
}

void Hot_Dog_Stand::print()
{
    cout << "id = " << id << endl;
    cout << "hot_dogs_sold = " << hot_dogs_sold << endl;
}

int Hot_Dog_Stand::getId()
{
    return id;
}

void Hot_Dog_Stand::setId(int id)
{
    this->id = id;
}

int Hot_Dog_Stand::getHotDogsSold()
{
    return hot_dogs_sold;
}

void Hot_Dog_Stand::setHotDogsSold(int hot_dogs_sold)
{
    this->hot_dogs_sold = hot_dogs_sold;
}

int Hot_Dog_Stand::totalHotDogsSold()
{
    return hot_dogs_sold;
}

double Hot_Dog_Stand::averageHotDogsSold()
{
    return hot_dogs_sold;
}

double Hot_Dog_Stand::averageHotDogsSold(int total_hot_dogs_sold)
{
    return total_hot_dogs_sold / numberOfHotDogStalls;
}

double Hot_Dog_Stand::maxHotDogsSold()
{
    return hot_dogs_sold;
}

double Hot_Dog_Stand::maxHotDogsSold(int total_hot_dogs_sold)
{
    return total_hot_dogs_sold;
}

double Hot_Dog_Stand::minHotDogsSold()
{
    return hot_dogs_sold;
}

double Hot_Dog_Stand::minHotDogsSold(int total_hot_dogs_sold)
{
    return total_hot_dogs_sold;
}

double Hot_Dog_Stand::getTotalRevenue()
{
    return total_revenue;
}

void Hot_Dog_Stand::setTotalRevenue(double total_revenue)
{
    this->total_revenue = total_revenue;
}

int numberOfHotDogStands()
{
    return 0;
}

int main(int argc, char **argv) {
    Hot_Dog_Stand hds1(1, 10);
    /**
     * @brief create an array of 3 hot dog stands
     * 
     */
    Hot_Dog_Stand **hds = new Hot_Dog_Stand*[3];
    hds1.print();
    hds1.justSold();
    hds1.print();
    hds[0] = new Hot_Dog_Stand(1, 10);
    hds[1] = new Hot_Dog_Stand(2, 20);
    hds[2] = new Hot_Dog_Stand(3, 30);
    for (int i = 0; i < 3; i++) {
        hds[i]->print();
    }
    /**
     * @brief calculate total revenue and average hot dogs sold for all hot dog stands
     * 
     */
    int total_hot_dogs_sold = 0;
    for (int i = 0; i < 3; i++) {
        total_hot_dogs_sold += hds[i]->getHotDogsSold();
    }
    cout << "total_hot_dogs_sold = " << total_hot_dogs_sold << endl;
    cout << "average_hot_dogs_sold = " << hds[0]->averageHotDogsSold(total_hot_dogs_sold) << endl;
    cout << "max_hot_dogs_sold = " << hds[0]->maxHotDogsSold(total_hot_dogs_sold) << endl;
    cout << "min_hot_dogs_sold = " << hds[0]->minHotDogsSold(total_hot_dogs_sold) << endl;
    return 0;
}

// Path: chapter7\projects\hot_dog_stands\hot_dog_stands.cpp


