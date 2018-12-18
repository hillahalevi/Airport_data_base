//
// Created by hilla on 11/28/18.
//

#ifndef EX2_VALID_H
#define EX2_VALID_H

#include <iostream>
#include "interface..h"
#include "myEmplyee.h"
#include "myCustomer.h"
#include "myPlane.h"
#include "myFlight.h"
#include "myReservation.h"
#include "Writer.h"
#include "Reader.h"

class Valid {
    Reader *myreader;
    Writer *mywriter;
public:

    bool availableflight(string &flightid, Classes cls);

    vector<string> availablecrew(Date &date, const string &id);

    string availablePlane(int model, const Date &date);

    Valid(Reader *pReader, Writer *pWriter);
};


#endif //EX2_VALID_H
