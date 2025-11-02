#ifndef TEXTUI_H
#define TEXTUI_H

#include "GreenHouse.h"
#include "InteractionMediator.h"
#include "Customer.h"
#include "SalesStaff.h"
#include "GreenHouseStaff.h"
#include "Command.h"
#include <string>

class TextUI {
private:
    GreenHouse* greenhouse;
    InteractionMediator* mediator;
    Customer* currentCustomer;
    SalesStaff* salesStaff;
    GreenHouseStaff* greenhouseStaff;
    
    // ANSI color codes
    const std::string GREEN = "\033[32m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string RESET = "\033[0m";

    void animatePrint(const std::string& text, int ms = 30);
    void populateGreenhouse();
    void initializeSystem();
    void cleanup();

public:
    TextUI();
    ~TextUI();
    void run();

private:
    // Menu handlers that use your patterns
    void handleViewCollection();
    void handleViewCart();
    void handlePurchase();
    void handleRemoveFromCart();
    void handleChatWithTeam();
    void handleStaffOperations();
    void handleAddDecorations();
};

#endif