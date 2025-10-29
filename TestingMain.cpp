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
    
    try {
        // Test default factory methods
        std::cout << "\n--- Testing Default Factory Methods ---\n";
        PlantType* defaultFlower = flowerFactory.createPlant();
        factoryPlants.push_back(defaultFlower);
        
        PlantType* defaultTree = treeFactory.createPlant();
        factoryPlants.push_back(defaultTree);
        
        // Test factory methods with price parameter
        std::cout << "\n--- Testing Factory Methods with Price ---\n";
        PlantType* pricedFlower = flowerFactory.createPlant(35.75);
        factoryPlants.push_back(pricedFlower);
        
        PlantType* pricedTree = treeFactory.createPlant(85.25);
        factoryPlants.push_back(pricedTree);
        
        // Set colors after creation
        defaultFlower->setColour("red");
        defaultTree->setColour("green");
        pricedFlower->setColour("pink");
        pricedTree->setColour("dark green");
        
        // Display factory-created plants
        std::cout << "\n--- Factory-Created Plants Summary ---\n";
        for (size_t i = 0; i < factoryPlants.size(); i++) {
            std::cout << (i+1) << ". ";
            factoryPlants[i]->display();
        }
    }
    catch (...) {
        // Ensure cleanup even if exceptions occur
        for (PlantType* plant : factoryPlants) {
            delete plant;
        }
        throw;
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
    
    try {
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
    }
    catch (...) {
        // Cleanup on exception
        for (PlantType* plant : colorTestPlants) {
            delete plant;
        }
        throw;
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
    
    try {
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
    }
    catch (...) {
        // Cleanup on exception
        for (PlantType* plant : allPlants) {
            delete plant;
        }
        throw;
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
    
    // Create test plants specifically for this test
    std::vector<PlantType*> testPlants;
    
    try {
        // Create plants for strategy testing
        PlantType* springRose = flowerFactory.createRose(25.0);
        springRose->setSeason("Spring");
        testPlants.push_back(springRose);
        
        PlantType* summerLily = flowerFactory.createPeaceLily(30.0);
        summerLily->setSeason("Summer");
        testPlants.push_back(summerLily);
        
        PlantType* autumnBonsai = treeFactory.createBonsai(80.0);
        autumnBonsai->setSeason("Autumn");
        testPlants.push_back(autumnBonsai);
        
        PlantType* regularRose = flowerFactory.createRose(20.0);
        testPlants.push_back(regularRose);
        
        PlantType* expensiveBonsai = treeFactory.createBonsai(120.0);
        testPlants.push_back(expensiveBonsai);

        // Test 1: No Discount Strategy (Default Behavior)
        std::cout << "\n--- Test 1: No Discount Strategy (Default Behavior) ---\n";
        customer.addToCart(testPlants[0]->clone());
        customer.addToCart(testPlants[1]->clone());
        
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
        
        // Add cloned items to trigger bulk discount
        customer.addToCart(testPlants[0]->clone());
        customer.addToCart(testPlants[1]->clone());
        customer.addToCart(testPlants[2]->clone());
        customer.addToCart(testPlants[3]->clone());
        
        std::cout << "Cart items: " << customer.getCart()->getItemCount() << "\n";
        std::cout << "Discount applied: " << bulkDiscount->getDescription() << "\n";
        std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
        std::cout << "Final price after bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
        
        customer.clearCart();

        // Test 3: Seasonal Discount Strategy
        std::cout << "\n--- Test 3: Seasonal Discount Strategy ---\n";
        std::string spring = "Spring";
        SeasonalDiscount* seasonalDiscount = new SeasonalDiscount(spring, 0.20); // 20% off spring plants
        
        //std::cout << "hi " <<std::endl; 

        customer.getCart()->setDiscountStrategy(seasonalDiscount);
        
        // Add cloned plants with different seasons
        customer.addToCart(testPlants[0]->clone()); // Spring plant
        customer.addToCart(testPlants[1]->clone()); // Summer plant (no discount)
        customer.addToCart(testPlants[4]->clone()); // No season set (no discount)
        
        std::cout << "Discount applied: " << seasonalDiscount->getDescription() << "\n";
        std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
        std::cout << "Final price after seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
        
        customer.clearCart();

        // Test 4: Withering Discount Strategy
        std::cout << "\n--- Test 4: Withering Discount Strategy ---\n";
        WitheringDiscount* witheringDiscount = new WitheringDiscount(0.25); // 25% off withering plants
        
        customer.getCart()->setDiscountStrategy(witheringDiscount);
        
        // Add cloned plants
        customer.addToCart(testPlants[0]->clone());
        customer.addToCart(testPlants[1]->clone());
        customer.addToCart(testPlants[2]->clone());
        
        std::cout << "Discount applied: " << witheringDiscount->getDescription() << "\n";
        std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
        std::cout << "Final price after withering discount: R" << customer.getCart()->applyDiscount() << "\n";
        std::cout << "Note: Withering discount only applies to plants in 'Withering' state\n";
        
        customer.clearCart();

        // Test 5: Strategy Switching at Runtime (GoF Principle)
        std::cout << "\n--- Test 5: Runtime Strategy Switching (GoF Principle) ---\n";
        
        // Start with bulk discount
        BulkDiscount* runtimeBulk = new BulkDiscount(2, 0.10);
        customer.getCart()->setDiscountStrategy(runtimeBulk);
        customer.addToCart(testPlants[0]->clone());
        customer.addToCart(testPlants[1]->clone());
        
        std::cout << "Initial strategy: Bulk Discount\n";
        std::cout << "Price with bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
        
        // Switch to seasonal discount at runtime
        std::string summer = "Summer";
        SeasonalDiscount* runtimeSeasonal = new SeasonalDiscount(summer, 0.15);
        customer.getCart()->setDiscountStrategy(runtimeSeasonal);
        std::cout << "Switched to: Seasonal Discount\n";
        std::cout << "Price with seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
        
        // Switch back to no strategy
        customer.getCart()->setDiscountStrategy(nullptr);
        std::cout << "Switched to: No Discount Strategy\n";
        std::cout << "Price with no discount: R" << customer.getCart()->applyDiscount() << "\n";
        
        customer.clearCart();

        std::cout << "\n--- Test 6: Complete Purchase Flow ---\n";
        GreenHouse* greenhouse = GreenHouse::getInstance();

        // Create NEW plants specifically for greenhouse test (separate from testPlants)
        PlantType* greenhouseRose = flowerFactory.createRose(25.0);
        PlantType* greenhouseLily = flowerFactory.createPeaceLily(30.0); 
        PlantType* greenhouseBonsai = treeFactory.createBonsai(80.0);

        greenhouse->addToInventory(greenhouseRose);
        greenhouse->addToInventory(greenhouseLily);
        greenhouse->addToInventory(greenhouseBonsai);

        std::vector<PlantType*> availablePlants = greenhouse->getInventory();
        BulkDiscount* greenhouseDiscount = new BulkDiscount(2, 0.10);

        if (availablePlants.size() >= 3) {
            customer.getCart()->setDiscountStrategy(greenhouseDiscount);
            
            // Add plants to cart - greenhouse maintains ownership
            customer.addToCart(availablePlants[0]);
            customer.addToCart(availablePlants[1]); 
            customer.addToCart(availablePlants[2]);
            
            std::cout << "Cart before purchase:\n";
            std::vector<PlantType*> cartItems = customer.getCart()->getItems();
            for (size_t i = 0; i < cartItems.size(); i++) {
                std::cout << " - " << cartItems[i]->getName() << " | R" << cartItems[i]->getPrice() << "\n";
            }

            std::cout << "Applying discount: " << greenhouseDiscount->getDescription() << "\n";
            std::cout << "Final amount: R" << customer.getCart()->applyDiscount() << "\n";
            
            customer.purchaseCart();  // Customer takes ownership during purchase
        }
        
        // Clear greenhouse for next tests
        std::vector<PlantType*> greenhouseInventory = greenhouse->getInventory();
        for (PlantType* plant : greenhouseInventory) {
            greenhouse->removeFromInventory(plant);
            delete plant;
        }
    }
    catch (...) {
        // Cleanup on exception
        for (PlantType* plant : testPlants) {
            delete plant;
        }
        throw;
    }
    
    // Cleanup test plants
    for (PlantType* plant : testPlants) {
        delete plant;
    }
    testPlants.clear();
}

void testEdgeCases() {
    std::cout << "\n\n⚠️  TEST 5: EDGE CASES\n";
    std::cout << "=====================\n";
    
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    std::vector<PlantType*> edgeCasePlants;
    
    try {
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
    }
    catch (const std::exception& e) {
        std::cout << "Exception in edge case test: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Unknown exception in edge case test" << std::endl;
    }
    
    // Always cleanup
    for (PlantType* plant : edgeCasePlants) {
        if (plant) {
            delete plant;
        }
    }
    edgeCasePlants.clear();
}