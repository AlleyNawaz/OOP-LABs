#include "EventDispatcher.h"
#include <iostream>

using namespace std;

void EventDispatcher::registerUnit(HospitalUnit* unit) {
    units.push_back(unit);
}

void EventDispatcher::dispatch(const HospitalEvent& ev) {
    cout << "EVENT DISPATCHED: " << ev << endl;

    for (HospitalUnit* unit : units) {
        unit->respond(ev);
    }
}