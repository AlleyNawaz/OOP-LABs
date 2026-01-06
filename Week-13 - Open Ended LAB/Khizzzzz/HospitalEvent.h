#ifndef HOSPITAL_EVENT_H
#define HOSPITAL_EVENT_H

#include <iostream>
#include <string>

using namespace std;

class HospitalEvent {
private:
    string origin;
    string category;
    int level;
    double value;

public:
    HospitalEvent(string srcName);
    HospitalEvent(string srcName, string kind);
    HospitalEvent(string srcName, int intensity);
    HospitalEvent(string srcName, double measurement);

    string getSource() const;
    int getSeverity() const;
    string getType() const;
    double getReading() const;

    friend ostream& operator<<(ostream& out, const HospitalEvent& ev);
    bool operator==(const HospitalEvent& other);
    bool operator>(const HospitalEvent& other);
};

#endif