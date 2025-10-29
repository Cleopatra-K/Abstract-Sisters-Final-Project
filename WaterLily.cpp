#include "WaterLily.h"


//WaterLily::WaterLily() : Aquatic("Water Lily", 35.0, "Floating aquatic plant with beautiful flowers") {}

WaterLily::WaterLily(const std::string &n, double p, const std::string &desc, std::string &colourType, const std::string season):Aquatic(n, p, desc, colourType, season){

}

void WaterLily::add(PlantType* plant){
    (void)plant;
}

void WaterLily::remove(PlantType* plant){
    (void)plant;
}

std::vector<PlantType*> WaterLily::getChildren(){
    return std::vector<PlantType*>();
}

PlantType* WaterLily::clone() const {
    return new WaterLily(*this);
}

std::string WaterLily::getCategory() const {
    return "Aquatic Plant";
}

void WaterLily::display() const {
    std::cout << "Water Lily: " << getName() << " | Price: R" << getPrice()
        << " | Season: " << getSeason()
        << " | State: " << getStateAsString()
        << " | " << getDescription() << std::endl;
}

void WaterLily::fertilize() { 
    std::cout << "Adding aquatic fertilizer" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void WaterLily::grow() { 
    std::cout << "Water lily spreading on water surface" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void WaterLily::giveAttention() { 
    std::cout << "Cleaning water around water lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void WaterLily::removeWeed() { 
    std::cout << "Removing algae and debris around water lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void WaterLily::water() { 
    std::cout << "Water lily in its water habitat" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void WaterLily::sunlight() { 
    std::cout << "Water lily enjoying full sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

