#include "Customer.h"
#include <iostream>

Customer::Customer(Mediator* med, const std::string& n, GreenHouse* gh)
    : Colleague(med, n), greenhouse(gh)
{
    cart = new ShoppingCart();
}

Customer::~Customer() {
    if (!ownedPlants.empty()) {
        returnPlantsToInventory();
    }
    delete cart;
}

ShoppingCart* Customer::getCart() { return cart; }

void Customer::addToCart(PlantType* plant) {
    if (greenhouse && greenhouse->isPlantAvailable(plant)) {
        greenhouse->removeFromInventory(plant);
        ownedPlants.push_back(plant);
        cart->addItem(plant);
        sendMessage("Added plant to cart.");  // <-- now works
    } else {
        std::cout << "Plant not available in inventory!" << std::endl;
    }
}

void Customer::removeFromCart(PlantType* plant) {
    cart->removeItem(plant);
    for (size_t i = 0; i < ownedPlants.size(); i++) {
        if (ownedPlants[i] == plant) {
            if (greenhouse) {
                greenhouse->addToInventory(plant);
            }
            ownedPlants.erase(ownedPlants.begin() + i);
            sendMessage("Item removed successfully.");  // <-- works now
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
        ownedPlants.clear();
        cart->clear();
        sendMessage("Purchase completed! Final price: R" + std::to_string(finalPrice));
    } else {
        sendMessage("Cart is empty. Nothing to purchase.");
    }
}

void Customer::returnPlantsToInventory() {
    if (!greenhouse) return;
    for (auto* plant : ownedPlants) {
        greenhouse->addToInventory(plant);
    }
    ownedPlants.clear();
}

void Customer::processPayment(double amount) {
    std::cout << "Processing payment of R" << amount << std::endl;
}

std::string Customer::getName() {
    return name;
}

void Customer::receiveMessage(const std::string& message) {
    std::cout << "Customer received message: " << message << std::endl;
}

void Customer::displayCart() {
    std::cout << "\nCustomer: " << getName() << std::endl;
    cart->display();
}
