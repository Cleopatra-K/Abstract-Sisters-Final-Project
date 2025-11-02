#include "ShoppingCart.h"
#include "PlantType.h"
#include "DiscountStrategy.h"
#include <algorithm>

ShoppingCart::ShoppingCart()
    : discountStrategy(nullptr) {}

ShoppingCart::~ShoppingCart() {
    // Context does not own PlantType* (Customer does)
    // But we do own the strategy
    if (discountStrategy) {
        delete discountStrategy;
        discountStrategy = nullptr;
    }
}

void ShoppingCart::setDiscountStrategy(DiscountStrategy* strategy) {
    // Replace existing strategy without deleting (could be managed externally)
    discountStrategy = strategy;
}

double ShoppingCart::calculateSubtotal() {
    double subtotal = 0.0;
    for (auto* plant : items) {
        subtotal += plant->getPrice();
    }
    return subtotal;
}

double ShoppingCart::applyDiscount() {
    if (discountStrategy){
        return discountStrategy->applyDiscount(this);
    }
    return calculateSubtotal();
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
    if (plant)
        items.push_back(plant);
}

void ShoppingCart::removeItem(PlantType* plant) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i] == plant) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void ShoppingCart::removePlant(const std::string& plantID) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i]->getUniqueID() == plantID) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void ShoppingCart::clear() {
    items.clear();  // Customer owns PlantType*, so we don’t delete them
}

void ShoppingCart::display() const {
    if (items.empty()) {
        std::cout << "🛒 Shopping cart is empty.\n";
        return;
    }

    std::cout << "\n=== Shopping Cart Contents ===\n";
    double subtotal = 0.0;

    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". ";
        items[i]->display();
        subtotal += items[i]->getPrice();
    }

    std::cout << "---------------------------------\n";
    std::cout << "Subtotal: R" << subtotal << "\n";

    // Apply discount strategy if one is set
    double finalTotal = subtotal;
    if (discountStrategy) {
        finalTotal = discountStrategy->applyDiscount(const_cast<ShoppingCart*>(this));
        std::cout << "Discount applied via strategy.\n";
    }

    std::cout << "Final Total: R" << finalTotal << "\n";
}
