// // #include <iostream>
// // #include <string>
// // #include <vector>
// // #include "PlantType.h"
// // #include "PlantFactory.h"
// // #include "FlowerFactory.h"
// // #include "TreeFactory.h"
// // #include "Rose.h"
// // #include "PeaceLily.h"
// // #include "WaterLily.h"
// // #include "BonsaiTree.h"
// // #include "Mangrove.h"
// // #include "Jacka.h"
// // #include "Customer.h"
// // #include "ShoppingCart.h"
// // #include "DiscountStrategy.h"
// // #include "BulkDiscount.h"
// // #include "SeasonalDiscount.h"
// // #include "WitheringDiscount.h"
// // #include "GreenHouse.h"

// // void testFactoryMethodPattern();
// // void testBridgePattern();
// // void testAllConcretePlants();
// // void testEdgeCases();
// // void testStrategyPattern();

// // int main() {
// //     std::cout << "╔══════════════════════════════════════════════════╗\n";
// //     std::cout << "║           COMPREHENSIVE PLANT TEST SUITE         ║\n";
// //     std::cout << "║   Factory Method + Bridge + Strategy Patterns   ║\n";
// //     std::cout << "╚══════════════════════════════════════════════════╝\n\n";

// //     // Test 1: Factory Method Pattern
// //     testFactoryMethodPattern();
    
// //     // Test 2: Bridge Pattern (Colors)
// //     testBridgePattern();
    
// //     // Test 3: All Concrete Plant Types
// //     testAllConcretePlants();
    
// //     // Test 4: Strategy Pattern (Discounts)
// //     testStrategyPattern();
    
// //     // Test 5: Edge Cases
// //     testEdgeCases();

// //     std::cout << "\n╔══════════════════════════════════════════════════╗\n";
// //     std::cout << "║            ALL TESTS COMPLETED SUCCESSFULLY      ║\n";
// //     std::cout << "╚══════════════════════════════════════════════════╝\n";
    
// //     return 0;
// // }

// // void testFactoryMethodPattern() {
// //     std::cout << "\n🧪 TEST 1: FACTORY METHOD PATTERN\n";
// //     std::cout << "===================================\n";
    
// //     FlowerFactory flowerFactory;
// //     TreeFactory treeFactory;
    
// //     std::vector<PlantType*> factoryPlants;
    
// //     // Test default factory methods
// //     std::cout << "\n--- Testing Default Factory Methods ---\n";
// //     PlantType* defaultFlower = flowerFactory.createPlant();
// //     defaultFlower->setColour("red");
// //     factoryPlants.push_back(defaultFlower);
    
// //     PlantType* defaultTree = treeFactory.createPlant();
// //     defaultTree->setColour("green");
// //     factoryPlants.push_back(defaultTree);
    
// //     // Test factory methods with price parameter
// //     std::cout << "\n--- Testing Factory Methods with Price ---\n";
// //     PlantType* pricedFlower = flowerFactory.createPlant(35.75);
// //     pricedFlower->setColour("pink");
// //     factoryPlants.push_back(pricedFlower);
    
// //     PlantType* pricedTree = treeFactory.createPlant(85.25);
// //     pricedTree->setColour("dark green");
// //     factoryPlants.push_back(pricedTree);
    
// //     // Display factory-created plants
// //     std::cout << "\n--- Factory-Created Plants Summary ---\n";
// //     for (size_t i = 0; i < factoryPlants.size(); i++) {
// //         std::cout << (i+1) << ". ";
// //         factoryPlants[i]->display();
// //     }
    
// //     // Cleanup
// //     for (PlantType* plant : factoryPlants) {
// //         delete plant;
// //     }
// //     factoryPlants.clear();
// // }

// // void testBridgePattern() {
// //     std::cout << "\n\nTEST 2: BRIDGE PATTERN (COLORS)\n";
// //     std::cout << "===================================\n";
    
// //     FlowerFactory flowerFactory;
// //     TreeFactory treeFactory;
    
// //     std::vector<PlantType*> colorTestPlants;
    
// //     // Create plants with different colors to test Bridge pattern
// //     PlantType* redRose = flowerFactory.createRose(25.0);
// //     redRose->setColour("red");
// //     colorTestPlants.push_back(redRose);
    
// //     PlantType* yellowRose = flowerFactory.createRose(28.0);
// //     yellowRose->setColour("yellow");
// //     colorTestPlants.push_back(yellowRose);
    
// //     PlantType* greenBonsai = treeFactory.createBonsai(75.0);
// //     greenBonsai->setColour("green");
// //     colorTestPlants.push_back(greenBonsai);
    
// //     PlantType* whiteLily = flowerFactory.createPeaceLily(32.0);
// //     whiteLily->setColour("white");
// //     colorTestPlants.push_back(whiteLily);
    
// //     // Test color changes at runtime (Bridge pattern advantage)
// //     std::cout << "\n--- Testing Runtime Color Changes (Bridge Pattern) ---\n";
// //     PlantType* chameleonPlant = treeFactory.createBonsai(60.0);
// //     chameleonPlant->setColour("green");
// //     chameleonPlant->display();
    
// //     std::cout << "Changing color to yellow...\n";
// //     chameleonPlant->setColour("yellow");
// //     chameleonPlant->display();
    
// //     std::cout << "Changing color to red...\n";
// //     chameleonPlant->setColour("red");
// //     chameleonPlant->display();
// //     colorTestPlants.push_back(chameleonPlant);
    
// //     // Display color information
// //     std::cout << "\n--- Color Implementation Details ---\n";
// //     for (size_t i = 0; i < colorTestPlants.size(); i++) {
// //         std::cout << (i+1) << ". " << colorTestPlants[i]->getName() 
// //                   << " | Color: " << colorTestPlants[i]->getColour()
// //                   << " | Has Color: " << (colorTestPlants[i]->hasColour() ? "Yes" : "No") << "\n";
// //     }
    
// //     // Cleanup
// //     for (PlantType* plant : colorTestPlants) {
// //         delete plant;
// //     }
// //     colorTestPlants.clear();
// // }

