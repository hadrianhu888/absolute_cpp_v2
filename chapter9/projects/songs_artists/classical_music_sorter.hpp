#ifndef CLASSICAL_MUSIC_SORTER_H
#define CLASSICAL_MUSIC_SORTER_H

#include <vector>
#include <string>

using namespace std;

// function declarations
void read_input_file(const string &filename, vector<string> &songs);
void write_output_file(const string &filename, const vector<string> &songs);
string extract_last_name_first(const string &name);
void format_songs(vector<string> &songs);
void sort_songs(vector<string> &songs);

#endif // CLASSICAL_MUSIC_SORTER_H
