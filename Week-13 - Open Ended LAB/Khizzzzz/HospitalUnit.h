#ifndef HOSPITAL_UNIT_H
#define HOSPITAL_UNIT_H

#include "HospitalEvent.h"

class HospitalUnit {
public:
    virtual void respond(const HospitalEvent& ev) = 0;
    virtual ~HospitalUnit() {}
};

class NursingStation : public HospitalUnit {
public:
    void respond(const HospitalEvent& ev) override;
};

class ICUTeam : public HospitalUnit {
public:
    void respond(const HospitalEvent& ev) override;
};

class PharmacySystem : public HospitalUnit {
public:
    void respond(const HospitalEvent& ev) override;
};

class BiomedicalUnit : public HospitalUnit {
public:
    void respond(const HospitalEvent& ev) override;
};

class FireSafetyUnit : public HospitalUnit {
public:
    void respond(const HospitalEvent& ev) override;
};

#endif