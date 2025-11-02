/**
 * @file BulkDiscount.h
 * @brief Concrete strategy for bulk purchase discounts
 */

#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "DiscountStrategy.h"

// Forward declaration
class ShoppingCart;

/**
 * @class BulkDiscountStrategy
 * @brief Concrete strategy that applies discounts based on cart contents
 * 
 * This strategy applies discounts when the customer purchases in bulk.
 * It checks the ShoppingCart's item count and applies discount if the minimum item threshold is met.
 * 
 */
class BulkDiscount: public DiscountStrategy {
private:
    int minItemCount;          ///< Minimum items required for discount
    double discountPercentage; ///< Discount percentage (e.g., 0.1 for 10%)

public:
    /**
     * @brief Constructs a bulk discount based on item count
     * 
     * @param minItems Minimum number of items required for discount
     * @param discount Percent discount (e.g., 0.15 for 15% off)
     */
    BulkDiscount(int minItems, double discount);
    
    /**
     * @brief Applies bulk discount to the cart
     * 
     * Checks if the cart meets the bulk requirements by item count
     * and applies the discount if conditions are met.
     * 
     * @param cart The shopping cart to evaluate for bulk discount
     * @return Discounted price if conditions met, original price otherwise
     */
    double applyDiscount(ShoppingCart* cart);
    
    /**
     * @brief Gets description of the bulk discount
     * 
     * @return String describing the bulk discount conditions
     */
    std::string getDescription();
    
    /**
     * @brief Gets the minimum item count required for discount
     * 
     * @return Minimum item count
     */
    int getMinItemCount();
    
    /**
     * @brief Gets the discount percentage
     * 
     * @return Discount percentage (e.g., 0.1 for 10%)
     */
    double getDiscountPercentage();
};

#endif 