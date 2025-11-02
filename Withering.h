/*
Concrete states representing growth, bloom, maturity, and decline.
*/
#ifndef WITHERINGSTATE_H
#define WITHERINGSTATE_H
#include <iostream>

#include "PlantState.h"

/**
 * @class WitheringState
 * @brief The "elderly" stage when plants need extra care
 * @author Cleopatra
 * This is when plants start showing their age - they might droop,
 * lose leaves, or need special attention. Like plant grandparents!
 */
class WitheringState : public PlantState {
public:
    /**
     * @brief Handles how the plant grows during its withering stage
     * @param plant The plant that's currently withering
     * 
     * Withering plants need emergency care and attention to recover.
     * It's like a plant health crisis that needs immediate help!
     */
    void handleGrowth(PlantType* plant) override;
    
    /**
     * @brief Shows that the plant is in its withering stage
     */
    void displayState() const override;
    
    /**
     * @brief Changes the plant to a healthier state if it recovers
     * @param plant The plant that might bounce back with care
     * 
     * With enough love and care, even withering plants can recover
     * and go back to being healthy again!
     */
    void changeState(PlantType* plant) override;
    
    /**
     * @brief Creates an exact copy of this withering state
     * @return A new withering state object
     */
    PlantState* clone() const override;
    
    /**
     * @brief Gets the name of this growth stage
     * @return "Withering" - the plant-needs-help stage
     */
    std::string getStateName() const override;
};

#endif 