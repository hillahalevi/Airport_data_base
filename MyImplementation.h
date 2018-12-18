//
// Created by hilla on 11/25/18.
//

#ifndef EX2_MYIMPLEMENTATION_H
#define EX2_MYIMPLEMENTATION_H

#include <iostream>
#include "interface..h"
#include "myEmplyee.h"
#include "myCustomer.h"
#include "myPlane.h"
#include "myFlight.h"
#include "myReservation.h"
#include "Writer.h"
#include "Reader.h"
#include "Valid.h"
#include "IDfactory.h"

#define E_FILE_NAME "eTable"
#define P_FILE_NAME "pTable"
#define F_FILE_NAME "fTable"
#define C_FILE_NAME "cTable"
#define R_FILE_NAME "rTable"
#define F_E_FILE_NAME "feTable"
#define P_D_FILE_NAME "pdTable"
#define D_E_FILE_NAME "deTable"
#define MAX_F_FLIGHT "mxfirstfTable"
#define MAX_E_FLIGHT "mxeconomyfTable"
using namespace std;

class MyImplementation : public Ex2 {
private:
    IDfactory *idmaker;
    Writer *mywriter;
    Reader *myreader;
    Valid *valid;
    list<Employee *> emploies;
    list<Customer *> customers;
    list<Flight *> flights;
    list<Plane *> planes;
    list<Reservation *> reservation;


public:
    bool exist(const std::string &name);

    void setIdFactory();

    MyImplementation() {
        mywriter = new Writer();
        myreader = new Reader;
        idmaker = new IDfactory();
        valid= new Valid(myreader, mywriter);
        setIdFactory();
    }

    Employee *addEmployee(int seniority, int byear, string bos_id, Jobs title);

    Employee *getEmployee(string id);

    Plane *addPlane(int model_number, map<Jobs, int> crew_needed, map<Classes, int> max_passangers);

    Plane *getPlane(string id);

    Flight *addFlight(int model_number, Date date, string source, string destination);

    Flight *getFlight(string id);

    Customer *addCustomer(string full_name, int priority);

    Customer *getCustomer(string id);

    Reservation *addResevation(string customerId, string flightId, Classes cls, int max_baggage);

    Reservation *getReservation(string id);

    virtual ~MyImplementation();


    void exit();

};


#endif //EX2_MYIMPLEMENTATION_H
