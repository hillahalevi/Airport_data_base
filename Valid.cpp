//
// Created by hilla on 11/28/18.
//

#include "Valid.h"

#define MAX_F_FLIGHT "mxfirstfTable"
#define MAX_E_FLIGHT "mxeconomyfTable"
#define F_E_FILE_NAME "feTable"
#define P_D_FILE_NAME "pdTable"
#define D_E_FILE_NAME "deTable"
#define E_FILE_NAME "eTable"
#define P_FILE_NAME "pTable"
#define F_FILE_NAME "fTable"
#define C_FILE_NAME "cTable"
#define R_FILE_NAME "rTable"


Valid::Valid(Reader *pReader, Writer *pWriter) {
    this->myreader = pReader;
    this->mywriter = pWriter;
}

/**
* check if theres a room in the flight
* @param flightid
* @param cls
* @return yes or no
*/
bool Valid::availableflight(string &flightid, Classes cls) {
    int max;

    string m;
    if (cls == FIRST_CLASS) {
        m = myreader->split(myreader->findById(MAX_F_FLIGHT, flightid, false), ',')[0];

    } else {
        m = myreader->split(myreader->findById(MAX_E_FLIGHT, flightid, false), ',')[0];
    }
    max = stoi(m);
    Flight *f = myreader->getF(flightid);
    list<Reservation *> res = f->getReservations();
    int passengesr = 0;
    for (Reservation *r:res) {
        if (r->getClass() == cls) {
            passengesr++;
            if (max > passengesr) {
                break;
            }

        }

    }
    return max > passengesr;
}

/**
* check if there is a free crew
* @param date
* @param id
* @return all the id of our crew mambers
*/
vector<string> Valid::availablecrew(Date &date, const string &id) {
    Plane *p = myreader->getP(id);
    map<Jobs, int> crew = p->getCrewNeeded();
    vector<string> slaves = myreader->gettable(E_FILE_NAME);
    vector<string> curslaves = myreader->gettable(D_E_FILE_NAME);
    vector<string> tmp;
    vector<string> tmp2;
    vector<string> final;
    int sum = 0;
    for (auto &x:crew) {
        tmp = myreader->search4(mywriter->wordafyJobs(x.first), slaves, 1);
        if (tmp.size() < x.second) {
            //not enough people
            final.clear();
            break;
        }
        int amount = x.second;
        sum += amount;
        for (auto &e:tmp) {
            if (amount == 0) {
                // we got all the people we need for this job
                break;
            }
            //dates of this employ
            tmp2 = myreader->search4(e, curslaves, 1);
            if (tmp2.empty() || (myreader->search4(date.getDate(), tmp2, 0).empty())) {
                //this employ is free for us in our time
                amount--;
                final.push_back(e);
            }


        }
        if (amount > 0) {
            //not enough people for this job
            final.clear();
            final.push_back("not valid");
            break;
        }
    }
    if (sum > final.size()) {
        final.clear();
        final.push_back("not valid");
    }
    return final;


}

/**
* check if there is a free plane
* @param model
* @param date
* @return  string id of that plane
*/
string Valid::availablePlane(int model, const Date &date) {
    //all planes that match our model info
    vector<string> matchPlanes = myreader->search4(to_string(model), myreader->gettable(P_FILE_NAME), 1);
    //all planes in process
    vector<string> planes_and_dates = myreader->gettable(P_D_FILE_NAME);
    vector<string> tmp;
    for (string id:matchPlanes) {
        //tmp holds all the dates this plane is reserved
        tmp = myreader->search4(id, planes_and_dates, 1);
        if (tmp.empty()) {
            //this plane is not reserved at all !
            return id;
        }
       if( myreader->search4(date.getDate(),tmp,0).empty()){
           //this plane does not work in our date - free!
           return id;

       }
    }
    string s;
    return s;
}
