/**
 * @file PlantDecorator.h
 * @author Jessica Marodi
 * @brief Abstract decorator base class for plant decorations
 */

#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "PlantType.h"

/**
 * @class PlantDecorator
 * @brief Abstract decorator base class for plant decorations
 * 
 * This class serves as the base decorator in the Decorator pattern,
 * wrapping a PlantType component to add additional functionality.
 */
class PlantDecorator : public PlantType{
protected:
    PlantType* plant;

public:
    /**
     * @brief Constructor
     * @param plant The PlantType component to be decorated
     */
    PlantDecorator(PlantType* comp) : plant(comp){}

    /**
     * @brief Virtual destructor
     */
    virtual ~PlantDecorator();

    /**
     * @brief Pure virtual operation to be implemented by concrete decorators
     */
    virtual void decorate();
};

#endif // PLANTDECORATOR_H