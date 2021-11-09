// Project
// Malla Grönqvist
// Definition file for class Jukebox

#include "jukebox.h"
#include <algorithm>  // std::find()
#include <fstream>
#include <iomanip>


Jukebox::Jukebox() {
    // Initiate menus
    mainMenu.setMenuTitle("*****JUKEBOX*****");
    mainMenu.addItem("File...", true);
    mainMenu.addItem("Add an album", false);
    mainMenu.addItem("Delete an album", false);
    mainMenu.addItem("Print...", false);
    mainMenu.addItem("Exit", true);

    fileMenu.setMenuTitle("*****FILE*****");
    fileMenu.addItem("Open", true);
    fileMenu.addItem("Save", false);
    fileMenu.addItem("Back to main menu", true);

    printMenu.setMenuTitle("*****PRINT*****");
    printMenu.addItem("Print one album", true);
    printMenu.addItem("Print all sorted by album name", true);
    printMenu.addItem("Print all sorted by album total time", true);
    printMenu.addItem("Print simple sorted by album name", true);
    printMenu.addItem("Print simple sorted by album total time", true);
    printMenu.addItem("Back to main menu", true);

}

void Jukebox::run() {

    bool again = true;
    do  // Repeat until user chooses to exit program
    {
        mainMenu.printMenuItems();  // Print main menu
        switch (mainMenu.getMenuChoice()) // Let the user select a menu item
        { // Run the selected part of the program
        case 1: {
            bool printFileMenu = true;
            do {    // Repeat until user chooses exit
                fileMenu.printMenuItems();  // Print file menu
                // Let the user select a menu item and run the selected function
                switch (fileMenu.getMenuChoice()) {
                case 1:
                    openFromFile();
                    break;
                case 2:
                    saveToFile();
                    break;
                case 3:
                    printFileMenu = false;
                }
            } while (printFileMenu);
        }
              break;
        case 2: addAlbum();
            break;
        case 3: removeAlbum();
            break;
        case 4: {
            bool printPrintMenu = true;
            do {
                printMenu.printMenuItems();
                switch (printMenu.getMenuChoice()) {
                case 1: printAlbum();
                    break;
                case 2: printAllSortedByName();
                    break;
                case 3: printAllSortedByLength();
                    break;
                case 4: printSimpleAllSortedByName();
                    break;
                case 5: printSimpleSortedByLength();
                    break;
                case 6: printPrintMenu = false;
                }
            } while (printPrintMenu);
        }
              break;
        case 5: again = false;
        }
    } while (again);
}

