#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Colleague.h"
#include "Command.h"
#include "GreenHouse.h"
#include <iostream>

/*
Concrete colleague representing a staff member who handles sales-related actions.
They can send/receive messages via the Mediator and execute commands.
*/

class SalesStaff : public Colleague {
private:
    Command* currentCommand; 

public:
    SalesStaff(Mediator* med, const std::string& n)
        : Colleague(med, n), currentCommand(nullptr) {}

    ~SalesStaff() override = default;

    void setCommand(Command* cmd) {
        currentCommand = cmd;
    }

    void executeCommand() {
        if (currentCommand) {
            std::cout << name << " executes command..." << std::endl;
            currentCommand->execute();
        } else {
            std::cout << name << " has no command to execute.\n";
        }
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "SalesStaff " << name << " received: " << message << std::endl;
    }

    void sendMessage(const std::string& message) override {
        std::cout << "SalesStaff " << name << " sends: " << message << std::endl;
        if (mediator) {
            mediator->sendMessage(message, this);
        }
    }

    void checkPlantAvailability(PlantType* plant) {
        GreenHouse* gh = GreenHouse::getInstance();
        if (gh->isPlantAvailable(plant)) {
            std::cout << name << ": Plant is available in inventory.\n";
        } else {
            std::cout << name << ": Plant not found in inventory.\n";
        }
    }
};

#endif