// // void testAllConcretePlants() {
// //     std::cout << "\n\n TEST 3: ALL CONCRETE PLANT TYPES\n";
// //     std::cout << "===================================\n";
    
// //     FlowerFactory flowerFactory;
// //     TreeFactory treeFactory;
    
// //     std::vector<PlantType*> allPlants;
    
// //     // Test all concrete flower types
// //     std::cout << "\n--- Testing All Flower Types ---\n";
// //     PlantType* rose = flowerFactory.createRose(25.50);
// //     rose->setColour("red");
// //     allPlants.push_back(rose);
    
// //     PlantType* peaceLily = flowerFactory.createPeaceLily(30.75);
// //     peaceLily->setColour("white");
// //     allPlants.push_back(peaceLily);
    
// //     PlantType* waterLily = flowerFactory.createWaterLily(35.25);
// //     waterLily->setColour("pink");
// //     allPlants.push_back(waterLily);
    
// //     // Test all concrete tree types
// //     std::cout << "\n--- Testing All Tree Types ---\n";
// //     PlantType* bonsai = treeFactory.createBonsai(80.00);
// //     bonsai->setColour("green");
// //     allPlants.push_back(bonsai);
    
// //     PlantType* mangrove = treeFactory.createMangrove(55.50);
// //     mangrove->setColour("green");
// //     allPlants.push_back(mangrove);
    
// //     PlantType* jacaranda = treeFactory.createJacarandaTree(45.75);
// //     jacaranda->setColour("purple");
// //     allPlants.push_back(jacaranda);
    
// //     // Display all plants with their categories
// //     std::cout << "\n--- All Concrete Plant Types Summary ---\n";
// //     for (size_t i = 0; i < allPlants.size(); i++) {
// //         std::cout << (i+1) << ". ";
// //         allPlants[i]->display();
// //         std::cout << "   Category: " << allPlants[i]->getCategory() << "\n";
// //     }
    
// //     // Test plant care template method
// //     std::cout << "\n--- Testing Plant Care Template Method ---\n";
// //     if (!allPlants.empty()) {
// //         std::cout << "Testing care routine on first plant:\n";
// //         allPlants[0]->careForPlant();
// //     }
    
// //     // Cleanup
// //     for (PlantType* plant : allPlants) {
// //         delete plant;
// //     }
// //     allPlants.clear();
// // }

// // void testStrategyPattern() {
// //     std::cout << "\n\n💰 TEST 4: STRATEGY PATTERN (DISCOUNT STRATEGIES)\n";
// //     std::cout << "=================================================\n";
    
// //     FlowerFactory flowerFactory;
// //     TreeFactory treeFactory;
// //     Customer customer;
    
// //     // Create test plants with different characteristics for discount testing
// //     std::vector<PlantType*> testPlants;
    
// //     // Plants in different seasons for seasonal discount testing
// //     std::string spring = "Spring";
// //     std::string summer = "Summer";
// //     std::string autumn = "Autumn";
    
// //     PlantType* springRose = flowerFactory.createRose(25.0);
// //     springRose->setSeason(spring);
// //     testPlants.push_back(springRose);
    
// //     PlantType* summerLily = flowerFactory.createPeaceLily(30.0);
// //     summerLily->setSeason(summer);
// //     testPlants.push_back(summerLily);
    
// //     PlantType* autumnBonsai = treeFactory.createBonsai(80.0);
// //     autumnBonsai->setSeason(autumn);
// //     testPlants.push_back(autumnBonsai);
    
// //     PlantType* regularRose = flowerFactory.createRose(20.0);
// //     testPlants.push_back(regularRose);
    
// //     PlantType* expensiveBonsai = treeFactory.createBonsai(120.0);
// //     testPlants.push_back(expensiveBonsai);

// //     // Test 1: No Discount Strategy (Default Behavior)
// //     std::cout << "\n--- Test 1: No Discount Strategy (Default Behavior) ---\n";
// //     customer.addToCart(testPlants[0]);
// //     customer.addToCart(testPlants[1]);
    
// //     std::cout << "Cart contents:\n";
// //     std::vector<PlantType*> cartItems = customer.getCart()->getItems();
// //     for (size_t i = 0; i < cartItems.size(); i++) {
// //         std::cout << " - " << cartItems[i]->getName() << " | R" << cartItems[i]->getPrice() 
// //                   << " | Season: " << cartItems[i]->getSeason() << "\n";
// //     }
    
// //     double subtotal = customer.getCart()->calculateSubtotal();
// //     std::cout << "Subtotal: R" << subtotal << "\n";
// //     std::cout << "Final price (no discount): R" << customer.getCart()->applyDiscount() << "\n";
    
// //     customer.clearCart();

// //     // Test 2: Bulk Discount Strategy
// //     std::cout << "\n--- Test 2: Bulk Discount Strategy ---\n";
// //     BulkDiscount* bulkDiscount = new BulkDiscount(3, 0.15); // 15% off for 3+ items
    
// //     customer.getCart()->setDiscountStrategy(bulkDiscount);
    
// //     // Add multiple items to trigger bulk discount
// //     customer.addToCart(testPlants[0]);
// //     customer.addToCart(testPlants[1]);
// //     customer.addToCart(testPlants[2]);
// //     customer.addToCart(testPlants[3]);
    
// //     std::cout << "Cart items: " << customer.getCart()->getItemCount() << "\n";
// //     std::cout << "Discount applied: " << bulkDiscount->getDescription() << "\n";
// //     std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
// //     std::cout << "Final price after bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
    
// //     customer.clearCart();

// //     // Test 3: Seasonal Discount Strategy
// //     std::cout << "\n--- Test 3: Seasonal Discount Strategy ---\n";
// //     SeasonalDiscount* seasonalDiscount = new SeasonalDiscount(spring, 0.20); // 20% off spring plants
    
// //     customer.getCart()->setDiscountStrategy(seasonalDiscount);
    
// //     // Add plants with different seasons
// //     customer.addToCart(testPlants[0]); // Spring plant
// //     customer.addToCart(testPlants[1]); // Summer plant (no discount)
// //     customer.addToCart(testPlants[4]); // No season set (no discount)
    
