#include <utility>

//
// Created by hilla on 11/25/18.
//

#include <fstream>
#include "myEmplyee.h"
#define E_FILE_NAME "eTable"


int myEmplyee::getBirthYear() {
    return this->birthyear;
}

Employee *myEmplyee::getEmployer() {
    return myreader->getE(bos);
}

string myEmplyee::getID() {
    return this->id;
}

Jobs myEmplyee::getTitle() {
    return this->title;
}

int myEmplyee::getSeniority() {
    return this->seniority;
}

myEmplyee::myEmplyee(int seniority, int birth_year,string b, Jobs title, string id,Reader* r) {
    this->seniority = seniority;
    this->birthyear = birth_year;
    this->bos = b;
    this->title = title;
    this->id = std::move(id);
    this->myreader=r;

}


myEmplyee::~myEmplyee() = default;

