//
// Created by hilla on 11/26/18.
//

#ifndef EX2_READER_H
#define EX2_READER_H

#include "interface..h"
#include <fstream>
#include <vector>


class Reader {
    list<Employee *> emploies;
    list<Customer *> customers;
    list<Flight *> flights;
    list<Plane *> planes;
    list<Reservation *> reservations;

public:
    string readLastID(string table);

    string findById(string table, string id, bool first);

    vector<string> split(string info, char c);

    map<Jobs, int> getCrew(string crew);

    vector<string> gettable(string table);

    vector<string> search4(string x,vector<string> table,int pos);

    Employee *getE(string id);

    Plane *getP(string id);

    Customer *getC(string id);

    Flight *getF(string id);

    Reservation *getR(string id);

    Jobs jobs2(string j);

    Classes class2(string j);


    ~Reader();




};


#endif //EX2_READER_H