// //     std::cout << "Discount applied: " << seasonalDiscount->getDescription() << "\n";
// //     std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
// //     std::cout << "Final price after seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
    
// //     customer.clearCart();

// //     // Test 4: Withering Discount Strategy
// //     std::cout << "\n--- Test 4: Withering Discount Strategy ---\n";
// //     WitheringDiscount* witheringDiscount = new WitheringDiscount(0.25); // 25% off withering plants
    
// //     customer.getCart()->setDiscountStrategy(witheringDiscount);
    
// //     // Note: For this test to work properly, you'd need plants in withering state
// //     // For demonstration, we'll use regular plants and show the structure
// //     customer.addToCart(testPlants[0]);
// //     customer.addToCart(testPlants[1]);
// //     customer.addToCart(testPlants[2]);
    
// //     std::cout << "Discount applied: " << witheringDiscount->getDescription() << "\n";
// //     std::cout << "Subtotal: R" << customer.getCart()->calculateSubtotal() << "\n";
// //     std::cout << "Final price after withering discount: R" << customer.getCart()->applyDiscount() << "\n";
// //     std::cout << "Note: Withering discount only applies to plants in 'Withering' state\n";
    
// //     customer.clearCart();

// //     // Test 5: Strategy Switching at Runtime (GoF Principle)
// //     std::cout << "\n--- Test 5: Runtime Strategy Switching (GoF Principle) ---\n";
    
// //     // Start with bulk discount
// //     customer.getCart()->setDiscountStrategy(new BulkDiscount(2, 0.10));
// //     customer.addToCart(testPlants[0]);
// //     customer.addToCart(testPlants[1]);
    
// //     std::cout << "Initial strategy: Bulk Discount\n";
// //     std::cout << "Price with bulk discount: R" << customer.getCart()->applyDiscount() << "\n";
    
// //     // Switch to seasonal discount at runtime
// //     customer.getCart()->setDiscountStrategy(new SeasonalDiscount(summer, 0.15));
// //     std::cout << "Switched to: Seasonal Discount\n";
// //     std::cout << "Price with seasonal discount: R" << customer.getCart()->applyDiscount() << "\n";
    
// //     // Switch back to no strategy
// //     customer.getCart()->setDiscountStrategy(nullptr);
// //     std::cout << "Switched to: No Discount Strategy\n";
// //     std::cout << "Price with no discount: R" << customer.getCart()->applyDiscount() << "\n";
    
// //     customer.clearCart();

// //     std::cout << "\n--- Test 6: Complete Purchase Flow ---\n";
// //     GreenHouse* greenhouse = GreenHouse::getInstance();

// //     // RESET the greenhouse for a clean test
// //     std::vector<PlantType*> oldInventory = greenhouse->getInventory();
// //     for (PlantType* plant : oldInventory) {
// //         greenhouse->removeFromInventory(plant);
// //         delete plant;
// //     }

// //     // Create and add fresh plants
// //     PlantType* testRose = flowerFactory.createRose(25.0);
// //     PlantType* testLily = flowerFactory.createPeaceLily(30.0); 
// //     PlantType* testBonsai = treeFactory.createBonsai(80.0);

// //     greenhouse->addToInventory(testRose);
// //     greenhouse->addToInventory(testLily);
// //     greenhouse->addToInventory(testBonsai);

// //     std::vector<PlantType*> availablePlants = greenhouse->getInventory();
// //     BulkDiscount* anotherBulkDiscount = new BulkDiscount(2, 0.10);

// //     if (availablePlants.size() >= 3) {
// //         customer.getCart()->setDiscountStrategy(anotherBulkDiscount);
// //         customer.addToCart(availablePlants[0]);
// //         customer.addToCart(availablePlants[1]); 
// //         customer.addToCart(availablePlants[2]);
        
// //         std::cout << "Cart before purchase:\n";
// //         std::vector<PlantType*> cartItems = customer.getCart()->getItems();
// //         for (size_t i = 0; i < cartItems.size(); i++) {
// //             std::cout << " - " << cartItems[i]->getName() << " | R" << cartItems[i]->getPrice() << "\n";
// //         }

// //         std::cout << "Applying discount: " << anotherBulkDiscount->getDescription() << "\n";
// //         std::cout << "Final amount: R" << customer.getCart()->applyDiscount() << "\n";
        
// //         customer.purchaseCart();  // ONE purchase only
// //     }

// //     // Don't cleanup testPlants here - they were either purchased or still in greenhouse

// //     //KM
// //     for (PlantType* plant : testPlants) {
// //         delete plant;
// //     }
// //     testPlants.clear();

// // }

// // void testEdgeCases() {
// //     std::cout << "\n\n⚠️  TEST 5: EDGE CASES\n";
// //     std::cout << "=====================\n";
    
// //     FlowerFactory flowerFactory;
// //     TreeFactory treeFactory;
    
// //     std::vector<PlantType*> edgeCasePlants;
    
// //     // Edge case 1: Free plant (price = 0)
// //     std::cout << "\n--- Edge Case: Free Plant ---\n";
// //     PlantType* freeRose = flowerFactory.createRose(0.0);
// //     freeRose->setColour("red");
// //     edgeCasePlants.push_back(freeRose);
    
// //     // Edge case 2: Very expensive plant
// //     std::cout << "\n--- Edge Case: Expensive Plant ---\n";
// //     PlantType* expensiveBonsai = treeFactory.createBonsai(999.99);
// //     expensiveBonsai->setColour("gold");
// //     edgeCasePlants.push_back(expensiveBonsai);
    
// //     // Edge case 3: Empty color
// //     std::cout << "\n--- Edge Case: Empty Color ---\n";
// //     PlantType* noColorPlant = flowerFactory.createPeaceLily(20.0);
// //     noColorPlant->setColour("");
// //     edgeCasePlants.push_back(noColorPlant);
    
// //     // Edge case 4: Invalid color (should handle gracefully)
// //     std::cout << "\n--- Edge Case: Invalid Color ---\n";
// //     PlantType* invalidColorPlant = treeFactory.createMangrove(40.0);
// //     invalidColorPlant->setColour("rainbow"); // This might not be implemented
// //     edgeCasePlants.push_back(invalidColorPlant);
    
