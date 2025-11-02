#include "TextUI.h"
#include "Rose.h"
#include "Jacka.h"
#include "Mangrove.h"
#include "WaterLily.h"
#include "BonsaiTree.h"
#include "PeaceLily.h"
#include "FlowerFactory.h"
#include "TreeFactory.h"
#include "AccessoriesStrategy.h"
#include "AdviceStrategy.h"
#include "AvailiabilityStrategy.h"

#include <iostream>
#include <thread>
#include <chrono>

TextUI::TextUI() : greenhouse(nullptr), mediator(nullptr), 
                   currentCustomer(nullptr), salesStaff(nullptr), 
                   greenhouseStaff(nullptr) {
    initializeSystem();
}

TextUI::~TextUI() {
    cleanup();
}

void TextUI::initializeSystem() {
    // Create core system components
    greenhouse = new GreenHouse();
    mediator = new InteractionMediator();
    
    // Create staff WITH GreenHouse pointer for SalesStaff
    salesStaff = new SalesStaff(mediator, "Sam", greenhouse);
    greenhouseStaff = new GreenHouseStaff(mediator, "Greta");
    
    // Register staff with mediator
    mediator->addColleague(salesStaff, Role::SalesStaff);
    mediator->addColleague(greenhouseStaff, Role::GreenHouseStaff);
    
    // Create Customer
    currentCustomer = new Customer(mediator, "Guest", greenhouse);
    mediator->addColleague(currentCustomer, Role::Customer);
    
    // Populate inventory using Abstract Factory
    populateGreenhouse();
}

void TextUI::populateGreenhouse() {
    // Use Abstract Factory to create plants
    FlowerFactory flowerFactory;
    TreeFactory treeFactory;
    
    greenhouse->addToInventory(flowerFactory.createRose(150.0));
    greenhouse->addToInventory(flowerFactory.createPeaceLily(180.0));
    greenhouse->addToInventory(treeFactory.createBonsai(250.0));
    greenhouse->addToInventory(flowerFactory.createWaterLily(200.0));
    greenhouse->addToInventory(treeFactory.createJacarandaTree(120.0));
    greenhouse->addToInventory(treeFactory.createMangrove(300.0));
}

