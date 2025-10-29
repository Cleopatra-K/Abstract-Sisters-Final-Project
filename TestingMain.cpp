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
#include "Customer.h"
#include "ShoppingCart.h"
#include "DiscountStrategy.h"
#include "BulkDiscount.h"
#include "SeasonalDiscount.h"
#include "WitheringDiscount.h"
#include "GreenHouse.h"

void testFactoryMethodPattern();
void testBridgePattern();
void testAllConcretePlants();
void testEdgeCases();
void testStrategyPattern();

int main() {
    std::cout << "╔══════════════════════════════════════════════════╗\n";
    std::cout << "║           COMPREHENSIVE PLANT TEST SUITE         ║\n";
    std::cout << "║   Factory Method + Bridge + Strategy Patterns   ║\n";
    std::cout << "╚══════════════════════════════════════════════════╝\n\n";

    // Test 1: Factory Method Pattern
    testFactoryMethodPattern();
    
    // Test 2: Bridge Pattern (Colors)
    testBridgePattern();
    
    // Test 3: All Concrete Plant Types
    testAllConcretePlants();
    
    // Test 4: Strategy Pattern (Discounts)
    testStrategyPattern();
    
    // Test 5: Edge Cases
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

void testStrategyPattern() {
    std::cout << "\n\n💰 TEST 4: STRATEGY PATTERN (DISCOUNT STRATEGIES)\n";
    std::cout << "=================================================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    Customer customer;
    
    // Create test plants with different characteristics for discount testing
    std::vector<PlantType*> testPlants;
    
    // Plants in different seasons for seasonal discount testing
    std::string spring = "Spring";
    std::string summer = "Summer";
    std::string autumn = "Autumn";
    
    PlantType* springRose = flowerFactory.createRose(25.0);
    springRose->setSeason(spring);
    testPlants.push_back(springRose);
    
    PlantType* summerLily = flowerFactory.createPeaceLily(30.0);
    summerLily->setSeason(summer);
    testPlants.push_back(summerLily);
    
    PlantType* autumnBonsai = treeFactory.createBonsai(80.0);
    autumnBonsai->setSeason(autumn);
    testPlants.push_back(autumnBonsai);
    
    PlantType* regularRose = flowerFactory.createRose(20.0);
    testPlants.push_back(regularRose);
    
    PlantType* expensiveBonsai = treeFactory.createBonsai(120.0);
    testPlants.push_back(expensiveBonsai);

    // Test 1: No Discount Strategy (Default Behavior)
    std::cout << "\n--- Test 1: No Discount Strategy (Default Behavior) ---\n";
    customer.addToCart(testPlants[0]);
    customer.addToCart(testPlants[1]);
    
    std::cout << "Cart contents:\n";
    std::vector<PlantType*> cartItems = customer.getCart()->getItems();
    for (size_t i = 0; i < cartItems.size(); i++) {
        std::cout << " - " << cartItems[i]->getName() << " | R" << cartItems[i]->getPrice() 
                  << " | Season: " << cartItems[i]->getSeason() << "\n";
    }
    
    double subtotal = customer.getCart()->calculateSubtotal();
    std::cout << "Subtotal: R" << subtotal << "\n";
    std::cout << "Final price (no discount): R" << customer.getCart()->applyDiscount() << "\n";
    
    customer.clearCart();

    // Test 2: Bulk Discount Strategy
    std::cout << "\n--- Test 2: Bulk Discount Strategy ---\n";
    BulkDiscount* bulkDiscount = new BulkDiscount(3, 0.15); // 15% off for 3+ items
    
    customer.getCart()->setDiscountStrategy(bulkDiscount);
    
    // Add multiple items to trigger bulk discount
    customer.addToCart(testPlants[0]);
    customer.addToCart(testPlants[1]);
    customer.addToCart(testPlants[2]);
    customer.addToCart(testPlants[3]);
    
    std::cout << "Cart items: " << customer.getCart()->getItemCount() << "\n";
    std::cout << "Discount applied: " << bulkDiscount->getDescription() << "\n";
    std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
    std::cout << "Final price after bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
    
    customer.clearCart();

    // Test 3: Seasonal Discount Strategy
    std::cout << "\n--- Test 3: Seasonal Discount Strategy ---\n";
    SeasonalDiscount* seasonalDiscount = new SeasonalDiscount(spring, 0.20); // 20% off spring plants
    
    customer.getCart()->setDiscountStrategy(seasonalDiscount);
    
    // Add plants with different seasons
    customer.addToCart(testPlants[0]); // Spring plant
    customer.addToCart(testPlants[1]); // Summer plant (no discount)
    customer.addToCart(testPlants[4]); // No season set (no discount)
    
    std::cout << "Discount applied: " << seasonalDiscount->getDescription() << "\n";
    std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
    std::cout << "Final price after seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
    
    customer.clearCart();

    // Test 4: Withering Discount Strategy
    std::cout << "\n--- Test 4: Withering Discount Strategy ---\n";
    WitheringDiscount* witheringDiscount = new WitheringDiscount(0.25); // 25% off withering plants
    
    customer.getCart()->setDiscountStrategy(witheringDiscount);
    
    // Note: For this test to work properly, you'd need plants in withering state
    // For demonstration, we'll use regular plants and show the structure
    customer.addToCart(testPlants[0]);
    customer.addToCart(testPlants[1]);
    customer.addToCart(testPlants[2]);
    
    std::cout << "Discount applied: " << witheringDiscount->getDescription() << "\n";
    std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
    std::cout << "Final price after withering discount: R" << customer.getCart()->applyDiscount() << "\n";
    std::cout << "Note: Withering discount only applies to plants in 'Withering' state\n";
    
    customer.clearCart();

    // Test 5: Strategy Switching at Runtime (GoF Principle)
    std::cout << "\n--- Test 5: Runtime Strategy Switching (GoF Principle) ---\n";
    
    // Start with bulk discount
    customer.getCart()->setDiscountStrategy(new BulkDiscount(2, 0.10));
    customer.addToCart(testPlants[0]);
    customer.addToCart(testPlants[1]);
    
    std::cout << "Initial strategy: Bulk Discount\n";
    std::cout << "Price with bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
    
    // Switch to seasonal discount at runtime
    customer.getCart()->setDiscountStrategy(new SeasonalDiscount(summer, 0.15));
    std::cout << "Switched to: Seasonal Discount\n";
    std::cout << "Price with seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
    
    // Switch back to no strategy
    customer.getCart()->setDiscountStrategy(nullptr);
    std::cout << "Switched to: No Discount Strategy\n";
    std::cout << "Price with no discount: R" << customer.getCart()->applyDiscount() << "\n";
    
    customer.clearCart();

    std::cout << "\n--- Test 6: Complete Purchase Flow ---\n";
    GreenHouse* greenhouse = GreenHouse::getInstance();

    // RESET the greenhouse for a clean test
    std::vector<PlantType*> oldInventory = greenhouse->getInventory();
    for (PlantType* plant : oldInventory) {
        greenhouse->removeFromInventory(plant);
        delete plant;
    }

    // Create and add fresh plants
    PlantType* testRose = flowerFactory.createRose(25.0);
    PlantType* testLily = flowerFactory.createPeaceLily(30.0); 
    PlantType* testBonsai = treeFactory.createBonsai(80.0);

    greenhouse->addToInventory(testRose);
    greenhouse->addToInventory(testLily);
    greenhouse->addToInventory(testBonsai);

    std::vector<PlantType*> availablePlants = greenhouse->getInventory();
    BulkDiscount* anotherBulkDiscount = new BulkDiscount(2, 0.10);

    if (availablePlants.size() >= 3) {
        customer.getCart()->setDiscountStrategy(anotherBulkDiscount);
        customer.addToCart(availablePlants[0]);
        customer.addToCart(availablePlants[1]); 
        customer.addToCart(availablePlants[2]);
        
        std::cout << "Cart before purchase:\n";
        std::vector<PlantType*> cartItems = customer.getCart()->getItems();
        for (size_t i = 0; i < cartItems.size(); i++) {
            std::cout << " - " << cartItems[i]->getName() << " | R" << cartItems[i]->getPrice() << "\n";
        }

        std::cout << "Applying discount: " << anotherBulkDiscount->getDescription() << "\n";
        std::cout << "Final amount: R" << customer.getCart()->applyDiscount() << "\n";
        
        customer.purchaseCart();  // ONE purchase only
    }

    // Don't cleanup testPlants here - they were either purchased or still in greenhouse
}

void testEdgeCases() {
    std::cout << "\n\n⚠️  TEST 5: EDGE CASES\n";
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