#include "PlantType.h"
// #include "ColourImplementation.h"
// #include "Green.h"
// #include "Yellow.h"
// #include "Red.h"

#include <iostream>
#include <sstream>

// Initialize static counter
int PlantType::nextID = 1000;

/**
 * @brief Base constructor that generates unique ID
 * @param n The name of the plant
 * @param p The price of the plant  
 * @param desc The description of the plant
 */
PlantType::PlantType(const std::string& n, double p, const std::string& desc)
    : name(n), price(p), description(desc), health(100), days(0), season("Spring") {
    
    // Your unique ID generation
    std::stringstream ss;
    ss << PlantType::nextID++;
    uniqueID = ss.str();
}

/**
 * @brief Full constructor
 * @param n The name of the plant
 * @param p The price of the plant
 * @param desc The description of the plant  
 * @param colourType Initial color type for the plant
 */
PlantType::PlantType(const std::string& n, double p, const std::string& desc, 
            std::string& /*colourType*/, std::string& season)
    : name(n), price(p), description(desc), health(100), days(0), season(season) 
{
    std::stringstream ss;
    ss << "PLANT_" << PlantType::nextID++;
    uniqueID = ss.str();
}

/**
 * @brief Destructor
 */
PlantType::~PlantType(){
    // No dynamic memory to clean up for factory pattern
}

void PlantType::careForPlant() {
    std::cout << "\n=== Caring for " << name << " ===" << std::endl;
    
    water();
    sunlight();
    fertilize();
    removeWeed();
    giveAttention();
    grow();
    
    std::cout << "=== Care routine complete ===" << std::endl;
}

void PlantType::fertilize() {
    std::cout << "Applying fertilizer to " << name << std::endl;
    health += 5;
    if (health > 100) health = 100;
}

void PlantType::grow() {
    std::cout << name << " is growing..." << std::endl;
    days += 1;
}

void PlantType::giveAttention() {
    std::cout << "Giving attention to " << name << std::endl;
    health += 3;
    if (health > 100) health = 100;
}

void PlantType::removeWeed() {
    std::cout << "Removing weeds around " << name << std::endl;
    health += 2;
    if (health > 100) health = 100;
}

void PlantType::water() {
    std::cout << "Watering " << name << std::endl;
    health += 10;
    if (health > 100) health = 100;
}

void PlantType::sunlight() {
    std::cout << "Exposing " << name << " to sunlight" << std::endl;
    health += 5;
    if (health > 100) health = 100;
}

// Getters and Setters
std::string PlantType::getName() const { return name; }
double PlantType::getPrice() const { return price; }
std::string PlantType::getDescription() const { return description; }
int PlantType::getHealth() const { return health; }
int PlantType::getDays() const { return days; }
std::string PlantType::getSeason() const { return season; }
std::string PlantType::getUniqueID() const { return uniqueID; }

void PlantType::setHealth(int h) { health = h; }
void PlantType::setDays(int d) { days = d; }
void PlantType::setSeason(const std::string& s) { season = s; }
void PlantType::setUniqueID(const std::string& id) { uniqueID = id; }

// Simple placeholder implementations for required methods
std::string PlantType::getColour(){
    return "green";
}

bool PlantType::hasColour(){
    return false;
}

// void PlantType::setColour(std::string& colourType){
//     // Empty for factory pattern test
// }

// std::string PlantType::getStateAsString() {
//     return "Healthy";
// }

// void PlantType::setState(PlantState* state) {
//     // Empty for factory pattern test
// }
// /**
//  * @brief Creates color implementation based on color type (Bridge Pattern)
//  * @param colourType The color to create ("green", "yellow", "red")
//  * @return ColourImplementation object or NULL if invalid
//  * @note This implements the Bridge Pattern by delegating color behavior to separate objects
//  */
// ColourImplementation* PlantType::createColour(std::string colourType){
//     // if(colourType == "green")
//     //     return new Green();
//     // else if(colourType == "yellow")
//     //     return new Yellow();
//     // else if(colourType == "red")
//     //     return new Red();
//     // else
//         return NULL;
// }

// /**
//  * @brief Gets the current color of the plant
//  * @return Color name as string or "no colour" if not set
//  * @note Uses the Bridge Pattern to delegate to color implementation
//  */
// std::string PlantType::getColour(){
//     // if(colourImpl == NULL){
//     //     return "no colour";
//     // }
//     // return colourImpl->fillColour();
//     if(colourImpl == NULL){
//         return colour;  // Return the string colour
//     }
//     // return colourImpl->fillColour();
//     return colour;
// }

// /**
//  * @brief Checks if plant has a color implementation
//  * @return true if color is set, false otherwise
//  */
// bool PlantType::hasColour(){
//     // return colourImpl != NULL;
//     return colourImpl != NULL || !colour.empty();
// }