void TextUI::animatePrint(const std::string& text, int ms) {
    for(char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
    std::cout << std::endl;
}

void TextUI::run() {
    animatePrint(MAGENTA + "🌸 Welcome to Pretoria Blooms 🌸" + RESET, 50);
    animatePrint("   'Begin small, grow beyond'", 50);

    int option;
    do {
        animatePrint("\n=== 🛒 Main Menu ===");
        std::cout << "1. View Collection\n2. View Cart\n3. Purchase Plants\n";
        std::cout << "4. Remove from Cart\n5. Add Decorations\n6. Chat with Team\n";
        std::cout << "7. Staff Operations\n8. Exit\n";
        std::cout << "Select option: ";
        std::cin >> option;

        switch(option) {
            case 1: handleViewCollection(); break;
            case 2: handleViewCart(); break;
            case 3: handlePurchase(); break;
            case 4: handleRemoveFromCart(); break;
            case 5: handleAddDecorations(); break;
            case 6: handleChatWithTeam(); break;
            case 7: handleStaffOperations(); break;
            case 8: animatePrint(GREEN + "\n🌿 Thank you for visiting us. Till next time!" + RESET); break;
            default: animatePrint(RED + "Invalid choice." + RESET); break;
        }
    } while(option != 8);
}

void TextUI::handleViewCollection() {
    animatePrint("\n=== 🌱 Plant Collection ===");
    greenhouse->displayAll();
}

void TextUI::handleViewCart() {
    animatePrint("\n=== 🛒 Your Cart ===");
    currentCustomer->displayCart();
}

void TextUI::handlePurchase() {
    animatePrint("\n=== 💰 Purchase Plants ===");
    
    // Display available plants
    auto plants = greenhouse->getInventory();
    if(plants.empty()) {
        animatePrint(RED + "No plants available in inventory." + RESET);
        return;
    }
    
    for(size_t i = 0; i < plants.size(); ++i) {
        std::cout << i+1 << ". ";
        plants[i]->display();
    }
    
    std::cout << "Select plant to purchase (0 to cancel): ";
    int choice;
    std::cin >> choice;
    
    if(choice > 0 && choice <= (int)plants.size()) {
        PlantType* selected = plants[choice-1];
        
        // Use SalesStaff to check availability first
        salesStaff->checkPlantAvailability(selected);
        
        // Use Mediator to send command to SalesStaff
        PurchaseCommand* purchaseCmd = new PurchaseCommand(currentCustomer, selected);
        mediator->sendCommand(purchaseCmd, Role::SalesStaff);
        
        animatePrint(GREEN + "✅ Purchase command sent to sales staff!" + RESET);
        
        // Clean up command object
        delete purchaseCmd;
    }
}

void TextUI::handleRemoveFromCart() {
    animatePrint("\n=== 🗑️ Remove from Cart ===");
    currentCustomer->displayCart();
    
    auto cartItems = currentCustomer->getCart()->getItems();
    if(!cartItems.empty()) {
        // Use Mediator to send remove command to SalesStaff
        RemovePlantCommand* removeCmd = new RemovePlantCommand(currentCustomer, cartItems[0]);
        mediator->sendCommand(removeCmd, Role::SalesStaff);
        animatePrint(YELLOW + "➖ Remove command sent to sales staff!" + RESET);
        
        delete removeCmd;
    } else {
        animatePrint(RED + "Cart is empty!" + RESET);
    }
}

void TextUI::handleAddDecorations() {
    animatePrint("\n=== 🎀 Add Decorations ===");
    currentCustomer->displayCart();
    
    auto cartItems = currentCustomer->getCart()->getItems();
    if(cartItems.empty()) {
        animatePrint(RED + "Add plants to cart first!" + RESET);
        return;
    }
    
    std::cout << "Select decoration type:\n";
    std::cout << "1. Pot\n2. Gift Wrap\n3. Special Arrangement\n";
    std::cout << "Choice: ";
    int decorChoice;
    std::cin >> decorChoice;
    
    std::string decorType, message, occasion;
    switch(decorChoice) {
        case 1: 
            decorType = "Pot";
            message = "Beautiful decorative pot";
            break;
        case 2: 
            decorType = "GiftWrap";
            message = "Elegant gift wrapping";
            break;
        case 3: 
            decorType = "SpecialArrangement";
            message = "Special occasion arrangement";
            occasion = "Congratulations";
            break;
        default: 
            animatePrint(RED + "Invalid choice." + RESET);
            return;
    }
    
    // Use Mediator to send decoration command to SalesStaff
    AddDecorationCommand* decorCmd = new AddDecorationCommand(
        salesStaff, cartItems[0], decorType, message, occasion
    );
    mediator->sendCommand(decorCmd, Role::SalesStaff);
    animatePrint(BLUE + "🎀 Decoration command sent to sales staff!" + RESET);
    
    delete decorCmd;
}

void TextUI::handleChatWithTeam() {
    animatePrint("\n=== 💬 Chat with Team ===");
    
    auto plants = greenhouse->getInventory();
    if(plants.empty()) {
        animatePrint(RED + "No plants available to discuss." + RESET);
        return;
    }
    
    // Display plants
    for(size_t i = 0; i < plants.size(); ++i) {
        std::cout << i+1 << ". " << plants[i]->getName() << std::endl;
    }
    
    std::cout << "Select plant to discuss: ";
    int plantChoice;
    std::cin >> plantChoice;
    
    if(plantChoice < 1 || plantChoice > (int)plants.size()) {
        animatePrint(RED + "Invalid choice." + RESET);
        return;
    }
    
    PlantType* selected = plants[plantChoice-1];
    
    std::cout << "Choose interaction:\n";
    std::cout << "1. Get Care Advice\n2. Check Availability\n3. Get Accessory Suggestions\n";
    std::cout << "Choice: ";
    int interactionChoice;
    std::cin >> interactionChoice;
    
    // Send message through mediator - will be routed to appropriate staff
    std::string message;
    switch(interactionChoice) {
        case 1: 
            message = "REQUEST_ADVICE for " + selected->getName();
            currentCustomer->sendMessage(message);
            break;
        case 2: 
            message = "CHECK_AVAILABILITY for " + selected->getName();
            currentCustomer->sendMessage(message);
            break;
        case 3: 
            message = "SUGGEST_ACCESSORIES for " + selected->getName();
            currentCustomer->sendMessage(message);
            break;
        default:
            animatePrint(RED + "Invalid choice." + RESET);
            return;
    }
    
    animatePrint(YELLOW + "💬 Message sent to team!" + RESET);
}

void TextUI::handleStaffOperations() {
    animatePrint("\n=== 👥 Staff Operations ===");
    
    auto plants = greenhouse->getInventory();
    if(plants.empty()) {
        animatePrint(RED + "No plants available for care." + RESET);
        return;
    }
    
    std::cout << "1. Water Plants\n2. Display All Plants\n";
    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;
    
    if(choice == 1) {
        // Use Mediator to send watering command to GreenHouseStaff
        WaterPlantCommand* waterCmd = new WaterPlantCommand(greenhouseStaff, plants[0]);
        mediator->sendCommand(waterCmd, Role::GreenHouseStaff);
        animatePrint(BLUE + "💧 Watering command sent to greenhouse staff!" + RESET);
        
        delete waterCmd;
    } else if(choice == 2) {
        greenhouse->displayAll();
    }
}

void TextUI::cleanup() {
    delete currentCustomer;
    delete salesStaff;
    delete greenhouseStaff;
    delete mediator;
    delete greenhouse;
}