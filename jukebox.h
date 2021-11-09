#ifndef DT019G_JUKEBOX_H
#define DT019G_JUKEBOX_H

#include "album.h"
#include "menu.h"
#include <vector>

class Jukebox {
private:
    // Data members
    std::vector<Album>listOfAlbums;
    Menu mainMenu, fileMenu, printMenu;

    // Member functions
    void addAlbum();
    void removeAlbum();
    void openFromFile();
    void saveToFile();
    void printAlbum();
    void printAllSortedByName();
    void printSimpleAllSortedByName();
    void printAllSortedByLength();
    void printSimpleSortedByLength();

public:
    // Default constructor
    Jukebox();
    // Member function for running the program
    void run();
};

// Help function for sorting by name
bool sortByName(const Album& album1, const Album& album2);
// Constant for file name
const std::string fileName = "jukebox.txt";

#endif //DT019G_JUKEBOX_H