// //     // Edge case 5: Direct instantiation (if constructors work)
// //     std::cout << "\n--- Edge Case: Direct Object Creation ---\n";
// //     std::string desc = "Special mystery rose";
// //     std::string color = "black";
// //     std::string season = "Unknown";
// //     PlantType* mysteryRose = new Rose("Mystery Rose", 30.0, desc, color, season);
// //     mysteryRose->display();
// //     edgeCasePlants.push_back(mysteryRose);
    
// //     // Display edge cases summary
// //     std::cout << "\n--- Edge Cases Summary ---\n";
// //     for (size_t i = 0; i < edgeCasePlants.size(); i++) {
// //         std::cout << (i+1) << ". " << edgeCasePlants[i]->getName()
// //                   << " | Price: R" << edgeCasePlants[i]->getPrice()
// //                   << " | Color: " << edgeCasePlants[i]->getColour()
// //                   << " | Health: " << edgeCasePlants[i]->getHealth() << "%\n";
// //     }
    
// //     // Cleanup
// //     for (PlantType* plant : edgeCasePlants) {
// //         std::cout << "Deleting: " << plant->getName() << "\n";
// //         delete plant;
// //     }
// //     edgeCasePlants.clear();

// //     GreenHouse::destroyInstance();

// // }

// #include <iostream>
// #include <string>
// #include <vector>
// #include "PlantType.h"
// #include "PlantFactory.h"
// #include "FlowerFactory.h"
// #include "TreeFactory.h"
// #include "Rose.h"
// #include "PeaceLily.h"
// #include "WaterLily.h"
// #include "BonsaiTree.h"
// #include "Mangrove.h"
// #include "Jacka.h"
// #include "Customer.h"
// #include "ShoppingCart.h"
// #include "DiscountStrategy.h"
// #include "BulkDiscount.h"
// #include "SeasonalDiscount.h"
// #include "WitheringDiscount.h"
// #include "GreenHouse.h"

// void testFactoryMethodPattern();
// void testBridgePattern();
// void testAllConcretePlants();
// void testEdgeCases();
// void testStrategyPattern();

// int main() {
//     std::cout << "╔══════════════════════════════════════════════════╗\n";
//     std::cout << "║           COMPREHENSIVE PLANT TEST SUITE         ║\n";
//     std::cout << "║   Factory Method + Bridge + Strategy Patterns   ║\n";
//     std::cout << "╚══════════════════════════════════════════════════╝\n\n";

//     testFactoryMethodPattern();
//     testBridgePattern();
//     testAllConcretePlants();
//     testStrategyPattern();
//     testEdgeCases();

//     std::cout << "\n╔══════════════════════════════════════════════════╗\n";
//     std::cout << "║            ALL TESTS COMPLETED SUCCESSFULLY      ║\n";
//     std::cout << "╚══════════════════════════════════════════════════╝\n";

//     return 0;
// }

// void testFactoryMethodPattern() {
//     std::cout << "\n TEST 1: FACTORY METHOD PATTERN\n";
//     std::cout << "===================================\n";

//     FlowerFactory flowerFactory;
//     TreeFactory treeFactory;

//     std::vector<PlantType*> factoryPlants;

//     // Use price-based creation only
//     PlantType* pricedFlower = flowerFactory.createPlant(35.75);
//     pricedFlower->setColour("pink");
//     factoryPlants.push_back(pricedFlower);

//     PlantType* pricedTree = treeFactory.createPlant(85.25);
//     pricedTree->setColour("dark green");
//     factoryPlants.push_back(pricedTree);

//     std::cout << "\n--- Factory-Created Plants Summary ---\n";
//     for (size_t i = 0; i < factoryPlants.size(); i++) {
//         std::cout << (i+1) << ". ";
//         factoryPlants[i]->display();
//     }

//     // Cleanup
//     for (PlantType* plant : factoryPlants) delete plant;
//     factoryPlants.clear();
// }

// void testBridgePattern() {
//     std::cout << "\n\n TEST 2: BRIDGE PATTERN (COLORS)\n";
//     std::cout << "===================================\n";

//     FlowerFactory flowerFactory;
//     TreeFactory treeFactory;

//     std::vector<PlantType*> colorTestPlants;

//     PlantType* redRose = flowerFactory.createRose(25.0);
//     redRose->setColour("red");
//     colorTestPlants.push_back(redRose);

//     PlantType* yellowRose = flowerFactory.createRose(28.0);
//     yellowRose->setColour("yellow");
//     colorTestPlants.push_back(yellowRose);

//     PlantType* greenBonsai = treeFactory.createBonsai(75.0);
//     greenBonsai->setColour("green");
//     colorTestPlants.push_back(greenBonsai);

//     PlantType* whiteLily = flowerFactory.createPeaceLily(32.0);
//     whiteLily->setColour("white");
//     colorTestPlants.push_back(whiteLily);

//     // Runtime color changes
//     std::cout << "\n--- Runtime Color Changes ---\n";
//     PlantType* chameleonPlant = treeFactory.createBonsai(60.0);
//     chameleonPlant->setColour("green");
//     chameleonPlant->display();
//     chameleonPlant->setColour("yellow");
//     chameleonPlant->display();
//     chameleonPlant->setColour("red");
//     chameleonPlant->display();
//     colorTestPlants.push_back(chameleonPlant);

//     std::cout << "\n--- Color Summary ---\n";
//     for (size_t i = 0; i < colorTestPlants.size(); i++) {
//         std::cout << (i+1) << ". " << colorTestPlants[i]->getName()
//                   << " | Color: " << colorTestPlants[i]->getColour()
//                   << " | Has Color: " << (colorTestPlants[i]->hasColour() ? "Yes" : "No") << "\n";
//     }

//     // Cleanup
//     for (PlantType* plant : colorTestPlants) delete plant;
//     colorTestPlants.clear();
// }

// void testAllConcretePlants() {
//     std::cout << "\n\n TEST 3: ALL CONCRETE PLANT TYPES\n";
//     std::cout << "===================================\n";

//     FlowerFactory flowerFactory;
//     TreeFactory treeFactory;

//     std::vector<PlantType*> allPlants;

