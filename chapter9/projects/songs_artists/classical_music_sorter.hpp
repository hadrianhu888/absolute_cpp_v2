#ifndef CLASSICAL_MUSIC_SORTER_H
#define CLASSICAL_MUSIC_SORTER_H

#include <vector>
#include <string>

using namespace std;

// function declarations
vector<string> readSongsFromFile(const string& filename);
void printVectorToTerminal(const vector<string>& vec, const string& title);
void sortSongsByArtistLastNameFirst(vector<string>& songs);
void sortSongsBySongTitle(vector<string>& songs);
void writeSortedSongsToOutputFile(const vector<string>& songs, const string& filename);

#endif // CLASSICAL_MUSIC_SORTER_H
