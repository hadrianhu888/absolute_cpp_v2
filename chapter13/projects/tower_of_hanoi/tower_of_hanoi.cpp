/**
 * @file tower_of_hanoi.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

string inFile = "in.txt";
string outFile = "out.txt";

void move_disks(int count, int needle1, int needle3, int needle2);
int count_disk_moves(int count);
void write_data_to_file(ifstream& in_stream, ofstream& out_stream);
int main(int argc, char **argv);

void move_disks(int count, int needle1, int needle3, int needle2)
{
    if (count > 0)
    {
        move_disks(count - 1, needle1, needle2, needle3);
        cout << "Move a disk from needle " << needle1 << " to needle " << needle3 << endl;
        move_disks(count - 1, needle2, needle3, needle1);
    }
}

int count_disk_moves(int count)
{
    if (count == 1)
    {
        return 1;
    }
    else
    {
        return 2 * count_disk_moves(count - 1) + 1;
    }
}

void write_data_to_file(ifstream& in_stream, ofstream& out_stream)
{
    int next;
    in_stream >> next;
    while (!in_stream.eof())
    {
        out_stream << next << endl;
        in_stream >> next;
    }
}

int main(int argc, char **argv)
{
    move_disks(3, 1, 3, 2);
    cout << "Number of moves for 3 disks: " << count_disk_moves(3) << endl;
    for(int i = 1; i < 10; i++)
    {
        move_disks(i, 1, 3, 2);
        cout << "Number of moves for " << i << " disks: " << count_disk_moves(i) << endl;
    }
    return 0;
}
