#include <utility>

//
// Created by hilla on 11/26/18.
//

#include <iostream>
#include <sstream>
#include "Reader.h"
#include "myEmplyee.h"
#include "myCustomer.h"
#include "myPlane.h"
#include "myFlight.h"
#include "myReservation.h"

#define E_FILE_NAME "eTable"
#define P_FILE_NAME "pTable"
#define F_FILE_NAME "fTable"
#define C_FILE_NAME "cTable"
#define R_FILE_NAME "rTable"
#define F_E_FILE_NAME "feTable"

/**
 * returns the last id in file
 * @param table
 * @return  string
 */
string Reader::readLastID(string table) {
    ifstream fin;
    fin.open(table);
    if (fin.is_open()) {
        fin.seekg(-2, ios_base::end);                // go two spots before the EOF
        bool keepLooping = true;
        while (keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data
            if ((int) fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            } else if (ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            } else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,
                          ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }
        string lastLine;
        getline(fin, lastLine);                      // Read the current line
        fin.close();
        return lastLine;
    }


}

/**
 * load table to a vector of strings
 * @param table
 * @return  vector
 */
vector<string> Reader::gettable(string table) {
    vector<string> result;
    ifstream fin;
    fin.open(table);
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            result.push_back(line);

        }
        fin.close();
    }
    return result;
}

/**
 * finds an info according to specific id
 * @param table file to lookfor
 * @param id
 * @return string
 */
string Reader::findById(string table, string id, bool first) {
    ifstream fin;
    fin.open(table);
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line.find(id, 0) != string::npos) {
                if (first) {
                    //need to check if its the first item
                    if (split(line, ',')[0] != id) {
                        //its not the first continue;
                        continue;
                    }
                }
                break;


            }

        }
        fin.close();


    }
    return line;
}

/**
 * split specific info string to details
 * @param info
 * @param c
 * @return vector
 */
vector<string> Reader::split(string info, char c) {
    stringstream easy2split(info);
    string part;
    vector<string> allparts;

    while (getline(easy2split, part, c)) {
        allparts.push_back(part);
    }
    return allparts;
}

/**
 * return right format
 * @param j
 * @return JOB
 */
Jobs Reader::jobs2(string j) {
    switch (j[0]) {
        case 'M':
            return MANAGER;
        case 'N':
            return NAVIGATOR;
        case 'F':
            return FLY_ATTENDANT;
        case 'P':
            return PILOT;
        default:
            return OTHER;
    }
}

/**
 * return right format
 * @param j
 * @return class
 */
Classes Reader::class2(string j) {
    if (j[0] == 'F') { return FIRST_CLASS; }
    return SECOND_CLASS;
}

/**
 * converts a string into map of crew members
 * @param crew
 * @return map
 */
map<Jobs, int> Reader::getCrew(string crew) {
    map<Jobs, int> final;
    vector<string> allparts = split(std::move(crew), ' ');
    //allparts now contains strings in this patters x:y
    vector<string> temp;
    for (auto &x:allparts) {
        temp = split(x, ':');
        Jobs title = jobs2(temp[0]);
        int amount = stoi(temp[1]);
        final.insert(pair<Jobs, int>(title, amount));

    }
    return final;
}

/**
 * create Employee according to its id
 * @param id
 * @return Employee
 */
Employee *Reader::getE(string id) {
    string info = findById(E_FILE_NAME, id, true);
    if (!info.empty() || id[0] == 'E') {
        vector<string> e = split(info, ',');
        string bos;
        if (e.size() == 5) {
            //there is a bos info
            bos = e[4];
        }
        Employee *p = new myEmplyee(stoi(e[2]), stoi(e[3]), bos, jobs2(e[1]), id, this);
        emploies.push_back(p);
        return p;

    }
    return nullptr;
}

/**
 * create Plane according to its id
 * @param id
 * @return Plane
 */
Plane *Reader::getP(string id) {
    string info = findById(P_FILE_NAME, id, true);
    if (!info.empty() || id[0] == 'P') {
        vector<string> e = split(info, ',');
        Plane *p = new myPlane(stoi(e[1]), id, getCrew(e[2]), stoi(e[3]), stoi(e[4]));
        planes.push_back(p);
        return p;
    }
    return nullptr;

}

/**
 * create Flight according to its id
 * @param id
 * @return Flight
 */
Flight *Reader::getF(string id) {
    string info = findById(F_FILE_NAME, id, true);
    if (!info.empty() || id[0] == 'F') {
        vector<string> e = split(info, ',');
        //search for crew assigned to our flight
        vector<string> crew = search4(id, gettable(F_E_FILE_NAME), 1);
        Flight *f = new myFlight(stoi(e[1]), id, crew, Date(e[2]), e[3], e[4], this);
        flights.push_back(f);
        return f;
    }
    return nullptr;
}

/**
 * create Customer according to its id
 * @param id
 * @return Customer
 */
Customer *Reader::getC(string id) {
    string info = findById(C_FILE_NAME, id, true);
    if (!info.empty() || id[0] == 'C') {
        vector<string> e = split(info, ',');

        Customer *c = new myCustomer(e[1], stoi(e[2]), id, this);
        customers.push_back(c);
        return c;
    }
    return nullptr;
}

/**
 * create Reservation according to its id
 * @param id
 * @return Reservation
 */
Reservation *Reader::getR(string id) {
    string info = findById(R_FILE_NAME, id, true);
    if (!info.empty() || id[0] == 'R') {
        vector<string> e = split(info, ',');

        Reservation*r= new myReservation(e[1], e[2], class2(e[3]), stoi(e[4]), this, id);
        reservations.push_back(r);
        return r;
    }
    return nullptr;
}

/**
 * search for a line that has parmaeter x in specific pos
 * @param x to look 4
 * @param table to search
 * @param pos location
 * @return all lines that fit
 */
vector<string> Reader::search4(string x, vector<string> table, int pos) {
    vector<string> alloptions;
    vector<string> tmp;
    for (const string &line:table) {
        tmp = split(line, ',');
        if (x == tmp[pos]) {
            alloptions.push_back(tmp[0]);
        }

    }
    return alloptions;
}

Reader::~Reader() {
   for(auto e:emploies){
        delete e;
    }
    for (auto p:planes){
        delete p;
    }
    for(auto f:flights){
        delete f;
    }
    for(auto c:customers){
        delete c;
    }
    for(auto r:reservations){
        delete r;
    }

}







