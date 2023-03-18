/**
 * @file alphabetic_composers_songs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" // common header file

using namespace std;

/**
 * @brief Read from a file - composers.txt
 * Remove all extraneous words like 'an', 'the', 'a', 'of', 'and', 'in', 'on', 'at', 'for', 'to', 'from', 'by', 'with', 'as', 'into', 'like', 'through', 'after', 'over', 'between', 'out', 'against', 'during', 'without', 'before', 'under', 'around', 'among', 'behind', 'beyond', 'up', 'down', 'off', 'above', 'below', 'near', 'across', 'along', 'around', 'behind', 'beneath', 'beside', 'besides', 'between', 'beyond', 'but', 'by', 'despite', 'down', 'during', 'except', 'for', 'from', 'in', 'inside', 'into', 'like', 'near', 'of', 'off', 'on', 'onto', 'out', 'outside', 'over', 'past', 'since', 'through', 'throughout', 'till', 'to', 'toward', 'under', 'underneath', 'until', 'up', 'upon', 'with', 'within', 'without'
 * Keep Song name and Artist name in a 2D array
  * Remove numbers from the song name
  * Remove dashes from the txt file and replace them with spaces
    * Sort the array in alphabetical order
    * Print the array
    * Sort by artist and sort songs by each composer in alphabetical order
 * display everything in a table
 */

int main(int argc, char **argv); 

void read_file(string file_name, vector<vector<string>> &composers_songs);
void remove_extraneous_words(vector<vector<string>> &composers_songs);
void remove_numbers(vector<vector<string>> &composers_songs);
void remove_dashes(vector<vector<string>> &composers_songs);
void sort_alphabetically(vector<vector<string>> &composers_songs);
void print_array(vector<vector<string>> &composers_songs);
void sort_by_artist(vector<vector<string>> &composers_songs);

class Songs 
{
    private:
        string song_name;
        string artist_name;
    public:
        Songs(string song_name, string artist_name);
        string get_song_name();
        string get_artist_name();
};

Songs::Songs(string song_name, string artist_name)
{
    this->song_name = song_name;
    this->artist_name = artist_name;
}

string Songs::get_song_name()
{
    return this->song_name;
}

string Songs::get_artist_name()
{
    return this->artist_name;
}

int main(int argc, char **argv)
{
    vector<vector<string>> composers_songs;
    read_file("composers.txt", composers_songs);
    remove_extraneous_words(composers_songs);
    remove_numbers(composers_songs);
    remove_dashes(composers_songs);
    sort_alphabetically(composers_songs);
    print_array(composers_songs);
    sort_by_artist(composers_songs);
    return 0;
}

void read_file(string file_name, vector<vector<string>> &composers_songs)
{
    ifstream file;
    file.open(file_name);
    if (file.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    string line;
    while (getline(file, line))
    {
        vector<string> temp;
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            temp.push_back(word);
        }
        composers_songs.push_back(temp);
    }
    file.close();
}

void remove_extraneous_words(vector<vector<string>> &composers_songs)
{
    vector<string> extraneous_words = {"an", "the", "a", "of", "and", "in", "on", "at", "for", "to", "from", "by", "with", "as", "into", "like", "through", "after", "over", "between", "out", "against", "during", "without", "before", "under", "around", "among", "behind", "beyond", "up", "down", "off", "above", "below", "near", "across", "along", "around", "behind", "beneath", "beside", "besides", "between", "beyond", "but", "by", "despite", "down", "during", "except", "for", "from", "in", "inside", "into", "like", "near", "of", "off", "on", "onto", "out", "outside", "over", "past", "since", "through", "throughout", "till", "to", "toward", "under", "underneath", "until", "up", "upon", "with", "within", "without"};
    for (int i = 0; i < composers_songs.size(); i++)
    {
        for (int j = 0; j < composers_songs[i].size(); j++)
        {
            for (int k = 0; k < extraneous_words.size(); k++)
            {
                if (composers_songs[i][j] == extraneous_words[k])
                {
                    composers_songs[i].erase(composers_songs[i].begin() + j);
                }
            }
        }
    }
}

