/**
 * @file PlantType.h
 * @brief Base component class for the type of plants hierarchy. This class participates in multiple design patterns.
 *
*/

#ifndef PLANTTYPE_H
#define PLANTTYPE_H
#include <string>
#include "PlantState.h"


/**
 * @brief Participates in the following design patterns:
 * 1. Bridge - abstraction for the bridge design pattern
 * 
 */

/**
 * @class PlantType
 * @brief The main plant class - this is like a blueprint for all plants
 * @author Cleopatra
 * This is the basic template for any plant in our system.
 * It knows its name, price, how healthy it is, and what stage it's in.
 */

class ColourImplementation;

class PlantType{
// PlantType abstract base class
    protected:
        std::string name;
        double price;
        std::string description;
        PlantState* currentState;
        int health;
        int days;

    public:
        PlantType(const std::string& n, double p, const std::string& desc);
        virtual ~PlantType();

        // Core methods prototype is here as well
        /**
         * @brief Creates an exact copy of this plant
         * @return A brand new plant that looks exactly like this one
         */
        virtual PlantType* clone() const = 0;

        /**
         * @brief Shows all the plant's info on screen
         */
        virtual void display() const;

        /**
         * @brief Tells us where this plant likes to live
         * @return "Indoor", "Outdoor", or "Aquatic"
         */
        virtual std::string getCategory() const = 0;
        
        // Plant care methods, for template
        virtual void fertilize();
        virtual void grow();
        virtual void giveAttention();
        virtual void removeWeed();
        virtual void water();
        virtual void sunlight();
        
        // Observer pattern methods (if needed)
        // virtual void attach();
        // virtual void detach();
        // virtual void notify();

        /**
        * @brief Change the plant's growth stage (like from baby to teen)
        * @param state The new stage to put the plant in
        */
        // State management
        void setState(PlantState* state);

        // Getters and setters
        std::string getName() const;
        double getPrice() const;
        std::string getDescription() const;
        int getHealth() const;
        int getDays() const;
        void setHealth(int h);
        void setDays(int d);
    private:
        ColourImplementation* colourImpl;

        ColourImplementation* createColour(std::string){}

    protected:
        std::string getColour(){}

        bool hasColour(){}

    public:
        PlantType(std::string& colourType){}
        virtual ~PlantType(){}
        virtual void printPlant() = 0;

        void setColour(std::string& colourType){}
};

#endif