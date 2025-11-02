#include "InteractionMediator.h"
#include <iostream>

void InteractionMediator::addColleague(Colleague* c, Role role) {
    if (c) {
        colleagues.push_back({c, role});
    }
}

void InteractionMediator::sendMessage(const std::string& message, Colleague* sender) {
    for (auto& info : colleagues) {
        if (info.colleague != sender) {
            info.colleague->receiveMessage(message);
        }
    }
}

void InteractionMediator::sendCommand(Command* cmd, Role targetRole) {
    if (!cmd) return;

    for (auto& info : colleagues) {
        if (info.role == targetRole) {
            cmd->execute(); // Currently executes immediately
            // break;         // stop after first match, or remove break to send to all with the role
        }
    }
}

// Optional: send message only to colleagues with specific role
void InteractionMediator::sendMessageToRole(const std::string& message, Role targetRole, Colleague* sender) {
    for (auto& info : colleagues) {
        if (info.role == targetRole && info.colleague != sender) {
            info.colleague->receiveMessage(message);
        }
    }
}
