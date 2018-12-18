//
// Created by hilla on 11/25/18.
//

#include "IDfactory.h"


string IDfactory::getslaves() {
    this->slaves++;
    string final = "E";
    final += to_string(slaves);
    return final;
}

string IDfactory::getplanes() {
    this->planes++;
    string final = "P";
    final += to_string(planes);
    return final;
}

string IDfactory::getflightes() {
    this->flights++;
    string final = "F";
    final += to_string(flights);
    return final;
}

string IDfactory::getcostumers() {
    this->costumers++;
    string final = "C";
    final += to_string(costumers);
    return final;
}

string IDfactory::getreservations() {
    this->reservations++;
    string final = "R";
    final += to_string(reservations);
    return final;
}

IDfactory::IDfactory() {
    this->slaves = 0;
    this->planes = 0;
    this->flights = 0;
    this->costumers = 0;
    this->reservations = 0;

}



void IDfactory::setslaves(string lastid) {
    lastid = lastid.erase(0, 1);
    slaves = stoi(lastid);

}

void IDfactory::setplanes(string lastid) {
    lastid = lastid.erase(0, 1);
    planes = stoi(lastid);

}

void IDfactory::setflightes(string lastid) {
    lastid = lastid.erase(0, 1);
    flights = stoi(lastid);

}

void IDfactory::setcostumers(string lastid) {
    lastid = lastid.erase(0, 1);
    costumers = stoi(lastid);

}

void IDfactory::setreservations(string lastid) {
    lastid = lastid.erase(0, 1);
     reservations= stoi(lastid);
}








