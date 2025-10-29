/**
 * @file WaterLily.h
 * @brief Inherited from PlantType
 *
*/
#ifndef WATERLILY_H
#define WATERLILY_H
#include "Aquatic.h"
#include <iostream>


/**
 * @class WaterLily
 * @brief A WaterLily
 * 
 * This class participates in multiple design patterns:
 * 1. Bridge - RefinedAbstraction
 * 2. ??
 * 
 * @ingroup Plants
 * @see PlantType, Outdoor, ColourImplementation, PruningStrategy
 * @author Cleopatra
 */

class WaterLily : public Aquatic{
public:
    WaterLily();

    /**
     * @brief Parameterized constructor for custom Rose properties
     * 
     * @param n The name of the plant variety
     * @param p The price of the plant
     * @param desc Description of the plant characteristics
     * @param colourType Initial color implementation type (e.g., "red", "green", "yellow")
     */
    WaterLily(const std::string& n, double p, const std::string& desc, std::string& colourType, const std::string season);

    /**
     * @brief Creates a deep copy of the Rose object
     * 
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType* clone() const override;

    std::string getCategory() const override;
    void display() const override;


protected:

    // Template method
    // Primitive operations inherited from abstract class in template
    void fertilize() override;
    void grow() override;
    void giveAttention() override;
    void removeWeed() override;
    void water() override;
    void sunlight() override;

    /**
     * @brief Adds a plant to the bundle (non-owning reference)
     * 
     * @param plant Plant to add (Customer maintains ownership)
     */
    void add(PlantType* plant) override;
    
    /**
     * @brief Removes a plant from the bundle
     * 
     * @param plant Plant to remove (Customer still owns the plant)
     */
    void remove(PlantType* plant) override;
    
    /**
     * @brief Gets all plants in this bundle
     * 
     * @return Vector of plant pointers in this bundle
     */
    std::vector<PlantType*> getChildren() override;
};
#endif