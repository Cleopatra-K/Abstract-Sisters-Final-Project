#include "BulkDiscount.h"
#include "ShoppingCart.h"
#include <sstream>

BulkDiscount::BulkDiscount(int minItems, double discount){
    minItemCount = minItems;
    discountPercentage = discount;
}

double BulkDiscount::applyDiscount(ShoppingCart* cart) {
    if (cart->getItemCount() >= static_cast<size_t>(minItemCount)) {
        double subtotal = cart->calculateSubtotal();
        return subtotal * (1 - discountPercentage);
    }
    return cart->calculateSubtotal(); 
}

std::string BulkDiscount::getDescription() {
    std::stringstream description;
    description << "Bulk Discount - " << (discountPercentage * 100) << "% off on orders of " << minItemCount << " or more items";
    return description.str();
}

int BulkDiscount::getMinItemCount(){
    return minItemCount;
}

double BulkDiscount::getDiscountPercentage(){
    return discountPercentage;
}