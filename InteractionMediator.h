#ifndef INTERACTIONMEDIATOR_H
#define INTERACTIONMEDIATOR_H

#include "Mediator.h"
#include "Colleague.h"
#include "Command.h"
#include <vector>
#include <string>
#include <memory>

enum class Role { Customer, SalesStaff, GreenHouseStaff };

struct ColleagueInfo {
    Colleague* colleague;
    Role role;
};

class InteractionMediator : public Mediator {
private:
    std::vector<ColleagueInfo> colleagues;

public:
    ~InteractionMediator() = default;

    void addColleague(Colleague* c, Role role);

    // Send a text message to all other colleagues
    void sendMessage(const std::string& message, Colleague* sender) override;

    // Send a command (executed immediately)
    void sendCommand(Command* cmd, Role targetRole = Role::SalesStaff);

    // Optional: send message only to a specific role
    void sendMessageToRole(const std::string& message, Role targetRole, Colleague* sender = nullptr);
};

#endif
