#include "EventDispatcher.h"

void EventDispatcher::addUnit(HospitalUnit* dept) {
    registeredUnits.push_back(dept);
}

void EventDispatcher::notify(const HospitalEvent& eventInfo) {
    cout << "EVENT BROADCAST: " << eventInfo << endl;

    for (HospitalUnit* dept : registeredUnits) {
        dept->respond(eventInfo);
    }
}