//     // Flowers
//     allPlants.push_back(flowerFactory.createRose(25.50));
//     allPlants.back()->setColour("red");
//     allPlants.push_back(flowerFactory.createPeaceLily(30.75));
//     allPlants.back()->setColour("white");
//     allPlants.push_back(flowerFactory.createWaterLily(35.25));
//     allPlants.back()->setColour("pink");

//     // Trees
//     allPlants.push_back(treeFactory.createBonsai(80.00));
//     allPlants.back()->setColour("green");
//     allPlants.push_back(treeFactory.createMangrove(55.50));
//     allPlants.back()->setColour("green");
//     allPlants.push_back(treeFactory.createJacarandaTree(45.75));
//     allPlants.back()->setColour("purple");

//     std::cout << "\n--- All Plants Summary ---\n";
//     for (size_t i = 0; i < allPlants.size(); i++) {
//         std::cout << (i+1) << ". ";
//         allPlants[i]->display();
//         std::cout << "   Category: " << allPlants[i]->getCategory() << "\n";
//     }

//     // Test care template
//     if (!allPlants.empty()) {
//         std::cout << "\n--- Testing Care Template Method ---\n";
//         allPlants[0]->careForPlant();
//     }

//     // Cleanup
//     for (PlantType* plant : allPlants) delete plant;
//     allPlants.clear();
// }

// void testStrategyPattern() {
//     std::cout << "\n\n TEST 4: STRATEGY PATTERN (DISCOUNTS)\n";
//     std::cout << "=======================================\n";

//     FlowerFactory flowerFactory;
//     TreeFactory treeFactory;
//     Customer customer;

//     std::vector<PlantType*> testPlants;
//     testPlants.push_back(flowerFactory.createRose(25.0)); // Spring plant
//     testPlants.back()->setSeason("Spring");
//     testPlants.push_back(flowerFactory.createPeaceLily(30.0)); // Summer plant
//     testPlants.back()->setSeason("Summer");
//     testPlants.push_back(treeFactory.createBonsai(80.0)); // Autumn plant
//     testPlants.back()->setSeason("Autumn");
//     testPlants.push_back(flowerFactory.createRose(20.0)); // Regular
//     testPlants.push_back(treeFactory.createBonsai(120.0)); // Expensive

//     // Bulk discount test
//     BulkDiscount* bulkDiscount = new BulkDiscount(3, 0.15);
//     customer.getCart()->setDiscountStrategy(bulkDiscount);
//     for (int i = 0; i < 4; i++) customer.addToCart(testPlants[i]);

//     std::cout << "\n--- Bulk Discount ---\n";
//     std::cout << "Final price: R" << customer.getCart()->applyDiscount() << "\n";
//     customer.clearCart();

//     // Seasonal discount test
//     SeasonalDiscount* seasonalDiscount = new SeasonalDiscount("Spring", 0.20);
//     customer.getCart()->setDiscountStrategy(seasonalDiscount);
//     customer.addToCart(testPlants[0]);
//     customer.addToCart(testPlants[1]);
//     customer.addToCart(testPlants[4]);

//     std::cout << "\n--- Seasonal Discount ---\n";
//     std::cout << "Final price: R" << customer.getCart()->applyDiscount() << "\n";
//     customer.clearCart();

//     // Withering discount test
//     WitheringDiscount* witheringDiscount = new WitheringDiscount(0.25);
//     customer.getCart()->setDiscountStrategy(witheringDiscount);
//     for (int i = 0; i < 3; i++) customer.addToCart(testPlants[i]);

//     std::cout << "\n--- Withering Discount ---\n";
//     std::cout << "Final price: R" << customer.getCart()->applyDiscount() << "\n";
//     customer.clearCart();

//     // Cleanup testPlants
//     for (PlantType* plant : testPlants) delete plant;
//     testPlants.clear();

//     delete bulkDiscount;
//     delete seasonalDiscount;
//     delete witheringDiscount;
// }

// void testEdgeCases() {
//     std::cout << "\n\n TEST 5: EDGE CASES\n";
//     std::cout << "=====================\n";

//     FlowerFactory flowerFactory;
//     TreeFactory treeFactory;

//     std::vector<PlantType*> edgePlants;

//     edgePlants.push_back(flowerFactory.createRose(0.0)); // Free
//     edgePlants.back()->setColour("red");

//     edgePlants.push_back(treeFactory.createBonsai(999.99)); // Expensive
//     edgePlants.back()->setColour("gold");

//     edgePlants.push_back(flowerFactory.createPeaceLily(20.0)); // Empty color
//     edgePlants.back()->setColour("");

//     edgePlants.push_back(treeFactory.createMangrove(40.0)); // Invalid color
//     edgePlants.back()->setColour("rainbow");

//     // Direct instantiation
//     edgePlants.push_back(new Rose("Mystery Rose", 50.0, "A mysterious rose", "Red", "Spring"));

//     std::cout << "\n--- Edge Plants Summary ---\n";
//     for (PlantType* plant : edgePlants) plant->display();

//     // Cleanup
//     for (PlantType* plant : edgePlants) delete plant;
//     edgePlants.clear();

//     // Destroy GreenHouse singleton
//     GreenHouse::destroyInstance();
// }


// #include <iostream>
// #include "GreenHouse.h"
// #include "Bundle.h"
// #include "Rose.h"
// #include "BreadthFirstIterator.h"

// int main() {
//     // -------------------------
//     // 1️⃣ GreenHouse test (STL iterator)
//     // -------------------------
//     GreenHouse greenhouse;

//     // Add plants (GreenHouse owns these)
//     greenhouse.addToInventory(new Rose("Red Rose", 25.0, "Beautiful flower", "red", "Spring"));
//     greenhouse.addToInventory(new Rose("White Rose", 20.0, "Elegant flower", "white", "Summer"));

//     std::cout << "GreenHouse inventory (using STL iterators):\n";
//     for (PlantType* plant : greenhouse.getInventory()) {
//         plant->display();
//     }
//     std::cout << "-------------------------\n";

//     // -------------------------
//     // 2️⃣ Bundle test (BFS CompositeIterator)
//     // -------------------------
//     Bundle* mainBundle = new Bundle("Main Bundle");

