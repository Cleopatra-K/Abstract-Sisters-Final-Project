/**
 * @file ShoppingCart.h
 * @brief ShoppingCart class as Context in Strategy pattern
 */

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "DiscountStrategy.h"
#include "PlantType.h"

// Forward declaration
class PlantType;

/**
 * @class ShoppingCart
 * @brief Context class in Strategy pattern for discount calculation
 * 
 * @note Item management is handled by the Customer class through composition. This class focuses solely on price calculations
 * and strategy delegation.
 */
class ShoppingCart {
private:
    std::vector<PlantType*> items;  ///< Plants/Bundles in cart (non-owning pointers) (managed by Customer)
    DiscountStrategy* discountStrategy;  ///< Current discount strategy

public:
    /**
     * @brief Constructs a ShoppingCart with default discount strategy
     */
    ShoppingCart();
    
    /**
     * @brief Destructor - cleans up strategy
     */
    ~ShoppingCart();
    
    /**
     * @brief Executes the discount strategy algorithm, this is like the execute()
     */
    double applyDiscount();

    /**
     * @brief Sets the discount strategy dynamically
     * 
     * @param strategy Pointer to the new DiscountStrategy implementation
     */
    void setDiscountStrategy(DiscountStrategy* strategy);
    
    /**
     * @brief Calculates subtotal without discount
     * 
     * @return Subtotal before any discounts
     */
    double calculateSubtotal();
        
    /**
     * @brief Gets all items in the cart
     * 
     * @return Vector of plants in cart
     */
    std::vector<PlantType*> getItems();
    
    /**
     * @brief Checks if cart is empty
     * 
     * @return true if cart is empty, false otherwise
     */
    bool isEmpty();
    
    /**
     * @brief Gets number of items in cart
     * 
     * @return Number of items
     */
    size_t getItemCount();
    

    /**
     * @brief Adds a plant or bundle to the cart (internal use by Customer)
     * 
     * ShoppingCart does NOT take ownership - Customer remains owner.
     * Customer::addToCart() calls this method.
     * 
     * @param plant Plant or Bundle to add (non-owning pointer)
     */
    void addItem(PlantType* plant);

    /**
     * @brief Removes a plant from the cart (internal use by Customer)
     * Customer::removeFromCart() calls this method.
     * 
     * @param plant Plant to remove
     */
    void removeItem(PlantType* plant);

    /**
     * @brief Clears all items from the cart (internal use by Customer)
     * 
     * Note: Does not delete the plants - just clears references
     * Customer::clearCart() calls this method.
     */
    void clear();
};

#endif