#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <vector>
#include "PlantType.h"
#include "Aggregate.h"

class PlantIterator;

/**
 * @class GreenHouse
 * @brief Singleton class that manages plant inventory using the Singleton design pattern
 * 
 * The GreenHouse class ensures only one instance exists throughout the application
 * and provides centralized management of plant inventory.
 */
class GreenHouse: public Aggregate{
private:
    std::vector<PlantType*> inventory;  ///< Collection of plants in the inventory
    static GreenHouse* instance;        ///< Static instance for Singleton pattern

    /**
     * @brief Private constructor to prevent external instantiation
     * 
     * The constructor is private to enforce the Singleton pattern and ensure
     * that only one instance of GreenHouse can be created through getInstance().
     */
    GreenHouse() = default;

public:
    /**
     * @brief Gets the singleton instance of GreenHouse
     * 
     * Implements lazy initialization - the instance is created on first call.
     * This method provides global access to the single GreenHouse instance.
     * 
     * @return Pointer to the singleton GreenHouse instance
     * 
     * @note This method is not thread-safe. In multithreaded environments,
     *       additional synchronization mechanisms would be required.
     */
    static GreenHouse* getInstance();
    
    /**
     * @brief Deleted copy constructor to prevent copying
     * 
     * Prevents the creation of copies of the singleton instance, which would
     * violate the Singleton pattern's single instance guarantee.
     */
    GreenHouse(const GreenHouse&) = delete;
    
    /**
     * @brief Deleted assignment operator to prevent assignment
     * 
     * Prevents assignment of the singleton instance, maintaining the
     * single instance guarantee of the Singleton pattern.
     */
    GreenHouse& operator=(const GreenHouse&) = delete;
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper destruction of derived classes if the Singleton pattern
     * is extended through inheritance in the future.
     */
    virtual ~GreenHouse() = default;
    
    /**
     * @brief Adds a plant to the inventory
     * 
     * Stores a plant in the greenhouse inventory. The plant is added to the
     * internal collection and becomes available for other operations.
     * 
     * @param plant Pointer to the PlantType object to add to inventory
     * 
     * @pre plant != nullptr
     * @post inventory.size() increases by 1
     * @post plant is contained in the inventory
     */
    void addToInventory(PlantType* plant);
    
    /**
     * @brief Removes a plant from the inventory
     * 
     * Searches for and removes the specified plant from the inventory.
     * If the plant is not found, no action is taken.
     * 
     * @param plant Pointer to the PlantType object to remove from inventory
     * 
     * @pre plant != nullptr
     * @post If plant was in inventory, inventory.size() decreases by 1
     * @post plant is no longer contained in the inventory
     */
    void removeFromInventory(PlantType* plant);
    
    /**
     * @brief Gets the current inventory
     * 
     * Returns a copy of the current inventory vector. This provides read-only
     * access to the inventory contents without exposing the internal storage.
     * 
     * @return std::vector<PlantType*> containing all plants in inventory
     * 
     * @note The returned vector is a copy, so modifications to it won't affect
     *       the actual inventory. Use add/remove methods to modify inventory.
     */
    std::vector<PlantType*> getInventory();
    
    /**
     * @brief Checks if a specific plant is available in inventory
     * 
     * Searches the inventory for the specified plant and returns whether
     * it is currently available.
     * 
     * @param plant Pointer to the PlantType object to search for
     * @return true if the plant is found in inventory, false otherwise
     * 
     * @pre plant != nullptr
     */
    bool isPlantAvailable(PlantType* plant);
};

#endif