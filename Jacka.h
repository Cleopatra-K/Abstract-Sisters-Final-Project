/**
 * @file Jacka.h
 * @brief Inherited from PlantType
 *
*/
#ifndef JACKA_H
#define JACKA_H
#include "Outdoor.h"

/**
 * @class Jacka
 * @brief A tree
 * 
 * This class participates in multiple design patterns:
 * 1. Bridge - RefinedAbstraction
 * 2. ??
 * 
 * @ingroup Plants
 * @see PlantType, Outdoor, ColourImplementation, PruningStrategy
 * @author Cleopatra
 */

class Jacka: public Outdoor{
public:
    Jacka();

    /**
     * @brief Parameterized constructor for custom Rose properties
     * 
     * @param n The name of the tree variety
     * @param p The price of the tree
     * @param desc Description of the tree characteristics
     * @param colourType Initial color implementation type (e.g., "red", "green", "yellow")
     */
    Jacka(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season);

    /**
     * @brief Creates a deep copy of the Rose object
     * 
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType* clone() const override;

protected:    

    // Template method
    // Primitive operations inherited from abstract class in template
    virtual void fertilize();
    virtual void grow();
    virtual void giveAttention();
    virtual void removeWeed();
    virtual void water();
    virtual void sunlight();

   
    


    
};
#endif