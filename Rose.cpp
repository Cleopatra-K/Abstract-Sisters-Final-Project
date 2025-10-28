#include "Rose.h"

Rose::Rose() : Outdoor("Rose", 25.0, "Beautiful flower with thorns") {}

Rose::Rose(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) 
    : Outdoor(n, p, desc, colourType) {}

PlantType* Rose::clone() const {
    return new Rose(*this);
}

std::string Rose::getCategory() const {
    return "Outdoor";
}

void Rose::display() const {
    std::cout << "Rose: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}

void Rose::fertilize() { 
    std::cout << "Fertilizing rose" << std::endl; 
}
void Rose::grow() { 
    std::cout << "Rose growing" << std::endl; 
}
void Rose::giveAttention() { 
    std::cout << "Giving attention to rose" << std::endl; 
}
void Rose::removeWeed() { 
    std::cout << "Removing weeds around rose" << std::endl; 
}
void Rose::water() { 
    std::cout << "Watering rose" << std::endl; 
}
void Rose::sunlight() { 
    std::cout << "Rose enjoying sunlight" << std::endl; 
}
