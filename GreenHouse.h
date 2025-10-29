// #ifndef GREENHOUSE_H
// #define GREENHOUSE_H

// #include <vector>
// #include <string>
// #include <iostream>
// #include "Aggregate.h"
// #include "Iterator.h"
// #include "PlantType.h"

// /**
//  * @class GreenHouse
//  * @brief Singleton class that manages plant inventory using the Singleton design pattern.
//  *
//  * The GreenHouse class ensures only one instance exists throughout the application
//  * and provides centralized management of plant inventory.
//  * Implements the Aggregate interface to allow creation of iterators for traversal.
//  */
// class GreenHouse : public Aggregate {
// private:
//     std::vector<PlantType*> inventory;   ///< Collection of plants in the inventory
//     static GreenHouse* instance;         ///< Static instance for Singleton pattern

//     /**
//      * @brief Private constructor to prevent external instantiation.
//      *
//      * The constructor is private to enforce the Singleton pattern and ensure
//      * that only one instance of GreenHouse can be created through getInstance().
//      */
//     GreenHouse() = default;

// public:
//     /**
//      * @brief Gets the singleton instance of GreenHouse.
//      *
//      * Implements lazy initialization — the instance is created on first call.
//      * This method provides global access to the single GreenHouse instance.
//      *
//      * @return Pointer to the singleton GreenHouse instance.
//      *
//      * @note This method is not thread-safe. In multithreaded environments,
//      *       additional synchronization mechanisms would be required.
//      */
//     static GreenHouse* getInstance();

//     /// Deleted copy constructor to prevent copying.
//     GreenHouse(const GreenHouse&) = delete;

//     /// Deleted assignment operator to prevent assignment.
//     GreenHouse& operator=(const GreenHouse&) = delete;

//     /// Virtual destructor for proper cleanup.
//     virtual ~GreenHouse() = default;

//     /**
//      * @brief Adds a plant to the inventory.
//      *
//      * Stores a plant in the greenhouse inventory. The plant is added to the
//      * internal collection and becomes available for other operations.
//      *
//      * @param plant Pointer to the PlantType object to add to inventory.
//      *
//      * @pre plant != nullptr
//      * @post inventory.size() increases by 1
//      * @post plant is contained in the inventory
//      */
//     void addToInventory(PlantType* plant);

//     /**
//      * @brief Removes a plant from the inventory.
//      *
//      * Searches for and removes the specified plant from the inventory.
//      * If the plant is not found, no action is taken.
//      *
//      * @param plant Pointer to the PlantType object to remove from inventory.
//      *
//      * @pre plant != nullptr
//      * @post If plant was in inventory, inventory.size() decreases by 1
//      * @post plant is no longer contained in the inventory
//      */
//     void removeFromInventory(PlantType* plant);

//     /**
//      * @brief Gets the current inventory.
//      *
//      * Returns a copy of the current inventory vector. This provides read-only
//      * access to the inventory contents without exposing the internal storage.
//      *
//      * @return std::vector<PlantType*> containing all plants in inventory.
//      *
//      * @note The returned vector is a copy, so modifications to it won't affect
//      *       the actual inventory. Use add/remove methods to modify inventory.
//      */
//     std::vector<PlantType*> getInventory();

//     /**
//      * @brief Checks if a specific plant is available in inventory.
//      *
//      * Searches the inventory for the specified plant and returns whether
//      * it is currently available.
//      *
//      * @param plant Pointer to the PlantType object to search for.
//      * @return true if the plant is found in inventory, false otherwise.
//      *
//      * @pre plant != nullptr
//      */
//     bool isPlantAvailable(PlantType* plant);

//     /**
//      * @brief Inner iterator class for traversing greenhouse inventory.
//      *
//      * Implements the Iterator interface for sequential access to PlantType objects
//      * stored in the GreenHouse inventory.
//      */
//     class GreenHouseIterator : public Iterator {
//     private:
//         std::vector<PlantType*>& plants; ///< Reference to the greenhouse inventory
//         size_t index;                    ///< Current index position in iteration

