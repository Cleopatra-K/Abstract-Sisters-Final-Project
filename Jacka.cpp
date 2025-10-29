#include "Jacka.h"

//Jacka::Jacka() : Outdoor("Jacaranda Tree", 45.0, "Beautiful purple flowering tree") {}

Jacka::Jacka(const std::string& n, double p, const std::string& desc, std::string& colourType, const std::string season) : Outdoor(n, p, desc, colourType, season) {}

PlantType* Jacka::clone() const {
    return new Jacka(*this);
}

std::string Jacka::getCategory() const {
    return "Tree";
}

void Jacka::display() const {
    std::cout << "Jacaranda Tree: " << getName() << " | Price: R" << getPrice()
        << " | Season: " << getSeason()
        << " | State: " << getStateAsString()
        << " | " << getDescription() << std::endl;
}

void Jacka::add(PlantType* plant){
    (void)plant;
}

void Jacka::remove(PlantType* plant){
    (void)plant;
}

std::vector<PlantType*> Jacka::getChildren(){
    return std::vector<PlantType*>();
}

void Jacka::fertilize() { 
    std::cout << "Fertilizing Jacaranda tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Jacka::grow() { 
    std::cout << "Jacaranda tree growing" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void Jacka::giveAttention() { 
    std::cout << "Giving attention to Jacaranda tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Jacka::removeWeed() { 
    std::cout << "Removing weeds around Jacaranda tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Jacka::water() { 
    std::cout << "Watering Jacaranda tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Jacka::sunlight() { 
    std::cout << "Jacaranda tree enjoying sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}



