/**
 * @file song.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SONG_SORTER_H_
#define SONG_SORTER_H_

#include <string>
#include <vector>

// Song struct to store information about a single song
struct Song {
    std::string artist;
    std::string title;
};

// Function prototypes
bool compare_songs(const Song &s1, const Song &s2); 
std::vector<Song> read_songs(const std::string &filename);
void write_songs(const std::vector<Song> &songs, const std::string &filename);

#endif // SONG_SORTER_H_

