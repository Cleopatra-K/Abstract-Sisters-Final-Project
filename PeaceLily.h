/*
Concrete “leaf” components extending PlantType. Represent individual plants.
*/
#ifndef PEACELILY_H
#define PEACELILY_H
#include "Indoor.h"

/**
 * @class PeaceLily
 * @brief An elegant indoor plant with white blooms
 * @author Cleopatra
 */
class PeaceLily : public IndoorPlant {
public:
    PeaceLily();
    PlantType* clone() const override;
};
#endif