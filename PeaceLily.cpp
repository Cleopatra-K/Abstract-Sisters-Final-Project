#include "PeaceLily.h"

PeaceLily::PeaceLily() : Indoor("Peace Lily", 30.0, "Elegant indoor plant with white flowers") {}

void PeaceLily::add(PlantType* plant){
    (void)plant; // Unused - PeaceLily is a leaf in Composite pattern
}

void PeaceLily::remove(PlantType* plant){
    (void)plant; // Unused - PeaceLily is a leaf in Composite pattern
}

std::vector<PlantType*> PeaceLily::getChildren(){
    return std::vector<PlantType*>();
}

PeaceLily::PeaceLily(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) 
    : Indoor(n, p, desc, colourType) {
        (void)season;
    }

PlantType* PeaceLily::clone() const {
    return new PeaceLily(*this);
}

std::string PeaceLily::getCategory() const {
    return "Flowering Plant";
}

void PeaceLily::display() const {
    std::cout << "Peace Lily: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}

void PeaceLily::fertilize() { 
    std::cout << "Fertilizing peace lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void PeaceLily::grow() { 
    std::cout << "Peace lily growing" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void PeaceLily::giveAttention() { 
    std::cout << "Giving attention to peace lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void PeaceLily::removeWeed() { 
    std::cout << "Removing weeds around peace lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void PeaceLily::water() { 
    std::cout << "Watering peace lily" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void PeaceLily::sunlight() { 
    std::cout << "Peace lily enjoying indirect sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}
