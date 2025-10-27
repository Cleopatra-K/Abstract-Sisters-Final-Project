#include "InteractionMediator.h" 

void InteractionMediator::addColleague(Colleague* c) {
        colleagues.push_back(c);
    }

void InteractionMediator::sendMessage(const std::string& message, Colleague* sender) {
    for (auto* c : colleagues) {
            if (c != sender) {
                c->receiveMessage(message);
            }
        }
}