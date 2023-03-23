#include "DataC.h"

DataC::DataC() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

DataC::DataC(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void DataC::set_date(int dayy, int monthh, int yearr) {
    this->year = yearr;
    this->month = monthh;
    this->day = dayy;
}

DataC& DataC::operator=(const DataC& S) {
    if (this != &S) {
        this->year = S.year;
        this->month = S.month;
        this->day = S.day;
    }
    return *this;
}

bool DataC::operator==(const DataC& S) {
    return ((this->day == S.day) && (this->month == S.month) && (this->year == S.year));
}

bool DataC::operator!=(const DataC& S) {
    return ((this->day != S.day) || (this->month != S.month) || (this->year != S.year));
}

bool DataC::operator>=(const DataC& S) {
    return ((this->day >= S.day) && (this->month >= S.month) && (this->year >= S.year));
}

bool DataC::operator<=(const DataC& S) {
    return ((this->day <= S.day) && (this->month <= S.month) && (this->year <= S.year));
}

istream& operator>>(istream& is, DataC& data) {
    cout << endl;
    cout << "year: ";
    is >> data.year;
    cout << "month: ";
    is >> data.month;
    cout << "day: ";
    is >> data.day;
    return is;
}

ostream& operator<<(ostream& os, const DataC& dat) {
    os << dat.day << "/" << dat.month << "/" << dat.year;
    return os;
}

int DataC::getYear() {
    return year;
}

void DataC::setYear(int yyear) {
    DataC::year = yyear;
}

int DataC::getMonth() {
    return month;
}

void DataC::setMonth(int mmonth) {
    DataC::month = mmonth;
}

int DataC::getDay() {
    return day;
}

void DataC::setDay(int dday) {
    DataC::day = dday;
}

bool DataC::operator>(const DataC& S) {
    return ((this->day > S.day) && (this->month > S.month) && (this->year > S.year));
}