//
// Created by hilla on 11/25/18.
//

#ifndef EX2_WRITER_H
#define EX2_WRITER_H
#include "interface..h"
#include <fstream>


class Writer {
public:
    void writer(Employee *p);

    void writer(Plane *p);

    void writer(Flight *p);

    void writer(Customer *p);

    void writer(Reservation *p);

    void writer(string a,string b,string table);

    string wordafyJobs(int j);

    string wordafyClasses(int c);

    int intTheDate(Date d);


};


#endif //EX2_WRITER_H
