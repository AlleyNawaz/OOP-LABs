#include "HospitalEvent.h"

HospitalEvent::HospitalEvent(string srcName) {
    origin = srcName;
    category = "General Alert";
    level = 1;
    value = 0.0;
}

HospitalEvent::HospitalEvent(string srcName, string kind) {
    origin = srcName;
    category = kind;
    level = 2;
    value = 0.0;
}

HospitalEvent::HospitalEvent(string srcName, int intensity) {
    origin = srcName;
    category = "Severity Alert";
    level = intensity;
    value = 0.0;
}

HospitalEvent::HospitalEvent(string srcName, double measurement) {
    origin = srcName;
    category = "Vital Sign Check";
    level = 1;
    value = measurement;
}

string HospitalEvent::getSource() const { return origin; }
int HospitalEvent::getSeverity() const { return level; }
string HospitalEvent::getType() const { return category; }
double HospitalEvent::getReading() const { return value; }

ostream& operator<<(ostream& out, const HospitalEvent& ev) {
    out << "[EVENT] Source: " << ev.origin
        << " | Type: " << ev.category
        << " | Severity: " << ev.level;

    if (ev.value != 0.0) {
        out << " | Reading: " << ev.value;
    }
    return out;
}

bool HospitalEvent::operator==(const HospitalEvent& other) {
    return origin == other.origin;
}

bool HospitalEvent::operator>(const HospitalEvent& other) {
    return level > other.level;
}