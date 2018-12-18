//
// Created by hilla on 11/25/18.
//

#include "interface..h"
#include "Writer.h"


Date::Date(string date) {
    if (date.length() != 10 || !isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3])
        || !isdigit(date[5]) || !isdigit(date[6]) || !isdigit(date[8]) || !isdigit(date[9]))
        throw "Illegal argument";
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    if (year < 1 || year > 9999 || month > 12 || month < 1 || day > 31 || day < 1)
        throw "Illegal argument";
    this->date = date;
}

bool Date::operator<(const Date &d) const {
    Writer w;
    return w.intTheDate(*this) < w.intTheDate(d);
}

bool Date::operator>(const Date &d) const {
    Writer w;
    return w.intTheDate(*this) > w.intTheDate(d);
}

bool Date::operator==(const Date &d) const {
    Writer w;
    return w.intTheDate(*this) == w.intTheDate(d);
}





