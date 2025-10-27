/**
 * @file DiscountStrategy.h
 * @brief Abstract base class for discount strategies in Strategy pattern
 */

#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include <string>
class ShoppingCart;

/**
 * @class DiscountStrategy
 * @brief Strategy interface in Strategy pattern for discount algorithms
 * 
 * The Strategy pattern allows the ShoppingCart (Context) to delegate
 * discount calculations to different algorithms interchangeably.
 */

class DiscountStrategy {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~DiscountStrategy(){};
    
    /**
     * @brief Applies discount algorithm to the shopping cart
     * 
     * This is the execute()
     * 
     * @param cart The shopping cart containing plants to evaluate
     * @return The discounted total price
     */
    virtual double applyDiscount(const ShoppingCart* cart) = 0;
    
    /**
     * @brief Gets a description of the discount strategy
     * 
     * Useful for displaying which discount is applied to the user.
     * @return String describing the discount strategy
     */
    virtual std::string getDescription() = 0;
};

#endif