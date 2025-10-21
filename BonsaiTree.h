/*
Concrete “leaf” components extending PlantType. Represent individual plants.
*/
#ifndef BONSAITREE_H
#define BONSAITREE_H
#include "Indoor.h"

/**
 * @class BonsaiTree
 * @brief A miniature indoor tree cultivated in a pot
 * @author Cleopatra
 */
class BonsaiTree : public IndoorPlant {
public:
    BonsaiTree();
    PlantType* clone() const override;
};
#endif