#include "Rose.h"

//Rose::Rose() : Outdoor("Rose", 25.0, "Beautiful flower with thorns", "hello", "hello") {}

Rose::Rose(){}

Rose::Rose(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) : Outdoor(n, p, desc, colourType, season) {
        //(void)season;
}

PlantType* Rose::clone() const {
    return new Rose(*this);
}

std::string Rose::getCategory() const {
    return "Outdoor";
}

void Rose::add(PlantType* plant){
    (void)plant;
}

void Rose::remove(PlantType* plant){
    (void)plant;
}

std::vector<PlantType*> Rose::getChildren(){
    return std::vector<PlantType*>();
}

void Rose::display() const {
    std::cout << "Rose: " << getName() << " | Price: R" << getPrice() 
        << " | Season: " << getSeason()
        << " | State: " << getStateAsString()
        << " | " << getDescription() << std::endl;
}

void Rose::fertilize() { 
    std::cout << "Fertilizing rose" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Rose::grow() { 
    std::cout << "Rose growing" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void Rose::giveAttention() { 
    std::cout << "Giving attention to rose" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Rose::removeWeed() { 
    std::cout << "Removing weeds around rose" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Rose::water() { 
    std::cout << "Watering rose" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Rose::sunlight() { 
    std::cout << "Rose enjoying sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}
