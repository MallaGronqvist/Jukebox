// Project
// Malla Grönqvist
// Header file for class MyTime

#ifndef DT019G_MYTIME_H
#define DT019G_MYTIME_H
#include <iostream>  // ostream, istream


class MyTime {
private:
    // Data members
    int hour, min, sec;

public:
    MyTime(); // Default constructor
    MyTime(int pHour, int pMin, int pSec);  // Constructor for initiating

    // Member functions
    void setHour(int pHour);
    void setMin(int pMin);
    void setSec(int pSec);

    int getHour()const { return hour; }
    int getMin()const { return min; }
    int getSec()const { return sec; }

    // Overloaded operators
    MyTime operator+(const MyTime& time) const;
    bool operator<(const MyTime& time) const;
    bool operator==(const MyTime& time) const;

};
// Overloaded operators for input/output from/to file
std::ostream& operator<<(std::ostream& os, const MyTime& time);
std::istream& operator>>(std::istream& is, MyTime& time);



#endif //DT019G_MYTIME_H
