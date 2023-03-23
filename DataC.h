#pragma once
#include <iostream>

using namespace std;

class DataC {
private:
    int year;
    int month;
    int day;
public:
    DataC();

    DataC(int day, int month, int year);

    void set_date(int day, int month, int year);

    DataC& operator=(const DataC&);

    bool operator==(const DataC&);

    bool operator!=(const DataC&);

    int getYear();

    void setYear(int);

    int getMonth();

    void setMonth(int);

    int getDay();

    void setDay(int);

    bool operator>=(const DataC&);

    bool operator>(const DataC&);

    bool operator<=(const DataC&);

    friend istream& operator>>(istream& is, DataC&);

    friend ostream& operator<<(ostream& os, const DataC&);
};