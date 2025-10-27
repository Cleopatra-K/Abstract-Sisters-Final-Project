/*
Concrete colleague responsible for plant care, updates, and growth cycles.
*/

#ifndef GREENHOUSESTAFF_H
#define GREENHOUSESTAFF_H

#include "Staff.h"

class GreenHouseStaff : public Staff {
public:
    GreenHouseStaff(Mediator* med, const std::string& n);
    void receiveMessage(const std::string& message);
    void handleRequest(const std::string& request);
};

#endif
