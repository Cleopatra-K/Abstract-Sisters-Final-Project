#include "Command.h"
#include "Customer.h"
#include "SalesStaff.h"
#include "GreenHouseStaff.h"
#include "PlantType.h"
#include "ShoppingCart.h"
#include "PlantDecorator.h"
#include "PotDecorator.h"
#include "GiftWrapDecorator.h"
#include "SpecialArrangement.h"

void PurchaseCommand::execute() {
    if (customer && plant) {
        std::cout << customer->getName() << " is purchasing "
                  << plant->getName() << "...\n";

        customer->getCart()->addItem(plant);
        customer->sendMessage("Purchase completed and added to cart.");
    }
}

void RemovePlantCommand::execute() {
    if (customer && plant) {
        std::cout << customer->getName() << " removed "
                  << plant->getName() << " from the cart.\n";

        customer->getCart()->removePlant(plant->getUniqueID());
        customer->sendMessage("Item removed successfully.");
    }
}

void WaterPlantCommand::execute() {
    if (staff && plant) {
        std::cout << staff->getName() << " is watering "
                  << plant->getName() << ".\n";
        staff->sendMessage("Plant has been watered.");
    }
}

void AddDecorationCommand::execute() {
    if (!staff || !plant) {
        std::cout << "Error: Invalid SalesStaff or Plant reference.\n";
        return;
    }

    std::cout << staff->getName()
              << " is adding decoration: " << decorationType << "...\n";

    PlantType* decorated = nullptr;

    if (decorationType == "Pot") {
        decorated = new PotDecorator(plant);
    }
    else if (decorationType == "GiftWrap") {
        decorated = new GiftWrapDecorator(plant);
    }
    else if (decorationType == "SpecialArrangement") {
        // Swap order to match SpecialArrangementDecorator constructor: (plant, occasion, message)
        decorated = new SpecialArrangementDecorator(plant, occasion, message);
    }
    else {
        std::cout << "Error: Unknown decoration type '" << decorationType << "'.\n";
        return;
    }

    std::cout << "Decoration applied successfully!\n";
    std::cout << "New Description: " << decorated->getDescription() << "\n";
    std::cout << "New Price: R" << decorated->getPrice() << "\n";

    // Replace original plant reference with decorated version
    plant = decorated;

    // Optionally, notify Mediator or ShoppingCart
    staff->sendMessage("Decoration successfully added to plant.");
}
