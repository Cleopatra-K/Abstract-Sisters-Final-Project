#include "PlantType.h"
#include "PlantState.h"

#include "ColourImplementation.h"
#include "Green.h"
#include "Yellow.h"
#include "Red.h"

#include <iostream>
#include <sstream>

// Initialize static counter
// int PlantType::nextID = 1000;

/**
 * @brief Creates color implementation based on color type (Bridge Pattern)
 * @param colourType The color to create ("green", "yellow", "red")
 * @return ColourImplementation object or NULL if invalid
 * @note This implements the Bridge Pattern by delegating color behavior to separate objects
 */
ColourImplementation* PlantType::createColour(std::string colourType){
    if(colourType == "green")
        return new Green();
    else if(colourType == "yellow")
        return new Yellow();
    else if(colourType == "red")
        return new Red();
    else
        return NULL;
}

/**
 * @brief Gets the current color of the plant
 * @return Color name as string or "no colour" if not set
 * @note Uses the Bridge Pattern to delegate to color implementation
 */
std::string PlantType::getColour(){
    if(colourImpl == NULL){
        return "no colour";
    }
    return colourImpl->fillColour();
}

/**
 * @brief Checks if plant has a color implementation
 * @return true if color is set, false otherwise
 */
bool PlantType::hasColour(){
    return colourImpl != NULL;
}

/**
 * @brief Base constructor that generates unique ID (Your functionality)
 * @param n The name of the plant
 * @param p The price of the plant  
 * @param desc The description of the plant
 */
PlantType::PlantType(const std::string& n, double p, const std::string& desc)
    : name(n), price(p), description(desc), currentState(nullptr), 
        colourImpl(nullptr), health(100), days(0) {
    
    // Your unique ID generation
    std::stringstream ss;
    ss << PlantType::nextID++;
    uniqueID = ss.str();
    season = "Unknown";
}

/**
 * @brief Full constructor with color support (Combined functionality)
 * @param n The name of the plant
 * @param p The price of the plant
 * @param desc The description of the plant  
 * @param colourType The color type for Bridge Pattern
 * @param season The growing season (default "Unknown")
 * @note Merges both your unique ID system and friend's color system
 */
PlantType::PlantType(const std::string& n, double p, const std::string& desc, 
    std::string& colourType, std::string season)
    : PlantType(n, p, desc) // Delegate to base constructor for ID generation
{
    // Your friend's color initialization
    colourImpl = createColour(colourType);
    this->season = season;
}

/**
 * @brief Destructor - cleans up color implementation
 * @note Prevents memory leaks from color objects
 */
PlantType::~PlantType(){
    if(colourImpl){
        delete colourImpl;
    }
}

/**
 * @brief Changes the plant's color (Bridge Pattern setter)
 * @param colourType The new color to set
 * @note Safely replaces existing color implementation
 */
void PlantType::setColour(std::string& colourType){
    if(colourImpl){
        delete colourImpl;
    }
    colourImpl = createColour(colourType);
}

std::string PlantType::getUniqueID() const { 
    return uniqueID; 
} 

void PlantType::setUniqueID(const std::string& id) { 
    uniqueID = id; 
} 

std::string PlantType::getSeason() const { 
    return season; 
} 

void PlantType::setSeason(const std::string& s) { 
    season = s; 
} 

/**
 * @brief Enhanced display showing color information
 * @note Now shows color in addition to your existing display fields
 */
void PlantType::display() const {
    std::cout << name << " [ID:" << uniqueID << "]" << " - $" << price 
            << " - Health: " << health << "% - Season: " << season;
    
    // Your friend's color display
    if (hasColour()) {
        std::cout << " - Colour: " << getColour();
    }
    
    // Your state display
    if (currentState) {
        std::cout << " - ";
        currentState->displayState();
    }

    std::cout << std::endl;
    if (!description.empty()) {
        std::cout << " " << description << std::endl;
    }
}