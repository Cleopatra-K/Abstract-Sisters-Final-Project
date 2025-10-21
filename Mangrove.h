/*
Concrete “leaf” components extending PlantType. Represent individual plants.
*/

#ifndef MANGROVE_H
#define MANGROVE_H
#include "Aquatic.h"

/**
 * @class Mangrove
 * @brief A resilient aquatic tree that thrives in coastal environments
 * @author Cleopatra
 */
class Mangrove : public AquaticPlant {
public:
    Mangrove();
    PlantType* clone() const override;
};
#endif