/**
 * @file GiftWrap.h
 * @author Jessica Marodi
 * @brief Concrete decorator that adds gift wrapping to a plant
 */

#ifndef GIFTWRAP_H
#define GIFTWRAP_H

#include "PlantDecorator.h"

/**
 * @class GiftWrap
 * @brief Concrete decorator that adds gift wrapping to a plant
 */
class GiftWrap : public PlantDecorator {
public:

    /**
     * @brief Constructor
     * @param plant The PlantType component to be wrapped as a gift
     */
    GiftWrap(PlantType* plant) : PlantDecorator(plant){}

    /**
     * @brief Destructor
     */
    ~GiftWrap();

    /**
     * @brief Performs the gift wrap operation
     * Adds gift wrapping functionality to the base plant operation
     */
    void decorate() override;
};

#endif // GIFTWRAP_H