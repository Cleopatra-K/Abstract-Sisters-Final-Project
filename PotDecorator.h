#ifndef POTDECORATOR_H
#define POTDECORATOR_H
#include "PlantDecorator.h"
#include "PotDecorator.h"
/*
Adds a decorative pot to a plant.
*/
class PotDecorator : public PlantDecorator{
 /**
     * @brief Performs the gift wrap operation
     * Adds pot decorator functionality to the base plant operation
     */
    void decorate() override;
};

#endif //POTDECORATOR_H