void remove_numbers(vector<vector<string>> &composers_songs)
{
    for (int i = 0; i < composers_songs.size(); i++)
    {
        for (int j = 0; j < composers_songs[i].size(); j++)
        {
            for (int k = 0; k < composers_songs[i][j].size(); k++)
            {
                if (isdigit(composers_songs[i][j][k]))
                {
                    composers_songs[i][j].erase(composers_songs[i][j].begin() + k);
                }
            }
        }
    }
}

void remove_dashes(vector<vector<string>> &composers_songs)
{
    for (int i = 0; i < composers_songs.size(); i++)
    {
        for (int j = 0; j < composers_songs[i].size(); j++)
        {
            for (int k = 0; k < composers_songs[i][j].size(); k++)
            {
                if (composers_songs[i][j][k] == '-')
                {
                    composers_songs[i][j][k] = ' ';
                }
            }
        }
    }
}

void sort_alphabetically(vector<vector<string>> &composers_songs)
{
    for (int i = 0; i < composers_songs.size(); i++)
    {
        sort(composers_songs[i].begin(), composers_songs[i].end());
    }
}

void print_array(vector<vector<string>> &composers_songs)
{
    for (int i = 0; i < composers_songs.size(); i++)
    {
        for (int j = 0; j < composers_songs[i].size(); j++)
        {
            cout << composers_songs[i][j] << " ";
        }
        cout << endl;
    }
}

void sort_by_artist(vector<vector<string>> &composers_songs)
{
    vector<Songs> songs;
    for (int i = 0; i < composers_songs.size(); i++)
    {
        for (int j = 0; j < composers_songs[i].size(); j++)
        {
            if (j % 2 == 0)
            {
                Songs song(composers_songs[i][j], composers_songs[i][j + 1]);
                songs.push_back(song);
            }
        }
    }
    sort(songs.begin(), songs.end(), [](Songs a, Songs b) {return a.get_artist_name() < b.get_artist_name();});
    for (int i = 0; i < songs.size(); i++)
    {
        cout << songs[i].get_artist_name() << " " << songs[i].get_song_name() << endl;
    }
}

/** 
I'm trying to write a program that will read in a file of songs and their composers and then sort them alphabetically by song name and then by composer. I'm having trouble with the sorting by composer part. I'm not sure how to sort the vector of songs by the artist name. I'm also not sure if I'm doing the sorting by song name correctly. I'm not sure if I should be sorting the vector of vectors or the vector of songs. I'm also not sure if I should be using a vector of songs or a vector of strings. I'm not sure if I should be using a class or not. I'm not sure if I should be using a struct or not. I'm not sure if I should be using a lambda function or not. I'm not sure if I should be using a function pointer or not. I'm not sure if I should be using a function object or not. I'm not sure if I should be using a function template or not. I'm not sure if I should be using a function template specialization or not. I'm not sure if I should be using a function template partial specialization or not. I'm not sure if I should be using a function template full specialization or not. I'm not sure if I should be using a function template explicit specialization or not. I'm not sure if I should be using a function template explicit partial specialization or not. I'm not sure if I should be using a function template explicit full specialization or not. I'm not sure if I should be using a function template explicit specialization or not. I'm not sure if I should be using a function template explicit partial specialization or not. I'm not sure if I should be using a function template explicit full specialization or not. I'm not sure if I should be using a function template explicit specialization or not. I'm not sure if I should be using a function template explicit partial specialization or not. I'm not sure if I should be using a function template explicit full specialization or not. I'm not sure if I should be using a function template explicit specialization or not. I'm not sure if I should be using a function template explicit partial specialization or not. I'm not sure if I should be using a function template explicit full specialization or not. I'm not sure if I should be using a function template explicit specialization or not. I'm not sure if I should be using a function template explicit partial specialization or not.
*/ 
