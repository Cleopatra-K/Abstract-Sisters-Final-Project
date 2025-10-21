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
 * @note Uses raw pointers with ownership semantics - Bundle owns its contained plants
 */
class Bundle : public PlantType {
private:
    std::string name;
    std::vector<PlantType*> plants;  ///< Owned plant pointers
    double bundleDiscount; ///< Additional discount for buying as bundle

public:
    Bundle(const std::string& bundleName, double discount = 0.1);
    
    /**
     * @brief Destructor - deletes all owned plants
     */
    ~Bundle();
    
    /**
     * @brief Adds a plant to the bundle (takes ownership)
     * 
     * @param plant Plant to add (Bundle takes ownership)
     */
    void addPlant(PlantType* plant);
    
    /**
     * @brief Removes a plant from the bundle (transfers ownership to caller)
     * 
     * @param plant Plant to remove
     * @return Pointer to removed plant (caller takes ownership)
     */
    PlantType* removePlant(PlantType* plant);
    
    // PlantType interface implementation
    double getPrice();
    std::string getName();
    std::string getDescription();
    void printPlant();
    PlantType* clone();
    
    /**
     * @brief Prevent copying (or implement deep copy)
     */
    Bundle(const Bundle&) = delete;
    Bundle& operator=(const Bundle&) = delete;
};
#endif