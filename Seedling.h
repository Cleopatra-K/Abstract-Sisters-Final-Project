/*
Concrete states representing growth, bloom, maturity, and decline.
*/
#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H
#include <iostream>

#include "PlantState.h"

/**
 * @class SeedlingState
 * @brief The "baby" stage of a plant's life
 * @author Cleopatra
 * Think of this as when a plant is just a tiny sprout - it's delicate,
 * needs lots of care, and is just starting to grow. Like a newborn plant!
 */
class SeedlingState : public PlantState {
public:
    /**
     * @brief Handles how the plant grows during its seedling stage
     * @param plant The plant that's currently a seedling
     * 
     * Seedlings need gentle care and protection while they establish themselves.
     * They're like plant babies - fragile but full of potential!
     */
    void handleGrowth(PlantType* plant) override;
    
    /**
     * @brief Shows that the plant is in its seedling stage
     */
    void displayState() const override;
    
    /**
     * @brief Changes the plant to the next growth stage when ready
     * @param plant The plant that might be ready to grow up
     * 
     * When the seedling gets strong enough, it graduates to the next stage!
     */
    void changeState(PlantType* plant) override;
    
    /**
     * @brief Creates an exact copy of this seedling state
     * @return A new seedling state object
     */
    PlantState* clone() const override;
    
    /**
     * @brief Gets the name of this growth stage
     * @return "Seedling" - the baby plant stage
     */
    std::string getStateName() const override;
};

#endif // SEEDLINGSTATE_H