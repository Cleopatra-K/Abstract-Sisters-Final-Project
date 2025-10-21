/*
Concrete “leaf” components extending PlantType. Represent individual plants.
*/
#ifndef WATERLILY_H
#define WATERLILY_H
#include "Aquatic.h"

/**
 * @class WaterLily
 * @brief A beautiful aquatic plant with floating leaves and flowers
 * @author Cleopatra
 */
class WaterLily : public AquaticPlant {
public:
    WaterLily();
    PlantType* clone() const override;
};
#endif