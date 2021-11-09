// Project
// Malla Grönqvist
// Header file for class Song

#ifndef DT019G_SONG_H
#define DT019G_SONG_H

#include "mytime.h"
#include <string>
#include <iostream>

class Song {
private:
    std::string title;
    std::string artist;
    MyTime length;

public:
    Song();  // Default constructor
    // Constructor for initiating
    Song(std::string pTitle, std::string pArtist, MyTime pLength);

    // Member functions
    void setTitle(std::string pTitle);
    void setArtist(std::string pArtist);
    void setLength(MyTime pLength);

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    MyTime getLength() const { return length; }

};

// Overloaded operators for saving to and reading from file.
std::ostream& operator<<(std::ostream& os, const Song& song);
std::istream& operator>>(std::istream& is, Song& song);

#endif //DT019G_SONG_H

