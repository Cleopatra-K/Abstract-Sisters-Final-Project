#include "GreenHouseStaff.h"

GreenHouseStaff::GreenHouseStaff(Mediator* med, const std::string& n) : Staff(med, n) {}

void GreenHouseStaff::receiveMessage(const std::string& message)  {
        std::cout << "GreenHouseStaff " << name << " received: " << message << std::endl;
    }

void GreenHouseStaff::handleRequest(const std::string& request) {
        if (request.find("availability") != std::string::npos) {
            std::cout << "GreenHouseStaff " << name << " checking plant availability...\n";
            sendMessage("Plant availability confirmed.");
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "GreenHouseStaff " << name << " cannot handle request.\n";
        }
    }