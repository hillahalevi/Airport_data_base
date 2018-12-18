//
// Created by hilla on 11/25/18.
//

#ifndef EX2_MYFLIGHT_H
#define EX2_MYFLIGHT_H

#include "interface..h"
#include "Reader.h"


class myFlight : public Flight {
private:
    int modelnum;
    vector<string> crew;
    Date date ;
    string src;
    string dst;
    string id;
    Reader * myreader;
public:
    virtual int getModelNumber();

    virtual list<Reservation *> getReservations();

    virtual list<Employee *> getAssignedCrew();

    virtual Date getDate();

    virtual string getSource();

    virtual string getDestination();

    virtual ~myFlight();

    virtual string getID();

    myFlight(int model, string id, vector<string> crew, Date date2enter, string src, string dst,Reader* r);

};


#endif //EX2_MYFLIGHT_H
