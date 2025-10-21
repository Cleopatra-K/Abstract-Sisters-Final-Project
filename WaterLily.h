/**
 * @file WaterLily.h
 * @brief Inherited from PlantType
 *
*/
#ifndef WATERLILY_H
#define WATERLILY_H
#include "Aquatic.h"

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
    WaterLily(const std::string& n, double p, const std::string& desc, std::string& colourType);

    /**
     * @brief Creates a deep copy of the Rose object
     * 
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType* clone() const override;
};
#endif