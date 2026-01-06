#include "HospitalUnit.h"

void NursingStation::respond(const HospitalEvent &e) {
    cout << ">> Nursing Station: Dispatching nurse to " << e.getSource() 
         << ". Checking patient status." << endl;
}

void ICUTeam::respond(const HospitalEvent &e) {
    if (e.getSeverity() >= 3) {
        cout << ">> ICU Team: CRITICAL ALERT! Specialists rushing to " << e.getSource() << endl;
    } else {
        cout << ">> ICU Team: Monitoring " << e.getSource() << " remotely." << endl;
    }
}

void PharmacySystem::respond(const HospitalEvent &e) {
    if (e.getType() == "Medicine Refill") {
        cout << ">> Pharmacy: Auto-generating refill order for " << e.getSource() << endl;
    }
}

void BiomedicalUnit::respond(const HospitalEvent &e) {
    if (e.getType() == "Equipment Malfunction") {
        cout << ">> Biomedical: Scheduling repair team for " << e.getSource() << endl;
    }
}

void FireSafetyUnit::respond(const HospitalEvent &e) {
    if (e.getType() == "Code Red" || e.getType() == "Fire") {
        cout << ">> Fire Safety: LOCKING DOORS. ACTIVATING SPRINKLERS at " << e.getSource() << endl;
    }
}