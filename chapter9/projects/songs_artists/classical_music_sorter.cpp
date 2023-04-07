/**
 * @file classical_music_sorter.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "classical_music_sorter.hpp"

using namespace std;

int main(int argc, char **argv); //main function prototype

void read_input_file(const string &filename, vector<string> &songs)
{
    ifstream infile(filename); // open the input file
    if (!infile)
    {
        cerr << "Error: failed to open input file." << endl;
        exit(1);
    }

    string line;
    while (getline(infile, line))
    { // read each line from the input file
        songs.push_back(line);
    }

    infile.close(); // close the input file
}

void write_output_file(const string &filename, const vector<string> &songs)
{
    ofstream outfile(filename); // open the output file
    if (!outfile)
    {
        cerr << "Error: failed to open output file." << endl;
        exit(1);
    }

    // write the songs in CSV format to the output file
    outfile << "Artist Name, Song Name" << endl;
    for (const string &song : songs)
    {
        size_t separator_pos = song.find(", "); // find the position of the separator between artist name and song name
        string artist_name = song.substr(separator_pos + 2); // extract the artist name
        string song_name = song.substr(0, separator_pos);    // extract the song name
        outfile << artist_name << ", " << song_name
                << endl; // write the artist name and song name in CSV format to the output file
    }

    outfile.close(); // close the output file
}

string extract_last_name_first(const string &name)
{
    size_t space_pos = name.rfind(" ");            // find the position of the last space character in the name
    string last_name = name.substr(space_pos + 1); // extract the last name
    string first_name = name.substr(0, space_pos); // extract the first name
    return last_name + ", " + first_name;          // concatenate the last name and first name in the desired order
}

void format_songs(vector<string> &songs)
{
    for (string &song : songs)
    {
        size_t dot_pos = song.find(". "); // find the position of the dot character after the song number
        if (dot_pos != string::npos)
        {                               // if a dot character is found
            song.erase(0, dot_pos + 2); // remove the song number and the following space character
        }
        size_t separator_pos = song.find(", "); // find the position of the separator between artist name and song name
        string artist_name = song.substr(0, separator_pos);            // extract the artist name
        string last_name_first = extract_last_name_first(artist_name); // format the artist name
        string song_name = song.substr(separator_pos + 2);             // extract the song name
        song = last_name_first + ", " + song_name; // concatenate the formatted artist name and song name
    }
}

void sort_songs(vector<string> &songs)
{
    sort(songs.begin(), songs.end()); // sort the songs alphabetically by artist name, then by song name
}

int main_sorter()
{
    vector<string> songs; // vector to store the songs

    read_input_file("input.txt", songs); // read the input file
    format_songs(songs);                           // format the songs
    sort_songs(songs);                             // sort the songs
    write_output_file("classical_music_sorted.txt", songs); // write the output file
    return 0;
}
