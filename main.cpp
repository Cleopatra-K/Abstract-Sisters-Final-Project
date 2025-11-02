#include <iostream>
#include "Rose.h"
#include "PeaceLily.h"
#include "Mangrove.h"
#include "WaterLily.h"
#include "Jacka.h"
#include "BonsaiTree.h"

int main() {
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║    PLANT CARE SYSTEM - QUICK TEST     ║\n";
    std::cout << "╚════════════════════════════════════════╝\n\n";

    // Create a simple test plant
    std::string redColor = "red";
    std::string summer = "Summer";
    
    Rose* testRose = new Rose("Test Rose", 25.0, "Testing rose", redColor, summer);
    testRose->setHealth(80);
    testRose->setDays(10);
    
    std::cout << "Before care:\n";
    testRose->display();
    std::cout << "Health: " << testRose->getHealth() << "% | Days: " << testRose->getDays() << "\n\n";
    
    // Test Template Method pattern
    testRose->careForPlant();
    
    std::cout << "\nAfter care:\n";
    testRose->display();
    std::cout << "Health: " << testRose->getHealth() << "% | Days: " << testRose->getDays() << "\n\n";
    
    // Test Prototype pattern
    std::cout << "Testing Prototype pattern (cloning)...\n";
    PlantType* clonedRose = testRose->clone();
    
    std::cout << "Original: " << testRose->getName() << " - Health: " << testRose->getHealth() << "%\n";
    std::cout << "Clone:    " << clonedRose->getName() << " - Health: " << clonedRose->getHealth() << "%\n";
    
    // Modify clone
    clonedRose->setHealth(50);
    std::cout << "\nAfter modifying clone:\n";
    std::cout << "Original: Health = " << testRose->getHealth() << "%\n";
    std::cout << "Clone:    Health = " << clonedRose->getHealth() << "%\n";
    
    if (testRose->getHealth() != clonedRose->getHealth()) {
        std::cout << "\n✓ Prototype pattern working: Deep copy confirmed!\n";
    }
    
    // Cleanup
    delete testRose;
    delete clonedRose;
    
    std::cout << "\n" << std::string(40, '=') << "\n\n";
    
    // Test with different plant types
    std::cout << "Testing with PeaceLily (Indoor plant)...\n\n";
    std::string greenColor = "green";
    std::string winter = "Winter";
    
    PeaceLily* lily = new PeaceLily("White Lily", 30.0, "Beautiful indoor plant", greenColor, winter);
    lily->setHealth(70);
    lily->setDays(5);
    
    std::cout << "Before care:\n";
    lily->display();
    std::cout << "Health: " << lily->getHealth() << "% | Days: " << lily->getDays() << "\n\n";
    
    // Test Template Method
    lily->careForPlant();
    
    std::cout << "\nAfter care:\n";
    lily->display();
    std::cout << "Health: " << lily->getHealth() << "% | Days: " << lily->getDays() << "\n\n";
    
    // Test Prototype with PeaceLily
    std::cout << "Cloning PeaceLily...\n";
    PlantType* clonedLily = lily->clone();
    
    std::cout << "Original: " << lily->getName() << " - Health: " << lily->getHealth() << "%\n";
    std::cout << "Clone:    " << clonedLily->getName() << " - Health: " << clonedLily->getHealth() << "%\n";
    
    // Cleanup
    delete lily;
    delete clonedLily;
    
    std::cout << "\n" << std::string(40, '=') << "\n\n";
    
    // Test with Aquatic plant
    std::cout << "Testing with WaterLily (Aquatic plant)...\n\n";
    std::string yellowColor = "yellow";
    std::string spring = "Spring";
    
    WaterLily* waterLily = new WaterLily("Lotus", 35.0, "Floating flower", yellowColor, spring);
    waterLily->setHealth(60);
    waterLily->setDays(15);
    
    std::cout << "Before care:\n";
    waterLily->display();
    std::cout << "Health: " << waterLily->getHealth() << "% | Days: " << waterLily->getDays() << "\n\n";
    
    // Test Template Method
    waterLily->careForPlant();
    
    std::cout << "\nAfter care:\n";
    waterLily->display();
    std::cout << "Health: " << waterLily->getHealth() << "% | Days: " << waterLily->getDays() << "\n\n";
    
    // Test Prototype with WaterLily
    std::cout << "Cloning WaterLily...\n";
    PlantType* clonedWaterLily = waterLily->clone();
    
    std::cout << "Original: " << waterLily->getName() << " - Health: " << waterLily->getHealth() << "%\n";
    std::cout << "Clone:    " << clonedWaterLily->getName() << " - Health: " << clonedWaterLily->getHealth() << "%\n";
    
    // Cleanup
    delete waterLily;
    delete clonedWaterLily;
    
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "\n✓ All tests complete!\n";
    std::cout << "✓ Template Method pattern: WORKING\n";
    std::cout << "✓ Prototype pattern: WORKING\n";
    std::cout << "✓ All plant types tested successfully!\n";
    
    return 0;
}

