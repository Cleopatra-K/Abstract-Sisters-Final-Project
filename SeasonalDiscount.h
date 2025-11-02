/**
 * @file SeasonalDiscount.h
 * @brief Concrete strategy for seasonal discounts
 */

#ifndef SEASONALDISCOUNT_H
#define SEASONALDISCOUNT_H

#include "DiscountStrategy.h"
#include <string>
#include <vector>

// Forward declaration
class ShoppingCart;
class PlantType;

/**
 * @class SeasonalDiscountStrategy
 * @brief Concrete strategy that applies seasonal discounts to specific plants
 * 
 * This strategy applies discounts based on seasonal promotions to specific 
 * plant types only. It checks each plant in the cart and applies discount only to eligible plant types.
 */
class SeasonalDiscount : public DiscountStrategy {
private:
    std::string currentSeason;          ///< Season name (e.g., "Spring", "Summer")
    double discountPercentage;   ///< Discount percentage (e.g., 0.15 for 15%)
    //std::vector<std::string> eligiblePlantTypes; ///< Plant types eligible for discount

    /**
     * @brief Checks if a specific plant is eligible for discount
     * 
     * @param plant The plant to check
     * @return true if plant is eligible, false otherwise
     */
    bool isPlantInSeason(PlantType* plant);

public:
    /**
     * @brief Constructs a seasonal discount for specific plant types
     * 
     * @param seasonName Name of the season for this discount
     * @param discount Percent discount (e.g., 0.15 for 15% off)
     * @param plantTypes Vector of plant types eligible for discount
     */
    SeasonalDiscount(std::string& seasonName, double discount);
    
    /**
     * @brief Applies seasonal discount to eligible plants in the cart
     * 
     * Applies discount only to eligible plant types in the cart.
     * Plants not in the eligible list remain at full price.
     * 
     * @param cart The shopping cart containing plants to evaluate
     * @return Discounted price after applying seasonal discount to eligible plants
     */
    double applyDiscount(ShoppingCart* cart);
    
    /**
     * @brief Gets description of the seasonal discount
     * 
     * @return String describing the seasonal discount and eligible plants
     */
    std::string getDescription();
    
    /**
     * @brief Gets the season name
     * 
     * @return Season name
     */
    std::string getSeason();
    
    /**
     * @brief Gets the discount percentage
     * 
     * @return Discount percentage (e.g., 0.1 for 10%)
     */
    double getDiscountPercentage();
    
    // /**
    //  * @brief Gets all eligible plant types
    //  * 
    //  * @return Vector of eligible plant type names
    //  */
    // std::vector<std::string> getEligiblePlantTypes();
};

#endif 