/*
Concrete “leaf” components extending PlantType. Represent individual plants.
*/
#ifndef JACKA_H
#define JACKA_H
#include "Outdoor.h"

/**
 * @class Jacaranda
 * @brief A vibrant outdoor flowering tree
 * @author Cleopatra
 */
class Jacaranda : public OutdoorPlant {
public:
    Jacaranda();
    PlantType* clone() const override;
};
#endif