//     // Create leaves (GreenHouse still owns these if needed elsewhere)
//     Rose* yellowRose = new Rose("Yellow Rose", 15.0, "Sunny flower", "yellow", "Summer");
//     Rose* pinkRose   = new Rose("Pink Rose", 18.0, "Lovely flower", "pink", "Spring");

//     mainBundle->add(yellowRose);
//     mainBundle->add(pinkRose);

//     // Nested bundle
//     Bundle* miniBundle = new Bundle("Mini Bundle");
//     miniBundle->add(new Rose("Mini Rose 1", 10.0, "Small flower", "red", "Spring"));
//     miniBundle->add(new Rose("Mini Rose 2", 12.0, "Small flower", "white", "Summer"));

//     mainBundle->add(miniBundle);

//     std::cout << "Traversing Bundles (BFS CompositeIterator):\n";
//     Iterator* it = mainBundle->createIterator();

//     while (it->hasNext()) {
//         PlantType* plant = it->currentItem();
//         if (plant) plant->display();
//         it->next();
//     }
//     delete it;

//     // -------------------------
//     // Cleanup (GreenHouse owns only its inventory)
//     // Bundles: delete top-level bundle; no need to delete children manually
//     // -------------------------
//     delete mainBundle;

//     // GreenHouse will delete its plants automatically when going out of scope
//     return 0;
// }

// #include <iostream>
// #include "ShoppingCart.h"
// #include "BulkDiscount.h"
// #include "SeasonalDiscount.h"
// #include "Rose.h"
// #include "BonsaiTree.h"
// #include "PeaceLily.h"

// int main() {
//     std::cout << "=== Strategy Pattern Test ===" << std::endl;

//     ShoppingCart cart;

//     // Use concrete Leafs instead of PlantType
//     PlantType* rose = new Rose("Rose", 120.0, "A beautiful red rose.", "red", "Summer");
//     PlantType* bonsai = new BonsaiTree("Bonsai Tree", 300.0, "A small decorative bonsai.", "green", "Spring");
//     PlantType* lily = new PeaceLily("Peace Lily", 150.0, "Elegant white indoor plant.", "yellow", "Winter");

//     cart.addItem(rose);
//     cart.addItem(bonsai);
//     cart.addItem(lily);

//     std::cout << "\n--- Cart Summary ---" << std::endl;
//     for (auto item : cart.getItems()) {
//         item->display();
//     }

//     std::cout << "Subtotal: R" << cart.calculateSubtotal() << std::endl;

//     std::cout << "\nApplying Bulk Discount (10% off 3+ items)..." << std::endl;
//     cart.setDiscountStrategy(new BulkDiscount(3, 0.10));
//     std::cout << "After Bulk Discount: R" << cart.applyDiscount() << std::endl;

//     std::cout << "\nApplying Seasonal Discount (15% off in-season plants)..." << std::endl;
//     cart.setDiscountStrategy(new SeasonalDiscount(0.15));
//     std::cout << "After Seasonal Discount: R" << cart.applyDiscount() << std::endl;

//     delete rose;
//     delete bonsai;
//     delete lily;

//     std::cout << "\n=== Test Complete ===" << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include "ShoppingCart.h"

// // Concrete plant includes
// #include "Rose.h"
// #include "Jacka.h"
// #include "Mangrove.h"
// #include "WaterLily.h"
// #include "BonsaiTree.h"
// #include "PeaceLily.h"

// int main() {
//     std::cout << "=== Greenhouse Testing ===\n";

//     // --- Create Plants ---
//     Rose* rose = new Rose("Red Rose", 50.0, "Thorny classic flower", "red", "Spring");
//     Jacka* jacka = new Jacka("Jacka Fern", 35.0, "Indoor leafy plant", "green", "Summer");
//     Mangrove* mangrove = new Mangrove("Mangrove Tree", 100.0, "Coastal tree", "green", "Winter");
//     WaterLily* waterlily = new WaterLily("Water Lily", 75.0, "Floating aquatic plant", "yellow", "Summer");
//     BonsaiTree* bonsai = new BonsaiTree("Mini Bonsai", 200.0, "Cultivated miniature tree", "green", "Autumn");
//     PeaceLily* peacelily = new PeaceLily("Peace Lily", 60.0, "Elegant indoor plant", "white", "Spring");

//     // --- Create ShoppingCart ---
//     ShoppingCart cart;

//     // --- Add plants to cart ---
//     cart.addItem(rose);
//     cart.addItem(jacka);
//     cart.addItem(mangrove);
//     cart.addItem(waterlily);
//     cart.addItem(bonsai);
//     cart.addItem(peacelily);

//     // --- Display items ---
//     std::cout << "\n=== Shopping Cart Items ===\n";
//     for (auto item : cart.getItems()) {
//         item->display();
//         std::cout << "-------------------------\n";
//     }

//     // --- Clone a plant (Prototype test) ---
//     std::cout << "\n=== Cloned Plant ===\n";
//     PlantType* clonedRose = rose->clone();
//     clonedRose->display();

//     // --- Use Breadth-First Iterators ---
//     std::cout << "\n=== BFS Iteration over Each Plant ===\n";
//     for (auto item : cart.getItems()) {
//         Iterator* it = item->createIterator();
//         for (it->first(); it->hasNext(); it->next()) {
//             PlantType* p = it->currentItem();
//             if (p)
//                 std::cout << "Iterated: " << p->getName() << std::endl;
//         }
//         delete it;
//     }

//     // --- Clean up ---
//     delete clonedRose;

//     // NOTE: If ShoppingCart doesn’t delete plants automatically,
//     // delete manually to avoid memory leaks:
//     delete rose;
//     delete jacka;
//     delete mangrove;
//     delete waterlily;
//     delete bonsai;
//     delete peacelily;

//     std::cout << "\n=== Test Complete ===\n";
//     return 0;
// }


// #include "Rose.h"
// #include "Jacka.h"
// #include "Mangrove.h"
// #include "WaterLily.h"
// #include "BonsaiTree.h"
// #include "PeaceLily.h"
// #include "GreenHouse.h"
// #include "ShoppingCart.h"

