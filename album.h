// Project
// Malla Grönqvist
// Header file for class Album

#ifndef DT019G_ALBUM_H
#define DT019G_ALBUM_H

#include "song.h"
#include <string>
#include <vector>

class Album {
private:
    // Data members
    std::string albumName;
    std::vector<Song>album;

public:
    // Member functions
    std::string getAlbumName() const;
    void setAlbumName(std::string pAlbumName);
    std::vector<Song> getAlbum() const;
    void setAlbum(std::vector<Song> pAlbum);

    void addSong(Song song);

    // Function that calculates the total length of an album.
    MyTime getAlbumLength() const;
    // Function for getting the number of songs in an album.
    size_t getNumberOfSongs() const;

    // Overloaded operators
    bool operator<(const Album& album) const;
    bool operator==(const Album& album) const;  // Needed for find() in jukebox

};

// Overloaded operators for saving to and reading from file.
std::ostream& operator<<(std::ostream& os, const Album& album);
std::istream& operator>>(std::istream& is, Album& album);



#endif //DT019G_ALBUM_H

