//
// Created by hilla on 11/25/18.
//

#ifndef EX2_MYID_H
#define EX2_MYID_H

#include "interface..h"


class IDfactory {
private:
    int slaves;
    int planes;
    int flights;
    int costumers;
    int reservations;

public:

    IDfactory();

    string getslaves();

    string getplanes();

    string getflightes();

    string getcostumers();

    string getreservations();

    void setslaves(string lastid);

    void setplanes(string lastid);

    void setflightes(string lastid);

    void setcostumers(string lastid);

    void setreservations(string lastid);


};


#endif //EX2_MYID_H
