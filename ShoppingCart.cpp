#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    discountStrategy = NULL;
}

double ShoppingCart::applyDiscount() {
    if (discountStrategy) {
        return discountStrategy->applyDiscount(this);
    }
    return calculateSubtotal();
}

ShoppingCart::~ShoppingCart() {
    if(discountStrategy){
        delete discountStrategy;
    }
    
}

void ShoppingCart::setDiscountStrategy(DiscountStrategy* strategy) {
    if (discountStrategy) {
        delete discountStrategy;
    }
    discountStrategy = strategy;
}

double ShoppingCart::calculateSubtotal() {
    double subtotal = 0.0;
    for (size_t i = 0; i < items.size(); i++) {
        subtotal += items[i]->getPrice();
    }
    return subtotal;
}

std::vector<PlantType*> ShoppingCart::getItems() {
    return items;
}

bool ShoppingCart::isEmpty() {
    return items.empty();
}

size_t ShoppingCart::getItemCount() {
    return items.size();
}

void ShoppingCart::addItem(PlantType* plant) {
    items.push_back(plant);
}

void ShoppingCart::removeItem(PlantType* plant) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i] == plant) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void ShoppingCart::clear() {
    items.clear();
}