// /**
//  * @brief Base constructor that generates unique ID (Your functionality)
//  * @param n The name of the plant
//  * @param p The price of the plant  
//  * @param desc The description of the plant
//  */
// PlantType::PlantType(const std::string& n, double p, const std::string& desc)
//     : name(n), price(p), description(desc), currentState(NULL)
//         , health(100), days(0), season("Spring"), colour("green"), colourImpl(NULL) {
    
//     // Your unique ID generation
//     std::stringstream ss;
//     ss << PlantType::nextID++;
//     uniqueID = ss.str();

//     // currentState = new SeedlingState();
// }

// /**
//  * @brief Full constructor with color support (Combined functionality)
//  * @param n The name of the plant
//  * @param p The price of the plant
//  * @param desc The description of the plant  
//  * @param colourType The color type for Bridge Pattern
//  * @param season The growing season (default "Unknown")
//  * @note Merges both your unique ID system and friend's color system
//  */
// PlantType::PlantType(const std::string& n, double p, const std::string& desc, 
//             std::string& colourType, std::string& season)
//     : name(n), price(p), description(desc), currentState(nullptr), 
//     health(100), days(0), season(season), colour("green"), colourImpl(nullptr) 
// {
//     std::stringstream ss;
//     ss << "PLANT_" << PlantType::nextID++;
//     uniqueID = ss.str();
    
//     // colourImpl = createColour(colourType); // Uncomment when implemented
//     // currentState = new SeedlingState();
// }

// /**
//  * @brief Destructor - cleans up color implementation
//  * @note Prevents memory leaks from color objects
//  */
// PlantType::~PlantType(){
//     // if(colourImpl){
//     //     delete colourImpl;
//     // }
//     if(colourImpl){
//         delete colourImpl;
//     }
//     if(currentState){
//         delete currentState;
//     }
// }

// /**
//  * @brief Changes the plant's color (Bridge Pattern setter)
//  * @param colourType The new color to set
//  * @note Safely replaces existing color implementation
//  */
// void PlantType::setColour(std::string& colourType){
//     if(colourImpl){
//         delete colourImpl;
//     }
//     colourImpl = createColour(colourType);
//     colour = colourType;
// }

// void PlantType::careForPlant() {
//     std::cout << "\n=== Caring for " << name << " ===" << std::endl;
    
//     water();
//     sunlight();
//     fertilize();
//     removeWeed();
//     giveAttention();
//     grow();
    
//     // After care, check if state should change
//     // if (currentState) {
//     //     currentState->changeState(this);
//     // }
    
//     std::cout << "=== Care routine complete ===" << std::endl;
// }

// void PlantType::fertilize() {
//     std::cout << "Applying fertilizer to " << name << std::endl;
//     health += 5;
//     if (health > 100) health = 100;
// }

// void PlantType::grow() {
//     std::cout << name << " is growing..." << std::endl;
//     days += 1;
//     // if (currentState) {
//     //     currentState->handleGrowth(this);
//     // }
// }

// void PlantType::giveAttention() {
//     std::cout << "Giving attention to " << name << std::endl;
//     health += 3;
//     if (health > 100) health = 100;
// }

// void PlantType::removeWeed() {
//     std::cout << "Removing weeds around " << name << std::endl;
//     health += 2;
//     if (health > 100) health = 100;
// }

// void PlantType::water() {
//     std::cout << "Watering " << name << std::endl;
//     health += 10;
//     if (health > 100) health = 100;
// }

// void PlantType::sunlight() {
//     std::cout << "Exposing " << name << " to sunlight" << std::endl;
//     health += 5;
//     if (health > 100) health = 100;
// }

// void PlantType::display() const {
//     std::cout << "\n--- Plant Information ---" << std::endl;
//     std::cout << "ID: " << uniqueID << std::endl;
//     std::cout << "Name: " << name << std::endl;
//     std::cout << "Category: " << getCategory() << std::endl;
//     std::cout << "Price: R" << price << std::endl;
//     std::cout << "Description: " << description << std::endl;
//     std::cout << "Health: " << health << "%" << std::endl;
//     std::cout << "Age: " << days << " days" << std::endl;
//     std::cout << "Season: " << season << std::endl;
//     std::cout << "Colour: " << colour << std::endl;
//     if (currentState) {
//         std::cout << "State: " << currentState->getStateName() << std::endl;
//     }
//     std::cout << "-------------------------\n" << std::endl;
// }

// // Getters and Setters
// std::string PlantType::getName() const { return name; }
// double PlantType::getPrice() const { return price; }
// std::string PlantType::getDescription() const { return description; }
// int PlantType::getHealth() const { return health; }
// int PlantType::getDays() const { return days; }
// std::string PlantType::getSeason() const { return season; }
// std::string PlantType::getUniqueID() const { return uniqueID; }

// void PlantType::setHealth(int h) { health = h; }
// void PlantType::setDays(int d) { days = d; }
// void PlantType::setSeason(const std::string& s) { season = s; }
// void PlantType::setUniqueID(const std::string& id) { uniqueID = id; }