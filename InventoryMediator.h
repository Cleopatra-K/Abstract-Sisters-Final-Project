/*
Coordinates inventory updates and notifications between greenhouse, staff, and sales floor.
*/

#ifndef INVENTORYMEDIATOR_H
#define INVENTORYMEDIATOR_H

#include "Mediator.h"
#include "Colleague.h"
#include <vector>
#include <iostream>

class InventoryMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;
public:
    void addColleague(Colleague* c);
    void sendMessage(const std::string& message, Colleague* sender);
};

#endif
