/**
 * @file Bundle.h
 * @brief Composite class representing a bundle of plants
 */

#ifndef BUNDLE_H
#define BUNDLE_H

#include "PlantType.h"
#include <vector>

/**
 * @class Bundle
 * @brief Composite in Composite pattern - represents a bundle of plants
 * 
 * A Bundle can contain individual plants (Leaf) or other bundles (Composite),
 * allowing hierarchical structures of plant collections. The ShoppingCart
 * can treat Bundles and individual plants uniformly through the PlantType interface.
 * 
 * @note Uses non-owning pointers - Customer owns all plants
 */
class Bundle : public PlantType {
private:
    std::vector<PlantType*> plants;  ///< Non-owning plant pointers
    std::string name;

public:
    /**
     * @brief Constructs a Bundle with a name
     * 
     * @param bundleName Name of the bundle
     */
    Bundle(std::string& bundleName);
    
    /**
     * @brief Destructor - does NOT delete plants (Customer owns them)
     */
    ~Bundle();
    
    // Composite Pattern Methods
    /**
     * @brief Adds a plant to the bundle (non-owning reference)
     * 
     * @param plant Plant to add (Customer maintains ownership)
     */
    void add(PlantType* plant);
    
    /**
     * @brief Removes a plant from the bundle
     * 
     * @param plant Plant to remove (Customer still owns the plant)
     */
    void remove(PlantType* plant);
    
    /**
     * @brief Gets all plants in this bundle
     * 
     * @return Vector of plant pointers in this bundle
     */
    std::vector<PlantType*> getChildren();
};

#endif