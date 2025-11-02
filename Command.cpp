#include "Command.h"
#include "Customer.h"
#include "GreenHouseStaff.h"

void PurchaseCommand::execute() {
    if (customer) {
        std::cout << customer->getName() << " is purchasing a plant...\n";
        customer->sendMessage("Purchase completed and added to cart.");
    }
}

void RemovePlantCommand::execute() {
    if (customer) {
        std::cout << customer->getName() << " removed a plant from the cart.\n";
        customer->sendMessage("Item removed successfully.");
    }
}

void WaterPlantCommand::execute() {
    if (staff) {
        std::cout << staff->getName() << " is watering the plant.\n";
        staff->sendMessage("Plant has been watered.");
    }
}

void DecoratePotCommand::execute() {
    if (staff) {
        std::cout << staff->getName() << " is decorating the pot.\n";
        staff->sendMessage("Pot decoration complete.");
    }
}
