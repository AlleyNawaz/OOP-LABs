#include <iostream>
#include "HospitalEvent.h"
#include "HospitalUnit.h"
#include "EventDispatcher.h"

using namespace std;

// Abstract Sensor
class VitalSensor {
public:
    virtual HospitalEvent generateEvent() = 0;
    virtual ~VitalSensor() {}
};

// Derived Sensors
class HeartRateSensor : public VitalSensor {
public:
    HospitalEvent generateEvent() override {
        return HospitalEvent("Patient Room 101 - Heart Monitor", 4);
    }
};

class OxygenSensor : public VitalSensor {
public:
    HospitalEvent generateEvent() override {
        return HospitalEvent("Patient Room 102 - O2 Monitor", 88.5);
    }
};

class TemperatureSensor : public VitalSensor {
public:
    HospitalEvent generateEvent() override {
        return HospitalEvent("ICU Room 5 - Thermometer", "Fever Detected");
    }
};

// Helper function
void processSensor(EventDispatcher& dispatcher, VitalSensor* s) {
    dispatcher.dispatch(s->generateEvent());
}

// --- Main Execution ---
int main() {
    cout << "HERMS SYSTEM STARTED " << endl;
    cout << "Student: Ali Nawaz (00000526123)" << endl;

    // 1. Setup Dispatcher
    EventDispatcher dispatcher;

    // 2. Create Units
    NursingStation* nurse = new NursingStation();
    ICUTeam* icu = new ICUTeam();
    PharmacySystem* pharmacy = new PharmacySystem();
    BiomedicalUnit* biomed = new BiomedicalUnit();
    FireSafetyUnit* fire = new FireSafetyUnit();

    // 3. Register Units
    dispatcher.registerUnit(nurse);
    dispatcher.registerUnit(icu);
    dispatcher.registerUnit(pharmacy);
    dispatcher.registerUnit(biomed);
    dispatcher.registerUnit(fire);

    // 4. Manual Events
    cout << "\nManual Event Generation " << endl;
    HospitalEvent e1("Main Lobby", "Code Red"); 
    HospitalEvent e2("ICU Ventilator 3", "Equipment Malfunction");
    HospitalEvent e3("Pharmacy Storage", "Medicine Refill");
    
    dispatcher.dispatch(e1);
    dispatcher.dispatch(e2);
    dispatcher.dispatch(e3);

    // 5. Operator Overloading Check
    cout << "\nOperator Overloading Check" << endl;
    HospitalEvent seriousEvent("ER", 5);
    HospitalEvent mildEvent("Ward", 1);
    
    if (seriousEvent > mildEvent) {
        cout << "System Check: ER Event is more severe than Ward Event." << endl;
    }

    // 6. Sensor Simulation
    cout << "\nSensor Simulation " << endl;
    HeartRateSensor hrSensor;
    OxygenSensor o2Sensor;
    
    processSensor(dispatcher, &hrSensor);
    processSensor(dispatcher, &o2Sensor);

    // Cleanup
    delete nurse; delete icu; delete pharmacy; delete biomed; delete fire;

    return 0;
}