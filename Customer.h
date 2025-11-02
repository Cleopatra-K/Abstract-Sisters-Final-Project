#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include "ShoppingCart.h"
#include "PlantType.h"
#include "GreenHouse.h"
#include "Colleague.h"

class Customer : public Colleague {   // <-- inherit from Colleague
private:
    ShoppingCart* cart;
    std::vector<PlantType*> ownedPlants;
    GreenHouse* greenhouse; // reference to GreenHouse

public:
    // Pass mediator and name to Colleague
    Customer(Mediator* med, const std::string& n, GreenHouse* gh);
    ~Customer();

    ShoppingCart* getCart();
    void addToCart(PlantType* plant);
    void removeFromCart(PlantType* plant);
    void clearCart();
    bool isCartEmpty();
    void purchaseCart();
    
    void displayCart();
    std::string getName() override;
    void receiveMessage(const std::string& message) override;
    void processPayment(double amount);

private:
    void returnPlantsToInventory();
};

#endif
