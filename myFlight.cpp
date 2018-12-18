#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by hilla on 11/25/18.
//

#include "myFlight.h"
#include "Reader.h"

#define R_FILE_NAME "rTable"

int myFlight::getModelNumber() {
    return this->modelnum;
}

list<Reservation *> myFlight::getReservations() {
    list<Reservation *> result;
    vector<string> res = myreader->search4(id, myreader->gettable(R_FILE_NAME), 2);
    for (string &r:res) {
        result.push_back(myreader->getR(r));
    }
    return result;
}

list<Employee *> myFlight::getAssignedCrew() {
    list<Employee *> res;
    for (string &r:this->crew) {
        res.push_back(myreader->getE(r));
    }
    return res;
}

Date myFlight::getDate() {
    return this->date;
}

string myFlight::getSource() {
    return this->src;
}

string myFlight::getDestination() {
    return this->dst;
}

string myFlight::getID() {
    return this->id;
}

myFlight::myFlight(int model, string id, vector<string> crew, Date date2enter, string src, string dst, Reader *r):date(
        std::move(date2enter)) {
    this->modelnum = model;
    this->id = std::move(id);
    this->crew = std::move(crew);
    this->src = std::move(src);
    this->dst = std::move(dst);
    this->myreader = r;
}

myFlight::~myFlight() = default;

