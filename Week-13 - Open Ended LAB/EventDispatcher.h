#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <vector>
#include "HospitalUnit.h"

class EventDispatcher {
private:
    vector<HospitalUnit*> units;

public:
    void registerUnit(HospitalUnit* unit);
    void dispatch(const HospitalEvent &e);
};

#endif