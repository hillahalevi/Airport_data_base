

//
// Created by hilla on 11/25/18.
//

#include "myCustomer.h"
#define R_FILE_NAME "rTable"

string myCustomer::getFullName() {
    return this->name;
}

int myCustomer::getPriority() {
    return this->prior;
}

list<Reservation *> myCustomer::getReservations() {
    list<Reservation*>res;
    //search for reservations contains our customer
    vector<string> reserv = reader->search4(id, reader->gettable(R_FILE_NAME), 1);
    for (string &r:reserv){
        res.push_back(reader->getR(r));
    }
    return res;
}

string myCustomer::getID() {
    return this->id;
}

myCustomer::myCustomer(string name, int priority, string id,Reader *r) {
    this->name = std::move(name);
    this->prior = priority;
    this->id = std::move(id);
    this->reader=r;

}

myCustomer::~myCustomer() = default;


