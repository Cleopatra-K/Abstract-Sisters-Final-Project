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

void testFactoryMethodPattern();
void testBridgePattern();
void testAllConcretePlants();
void testEdgeCases();

int main() {
    std::cout << "╔══════════════════════════════════════════════════╗\n";
    std::cout << "║           COMPREHENSIVE PLANT TEST SUITE         ║\n";
    std::cout << "║        Testing Factory Method + Bridge          ║\n";
    std::cout << "╚══════════════════════════════════════════════════╝\n\n";

    // Test 1: Factory Method Pattern
    testFactoryMethodPattern();
    
    // Test 2: Bridge Pattern (Colors)
    testBridgePattern();
    
    // Test 3: All Concrete Plant Types
    testAllConcretePlants();
    
    // Test 4: Edge Cases
    testEdgeCases();

    std::cout << "\n╔══════════════════════════════════════════════════╗\n";
    std::cout << "║            ALL TESTS COMPLETED SUCCESSFULLY      ║\n";
    std::cout << "╚══════════════════════════════════════════════════╝\n";
    
    return 0;
}

void testFactoryMethodPattern() {
    std::cout << "\n🧪 TEST 1: FACTORY METHOD PATTERN\n";
    std::cout << "===================================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    std::vector<PlantType*> factoryPlants;
    
    // Test default factory methods
    std::cout << "\n--- Testing Default Factory Methods ---\n";
    PlantType* defaultFlower = flowerFactory.createPlant();
    defaultFlower->setColour("red");
    factoryPlants.push_back(defaultFlower);
    
    PlantType* defaultTree = treeFactory.createPlant();
    defaultTree->setColour("green");
    factoryPlants.push_back(defaultTree);
    
    // Test factory methods with price parameter
    std::cout << "\n--- Testing Factory Methods with Price ---\n";
    PlantType* pricedFlower = flowerFactory.createPlant(35.75);
    pricedFlower->setColour("pink");
    factoryPlants.push_back(pricedFlower);
    
    PlantType* pricedTree = treeFactory.createPlant(85.25);
    pricedTree->setColour("dark green");
    factoryPlants.push_back(pricedTree);
    
    // Display factory-created plants
    std::cout << "\n--- Factory-Created Plants Summary ---\n";
    for (size_t i = 0; i < factoryPlants.size(); i++) {
        std::cout << (i+1) << ". ";
        factoryPlants[i]->display();
    }
    
    // Cleanup
    for (PlantType* plant : factoryPlants) {
        delete plant;
    }
    factoryPlants.clear();
}

void testBridgePattern() {
    std::cout << "\n\n🎨 TEST 2: BRIDGE PATTERN (COLORS)\n";
    std::cout << "===================================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    std::vector<PlantType*> colorTestPlants;
    
    // Create plants with different colors to test Bridge pattern
    PlantType* redRose = flowerFactory.createRose(25.0);
    redRose->setColour("red");
    colorTestPlants.push_back(redRose);
    
    PlantType* yellowRose = flowerFactory.createRose(28.0);
    yellowRose->setColour("yellow");
    colorTestPlants.push_back(yellowRose);
    
    PlantType* greenBonsai = treeFactory.createBonsai(75.0);
    greenBonsai->setColour("green");
    colorTestPlants.push_back(greenBonsai);
    
    PlantType* whiteLily = flowerFactory.createPeaceLily(32.0);
    whiteLily->setColour("white");
    colorTestPlants.push_back(whiteLily);
    
    // Test color changes at runtime (Bridge pattern advantage)
    std::cout << "\n--- Testing Runtime Color Changes (Bridge Pattern) ---\n";
    PlantType* chameleonPlant = treeFactory.createBonsai(60.0);
    chameleonPlant->setColour("green");
    chameleonPlant->display();
    
    std::cout << "Changing color to yellow...\n";
    chameleonPlant->setColour("yellow");
    chameleonPlant->display();
    
    std::cout << "Changing color to red...\n";
    chameleonPlant->setColour("red");
    chameleonPlant->display();
    colorTestPlants.push_back(chameleonPlant);
    
    // Display color information
    std::cout << "\n--- Color Implementation Details ---\n";
    for (size_t i = 0; i < colorTestPlants.size(); i++) {
        std::cout << (i+1) << ". " << colorTestPlants[i]->getName() 
                  << " | Color: " << colorTestPlants[i]->getColour()
                  << " | Has Color: " << (colorTestPlants[i]->hasColour() ? "Yes" : "No") << "\n";
    }
    
    // Cleanup
    for (PlantType* plant : colorTestPlants) {
        delete plant;
    }
    colorTestPlants.clear();
}

