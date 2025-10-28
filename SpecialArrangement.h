#ifndef SPECIALARRANGEMENT_H
#define SPECIALARRANGEMENT_H
#include "PlantDecorator.h"

/*
Adds a decorative pot to a plant.
*/
class SpecialArrangement : public PlantDecorator{
 /**
     * @brief Performs the gift wrap operation
     * Adds pot decorator functionality to the base plant operation
     */
    void decorate() override;
        /**
     * @brief Destructor
     */
    ~SpecialArrangement() override{}
     /**
     * @brief Constructor
     * @param plant The PlantType component to be arranged specially
     */
    SpecialArrangement(PlantType* plant);
    std::string message;
};

#endif //SPECIALARRANGEMENT_H