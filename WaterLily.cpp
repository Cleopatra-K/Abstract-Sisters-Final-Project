#include "WaterLily.h"

WaterLily::WaterLily() : Aquatic("Water Lily", 35.0, "Floating aquatic plant with beautiful flowers") {}

WaterLily::WaterLily(const std::string& n, double p, const std::string& desc, std::string& colourType) 
    : Aquatic(n, p, desc, colourType) {}

PlantType* WaterLily::clone() const {
    return new WaterLily(*this);
}

std::string WaterLily::getCategory() const {
    return "Aquatic Plant";
}

void WaterLily::display() const {
    std::cout << "Water Lily: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}

void WaterLily::fertilize() { 
    std::cout << "Adding aquatic fertilizer" << std::endl; 
}

void WaterLily::grow() { 
    std::cout << "Water lily spreading on water surface" << std::endl; 
}

void WaterLily::giveAttention() { 
    std::cout << "Cleaning water around water lily" << std::endl; 
}

void WaterLily::sunlight() { 
    std::cout << "Water lily enjoying full sunlight" << std::endl; 
}
