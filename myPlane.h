//
// Created by hilla on 11/25/18.
//
#include "interface..h"

#ifndef EX2_MYPLANE_H
#define EX2_MYPLANE_H


class myPlane : public Plane {
private:
    int modelNum;
    string id;
    map<Jobs, int> crew;
    int maxFirstClass;
    int maxEconomyClass;

public:
    myPlane(int model, string id, map<Jobs, int> crew, int maxfirst,
            int maxsecod);

    virtual int getModelNumber();

    virtual map<Jobs, int> getCrewNeeded();

    virtual int getMaxFirstClass();

    virtual int getMaxEconomyClass();

    virtual string getID();

    virtual ~myPlane();

};


#endif //EX2_MYPLANE_H
