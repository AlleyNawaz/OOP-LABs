#include <iostream>
#include "HospitalEvent.h"
#include "HospitalUnit.h"
#include "EventDispatcher.h"

using namespace std;

class MedicalSensor {
public:
    virtual HospitalEvent createEvent() = 0;
    virtual ~MedicalSensor() {}
};

class PulseSensor : public MedicalSensor {
public:
    HospitalEvent createEvent() override {
        return HospitalEvent("Room 201 - Pulse Monitor", 4);
    }
};

class OxygenLevelSensor : public MedicalSensor {
public:
    HospitalEvent createEvent() override {
        return HospitalEvent("Room 202 - Oxygen Monitor", 87.2);
    }
};

class BodyTempSensor : public MedicalSensor {
public:
    HospitalEvent createEvent() override {
        return HospitalEvent("ICU Ward 3 - Temperature Sensor", "High Temperature Alert");
    }
};

void handleSensor(EventDispatcher& eventManager, MedicalSensor* device) {
    eventManager.dispatch(device->createEvent());
}

int main() {
    cout << "HOSPITAL EVENT MONITORING SYSTEM ACTIVE" << endl;
    cout << "Student: Ali Nawaz (00000526123)" << endl;

    EventDispatcher eventManager;

    NursingStation* nursingDesk = new NursingStation();
    ICUTeam* criticalCare = new ICUTeam();
    PharmacySystem* medicineDept = new PharmacySystem();
    BiomedicalUnit* bioSupport = new BiomedicalUnit();
    FireSafetyUnit* safetyDept = new FireSafetyUnit();

    eventManager.registerUnit(nursingDesk);
    eventManager.registerUnit(criticalCare);
    eventManager.registerUnit(medicineDept);
    eventManager.registerUnit(bioSupport);
    eventManager.registerUnit(safetyDept);

    cout << "\nManual Event Tests" << endl;
    HospitalEvent eventA("Reception Area", "Emergency Alert");
    HospitalEvent eventB("ICU Machine 7", "Technical Failure");
    HospitalEvent eventC("Medical Store", "Stock Low");

    eventManager.dispatch(eventA);
    eventManager.dispatch(eventB);
    eventManager.dispatch(eventC);

    cout << "\nSeverity Comparison Test" << endl;
    HospitalEvent criticalEvent("Emergency Room", 5);
    HospitalEvent normalEvent("General Ward", 1);

    if (criticalEvent > normalEvent) {
        cout << "Alert: Emergency Room incident is more severe than Ward incident." << endl;
    }

    cout << "\nLive Sensor Monitoring" << endl;
    PulseSensor pulseDevice;
    OxygenLevelSensor oxygenDevice;

    handleSensor(eventManager, &pulseDevice);
    handleSensor(eventManager, &oxygenDevice);

    delete nursingDesk;
    delete criticalCare;
    delete medicineDept;
    delete bioSupport;
    delete safetyDept;

    return 0;
}