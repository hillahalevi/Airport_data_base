//
// Created by hilla on 11/25/18.
//

#ifndef EX2_MYCOSTUMER_H
#define EX2_MYCOSTUMER_H

#include "myFlight.h"


class myCustomer : public Customer {
private:
    string name;
    int prior;
    string id;
    Reader* reader;


public:
    virtual string getFullName();

    virtual int getPriority();

    virtual list<Reservation *> getReservations();

    virtual ~myCustomer();

    virtual string getID();

    myCustomer(string name, int priority, string id,Reader *r);

};


#endif //EX2_MYCOSTUMER_H
