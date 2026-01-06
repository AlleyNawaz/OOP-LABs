#ifndef HOSPITALEVENT_H
#define HOSPITALEVENT_H

#include <iostream>
#include <string>
using namespace std;

class HospitalEvent {
private:
    string source;
    string eventType;
    int severityLevel;
    double vitalReading;

public:
    // Constructors
    HospitalEvent(string src);
    HospitalEvent(string src, string type);
    HospitalEvent(string src, int severity);
    HospitalEvent(string src, double reading);

    // Getters
    string getSource() const;
    int getSeverity() const;
    string getType() const;
    double getReading() const;

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const HospitalEvent& e);
    bool operator==(const HospitalEvent& other);
    bool operator>(const HospitalEvent& other);
};

#endif