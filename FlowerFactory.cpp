#include "FlowerFactory.h"
#include "Rose.h"
#include "PeaceLily.h"
#include "WaterLily.h"

// Factory Method 1: Default creation
PlantType* FlowerFactory::createPlant() const {
    // Default plant returned by FlowerFactory is Rose 
    // The Rose constructor initializes name, price, and description 
    return new Rose(); 
}

// Factory Method 2: Price specified creation
PlantType* FlowerFactory::createPlant(double price) const {
    return new Rose(price); // Use parameterized constructor 
}

// Specific creation methods (convenience methods often included in Factory Method)
PlantType* FlowerFactory::createRose(double price) const {
    return new Rose(price); 
}

PlantType* FlowerFactory::createPeaceLily(double price) const {
    return new PeaceLily(price); 
}

PlantType* FlowerFactory::createWaterLily(double price) const {
    return new WaterLily(price); 
}

// Required accessor (Creator participant)
std::string FlowerFactory::getFactoryType() const {
    return "Flower Factory"; 
}