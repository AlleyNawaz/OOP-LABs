#include "HospitalUnit.h"

void NursingStation::respond(const HospitalEvent& ev) {
    cout << ">> Nursing Desk: Nurse assigned to "
         << ev.getSource() << ". Patient evaluation started." << endl;
}

void ICUTeam::respond(const HospitalEvent& ev) {
    if (ev.getSeverity() >= 3) {
        cout << ">> ICU Response: HIGH PRIORITY! Medical experts heading to "
             << ev.getSource() << endl;
    } else {
        cout << ">> ICU Response: Situation under observation at "
             << ev.getSource() << endl;
    }
}

void PharmacySystem::respond(const HospitalEvent& ev) {
    if (ev.getType() == "Medicine Refill") {
        cout << ">> Pharmacy Unit: Refill request generated for "
             << ev.getSource() << endl;
    }
}

void BiomedicalUnit::respond(const HospitalEvent& ev) {
    if (ev.getType() == "Equipment Malfunction") {
        cout << ">> Biomedical Services: Maintenance scheduled at "
             << ev.getSource() << endl;
    }
}

void FireSafetyUnit::respond(const HospitalEvent& ev) {
    if (ev.getType() == "Code Red" || ev.getType() == "Fire") {
        cout << ">> Fire Control: Emergency protocol activated at "
             << ev.getSource() << endl;
    }
}