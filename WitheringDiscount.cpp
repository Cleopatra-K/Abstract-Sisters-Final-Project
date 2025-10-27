#include "WitheringDiscount.h"
#include "ShoppingCart.h"
#include "PlantType.h"
#include <sstream>

WitheringDiscountStrategy::WitheringDiscountStrategy(double discount){
    discountPercentage=discount;
}

double WitheringDiscountStrategy::applyDiscount(ShoppingCart* cart) {
    double subtotal = cart->calculateSubtotal();
    double discountAmount = 0.0;
    
    std::vector<PlantType*> items = cart->getItems();
    for (size_t i = 0; i < items.size(); i++) {
        PlantType* plant = items[i];
        if (isPlantWithering(plant)) {
            discountAmount += plant->getPrice() * discountPercentage;
        }
    }
    
    return subtotal - discountAmount;
}

std::string WitheringDiscountStrategy::getDescription() {
    std::stringstream description;

    description << "Withering Plant Discount - " << (discountPercentage * 100) << "% off on plants in withering state";
    return description.str();
}

double WitheringDiscountStrategy::getDiscountPercentage(){
    return discountPercentage;
}

bool WitheringDiscountStrategy::isPlantWithering(PlantType* plant){
    // Call getStateName() on the plant's current state
    return plant->getStateAsString() == "Withering";
}