//     public:
//         /**
//          * @brief Constructs an iterator for the given inventory vector.
//          * @param p Reference to the vector of PlantType pointers.
//          */
//         explicit GreenHouseIterator(std::vector<PlantType*>& p)
//             : plants(p), index(0) {}

//         /**
//          * @brief Checks if there are more elements in the collection.
//          * @return true if another element exists, false otherwise.
//          */
//         // bool hasNext() override {
//         //     return index < plants.size();
//         // }

//         /**
//          * @brief Returns the next element in the collection.
//          * @return Pointer to the next PlantType, or nullptr if at the end.
//          */
//         // PlantType* next() override {
//         //     if (hasNext())
//         //         return plants[index++];
//         //     return nullptr;
//         // }

//         bool hasNext() const override { return index < collection.size(); }

//         PlantType* next() override {
//             return hasNext() ? &collection[index++] : nullptr;
//         }

//     };

//     /**
//      * @brief Creates a concrete iterator for the greenhouse inventory.
//      *
//      * This allows external code to traverse the inventory without directly accessing it.
//      * 
//      * @return Pointer to a new GreenHouseIterator instance.
//      */
//     Iterator* createIterator() override {
//         return new GreenHouseIterator(inventory);
//     }
// };

// #endif // GREENHOUSE_H

#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include <vector>
#include <string>
#include <iostream>
#include "Aggregate.h"
#include "Iterator.h"
#include "PlantType.h"
#include "PlantIterator.h"

/**
 * @class GreenHouse
 * @brief Singleton class managing plant inventory.
 *
 * GreenHouse ensures only one instance exists and provides centralized 
 * management of plant inventory. Implements the Aggregate interface 
 * to allow creation of iterators for traversing the inventory.
 */
class GreenHouse : public Aggregate {
private:
    std::vector<PlantType*> inventory;   ///< Collection of plants in the greenhouse
    static GreenHouse* instance;         ///< Singleton instance

    /**
     * @brief Private constructor to prevent direct instantiation.
     *
     * Ensures only a single instance exists via getInstance().
     */
    GreenHouse() = default;

public:
    /**
     * @brief Returns the singleton instance of GreenHouse.
     * @return Pointer to the GreenHouse instance.
     *
     * Implements lazy initialization. Note: not thread-safe.
     */
    static GreenHouse* getInstance();

    // Prevent copying and assignment
    GreenHouse(const GreenHouse&) = delete;
    GreenHouse& operator=(const GreenHouse&) = delete;

    /// Destructor
    virtual ~GreenHouse() = default;

    /**
     * @brief Adds a plant to the inventory.
     * @param plant Pointer to the plant to add.
     */
    void addToInventory(PlantType* plant);

    /**
     * @brief Removes a plant from the inventory.
     * @param plant Pointer to the plant to remove.
     */
    void removeFromInventory(PlantType* plant);

    /**
     * @brief Returns a copy of the current inventory.
     * @return Vector of PlantType pointers.
     */
    std::vector<PlantType*> getInventory();

    /**
     * @brief Checks if a plant is available in the inventory.
     * @param plant Pointer to the plant to check.
     * @return true if the plant is in the inventory, false otherwise.
     */
    bool isPlantAvailable(PlantType* plant);

    /**
     * @class GreenHouseIterator
     * @brief Iterator for traversing greenhouse inventory.
     */
    class GreenHouseIterator : public Iterator {
    private:
        std::vector<PlantType*>& plants; ///< Reference to inventory
        size_t index;                    ///< Current position in iteration

    public:
        explicit GreenHouseIterator(std::vector<PlantType*>& p)
            : plants(p), index(0) {}

        bool hasNext() const override { return index < plants.size(); }

        //     return hasNext() ? plants[index++] : nullptr;
        // }
    };

    /**
     * @brief Creates an iterator for the inventory.
     * @return Pointer to a new GreenHouseIterator instance.
     */
    Iterator* createIterator() override {
        return new PlantIterator(inventory);
    }
};

#endif // GREENHOUSE_H

