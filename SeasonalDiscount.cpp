#include "SeasonalDiscount.h"
#include "ShoppingCart.h"
#include "PlantType.h"
#include <sstream>

SeasonalDiscount::SeasonalDiscount(const std::string& season, double discount){
    currentSeason = season;
    discountPercentage = discount;
}


double SeasonalDiscount::applyDiscount(ShoppingCart* cart) {
    double subtotal = cart->calculateSubtotal();
    double discountAmount = 0.0;
    
    std::vector<PlantType*> items = cart->getItems();
    for (size_t i = 0; i < items.size(); i++) {
        PlantType* plant = items[i];
        if (isPlantInSeason(plant)) {
            discountAmount += plant->getPrice() * discountPercentage;
        }
    }
    
    return subtotal - discountAmount;
}

std::string SeasonalDiscount::getDescription() {
    std::stringstream description;
    description << currentSeason << " Season Sale - " << (discountPercentage * 100) << "% off on seasonal plants";
    return description.str();
}

double SeasonalDiscount::getDiscountPercentage(){
    return discountPercentage;
}

std::string SeasonalDiscount::getSeason(){
    return currentSeason;
}

bool SeasonalDiscount::isPlantInSeason(PlantType* plant){   
    return plant->getSeason() == currentSeason;   
}