/*
Manages communication between customers and staff.
*/

#ifndef INTERACTIONMEDIATOR_H
#define INTERACTIONMEDIATOR_H

#include "Mediator.h"
#include "Colleague.h"
#include <vector>

class InteractionMediator : public Mediator {
private:
    std::vector<Colleague*> colleagues;

public:
    void addColleague(Colleague* c);
    void sendMessage(const std::string& message, Colleague* sender);
};

#endif
