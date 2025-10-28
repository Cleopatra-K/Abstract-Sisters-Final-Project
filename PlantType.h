/**
 * @file PlantType.h
 * @brief Base component class for the type of plants hierarchy. This class participates in multiple design patterns.
 *
*/

#ifndef PLANTTYPE_H
#define PLANTTYPE_H
#include <string>
#include <vector>
//#include "PlantState.h"


/**
 * @brief Participates in the following design patterns:
 * 1. Bridge - abstraction for the bridge design pattern
 * 2. Composite - the component
 */

/**
 * @class PlantType
 * @brief The main plant class - this is like a blueprint for all plants
 * @author Cleopatra
 * This is the basic template for any plant in our system.
 * It knows its name, price, how healthy it is, and what stage it's in.
 */

class ColourImplementation;
class PlantState;
class PlantType{
    private:
        int nextID = 1000; 

        ColourImplementation* colourImpl; ///< Pointer to the color implementation (Implementor in Bridge pattern)

        /**
         * @brief Factory method to create appropriate ColourImplementation
         * 
         * @param colourType String identifier for the desired color implementation
         * @return Pointer to the newly created ColourImplementation object
         * @note This method encapsulates the creation logic, allowing the Abstraction to control which ConcreteImplementor is used
         */
        ColourImplementation* createColour(std::string colourType);

        // PlantType abstract base class
        std::string name;
        double price;
        std::string description;
        PlantState* currentState;
        int health;
        int days;
        std::string uniqueID;
        std::string season;
        std::string colour;

    protected:
        /**
         * @brief Retrieves the current color of the plant
         * @return String representing the plant's current color
         */
        std::string getColour();

        /**
         * @brief Checks if the plant currently has a color implementation
         * @return true if colourImpl is not null, false otherwise
         */
        bool hasColour();


        // Plant care methods, for template
        virtual void fertilize();
        virtual void grow();
        virtual void giveAttention();
        virtual void removeWeed();
        virtual void water();
        virtual void sunlight();


    public:

        PlantType(){};

        PlantType(const std::string& n, double p, const std::string& desc);

        /**
         * @brief Constructs a PlantType with initial properties and color
         * 
         * @param n The name of the plant
         * @param p The price of the plant
         * @param desc The description of the plant
         * @param colourType Initial color type for the plant
         */
        PlantType(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season);
        /**
         * @brief Virtual destructor for proper cleanup
         */
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
        
        //template method
        void careForPlant();

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
        std::string getUniqueID() const;
        void setUniqueID(const std::string& id);
        std::string getSeason() const;
        void setSeason(const std::string& s);
        std::string getStateAsString() ;


        /**
         * @brief Dynamically changes the plant's color implementation
         * @param colourType The new color type to apply to the plant
         */
        void setColour(std::string& colourType);

        //Composite design pattern stuff
        /**
         * @brief Adds a child component - pure virtual
         * @param component The plant component to add
         * @note Composite (Bundle) must implement this, Leaf throws exception
         */
        virtual void add(PlantType* component) = 0;

        /**
         * @brief Removes a child component - pure virtual
         * @param component The plant component to remove
         * @note Composite (Bundle) must implement this, Leaf throws exception
         */
        virtual void remove(PlantType* component) = 0;

        /**
         * @brief Gets child components - pure virtual
         * @return Vector of child components
         * @note Composite returns children, Leaf returns empty vector
         */
        virtual std::vector<PlantType*> getChildren() = 0;
};

#endif