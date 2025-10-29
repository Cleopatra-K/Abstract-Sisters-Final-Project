/**
 * @file PeaceLily.h
 * @brief Inherited from PlantType
 *
*/
#ifndef PEACELILY_H
#define PEACELILY_H
#include "Indoor.h"

/**
 * @class PeaceLily
 * @brief A PeaceLily
 * 
 * This class participates in multiple design patterns:
 * 1. Bridge - RefinedAbstraction
 * 2. ??
 * 
 * @ingroup Plants
 * @see PlantType, Outdoor, ColourImplementation, PruningStrategy
 * @author Cleopatra
 */

class PeaceLily : public Indoor{
public:
    PeaceLily();


    /**
     * @brief Parameterized constructor for custom Rose properties
     * 
     * @param n The name of the plant variety
     * @param p The price of the plant
     * @param desc Description of the plant characteristics
     * @param colourType Initial color implementation type (e.g., "red", "green", "yellow")
     */
    PeaceLily(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season);

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
    virtual void water();
    virtual void sunlight();
};
#endif