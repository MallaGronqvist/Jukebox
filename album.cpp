// Project
// Malla Grönqvist
// Definition file for class Album

#include "album.h"
#include "song.h"
#include <vector>

std::string Album::getAlbumName() const {
    return albumName;
}

void Album::setAlbumName(std::string pAlbumName) {
    albumName = pAlbumName;
}

std::vector<Song> Album::getAlbum() const {
    return album;
}

void Album::addSong(Song song) {
    album.push_back(song);  // Add song to the vector.
}

bool Album::operator<(const Album& album) const {
    return getAlbumLength() < album.getAlbumLength();
}

MyTime Album::getAlbumLength() const {
    MyTime albumLength;
    // Calculate the sum of the lengths of the songs in album.
    for (auto idx : album) {
        albumLength = albumLength + idx.getLength();
    }

    return albumLength;
}

size_t Album::getNumberOfSongs() const {
    return album.size();
}

void Album::setAlbum(std::vector<Song> pAlbum) {
    album = pAlbum;
}

bool Album::operator==(const Album& album) const {
    // Copy album names to temporary strings.
    std::string tmpString1 = albumName;
    std::string tmpString2 = album.albumName;
    // Convert all characters to uppercase for non-case sensitive comparison
    for (auto& c : tmpString1) {
        c = toupper(c);
    }
    for (auto& c : tmpString2) {
        c = toupper(c);
    }

    // Compare album names.
    return tmpString1 == tmpString2;
}

std::ostream& operator<<(std::ostream& os, const Album& album) {
    // Write album name and number of songs to file
    os << album.getAlbumName() << std::endl;
    os << album.getNumberOfSongs() << std::endl;

    // Declare a temporary vector for simple iteration over album
    std::vector<Song>tmpAlbum;
    // Copy album to temporary vector
    tmpAlbum = album.getAlbum();

    // Iterate over vector and write each element to file
    for (auto idx : tmpAlbum) {
        os << idx;
        os << std::endl;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Album& album) {
    std::string tmpString;
    getline(is, tmpString);   // Read in album name.
    album.setAlbumName(tmpString);  // Set album name.

    int tmpInt;     // Read in no of song.
    is >> tmpInt;
    is.get();

    // Add songs to album one by one for tmpInt times.
    for (int x = 1; x <= tmpInt; x++) {
        Song tmpSong;
        is >> tmpSong;  // Use the overloaded operator>> from class Song.
        album.addSong(tmpSong);
    }

    return is;
}
