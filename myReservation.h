//
// Created by hilla on 11/25/18.
//

#ifndef EX2_MYRESERVATION_H
#define EX2_MYRESERVATION_H

#include "interface..h"
#include "Reader.h"

class myReservation : public Reservation {
    int maxbag;
    Classes clas;
    string flight_id;
    string customer_id;
    string id;
    Reader *myreader;


public:
    myReservation(string c, string f, Classes c1, int baggage, Reader *r,string id);

    virtual Customer *getCustomer();

    virtual Flight *getFlight();

    virtual Classes getClass();

    virtual int getMaxBaggage();

    virtual ~myReservation();

    virtual string getID();


};


#endif //EX2_MYRESERVATION_H
