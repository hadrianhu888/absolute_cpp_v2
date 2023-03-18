/**
 * @file print_vertical_graph.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream> 
#include <chrono> 
#include <random> 
#include <ctime> 

using namespace std;
using namespace std::chrono;

#define ROWS 10
#define COLS 10

srand(time(0));
int random_seed= rand() % 1000;
/**
 * @brief prints out a vertical bar graph with * star symbols
 * 
 */

void get_data(vector<int> &data, string filename);
void print_graph(vector<int> &data);
void bins(vector<int> &data, vector<int> &bins);    
int set_bins();
int main(int argc,char **argv);
void write_random_data(void); 
void generate_random_data(void);

int main(int argc,char **argv)
{
    vector<int> data;
    vector<int> bins;
    int bin_size;
    string filename;
    if(argc==2)
    {
        filename=argv[1];
    }
    else
    {
        filename="data.txt";
    }
    get_data(data,filename);
    bin_size=set_bins();
    bins(data,bins);
    print_graph(bins);
    return 0;
}

void get_data(vector<int> &data, string filename)
{
    ifstream in_file;
    in_file.open(filename);
    if(!in_file)
    {
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    int num;
    while(in_file>>num)
    {
        data.push_back(num);
    }
    in_file.close();
}

void print_graph(vector<int> &data)
{
    for(int i=0;i<data.size();i++)
    {
        cout<<i<<"|";
        for(int j=0;j<data[i];j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void bins(vector<int> &data, vector<int> &bins)
{
    int bin_size=set_bins();
    bins.resize(bin_size);
    for(int i=0;i<data.size();i++)
    {
        bins[data[i]/10]++;
    }
}

int set_bins()
{
    int bin_size;
    cout<<"Enter the number of bins: ";
    cin>>bin_size;
    return bin_size;
}

void write_random_data(void)
{
    ofstream out_file;
    out_file.open("data.txt");
    if(!out_file)
    {
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    for(int i=0;i<100;i++)
    {
        out_file<<rand()%100<<endl;
    }
    out_file.close();
}

void generate_random_data(void)
{
    ofstream out_file;
    out_file.open("data.txt");
    if(!out_file)
    {
        cout<<"Error opening file"<<endl;
        exit(1);
    }
    for(int i=0;i<100;i++)
    {
        out_file<<rand()%100<<endl;
    }
    out_file.close();
}

// Path: chapter5\projects\print_vertical_graph.cpp
