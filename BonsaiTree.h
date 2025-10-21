/**
 * @file BonsaiTree.h
 * @brief Inherited from PlantType
 *
*/
#ifndef BONSAITREE_H
#define BONSAITREE_H
#include "Indoor.h"

/**
 * @class BonsaiTree
 * @brief A miniature indoor tree cultivated in a pot
 * @author Cleopatra
 */
class BonsaiTree : public Indoor{
public:
    BonsaiTree();


    /**
     * @brief Parameterized constructor for custom Rose properties
     * 
     * @param n The name of the tree variety
     * @param p The price of the tree
     * @param desc Description of the tree characteristics
     * @param colourType Initial color implementation type (e.g., "red", "green", "yellow")
     */
    BonsaiTree(const std::string& n, double p, const std::string& desc, std::string& colourType);

    /**
     * @brief Creates a deep copy of the Rose object
     * 
     * Implements the Prototype pattern by providing cloning capability.
     * @return Pointer to a new Rose object that is a copy of this one
     */
    PlantType* clone() const override;
};
#endif