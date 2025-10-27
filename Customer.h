/**
 * @file Customer.h
 * @brief Customer class that owns and maintains ShoppingCart as Strategy Context
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Colleague.h"
#include "ShoppingCart.h"  // This is the Strategy Context

// Forward declaration
class PlantType;

/**
 * @class Customer
 * @brief Owns and maintains ShoppingCart as Strategy Context
 * 
 * The Customer acts as a client to the Strategy pattern by owning and using the ShoppingCart, which serves as the actual Context in the Strategy design pattern for payment processing.
 * 
 * The ShoppingCart has a composition relationship with Customer - it cannot exist without a Customer and its lifecycle is tied to the Customer's lifecycle.
 */
class Customer : public Colleague {
private:
    ShoppingCart* cart;  ///< The Strategy Context for payment strategies (composition)
    std::vector<PlantType*> ownedPlants; ///< Plants owned by this customer

public:
    /**
     * @brief Constructs a Customer with a new ShoppingCart
     */
    Customer();
    
    /**
     * @brief Destructor - cleans up the owned ShoppingCart
     */
    ~Customer();
    
    /**
     * @brief Gets the customer's shopping cart (Strategy Context)
     * 
     * @return Pointer to the ShoppingCart context
     */
    ShoppingCart* getCart() const;
    
    /**
     * @brief Adds a plant to the shopping cart
     * 
     * @param plant Plant to add to cart
     */
    void addToCart(PlantType* plant);
    
    /**
     * @brief Removes a plant from the shopping cart
     * 
     * @param plant Plant to remove from cart
     */
    void removeFromCart(PlantType* plant);
    
    /**
     * @brief Clears all items from the shopping cart
     */
    void clearCart();
    
    /**
     * @brief Checks if the shopping cart is empty
     * 
     * @return true if cart is empty, false otherwise
     */
    bool isCartEmpty() const;

    /**
     * @brief Purchases cart contents - transfers ownership elsewhere
     */
    void purchaseCart();
};

#endif