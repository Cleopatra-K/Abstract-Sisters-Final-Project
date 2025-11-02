#include "InventoryMediator.h"

void InventoryMediator::addColleague(Colleague* c) {
        colleagues.push_back(c);
}

void InventoryMediator::sendMessage(const std::string& message, Colleague* sender) {
    std::cout << "Inventory Mediator Broadcasting: " << message << std::endl;
    for (auto* c : colleagues) {
            if (c != sender)
                c->receiveMessage(message);
        }
}