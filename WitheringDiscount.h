/**
 * @file WitheringDiscount.h
 * @brief Concrete strategy for discounts on withering plants
 */

#ifndef WITHERINGDISCOUNT_H
#define WITHERINGDISCOUNT_H

#include "DiscountStrategy.h"
#include "PlantState.h"
#include <string>

// Forward declarations
class ShoppingCart;
class PlantType;

/**
 * @class WitheringDiscountStrategy
 * @brief Concrete strategy that applies discounts to withering plants
 */
class WitheringDiscountStrategy : public DiscountStrategy {
private:
    double discountPercentage;   ///< Discount percentage 

public:
    /**
     * @brief Constructs a withering discount strategy
     * 
     * @param discount Percent discount (e.g., 0.25 for 25% off)
     */
    WitheringDiscountStrategy(double discount);
    
    /**
     * @brief Applies withering discount to eligible plants in cart
     * 
     * Checks each plant's current state by calling PlantState::getStateName() 
     * and applies discount only to plants where getStateName() returns "Withering".
     * 
     * @param cart The shopping cart containing plants to evaluate
     * @return Discounted price after applying withering discounts
     */
    double applyDiscount(ShoppingCart* cart);
    
    /**
     * @brief Gets description of the withering discount
     * 
     * @return String describing the withering discount conditions
     */
    std::string getDescription();
    
    /**
     * @brief Gets the discount percentage
     * 
     * @return Discount percentage (e.g., 0.3 for 30%)
     */
    double getDiscountPercentage();
    
    /**
     * @brief Checks if a plant qualifies for withering discount
     * 
     * Specifically calls PlantState::getStateName() on the plant's current state and returns true if the state name equals "Withering".
     * 
     * @param plant The plant to check using its current state
     * @return true if PlantState::getStateName() returns "Withering", false otherwise
     */
    bool isPlantWithering(PlantType* plant);
};

#endif