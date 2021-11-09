// Project
// Malla Grönqvist
// Definition file for class Song

#include "song.h"

Song::Song() {
    // Initiate strings as empty by default string constructor.
    // length is initiated by default constructor from class Time.
}

Song::Song(std::string pTitle, std::string pArtist, MyTime pLength) {
    // Initiate data members with the given parameters.
    title = pTitle;
    artist = pArtist;
    length = pLength;
}

void Song::setTitle(std::string pTitle) {
    title = pTitle;
}

void Song::setLength(MyTime pLength) {
    length = pLength;
}

void Song::setArtist(std::string pArtist) {
    artist = pArtist;
}

// Overloaded operators for saving to and reading from file.
const char DELIM = '|'; // Delimiter in between data members in text file.
std::ostream& operator<<(std::ostream& os, const Song& song) {
    os << song.getTitle() << DELIM;
    os << song.getArtist() << DELIM;
    os << song.getLength();

    return os;
}

std::istream& operator>>(std::istream& is, Song& song) {
    std::string tmpString1, tmpString2;
    getline(is, tmpString1, DELIM); // Read until DELIM into tmpString.
    getline(is, tmpString2, DELIM);

    song.setTitle(tmpString1);  // Set values.
    song.setArtist(tmpString2);

    MyTime tmpLength;
    is >> tmpLength; // Use overloaded operator from class MyTime.
    is.get();
    song.setLength(tmpLength);  // Set value.

    return is;
}
