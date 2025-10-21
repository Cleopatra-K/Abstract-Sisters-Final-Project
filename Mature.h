/*
Concrete states representing growth, bloom, maturity, and decline.
*/
#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

/**
 * @class MatureState
 * @brief The "adult" stage of a plant's life
 * @author Cleopatra
 * This is when the plant is fully grown, stable, and strong.
 * It's like a plant in its prime working years - reliable and established.
 */
class MatureState : public PlantState {
public:
    /**
     * @brief Handles how the plant grows during its mature stage
     * @param plant The plant that's currently mature
     * 
     * Mature plants are stable and don't need as much babying.
     * They're the reliable adults of the plant world!
     */
    void handleGrowth(PlantType* plant) override;
    
    /**
     * @brief Shows that the plant is in its mature stage
     */
    void displayState() const override;
    
    /**
     * @brief Changes the plant to the next growth stage when ready
     * @param plant The plant that might be getting older
     * 
     * After a long, productive life, even mature plants eventually age.
     */
    void changeState(PlantType* plant) override;
    
    /**
     * @brief Creates an exact copy of this mature state
     * @return A new mature state object
     */
    PlantState* clone() const override;
    
    /**
     * @brief Gets the name of this growth stage
     * @return "Mature" - the grown-up plant stage
     */
    std::string getStateName() const override;
};

#endif