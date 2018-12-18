//
// Created by hilla on 11/25/18.
//
#include "interface..h"
#include "Reader.h"

#ifndef EX2_MYEMPLYEE_H
#define EX2_MYEMPLYEE_H


class myEmplyee : public Employee {
private:
    int seniority;
    int birthyear;
    string id;
    string bos;
    Jobs title;
    Reader *myreader;

public:
    myEmplyee(int seniority, int birth_year, string b, Jobs title, string id,Reader* r);

    virtual int getBirthYear();

    virtual Employee *getEmployer();

    virtual string getID();

    virtual Jobs getTitle();

    virtual int getSeniority();

    virtual ~myEmplyee();


};


#endif //EX2_MYEMPLYEE_H
