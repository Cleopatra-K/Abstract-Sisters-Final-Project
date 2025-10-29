/**
 * @file Customer.h
 * @brief Customer class that owns and maintains ShoppingCart as Strategy Context
 * 
 * The Customer manages plant ownership and cart operations while integrating with the GreenHouse inventory system. When plants are added to the cart, they are
 * removed from inventory. If purchase is abandoned, plants are returned to inventory.
 * 
 * The ShoppingCart serves as the Context in the Strategy pattern for discount calculations.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Colleague.h"
#include "ShoppingCart.h"  // This is the Strategy Context

// Forward declarations
class PlantType;
class GreenHouse;

/**
 * @class Customer
 * @brief Owns and maintains ShoppingCart as Strategy Context
 * 
 * The Customer acts as the owner of plants and the client to the Strategy pattern by using the ShoppingCart, which serves as the actual Context in the Strategy
 * design pattern for discount processing.
 * 
 * The ShoppingCart has a composition relationship with Customer - it cannot exist without a Customer and its lifecycle is tied to the Customer's lifecycle.
 * 
 * @note When plants are added to the cart, they are removed from GreenHouse inventory.
 * If the customer abandons the purchase, plants are automatically returned to inventory.
 */
class Customer : public Colleague {
private:
    ShoppingCart* cart;  ///< The Strategy Context for discount strategies (composition)
    std::vector<PlantType*> ownedPlants; ///< Plants currently owned by this customer
    std::string name;

    /**
     * @brief Returns all plants in cart back to GreenHouse inventory
     * @note Used when customer abandons purchase or clears cart
     */
    void returnPlantsToInventory();
    
    /**
     * @brief Processes payment for the purchase
     * @param amount The amount to charge after discounts are applied
     */
    void processPayment(double amount);

public:
    /**
     * @brief Constructs a Customer with a new ShoppingCart
     */
    Customer();
    
    /**
     * @brief Destructor - cleans up owned ShoppingCart and returns plants to inventory if needed
     */
    ~Customer();
    
    /**
     * @brief Gets the customer's shopping cart (Strategy Context)
     * 
     * @return Pointer to the ShoppingCart context for discount strategy operations
     */
    ShoppingCart* getCart();
    
    /**
     * @brief Adds a plant to the shopping cart and removes it from inventory
     * 
     * The plant is removed from GreenHouse inventory and added to the customer's
     * owned plants list and shopping cart.
     * 
     * @param plant Plant to add to cart
     */
    void addToCart(PlantType* plant);
    
    /**
     * @brief Removes a plant from the shopping cart and returns it to inventory
     * 
     * The plant is removed from both the cart and the customer's owned plants list,
     * and returned to the GreenHouse inventory.
     * 
     * @param plant Plant to remove from cart
     */
    void removeFromCart(PlantType* plant);
    
    /**
     * @brief Clears all items from the shopping cart and returns them to inventory
     * 
     * All plants in the cart are returned to GreenHouse inventory and the cart
     * is emptied. This is used when a customer abandons their purchase.
     */
    void clearCart();
    
    /**
     * @brief Checks if the shopping cart is empty
     * 
     * @return true if cart is empty, false otherwise
     */
    bool isCartEmpty();

    /**
     * @brief Purchases cart contents - applies discount strategy and processes payment
     * 
     * This method applies the current discount strategy to calculate the final price, processes the payment, and completes the purchase. Plants are permanently
     * transferred to the customer and not returned to inventory.
     * 
     * @note The discount strategy is applied through the ShoppingCart context
     */
    void purchaseCart();

    void receiveMessage(const std::string& message);

    std::string getName();
};

#endif