void Jukebox::addAlbum() {
    std::cout << "*****Add an album to the list of albums*****" << std::endl;
    // Declare a temporary Album object
    Album tmpAlbum;
    std::string tmpAlbumName;
    std::cout << "Enter album name:" << std::endl;
    getline(std::cin, tmpAlbumName);     // Read in user input
    tmpAlbum.setAlbumName(tmpAlbumName);    // Set album name

    bool again = true;
    do {    // Add songs to album as long as user chooses 'yes'.
        char ch;
        do {
            std::cout << "Enter a song (Y/N)?" << std::endl;
            std::cin >> ch;     // Read in user input.
            ch = toupper(ch);       // Convert to uppercase.
        } while (!(ch == 'Y' || ch == 'N'));      // Repeat as long as user input is invalid.
        std::cin.get();
        if (ch == 'N') {
            again = false;
        }
        else {
            // Declare a temporary Song object
            Song tmpSong;
            std::string tmpTitle, tmpName;
            // Declare a temporary Time object
            MyTime tmpTime;
            int hour, min, sec;

            std::cout << "Enter song title:" << std::endl;
            getline(std::cin, tmpTitle);
            std::cout << "Enter artist name:" << std::endl;
            getline(std::cin, tmpName);
            std::cout << "Enter song length in h, min and sec:" << std::endl;
            std::cout << "Hours:" << std::endl;
            std::cin >> hour;
            std::cin.get();
            std::cout << "Minutes:" << std::endl;
            std::cin >> min;
            std::cin.get();
            std::cout << "Seconds:" << std::endl;
            std::cin >> sec;
            std::cin.get();

            // Set values of data members.
            tmpTime.setHour(hour);
            tmpTime.setMin(min);
            tmpTime.setSec(sec);
            tmpSong.setTitle(tmpTitle);
            tmpSong.setArtist(tmpName);
            tmpSong.setLength(tmpTime);

            // Add song to album.
            tmpAlbum.addSong(tmpSong);

            std::cout << "The song you entered was added to the album!" << std::endl;
        }
    } while (again);
    // Add album to the list of albums.
    listOfAlbums.push_back(tmpAlbum);
    std::cout << "The album you entered was added to the list of albums!" << std::endl;

    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::removeAlbum() {
    std::cout << "*****Remove an album*****" << std::endl;
    std::cout << "Enter album name:" << std::endl;
    std::string searchTerm;
    getline(std::cin, searchTerm);  // Read in user input
    // Declare a temporary Album object and set its name with searchTerm.
    Album tmpAlbum;
    tmpAlbum.setAlbumName(searchTerm);

    // Search for the album in the list of albums.
    // Find uses the overloaded operator== from class Album
    // for a non-case sensitive search.
    auto searched = std::find(listOfAlbums.begin(), listOfAlbums.end(), tmpAlbum);

    // If the album is found, erase it from the list.
    if (searched != listOfAlbums.end()) {
        listOfAlbums.erase(searched);
        std::cout << "The album was found and erased." << std::endl;
    }
    else {
        std::cout << "The album was not found." << std::endl;
    }

    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::openFromFile() {

    std::fstream inFile;
    inFile.open(fileName, std::ios::in); // Open file for reading.

    if (inFile.is_open()) {  // If the file could be opened
        std::cout << "Loading the list of albums from file " << fileName << "." << std::endl;
        listOfAlbums.clear();  // Erase any previous data from the list.
        // A temporary Album object
        Album tmpAlbum;
        // As long as there are albums to read in
        while (inFile >> tmpAlbum) {
            listOfAlbums.push_back(tmpAlbum);  // Add album to the list
            std::vector<Song>empty;
            tmpAlbum.setAlbum(empty);   // Reset tmpAlbum's vector to empty.
        }
        inFile.close();     // Close file.
        std::cout << "The list of albums has been loaded!" << std::endl << std::endl;

        // Enable all menu options when file has been opened.
        mainMenu.setMenuItemOptions(true);
        fileMenu.setMenuItemOptions(true);

    }
    else {    // If file could not be opened, print info to user.
        std::cout << "Could not open file!" << std::endl;
    }
}

void Jukebox::saveToFile() {

    std::cout << std::endl << "The list of albums was saved to " << fileName << "."
        << std::endl << std::endl;

    std::fstream outFile(fileName, std::ios::out); // Open file for writing.
    // Write each item in list to file
    for (auto idx : listOfAlbums) {
        outFile << idx;
    }
    outFile.close(); // Close the file.
}

void Jukebox::printAlbum() {
    std::cout << std::endl << "*****Print an Album from the List of Albums*****" << std::endl
        << "Enter album name:" << std::endl;
    std::string searchTerm;
    getline(std::cin, searchTerm);

    // Declare a temporary Album object and set its name with searchTerm.
    Album tmpAlbum;
    tmpAlbum.setAlbumName(searchTerm);

    // Search for the album in the list of albums.
    // Find uses the overloaded operator== from class Album
    // for a non-case sensitive search.
    auto pr = std::find(listOfAlbums.begin(), listOfAlbums.end(), tmpAlbum);

    // If the album is found, print it on screen.
    if (pr != listOfAlbums.end()) {
        std::cout << "Album name: " << (*pr).getAlbumName() << std::endl
            << "**********************************************************************************" << std::endl;
        std::cout << std::left << std::setw(5) << "No" << std::setw(50) << "Title" << std::setw(20)
            << "Artist" << std::setw(20) << "Length" << std::endl
            << "**********************************************************************************" << std::endl;
        int count = 1;
        // Copy album's songs to a temporary vector
        std::vector<Song>tmpVector;
        tmpVector = (*pr).getAlbum();
        // Print each song from the vector
        for (auto idx : tmpVector) {
            std::cout << std::left << std::setw(5) << count << std::setw(50) << idx.getTitle()
                << std::setw(20) << idx.getArtist();
            // Copy song length to a temporary MyTime object
            MyTime tmpTime = idx.getLength();
            // Format song length
            if (tmpTime.getHour() > 0) {
                std::cout << std::right << std::setw(1) << tmpTime.getHour() << ":";
                tmpTime.getMin() < 10 ? std::cout << "0" << tmpTime.getMin() << ":"
                    : std::cout << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            else {
                std::cout << std::right << std::setw(1) << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            count++;
        }
        std::cout << "**********************************************************************************" << std::endl;
    }
    else {    // If album wasn't found, print info to user.
        std::cout << "The album was not found." << std::endl;
    }
    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::printAllSortedByName() {
    // Sort albums by using function sortByName.
    sort(listOfAlbums.begin(), listOfAlbums.end(), sortByName);
    // Print the sorted list.
    std::cout << std::endl << "*****List of Albums Sorted by Album Name*****" << std::endl
        << "Listing all album information:" << std::endl
        << "==================================================================================" << std::endl;
    // Print each album from the list
    for (auto idx : listOfAlbums) {
        std::cout << "Album name: " << idx.getAlbumName() << std::endl
            << "**********************************************************************************" << std::endl;
        std::cout << std::left << std::setw(5) << "No" << std::setw(50) << "Title" << std::setw(20)
            << "Artist" << std::setw(20) << "Length" << std::endl
            << "**********************************************************************************" << std::endl;
        int count = 1;
        // Copy the album's songs to a temporary vector
        std::vector<Song>tmpVector;
        tmpVector = idx.getAlbum();
        // Print each song from the vector (as in function printAlbum)
        for (auto idx : tmpVector) {
            std::cout << std::left << std::setw(5) << count << std::setw(50) << idx.getTitle()
                << std::setw(20) << idx.getArtist();
            MyTime tmpTime = idx.getLength();
            if (tmpTime.getHour() > 0) {
                std::cout << std::right << std::setw(1) << tmpTime.getHour() << ":";
                tmpTime.getMin() < 10 ? std::cout << "0" << tmpTime.getMin() << ":"
                    : std::cout << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            else {
                std::cout << std::right << std::setw(1) << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            count++;
        }
        std::cout << "**********************************************************************************" << std::endl;
    }
    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::printSimpleAllSortedByName() {
    // Sort albums by using function sortByName.
    sort(listOfAlbums.begin(), listOfAlbums.end(), sortByName);
    // Print the sorted list.
    std::cout << std::endl << "*****List of Albums Sorted by Album Name*****" << std::endl
        << "Listing only album names:" << std::endl
        << "=========================================================" << std::endl;
    int count = 1;
    for (auto idx : listOfAlbums) {
        std::cout << count << " : " << idx.getAlbumName() << std::endl;
        count++;
    }
    std::cout << "=========================================================" << std::endl;
    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::printAllSortedByLength() {
    // Sort albums by length using the overloaded operator< from class Album
    sort(listOfAlbums.begin(), listOfAlbums.end());
    // Print the sorted list.
    std::cout << std::endl << "*****List of Albums Sorted by Album Length*****" << std::endl
        << "Listing all album information, longest album first:" << std::endl
        << "==================================================================================" << std::endl;
    int countAlbum = 1;
    // Print the list in reversed order to get the longest album first.
    std::vector<Album>::reverse_iterator ri;
    for (ri = listOfAlbums.rbegin(); ri != listOfAlbums.rend(); ri++) {
        std::cout << countAlbum << ": " << (*ri).getAlbumName() << " | Album length: ";
        MyTime tmpLength = (*ri).getAlbumLength();
        if (tmpLength.getHour() > 0) {
            std::cout << std::right << std::setw(1) << tmpLength.getHour() << ":";
            tmpLength.getMin() < 10 ? std::cout << "0" << tmpLength.getMin() << ":"
                : std::cout << tmpLength.getMin() << ":";
            tmpLength.getSec() < 10 ? std::cout << "0" << tmpLength.getSec() << std::endl
                : std::cout << tmpLength.getSec() << std::endl;
        }
        else {
            std::cout << std::right << std::setw(1) << tmpLength.getMin() << ":";
            tmpLength.getSec() < 10 ? std::cout << "0" << tmpLength.getSec() << std::endl
                : std::cout << tmpLength.getSec() << std::endl;
        }
        std::cout << "**********************************************************************************" << std::endl;

        std::cout << std::left << std::setw(5) << "No" << std::setw(50) << "Title" << std::setw(20)
            << "Artist" << std::setw(20) << "Length" << std::endl
            << "**********************************************************************************" << std::endl;
        // Print the album's songs
        int countSong = 1;
        std::vector<Song> tmpVector;
        tmpVector = (*ri).getAlbum();
        for (auto idx : tmpVector) {
            std::cout << std::left << std::setw(5) << countSong << std::setw(50) << idx.getTitle()
                << std::setw(20) << idx.getArtist();
            MyTime tmpTime = idx.getLength();
            if (tmpTime.getHour() > 0) {
                std::cout << std::right << std::setw(1) << tmpTime.getHour() << ":";
                tmpTime.getMin() < 10 ? std::cout << "0" << tmpTime.getMin() << ":"
                    : std::cout << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            else {
                std::cout << std::right << std::setw(1) << tmpTime.getMin() << ":";
                tmpTime.getSec() < 10 ? std::cout << "0" << tmpTime.getSec() << std::endl
                    : std::cout << tmpTime.getSec() << std::endl;
            }
            countSong++;
        }
        countAlbum++;
        std::cout << "**********************************************************************************" << std::endl;
    }
    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

void Jukebox::printSimpleSortedByLength() {
    // Sort albums by length using the overloaded operator< from class Album
    sort(listOfAlbums.begin(), listOfAlbums.end());
    // Print the sorted list.
    std::cout << std::endl << "*****List of Albums Sorted by Album Length*****" << std::endl
        << "Listing only album names and length, longest album first:" << std::endl
        << "=========================================================" << std::endl;
    int count = 1;
    // Print the list in reversed order to get the longest album first.
    std::vector<Album>::reverse_iterator ri;
    for (ri = listOfAlbums.rbegin(); ri != listOfAlbums.rend(); ri++) {
        std::cout << count << ": " << (*ri).getAlbumName() << " | ";
        MyTime tmpLength = (*ri).getAlbumLength();
        if (tmpLength.getHour() > 0) {
            std::cout << tmpLength.getHour() << ":";
            tmpLength.getMin() < 10 ? std::cout << "0" << tmpLength.getMin() << ":"
                : std::cout << tmpLength.getMin() << ":";
            tmpLength.getSec() < 10 ? std::cout << "0" << tmpLength.getSec() << std::endl
                : std::cout << tmpLength.getSec() << std::endl;
        }
        else {
            std::cout << tmpLength.getMin() << ":";
            tmpLength.getSec() < 10 ? std::cout << "0" << tmpLength.getSec() << std::endl
                : std::cout << tmpLength.getSec() << std::endl;
        }
        count++;
    }
    std::cout << "=========================================================" << std::endl;
    std::cout << "Press enter to return to previous menu." << std::endl;
    std::cin.get();
}

bool sortByName(const Album& album1, const Album& album2) {
    // Copy album names to strings
    std::string name1, name2;
    name1 = album1.getAlbumName();
    name2 = album2.getAlbumName();
    // Convert names to upper case for non case sensitive comparison.
    for (auto& c : name1) {
        c = toupper(c);
    }
    for (auto& c : name2) {
        c = toupper(c);
    }
    return name1 < name2;
}
