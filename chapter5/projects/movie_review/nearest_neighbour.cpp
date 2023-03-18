/**
 * @file nearest_neighbour.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <map>
#include <set>
#include <iterator>
#include <functional>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <utility>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <exception>
#include <new>
#include <initializer_list>
#include <tuple>
#include <array>
#include <regex>
#include <chrono>
#include <random>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono; 

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::uniform_int_distribution<int> distribution(1,100);

int random_number_generator(void); 
int nearest_neighbour(int *arr, int size, int target);
int main(int argc, char **argv); 
void print_random_numbers(void);
void print_nearest_neighbour(void);



int random_number_generator(void)
{
    return distribution(generator);
}

int nearest_neighbour(int *arr, int size, int target)
{
    int min = abs(arr[0] - target);
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (abs(arr[i] - target) < min)
        {
            min = abs(arr[i] - target);
            index = i;
        }
    }
    return index;
}

void print_random_numbers(void)
{
    for (int i = 0; i < 10; i++)
    {
        cout << random_number_generator() << " ";
    }
    cout << endl;
}

void print_nearest_neighbour(void)
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = random_number_generator();
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int target = random_number_generator();
    cout << "target: " << target << endl;
    int index = nearest_neighbour(arr, 10, target);
    cout << "nearest neighbour: " << arr[index] << endl;
}

int main(int argc, char **argv)
{
    print_random_numbers();
    print_nearest_neighbour();
    return 0;
}

