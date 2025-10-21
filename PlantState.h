/*
Abstract state interface for different life stages of a plant.
*/
#ifndef PLANTSTATE_H
#define PLANTSTATE_H
#include <string>

// Forward declaration
class PlantType;

/**
 * @class PlantState
 * @brief Represents what "age group" a plant is in
 *@author Cleopatra
 * Think of this as the plant's current life stage - baby, teen, adult, or elderly.
 * Each stage behaves differently and needs different kinds of care.
 */
class PlantState {
public:
    virtual ~PlantState() = default;
    
    /**
     * @brief Handles how the plant grows in this specific stage
     * @param plant The plant that's in this growth stage
     */
    virtual void handleGrowth(PlantType* plant) = 0;
    
    /**
     * @brief Shows what stage the plant is currently in
     */
    virtual void displayState() const = 0;
    
    /**
     * @brief Changes the plant to the next appropriate stage
     * @param plant The plant that might be ready to grow up or down
     */
    virtual void changeState(PlantType* plant) = 0;
    
    /**
     * @brief Creates an exact copy of this growth stage
     * @return A new state object just like this one
     */
    virtual PlantState* clone() const = 0;
    
    /**
     * @brief Gets the name of this growth stage
     * @return The stage name like "Seedling" or "Blooming"
     */
    virtual std::string getStateName() const = 0;
};

#endif