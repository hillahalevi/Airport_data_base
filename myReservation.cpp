#include <utility>

#include <utility>

#include <utility>

//
// Created by hilla on 11/25/18.
//

#include "myReservation.h"

Customer *myReservation::getCustomer() {
    return myreader->getC(this->customer_id);
}

Flight *myReservation::getFlight() {
    return myreader->getF(this->flight_id);
}

Classes myReservation::getClass() {
    return this->clas;
}

int myReservation::getMaxBaggage() {
    return this->maxbag;
}

string myReservation::getID() {
    return this->id;
}

myReservation::myReservation(string c, string f, Classes c1, int baggage, Reader *r,string id) {
    this->customer_id = std::move(c);
    this->flight_id = std::move(f);
    this->clas = c1;
    this->id = std::move(id);
    this->myreader = r;
    this->maxbag=baggage;
}


myReservation::~myReservation() {
    customer_id.clear();
    flight_id.clear();
    id.clear();
}
