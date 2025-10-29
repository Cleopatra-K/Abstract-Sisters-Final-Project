/**
 * @file Customer.cpp
 * @brief Customer class that owns and maintains ShoppingCart as Strategy Context
 */

#include "Customer.h"
#include "GreenHouse.h"

Customer::Customer() {
    cart = new ShoppingCart();
}

Customer::~Customer() {
    // If customer is destroyed without purchasing, return plants to inventory
    if (!ownedPlants.empty()) {
        returnPlantsToInventory();
    }
    delete cart;
}

ShoppingCart* Customer::getCart() {
    return cart;
}

void Customer::addToCart(PlantType* plant) {
    GreenHouse::getInstance()->removeFromInventory(plant);
    
    ownedPlants.push_back(plant);
    cart->addItem(plant);
}

void Customer::removeFromCart(PlantType* plant) {
    cart->removeItem(plant);
    
    for (size_t i = 0; i < ownedPlants.size(); i++) {
        if (ownedPlants[i] == plant) {
            GreenHouse::getInstance()->addToInventory(plant);
            ownedPlants.erase(ownedPlants.begin() + i);
            break;
        }
    }
}

void Customer::clearCart() {
    returnPlantsToInventory();
    
    cart->clear();
}

bool Customer::isCartEmpty() {
    return cart->isEmpty();
}

void Customer::purchaseCart() {
    if (!cart->isEmpty()) {
        double finalPrice = cart->applyDiscount();
        
        processPayment(finalPrice);
        
        ownedPlants.clear(); //Customer keeps ownership until system disposal
        cart->clear();
        
        std::cout << "Purchase completed! Final price: $" << finalPrice << std::endl;
    } else {
        std::cout << "Cart is empty. Nothing to purchase." << std::endl;
    }
}

void Customer::returnPlantsToInventory() {
    for (size_t i = 0; i < ownedPlants.size(); i++) {
        GreenHouse::getInstance()->addToInventory(ownedPlants[i]);
    }
    ownedPlants.clear();
}


void Customer::processPayment(double amount) {
    std::cout << "Processing payment of R" << amount << std::endl;
}

std::string Customer::getName(){
    return name;
}

void receiveMessage(const std::string& message){
    (void)message;
}
