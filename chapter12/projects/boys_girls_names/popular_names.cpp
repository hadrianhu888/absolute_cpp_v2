/**
 * @file popular_names.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:\\GitHubRepos\absolute_cpp_v2\common.hpp"

using namespace std;

string boys_file = "boynames.txt";
string girls_file = "girlnames.txt";
string merged_file = "mergednames.txt";

void openBoysGirlsNamesFiles(ifstream &boysFile, ifstream &girlsFile);
void mergeFilesContents(ifstream &boysFile, ifstream &girlsFile, ofstream &mergedFile);
void getNameData(map<string, int> &names_map, ifstream &mergedFile);
map<string, int> storeNamesInMap(ifstream &mergedFile);
void displayNamesInMap(map<string, int> &names_map);
void getUserNameRequest(map<string, int> &names_map);

int main() {
    ifstream boysFile, girlsFile;
    ofstream outputFile;

    openBoysGirlsNamesFiles(boysFile, girlsFile);
    mergeFilesContents(boysFile, girlsFile, outputFile);
    outputFile.close();
    boysFile.close();
    girlsFile.close();

    ifstream mergedFile(merged_file);
    map<string, int> names_map = storeNamesInMap(mergedFile);
    mergedFile.close();

    getUserNameRequest(names_map);

    return 0;
}

void openBoysGirlsNamesFiles(ifstream &boysFile, ifstream &girlsFile) {
    boysFile.open(boys_file);
    girlsFile.open(girls_file);

    if (!boysFile || !girlsFile) {
        cout << "Error opening input files." << endl;
        exit(1);
    }
}

void mergeFilesContents(ifstream &boysFile, ifstream &girlsFile, ofstream &mergedFile) {
    mergedFile.open(merged_file);
    if (!mergedFile) {
        cout << "Error opening output file." << endl;
        exit(1);
    }

    string line;
    while (getline(boysFile, line)) {
        mergedFile << line << endl;
    }
    while (getline(girlsFile, line)) {
        mergedFile << line << endl;
    }
}

map<string, int> storeNamesInMap(ifstream &mergedFile) {
    map<string, int> names_map;
    string line;

    while (getline(mergedFile, line)) {
        stringstream ss(line);
        string name;
        int rank;
        getline(ss, name, ',');
        ss >> rank;
        names_map[name] = rank;
    }

    return names_map;
}

void getUserNameRequest(map<string, int> &names_map) {
    string input_name;
    cout << "Enter a name to find its popularity (or type 'exit' to quit): ";

    while (getline(cin, input_name)) {
        if (input_name == "exit") break;

        auto it = names_map.find(input_name);
        if (it != names_map.end()) {
            cout << input_name << " has a popularity rank of " << it->second << "." << endl;
        } else {
            cout << input_name << " was not found in the list." << endl;
        }

        cout << "Enter another name (or type 'exit' to quit): ";
    }
}
