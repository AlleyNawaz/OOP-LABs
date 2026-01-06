#ifndef HOSPITALUNIT_H
#define HOSPITALUNIT_H

#include "HospitalEvent.h"

// Abstract Base Class
class HospitalUnit {
public:
    virtual void respond(const HospitalEvent &e) = 0;
    virtual ~HospitalUnit() {}
};

// Derived Classes
class NursingStation : public HospitalUnit {
public:
    void respond(const HospitalEvent &e) override;
};

class ICUTeam : public HospitalUnit {
public:
    void respond(const HospitalEvent &e) override;
};

class PharmacySystem : public HospitalUnit {
public:
    void respond(const HospitalEvent &e) override;
};

class BiomedicalUnit : public HospitalUnit {
public:
    void respond(const HospitalEvent &e) override;
};

class FireSafetyUnit : public HospitalUnit {
public:
    void respond(const HospitalEvent &e) override;
};

#endif