# Jukebox

This is a console application that simulates a jukebox where the user can view, sort, add or delete music albums.

## Purpose

The purpose of this project has been to create a Jukebox program that handles a set of albums using classes, algorithms 
and containers from STL. In this way my aim has been to gain a better understanding of how classes and STL algorithms
and containers are used.

### Technical description

The classes MyTime, Song and Album form the building blocks of this program that are necessary for determining
the format in which the data kept by the program is saved. I began building the program by coding these classes. 
MyTime manages the formatting of the length of songs and
albums in hours, minutes and seconds. Song uses MyTime to handle length information about songs while also keeping 
information about the song's titles and artists. The class Album instead binds several Song objects together into
an album and saves an album name together with the collection of songs. Moreover the program contains the classes 
MenuItem and Menu that manage the contents of various menus used in
the program. All the classes mentioned so far also include set- and get- functions that make it possible to access
and change data encapsulated in those classes.

MyTime and Album also contain overloaded operators (<, == and +) that enable arithmetic operations, such as addition
 and comparison, on their data members. The file operators << and >> have also been overloaded for file input and output
 of data members in classes MyTime, Song and Album.
 
 All these classes are brought together in the class Jukebox that makes use of them. The class Jukebox contains a list
 of albums and three different menus. It also forms a user interface through which the external user can look
 at and make some changes to data, open data from or save data to file.
 
 Finally the main program contains only a Jukebox object, that is run by the class Jukebox' member function run().
 
### Special Gotchas
 
As the class Jukebox works as a user interface, it also hides the other classes from the user and makes the data
more secured. The encapsulation of data in the program's classes protects the data from getting modified by any external
user as it can be modified only by the classes' member functions that set their values.

The classes and the overloading of various operators in the classes made the code more organized, and for example
file operations could be written with a rather simple code once the operator>> and the operator<< had been overloaded.
The overloading made the code more compact and elegant.

At the same time the overloaded operators were one of the most challenging parts of this project for me. 
The function openFromFile() in Jukebox, that makes use of the overloaded operator>> posed a challenge
with all the layers of overloading done in the different classes. All the details in the different classes had to match
to make the whole work in openFromFile(). Further, I assume that my solution of "resetting" the Album object tmpAlbum
with setAlbum() and an empty vector is probably not the most elegant way to handle the situation. 

I think I also learned more about how STL containers and algorithms work and how they can be used. For example, 
I found out that find() works using the operator==, and figured out that that operator had to be
defined for the specific class, the objects of which were to be compared by find(). 

### Instructions for compiling and running the program

The project consists of following files that should be compiled together:

<li>main.cpp
 <li>jukebox.h & jukebox.cpp
  <li>menu.h & menu.cpp
   <li>album.h & album.cpp
    <li>mytime.h & mytime.cpp
     <li>song.h & song.cpp
      
Moreover, the program makes use of the text file 'jukebox' to save the list of albums to file. This file should
be in the same folder with the source files when the program is compiled.       
