//
// Created by hilla on 11/25/18.
//

#include <iostream>
#include "Writer.h"

#define DIVIDER ","
#define E_FILE_NAME "eTable"
#define P_FILE_NAME "pTable"
#define F_FILE_NAME "fTable"
#define C_FILE_NAME "cTable"
#define R_FILE_NAME "rTable"
#define F_E_FILE_NAME "feTable"
#define P_D_FILE_NAME "pdTable"
#define D_E_FILE_NAME "deTable"


void Writer::writer(Employee *p) {
    ofstream eFile;
    eFile.open(E_FILE_NAME, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    string final;
    if (p->getEmployer()) {
        final = p->getEmployer()->getID();
    }
    eFile << p->getID() << DIVIDER << wordafyJobs(p->getTitle()) << DIVIDER
          << p->getSeniority() << DIVIDER << p->getBirthYear() << DIVIDER << final
          << "\n";
    eFile.close();
}

void Writer::writer(Plane *p) {
    ofstream eFile;
    eFile.open(P_FILE_NAME, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    string crew;
    map<Jobs, int> m = p->getCrewNeeded();
    for (auto it : m) {
        crew += wordafyJobs(it.first) + ":" + std::to_string(it.second);
        if (!(it.first == m.rbegin()->first)) {
            crew += " ";
        }

    }
    eFile << p->getID() << DIVIDER << p->getModelNumber() << DIVIDER
          << crew << DIVIDER << p->getMaxFirstClass() << DIVIDER
          << p->getMaxEconomyClass() << "\n";
    eFile.close();
}

void Writer::writer(Flight *p) {
    ofstream eFile;
    eFile.open(F_FILE_NAME, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    eFile << p->getID() << DIVIDER << p->getModelNumber() << DIVIDER
          << p->getDate().getDate() << DIVIDER << p->getSource() << DIVIDER << p->getDestination()
          << "\n";
    eFile.close();
}

void Writer::writer(Customer *p) {
    ofstream eFile;
    eFile.open(C_FILE_NAME, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    eFile << p->getID() << DIVIDER << p->getFullName() << DIVIDER
          << p->getPriority() << endl;
    eFile.close();

}

void Writer::writer(Reservation *p) {
    ofstream eFile;
    eFile.open(R_FILE_NAME, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    string fligntid=p->getFlight()->getID();
    string customerid=p->getCustomer()->getID();
    string max =to_string(p->getMaxBaggage());
    eFile << p->getID() << DIVIDER << customerid << DIVIDER
          << fligntid << DIVIDER << wordafyClasses(p->getClass()) << DIVIDER << max << endl;
    eFile.close();


}

void Writer::writer(string a, string b, string table) {
    ofstream eFile;
    eFile.open(table, ios::out | ios::app | ios::ate);
    if (!eFile.is_open())
        throw "cant open file";
    eFile << a << DIVIDER << b << "\n";
    eFile.close();


}

/**
 * from enum to readable string
 * @param c
 * @return string
 */
string Writer::wordafyJobs(int j) {
    switch (j) {
        case 0:
            return "MANAGER";
        case 1:
            return "NAVIGATOR";
        case 2:
            return "FLY_ATTENDANT";
        case 3:
            return "PILOT";
        default:
            return "other";
    }
}

/**
 * from enum to readable string
 * @param c
 * @return string
 */
string Writer::wordafyClasses(int c) {
    if (c == 0) {
        return "FIRST_CLASS";
    }
    return "SECOND_CLASS";
}

int Writer::intTheDate(Date d) {
    string s;
    string date=d.getDate();
    s+=date.substr(0, 4);
    s+=date.substr(5, 2);
    s+=date.substr(8, 2);
    return stoi(s);
}


