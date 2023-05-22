/**
 * @file birthday_map.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

int n = 2000;
int days = 365;
/**
 * @brief generate srand seed
 *
 */
void generateSrandSeed();
map<int, int> birthday_counts;
map<int, int> birthdate_statistics;
int assignRandomBirthDates(map<int, int> &birthday_counts, int n);
map<int, int> initializeMapToZeros(map<int, int> &birthday_counts);
void printInitialRandomMap(map<int, int> &birthday_counts);
void printMap(map<int, int> &birthday_counts);
int countSameBirthdays(map<int, int> &birthday_counts);
map<int, int> generate_birthdate_statistics(int birthdates[], int counts[]);
int main(int argc, char **argv);

int main(int argc, char **argv)
{
    initializeMapToZeros(birthday_counts);
    generateSrandSeed();
    assignRandomBirthDates(birthday_counts, n);
    printInitialRandomMap(birthday_counts);
    printMap(birthday_counts);
    countSameBirthdays(birthday_counts);
    return 0;
}

/**
 * @brief generate srand seed
 *
 */

void generateSrandSeed()
{
    srand(time(NULL));
}

/**
 * @brief assign random birthdays to n people
 *
 * @param birthday_counts
 * @param n
 * @return int
 */

int assignRandomBirthDates(map<int, int> &birthday_counts, int n)
{
    int birthday;
    for (int i = 0; i < n; i++)
    {
        birthday = rand() % days;
        birthday_counts[birthday]++;
    }
    return 0;
}

/**
 * @brief initialize map to zeros
 *
 * @param birthday_counts
 * @return map<int, int>
 */

map<int, int> initializeMapToZeros(map<int, int> &birthday_counts)
{
    for (int i = 0; i < days; i++)
    {
        birthday_counts[i] = 0;
    }
    return birthday_counts;
}

/**
 * @brief print map
 *
 * @param birthday_counts
 */

void printMap(map<int, int> &birthday_counts)
{
    for (int i = 0; i < days; i++)
    {
        cout << "birthday_counts[" << i << "] = " << birthday_counts[i] << endl;
    }
}

/**
 * @brief count same birthdays
 *
 * @param birthday_counts
 * @return int
 */
int countSameBirthdays(map<int, int> &birthday_counts)
{
    int same_birthdays = 0;
    for (int i = 0; i < days; i++)
    {
        if (birthday_counts[i] > 1)
        {
            same_birthdays++;
        }
    }
    cout << "Number of same birthdays: " << same_birthdays << endl;
    return same_birthdays;
}

map<int,int> generate_birthdate_statistics(int birthdates[],int counts[])
{
    for (int i = 0; i < days; i++)
    {
        birthdate_statistics[birthdates[i]] = counts[i];
    }
    return birthdate_statistics;
}

void printInitialRandomMap(map<int, int> &birthday_counts)
{
    for (int i = 0; i < days; i++)
    {
        cout << "birthday_counts[" << i << "] = " << birthday_counts[i] << endl;
    }
}
