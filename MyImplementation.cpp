//
// Created by hilla on 11/29/18.
//

#include "MyImplementation.h"

bool MyImplementation::exist(const std::string &name) {
    ifstream file(name);
    return !!file;
}

void MyImplementation::setIdFactory() {
    if (exist(E_FILE_NAME)) {
        idmaker->setslaves(myreader->readLastID(E_FILE_NAME));
    }
    if (exist(P_FILE_NAME)) {
        idmaker->setplanes(myreader->readLastID(P_FILE_NAME));
    }
    if (exist(F_FILE_NAME)) {
        idmaker->setflightes(myreader->readLastID(F_FILE_NAME));
    }
    if (exist(R_FILE_NAME)) {
        string last = myreader->readLastID(R_FILE_NAME);
        idmaker->setreservations(myreader->readLastID(R_FILE_NAME));
    }
    if (exist(C_FILE_NAME)) {
        idmaker->setcostumers(myreader->readLastID(C_FILE_NAME));
    }

}

Employee *MyImplementation::addEmployee(int seniority, int byear, string bos_id, Jobs title) {
    if (seniority < 0 || byear < 0 || byear > 9999) {
        throw "not a valid input";
    }
    Employee *e = new myEmplyee(seniority, byear, bos_id, title, idmaker->getslaves(), myreader);
    mywriter->writer(e);
    emploies.push_back(e);

    return e;
}

Employee *MyImplementation::getEmployee(string id) {
    return myreader->getE(id);
}

Plane *MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers) {
    Plane *p = new myPlane(model_number, idmaker->getplanes(), crew_needed, max_passangers[FIRST_CLASS],
                           max_passangers[SECOND_CLASS]);
    mywriter->writer(p);
    planes.push_back(p);
    return p;
}

Plane *MyImplementation::getPlane(string id) {
    return myreader->getP(id);
}

Flight *MyImplementation::addFlight(int model_number, Date date, string source, string destination) {
    string planeid = valid->availablePlane(model_number, date);
    if (planeid.empty()) {
        throw "no available plane";
    }
    vector<string> crew = valid->availablecrew(date, planeid);
    if (crew[0]== "not valid") {
        throw "no available crew";
    }
    string id = idmaker->getflightes();
    Flight *f = new myFlight(model_number, id, crew, date, source, destination, myreader);
    Plane *plane = myreader->getP(planeid);
    mywriter->writer(f);
    //update dates:planes table
    mywriter->writer(date.getDate(), planeid, P_D_FILE_NAME);
    //update maxEconomy:flights table
    mywriter->writer(to_string(plane->getMaxEconomyClass()), id, MAX_E_FLIGHT);
    //update maxFirst:flights table
    mywriter->writer(to_string(plane->getMaxFirstClass()), id, MAX_F_FLIGHT);
    for (string &p:crew) {
        //update employ:flights table
        mywriter->writer(p, id, F_E_FILE_NAME);
        //update date:employ table
        mywriter->writer(date.getDate(), p, D_E_FILE_NAME);
    }
    flights.push_back(f);
    return f;
}

Flight *MyImplementation::getFlight(string id) { return myreader->getF(id); }

Customer *MyImplementation::addCustomer(string full_name, int priority) {
    if (priority > 5 || priority < 1) {
        throw "not a valid input";
    }
    Customer *c = new myCustomer(full_name, priority, idmaker->getcostumers(), myreader);
    mywriter->writer(c);
    customers.push_back(c);
    return c;
}

Customer *MyImplementation::getCustomer(string id) { return myreader->getC(id); }

Reservation *MyImplementation::addResevation(string customerId, string flightId, Classes cls, int max_baggage) {
    string findF = myreader->findById(F_FILE_NAME, flightId, true);
    string findC = myreader->findById(C_FILE_NAME, customerId, true);
    if (findF.empty() || findC.empty()) {
        throw "this id are not in the system";
    }
    if (cls != FIRST_CLASS && cls != SECOND_CLASS) {
        throw "this class is not in the system";
    }
    if (!valid->availableflight(flightId, cls)) {
        throw "full capacity - no room for you!";
    }
    Reservation *r = new myReservation(customerId, flightId, cls, max_baggage, myreader,
                                       idmaker->getreservations());
    mywriter->writer(r);
    reservation.push_back(r);
    return r;
}

Reservation *MyImplementation::getReservation(string id) {
    return myreader->getR(id);
}


void MyImplementation::exit() {
    for(Employee* e:emploies){
        delete e;
    }
    for (Plane *p:planes){
        delete p;
    }
    for(Flight *f:flights){
        delete f;
    }
    for(Customer *c:customers){
        delete c;
    }
    for(Reservation *r:reservation){
        delete r;
    }

}

MyImplementation::~MyImplementation() {
    delete idmaker;
    delete valid;
    delete mywriter;
    delete myreader;
}