// int main() {
//     GreenHouse gh;

//     gh.addToInventory(new Rose("Red Rose", 50.0, "Lovely garden flower", "Red", "Spring"));
//     gh.addToInventory(new Jacka("Jacka Bloom", 40.0, "Bright and strong", "Yellow", "Summer"));
//     gh.addToInventory(new PeaceLily("Peace Lily", 60.0, "Indoor air purifier", "White", "Winter"));
//     gh.addToInventory(new BonsaiTree("Mini Bonsai", 150.0, "Artistic indoor tree", "Green", "Autumn"));
//     gh.addToInventory(new WaterLily("Water Lily", 80.0, "Floating beauty", "Pink", "Summer"));
//     gh.addToInventory(new Mangrove("Mangrove", 120.0, "Coastal survivor", "Brown", "All"));

//     gh.displayAll();

//     std::cout << "\n--- End of program ---\n";
//     return 0;
// }

// #include <iostream>
// #include "Rose.h"
// #include "Jacka.h"
// #include "PeaceLily.h"
// #include "BonsaiTree.h"
// #include "Mangrove.h"
// #include "WaterLily.h"
// #include "Bundle.h"
// #include "ShoppingCart.h"
// #include "Customer.h"

// int main() {
//     std::cout << "=== Greenhouse Composite & Cart Test ===" << std::endl;

//     // --- Create some plants (no smart pointers) ---
//     Rose* rose = new Rose("Red Rose", 80.0, "A symbol of love.", "Red", "Spring");
//     Jacka* jacka = new Jacka("Jacka", 65.0, "Bright garden flower.", "Yellow", "Summer");
//     PeaceLily* peace = new PeaceLily("Peace Lily", 120.0, "Indoor air purifier.", "White", "Winter");
//     BonsaiTree* bonsai = new BonsaiTree("Bonsai Tree", 250.0, "Miniature tree for decor.", "Green", "Autumn");
//     Mangrove* mangrove = new Mangrove("Mangrove", 300.0, "Coastal water tree.", "Brown", "Spring");
//     WaterLily* waterLily = new WaterLily("Water Lily", 180.0, "Aquatic floating flower.", "Pink", "Summer");

//     std::cout << "\n--- Individual Plant Display ---\n";
//     rose->display();
//     jacka->display();
//     peace->display();
//     bonsai->display();
//     mangrove->display();
//     waterLily->display();

//     // --- Create a bundle (composite) ---
//     Bundle* indoorBundle = new Bundle("Indoor Collection");
//     indoorBundle->add(peace);
//     indoorBundle->add(bonsai);

//     Bundle* aquaticBundle = new Bundle("Aquatic Collection");
//     aquaticBundle->add(mangrove);
//     aquaticBundle->add(waterLily);

//     Bundle* collection = new Bundle("Full Greenhouse Collection");
//     collection->add(rose);
//     collection->add(jacka);
//     collection->add(indoorBundle);
//     collection->add(aquaticBundle);

//     std::cout << "\n--- Display Bundle Structure ---\n";
//     collection->display();

//       Mediator* med = nullptr;        // Assuming no mediator for testing
//     GreenHouse* gh = nullptr;       // Assuming no greenhouse for testing

//     // --- Create a customer and shopping cart ---
//     Customer* customer = new Customer(med, "John Doe", gh);
//     customer->getCart()->addItem(rose);
//     customer->getCart()->addItem(bonsai);
//     customer->getCart()->addItem(waterLily);

//     std::cout << "\n--- Cart Contents ---\n";
//     customer->getCart()->display();

//     std::cout << "\nRemoving 'Bonsai Tree' from cart...\n";
//     customer->getCart()->removePlant(bonsai->getUniqueID());

//     std::cout << "\n--- Updated Cart ---\n";
//     customer->getCart()->display();

//     // --- Cleanup ---
//     delete rose;
//     delete jacka;
//     delete peace;
//     delete bonsai;
//     delete mangrove;
//     delete waterLily;
//     delete indoorBundle;
//     delete aquaticBundle;
//     delete collection;
//     delete customer;

//     std::cout << "\n=== Test Complete ===\n";
//     return 0;
// }

// TestingMain.cpp
// Text UI for Pretoria Blooms (TUI)
// Assumes no smart pointers, as you requested.
#include "Rose.h"
#include "Jacka.h"
#include "Mangrove.h"
#include "WaterLily.h"
#include "BonsaiTree.h"
#include "PeaceLily.h"
#include "GreenHouse.h"
#include "AccessoriesStrategy.h"
#include "AdviceStrategy.h"
#include "AvailiabilityStrategy.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// Global cart
vector<PlantType*> cart;

// ANSI color codes
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

