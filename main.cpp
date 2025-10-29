#include <iostream>
#include <string>
#include <vector>
#include "PlantType.h"
#include "PlantFactory.h"
#include "FlowerFactory.h"
#include "TreeFactory.h"
#include "Rose.h"
#include "PeaceLily.h"
#include "WaterLily.h"
#include "BonsaiTree.h"
#include "Mangrove.h"
#include "Jacka.h"

int main() {
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║       PLANT FACTORY TEST SUITE         ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";

    std::vector<PlantType*> plants;

    FlowerFactory flowerFactory;
    TreeFactory treeFactory;

    // ----------------------------
    // Normal plants
    // ----------------------------
    PlantType* defaultRose = flowerFactory.createPlant();
    defaultRose->setColour("red");
    defaultRose->display();
    plants.push_back(defaultRose);

    PlantType* defaultBonsai = treeFactory.createPlant();
    defaultBonsai->setColour("green");
    defaultBonsai->display();
    plants.push_back(defaultBonsai);

    PlantType* customRose = flowerFactory.createRose(40.50);
    customRose->setColour("yellow");
    customRose->display();
    plants.push_back(customRose);

    PlantType* customBonsai = treeFactory.createBonsai(70.00);
    customBonsai->setColour("blue");
    customBonsai->display();
    plants.push_back(customBonsai);

    // ----------------------------
    // Edge cases
    // ----------------------------
    std::cout << "\n=== EDGE CASES ===\n";

    PlantType* freeRose = flowerFactory.createRose(0.0);
    freeRose->setColour("transparent");
    freeRose->display();
    plants.push_back(freeRose);

    PlantType* expensiveBonsai = treeFactory.createBonsai(1000);
    expensiveBonsai->setColour("gold");
    expensiveBonsai->display();
    plants.push_back(expensiveBonsai);

    PlantType* noColourRose = flowerFactory.createRose(25.0);
    noColourRose->setColour(""); // empty colour
    noColourRose->display();
    plants.push_back(noColourRose);

    // Mystery plant with empty description & colour
    std::string mysteryDesc = "";
    std::string mysteryColour = "Black";
    std::string mysterySeason = "Unknown";
    PlantType* mysteryPlant = new Rose("Mystery Rose", 30.0, mysteryDesc, mysteryColour, mysterySeason);
    mysteryPlant->display();
    plants.push_back(mysteryPlant);

    // ----------------------------
    // Test summary
    // ----------------------------
    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║              TEST SUMMARY              ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    std::cout << "Total plants created: " << plants.size() << "\n\n";

    for (std::size_t i = 0; i < plants.size(); i++) {
        std::cout << (i+1) << ". " << plants[i]->getName()
                  << " | Price: R" << plants[i]->getPrice()
                  << " | Colour: " << plants[i]->getColour()
                  << " | Health: " << plants[i]->getHealth() << "%\n";
    }

    // ----------------------------
    // Cleanup
    // ----------------------------
    std::cout << "\n--- Cleaning up memory ---\n";
    for (PlantType* plant : plants) {
        std::cout << "Deleting: " << plant->getName() << "\n";
        delete plant;
    }
    plants.clear();

    std::cout << "\n✓ All tests complete. Memory cleaned up successfully!\n";
    return 0;
}
