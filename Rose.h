/**
 * @file Rose.h
 * @brief Inherited from PlantType
 *
 */
#ifndef ROSE_H
#define ROSE_H

#include <vector>
#include <string>
#include "Outdoor.h"

class PlantType;

/**
 * @class Rose
 * @brief  A beautiful outdoor flower with thorns
 * This class participates in multiple design patterns:
 * 1. Bridge- RefinedAbstraction
 * 2. Composite - Leaf
 *
 * @ingroup Plants
 * @see PlantType, Outdoor, ColourImplementation
 * @author Cleopatra
 */
class Rose : public Outdoor{
public:
    Rose();

    /**
     * @brief Parameterized constructor for custom Rose properties
     *
     * @param n The name of the rose variety
     * @param p The price of the rose
     * @param desc Description of the rose characteristics
     * @param colourType Initial color implementation type (e.g., "red", "green", "yellow")
     */
    Rose(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season);

    /**
     * @brief Creates a deep copy of the Rose object
     *
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType *clone() const override;

    protected:

    // Template method
    // Primitive operations inherited from abstract class in template
    virtual void fertilize();
    virtual void grow();
    virtual void giveAttention();
    virtual void removeWeed();
    virtual void water();
    virtual void sunlight();

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