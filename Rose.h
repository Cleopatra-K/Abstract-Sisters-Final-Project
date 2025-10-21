/**
 * @file Rose.h
 * @brief Inherited from PlantType
 *
*/
#ifndef ROSE_H
#define ROSE_H
#include "Outdoor.h"

/**
 * @class Rose
 * @brief  A beautiful outdoor flower with thorns
 * This class participates in multiple design patterns:
 * 1. Bridge- RefinedAbstraction
 * 2.  ??
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
    Rose(const std::string& n, double p, const std::string& desc, std::string& colourType);

    /**
     * @brief Creates a deep copy of the Rose object
     * 
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType* clone() const override;
    
};
#endif