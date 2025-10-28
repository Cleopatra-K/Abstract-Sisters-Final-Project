#include "FlowerFactory.h"
#include "Rose.h"
#include "PeaceLily.h"
#include "WaterLily.h"

// Factory Method 1: Create default flower (Rose)
PlantType* FlowerFactory::createPlant() const {
    std::cout << "FlowerFactory: Creating default Rose..." << std::endl;
    return new Rose();  // Use default constructor
}

// Factory Method 2: Create default flower with custom price
PlantType* FlowerFactory::createPlant(double price) const {
    std::cout << "FlowerFactory: Creating Rose with custom price..." << std::endl;
    return createRose(price);
}

PlantType* FlowerFactory::createRose(double price) const {
    std::string colourType = "red";
    std::string name = "Rose";
    std::string desc = "Beautiful flowering plant with thorns";
    Rose* rose = new Rose(name, price, desc, colourType);
    std::cout << "Created: Rose at R" << price << std::endl;
    return rose;
}

PlantType* FlowerFactory::createPeaceLily(double price) const {
    std::string colourType = "white";
    std::string name = "Peace Lily";
    std::string desc = "Elegant indoor plant with white flowers";
    PeaceLily* lily = new PeaceLily(name, price, desc, colourType);
    std::cout << "Created: Peace Lily at R" << price << std::endl;
    return lily;
}

PlantType* FlowerFactory::createWaterLily(double price) const {
    std::string colourType = "pink";
    std::string name = "Water Lily";
    std::string desc = "Beautiful floating aquatic plant";
    WaterLily* wlily = new WaterLily(name, price, desc, colourType);
    std::cout << "Created: Water Lily at R" << price << std::endl;
    return wlily;
}

std::string FlowerFactory::getFactoryType() const {
    return "FlowerFactory";
}