void animatePrint(const string& text, int ms = 30) {
    for(char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
    cout << endl;
}

// Populate greenhouse with plants
void populateGreenhouse(GreenHouse* greenhouse) {
    greenhouse->addToInventory(new Rose("Rose", 150.0, "A beautiful red rose.", "Red", "Spring"));
    greenhouse->addToInventory(new PeaceLily("Peace Lily", 180.0, "Elegant indoor plant with white blooms.", "Green", "Summer"));
    greenhouse->addToInventory(new BonsaiTree("Bonsai Tree", 250.0, "Miniature tree symbolizing harmony.", "Green", "All"));
    greenhouse->addToInventory(new WaterLily("Water Lily", 200.0, "Floating flower for ponds.", "Yellow", "Summer"));
    greenhouse->addToInventory(new Jacka("Jacka", 120.0, "Rare exotic plant that thrives in shade.", "Green", "Autumn"));
    greenhouse->addToInventory(new Mangrove("Mangrove", 300.0, "Coastal tree growing in salty water.", "Red", "Winter"));
}

// Display cart
void viewCart() {
    animatePrint("\n🪴 Your Cart:");
    if(cart.empty()) {
        animatePrint(RED "Your cart is empty! Add some plants first." RESET);
        return;
    }
    double subtotal = 0.0;
    int i = 1;
    for(auto* plant : cart) {
        cout << i++ << ". " << plant->getName() 
             << " - R" << fixed << setprecision(2) << plant->getPrice() << endl;
        subtotal += plant->getPrice();
    }
    cout << "---------------------------\n";
    cout << "Subtotal: R" << fixed << setprecision(2) << subtotal << "\n";
}

// Print receipt with colors and plant diagram
void printReceipt(double subtotal, double decorationsCharge) {
    double total = subtotal + decorationsCharge;

    animatePrint("\nPrinting out your slip...\n", 50);
    this_thread::sleep_for(chrono::milliseconds(800));

    cout << MAGENTA;
    cout << "╔══════════════════════════════════╗\n";
    cout << "║         🌸 Pretoria Blooms 🌸       ║\n";
    cout << "║     'Begin small, grow beyond'     ║\n";
    cout << "╚══════════════════════════════════╝\n";
    cout << RESET;

    cout << fixed << setprecision(2);
    cout << "Subtotal: R" << subtotal << "\n";
    cout << "Decorations surcharge: R" << decorationsCharge << "\n";
    cout << "Final total: R" << total << "\n\n";

    cout << "Confirm payment? (y/n): ";
    char confirm;
    cin >> confirm;

    if(confirm == 'y' || confirm == 'Y') {
        animatePrint("\nProcessing payment...\n", 40);
        this_thread::sleep_for(chrono::milliseconds(1000));
        animatePrint(GREEN "✅ Payment successful!" RESET);
        animatePrint("SalesStaff Sam: Purchase completed. Enjoy your plants!");
        animatePrint("GreenHouseStaff Greta: Purchase completed. Enjoy your plants!");
        cart.clear(); // empty cart
    } else {
        animatePrint(RED "❌ Payment cancelled." RESET);
    }
}

// Buy plants
void buyPlants(GreenHouse* greenhouse) {
    double subtotal = 0.0, decorationsCharge = 0.0;
    auto plants = greenhouse->getInventory();

    animatePrint("\nAvailable Plants:");
    for(size_t i = 0; i < plants.size(); ++i) {
        cout << i+1 << ". " << plants[i]->getName()
             << " | Price: R" << plants[i]->getPrice()
             << " | State: " << plants[i]->getStateAsString() << endl;
    }

    int choice;
    do {
        cout << "\nEnter plant number to add to cart (0 to finish): ";
        cin >> choice;
        if(choice >= 1 && choice <= (int)plants.size()) {
            PlantType* selected = plants[choice-1];
            cart.push_back(selected);
            subtotal += selected->getPrice();
            animatePrint(GREEN "Added " + selected->getName() + " to cart." RESET);
        } else if(choice != 0) {
            animatePrint(RED "Invalid selection." RESET);
        }
    } while(choice != 0);

    if(cart.empty()) {
        animatePrint(RED "No plants selected. Returning to main menu." RESET);
        return;
    }

    // Decorations
    char decoChoice;
    cout << "\nWould you like to add decorations? (y/n): ";
    cin >> decoChoice;
    while(decoChoice == 'y' || decoChoice == 'Y') {
        cout << "\nChoose decoration:\n";
        cout << "1. Pot (R20)\n2. GiftWrap (R15)\n3. Special Arrangement (R30)\n4. Exit\n";
        cout << "Enter choice (1-4): ";
        int deco; cin >> deco;
        if(deco == 4) break;
        switch(deco) {
            case 1: decorationsCharge += 20; break;
            case 2: decorationsCharge += 15; break;
            case 3: decorationsCharge += 30; break;
            default: animatePrint(RED "Invalid option." RESET); break;
        }
        cout << "Add more decorations? (y/n): ";
        cin >> decoChoice;
    }

    printReceipt(subtotal, decorationsCharge);
}

// Chat with team
void chatMenu(GreenHouse* greenhouse) {
    int option = 0;
    auto plants = greenhouse->getInventory();
    if(plants.empty()) {
        animatePrint(RED "No plants available to discuss." RESET);
        return;
    }

    do {
        animatePrint("\n=== 💬 Chat with the Team ===");
        cout << "1. Need advice on a plant\n2. Check availability\n3. Suggest accessories\n4. Exit\n";
        cout << "Select option: ";
        cin >> option;
        if(option == 4) break;

        cout << "\nSelect plant to discuss:\n";
        for(size_t i = 0; i < plants.size(); ++i)
            cout << i+1 << ". " << plants[i]->getName() << endl;
        int plantChoice; cin >> plantChoice;
        if(plantChoice < 1 || plantChoice > (int)plants.size()) {
            animatePrint(RED "Invalid choice." RESET);
            continue;
        }

        PlantType* selected = plants[plantChoice-1];
        InteractionStrategy* strategy = nullptr;
        switch(option) {
            case 1: strategy = new AdviceStrategy(); break;
            case 2: strategy = new AvailabilityStrategy(greenhouse); break;
            case 3: strategy = new AccessoriesStrategy(); break;
        }
        if(strategy) {
            animatePrint(BLUE "Greta is thinking..." RESET, 50);
            this_thread::sleep_for(chrono::milliseconds(500));
            strategy->execute(selected);
            delete strategy;
        }
    } while(option != 4);
}

int main() {
    animatePrint(MAGENTA "🌸 Welcome to Pretoria Blooms 🌸" RESET, 50);
    animatePrint("   'Begin small, grow beyond'", 50);
    animatePrint("Ready to shop for rooted treasures?\n", 50);

    GreenHouse* greenhouse = new GreenHouse();
    populateGreenhouse(greenhouse);

    int option;
    do {
        animatePrint("\n=== 🛒 Main Menu ===");
        cout << "1. View Collection\n2. View Cart\n3. Buy\n4. Chat to Team\n5. Exit\n";
        cout << "Select option: ";
        cin >> option;

        switch(option) {
            case 1: greenhouse->displayAll(); break;
            case 2: viewCart(); break;
            case 3: buyPlants(greenhouse); break;
            case 4: chatMenu(greenhouse); break;
            case 5: animatePrint(GREEN "\n🌿 Thank you for visiting us. Til next time!" RESET); break;
            default: animatePrint(RED "Invalid choice." RESET); break;
        }
    } while(option != 5);

    delete greenhouse;
    return 0;
}
