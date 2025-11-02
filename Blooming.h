/*
Concrete states representing growth, bloom, maturity, and decline.
*/
#ifndef BLOOMINGSTATE_H
#define BLOOMINGSTATE_H
#include <iostream>

#include "PlantState.h"

/**
 * @class BloomingState
 * @brief The "teenage" stage when plants show their flowers
 * @author
 * This is when plants are at their most beautiful - showing off their colors
 * and flowers. It's like the plant's prom night!
 */
class BloomingState : public PlantState {
public:
    /**
     * @brief Handles how the plant grows during its blooming stage
     * @param plant The plant that's currently blooming
     * 
     * Blooming plants are showing off their flowers but need good health
     * to stay beautiful. They're like teenagers at a dance!
     */
    void handleGrowth(PlantType* plant) override;
    
    /**
     * @brief Shows that the plant is in its blooming stage
     */
    void displayState() const override;
    
    /**
     * @brief Changes the plant to the next growth stage when ready
     * @param plant The plant that might be ready to move on
     * 
     * After the big show of flowers, the plant settles into maturity.
     */
    void changeState(PlantType* plant) override;
    
    /**
     * @brief Creates an exact copy of this blooming state
     * @return A new blooming state object
     */
    PlantState* clone() const override;
    
    /**
     * @brief Gets the name of this growth stage
     * @return "Blooming" - the flower-showing stage
     */
    std::string getStateName() const override;
};

#endif 