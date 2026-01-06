#include "HospitalEvent.h"

// 1. Constructor: Source only
HospitalEvent::HospitalEvent(string src) {
    source = src;
    eventType = "General Alert";
    severityLevel = 1;
    vitalReading = 0.0;
}

// 2. Constructor: Source and Type
HospitalEvent::HospitalEvent(string src, string type) {
    source = src;
    eventType = type;
    severityLevel = 2; 
    vitalReading = 0.0;
}

// 3. Constructor: Source and Severity
HospitalEvent::HospitalEvent(string src, int severity) {
    source = src;
    eventType = "Severity Alert";
    severityLevel = severity;
    vitalReading = 0.0;
}

// 4. Constructor: Source and Vital Reading
HospitalEvent::HospitalEvent(string src, double reading) {
    source = src;
    eventType = "Vital Sign Check";
    severityLevel = 1;
    vitalReading = reading;
}

// Getters
string HospitalEvent::getSource() const { return source; }
int HospitalEvent::getSeverity() const { return severityLevel; }
string HospitalEvent::getType() const { return eventType; }
double HospitalEvent::getReading() const { return vitalReading; }

// Overloading <<
ostream& operator<<(ostream& os, const HospitalEvent& e) {
    os << "[EVENT] Source: " << e.source << " | Type: " << e.eventType 
       << " | Severity: " << e.severityLevel;
    if (e.vitalReading != 0.0) {
        os << " | Reading: " << e.vitalReading;
    }
    return os;
}

// Overloading ==
bool HospitalEvent::operator==(const HospitalEvent& other) {
    return this->source == other.source;
}

// Overloading >
bool HospitalEvent::operator>(const HospitalEvent& other) {
    return this->severityLevel > other.severityLevel;
}