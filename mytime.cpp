// Project
// Malla Grönqvist
// Definition file for class MyTime

#include "mytime.h"

MyTime::MyTime() {

    hour = min = sec = 0;
}

MyTime::MyTime(int pHour, int pMin, int pSec) {
    // Set values of data members
    setHour(pHour);
    setMin(pMin);
    setSec(pSec);
}

void MyTime::setHour(int pHour) {
    // Check that value is valid before setting it.
    if (pHour >= 0 && pHour < 24)
        hour = pHour;
    else
        hour = -1;
}

void MyTime::setMin(int pMin) {
    // Check that value is valid before setting it.
    if (pMin >= 0 && pMin < 60)
        min = pMin;
    else
        min = -1;
}

void MyTime::setSec(int pSec) {
    // Check that value is valid before setting it.
    if (pSec >= 0 && pSec < 60)
        sec = pSec;
    else
        sec = -1;
}

MyTime MyTime::operator+(const MyTime& time) const {
    // Declare time object sum
    MyTime sum;
    // Calculate the sums of the data members.
    sum.sec = sec + time.sec;
    sum.min = min + time.min + sum.sec / 60;
    sum.hour = hour + time.hour + sum.min / 60;
    sum.sec %= 60;
    sum.min %= 60;
    return sum;
}

bool MyTime::operator<(const MyTime& time) const {
    // Convert to seconds and compare the two time objects.
    return (hour * 60 * 60 + min * 60 + sec) < (time.hour * 60 * 60 + time.min * 60 + sec);
}

bool MyTime::operator==(const MyTime& time) const {
    // Compare equality of data members.
    return hour == time.hour && min == time.min && sec == time.sec;
}

std::ostream& operator<<(std::ostream& os, const MyTime& time) {
    // Convert data members to seconds and write to file.
    os << time.getHour() * 60 * 60 + time.getMin() * 60 + time.getSec();
    return os;
}

std::istream& operator>>(std::istream& is, MyTime& time) {
    // Read in time
    int tmpTime;
    is >> tmpTime;

    // Convert time to hours, mins and secs.
    int tmpHour, tmpMin, tmpSec;
    tmpHour = (tmpTime / 60 / 60);
    tmpMin = ((tmpTime - (tmpHour * 60 * 60)) / 60);
    tmpSec = (tmpTime - (tmpHour * 60 * 60) - (tmpMin * 60));

    // Set values of data members.
    time.setHour(tmpHour);
    time.setMin(tmpMin);
    time.setSec(tmpSec);

    return is;
}