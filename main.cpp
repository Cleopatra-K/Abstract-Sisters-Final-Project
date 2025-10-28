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

    // Default plants
    std::string red = "red";
    PlantType* defaultRose = flowerFactory.createPlant();
    defaultRose->setColour(red);
    defaultRose->display();
    plants.push_back(defaultRose);

    std::string green = "green";
    PlantType* defaultBonsai = treeFactory.createPlant();
    defaultBonsai->setColour(green);
    defaultBonsai->display();
    plants.push_back(defaultBonsai);

    // Custom price plants
    std::string yellow = "yellow";
    PlantType* customRose = flowerFactory.createRose(40.50);
    customRose->setColour(yellow);
    customRose->display();
    plants.push_back(customRose);

    std::string blue = "blue";
    PlantType* customBonsai = treeFactory.createBonsai(70.00);
    customBonsai->setColour(blue);
    customBonsai->display();
    plants.push_back(customBonsai);

    // Edge cases
    std::cout << "\n=== EDGE CASES ===\n";

    std::string transparent = "transparent";
    PlantType* freeRose = flowerFactory.createRose(0.0);
    freeRose->setColour(transparent);
    freeRose->display();
    plants.push_back(freeRose);

    std::string gold = "gold";
    PlantType* expensiveBonsai = treeFactory.createBonsai(1e6);
    expensiveBonsai->setColour(gold);
    expensiveBonsai->display();
    plants.push_back(expensiveBonsai);

    std::string empty = "";
    PlantType* noColourRose = flowerFactory.createRose(25.0);
    noColourRose->setColour(empty);
    noColourRose->display();
    plants.push_back(noColourRose);

    // Null/empty description test
    std::string mysteryDesc = "";
    std::string mysteryColour = "";
    PlantType* mysteryPlant = new Rose("Mystery Rose", 30.0, mysteryDesc, mysteryColour);
    mysteryPlant->display();
    plants.push_back(mysteryPlant);

    // Summary
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

    // Cleanup
    std::cout << "\n--- Cleaning up memory ---\n";
    for (PlantType* plant : plants) {
        std::cout << "Deleting: " << plant->getName() << "\n";
        delete plant;
    }
    plants.clear();

    std::cout << "\n✓ All tests complete. Memory cleaned up successfully!\n";
    return 0;
}
