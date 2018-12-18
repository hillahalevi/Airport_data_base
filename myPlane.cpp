#include <utility>

#include <utility>

//
// Created by hilla on 11/25/18.
//

#include "myPlane.h"

int myPlane::getModelNumber() {
    return this->modelNum;
}

map<Jobs, int> myPlane::getCrewNeeded() {
    return this->crew;
}

int myPlane::getMaxFirstClass() {
    return this->maxFirstClass;
}

int myPlane::getMaxEconomyClass() {
    return this->maxEconomyClass;
}

string myPlane::getID() {
    return this->id;
}

myPlane::myPlane(int model, string id, map<Jobs, int> crew, int maxfirst,
                 int maxsecod) {
    this->modelNum = model;
    this->id = std::move(id);
    this->crew = std::move(crew);
    this->maxFirstClass = maxfirst;
    this->maxEconomyClass = maxsecod;

}

myPlane::~myPlane() = default;