void testAllConcretePlants() {
    std::cout << "\n\n🌿 TEST 3: ALL CONCRETE PLANT TYPES\n";
    std::cout << "===================================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    std::vector<PlantType*> allPlants;
    
    // Test all concrete flower types
    std::cout << "\n--- Testing All Flower Types ---\n";
    PlantType* rose = flowerFactory.createRose(25.50);
    rose->setColour("red");
    allPlants.push_back(rose);
    
    PlantType* peaceLily = flowerFactory.createPeaceLily(30.75);
    peaceLily->setColour("white");
    allPlants.push_back(peaceLily);
    
    PlantType* waterLily = flowerFactory.createWaterLily(35.25);
    waterLily->setColour("pink");
    allPlants.push_back(waterLily);
    
    // Test all concrete tree types
    std::cout << "\n--- Testing All Tree Types ---\n";
    PlantType* bonsai = treeFactory.createBonsai(80.00);
    bonsai->setColour("green");
    allPlants.push_back(bonsai);
    
    PlantType* mangrove = treeFactory.createMangrove(55.50);
    mangrove->setColour("green");
    allPlants.push_back(mangrove);
    
    PlantType* jacaranda = treeFactory.createJacarandaTree(45.75);
    jacaranda->setColour("purple");
    allPlants.push_back(jacaranda);
    
    // Display all plants with their categories
    std::cout << "\n--- All Concrete Plant Types Summary ---\n";
    for (size_t i = 0; i < allPlants.size(); i++) {
        std::cout << (i+1) << ". ";
        allPlants[i]->display();
        std::cout << "   Category: " << allPlants[i]->getCategory() << "\n";
    }
    
    // Test plant care template method
    std::cout << "\n--- Testing Plant Care Template Method ---\n";
    if (!allPlants.empty()) {
        std::cout << "Testing care routine on first plant:\n";
        allPlants[0]->careForPlant();
    }
    
    // Cleanup
    for (PlantType* plant : allPlants) {
        delete plant;
    }
    allPlants.clear();
}

void testEdgeCases() {
    std::cout << "\n\n⚠️  TEST 4: EDGE CASES\n";
    std::cout << "=====================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    std::vector<PlantType*> edgeCasePlants;
    
    // Edge case 1: Free plant (price = 0)
    std::cout << "\n--- Edge Case: Free Plant ---\n";
    PlantType* freeRose = flowerFactory.createRose(0.0);
    freeRose->setColour("red");
    edgeCasePlants.push_back(freeRose);
    
    // Edge case 2: Very expensive plant
    std::cout << "\n--- Edge Case: Expensive Plant ---\n";
    PlantType* expensiveBonsai = treeFactory.createBonsai(999.99);
    expensiveBonsai->setColour("gold");
    edgeCasePlants.push_back(expensiveBonsai);
    
    // Edge case 3: Empty color
    std::cout << "\n--- Edge Case: Empty Color ---\n";
    PlantType* noColorPlant = flowerFactory.createPeaceLily(20.0);
    noColorPlant->setColour("");
    edgeCasePlants.push_back(noColorPlant);
    
    // Edge case 4: Invalid color (should handle gracefully)
    std::cout << "\n--- Edge Case: Invalid Color ---\n";
    PlantType* invalidColorPlant = treeFactory.createMangrove(40.0);
    invalidColorPlant->setColour("rainbow"); // This might not be implemented
    edgeCasePlants.push_back(invalidColorPlant);
    
    // Edge case 5: Direct instantiation (if constructors work)
    std::cout << "\n--- Edge Case: Direct Object Creation ---\n";
    std::string desc = "Special mystery rose";
    std::string color = "black";
    std::string season = "Unknown";
    PlantType* mysteryRose = new Rose("Mystery Rose", 30.0, desc, color, season);
    mysteryRose->display();
    edgeCasePlants.push_back(mysteryRose);
    
    // Display edge cases summary
    std::cout << "\n--- Edge Cases Summary ---\n";
    for (size_t i = 0; i < edgeCasePlants.size(); i++) {
        std::cout << (i+1) << ". " << edgeCasePlants[i]->getName()
                  << " | Price: R" << edgeCasePlants[i]->getPrice()
                  << " | Color: " << edgeCasePlants[i]->getColour()
                  << " | Health: " << edgeCasePlants[i]->getHealth() << "%\n";
    }
    
    // Cleanup
    for (PlantType* plant : edgeCasePlants) {
        std::cout << "Deleting: " << plant->getName() << "\n";
        delete plant;
    }
    edgeCasePlants.clear();
}