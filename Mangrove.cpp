#include "Mangrove.h"

Mangrove::Mangrove() : Aquatic() {}

Mangrove::Mangrove(const std::string& n, double p, const std::string& desc,
                   const std::string& colourType, const std::string& season)
    : Aquatic(n, p, desc, colourType, season) {}

PlantType* Mangrove::clone() const {
    return new Mangrove(*this);
}

std::string Mangrove::getCategory() const {
    return "Tree";
}

void Mangrove::display() const {
    std::cout << "Mangrove: " << getName() << " | Price: R" << getPrice()
        << " | Season: " << getSeason()
        << " | State: " << getStateAsString()
        << " | " << getDescription() << std::endl;
}


void Mangrove::fertilize() { 
    std::cout << "Fertilizing mangrove" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Mangrove::grow() { 
    std::cout << "Mangrove growing in water" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void Mangrove::giveAttention() { 
    std::cout << "Maintaining mangrove habitat" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Mangrove::removeWeed() { 
    std::cout << "Cleaning around mangrove roots" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Mangrove::water() { 
    std::cout << "Mangrove in its natural water environment" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void Mangrove::sunlight() { 
    std::cout << "Mangrove enjoying coastal sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

// Iterator (leaf: single element)
Iterator* Mangrove::createIterator() {
    std::vector<PlantType*> selfVector = { this };
    return new BreadthFirstIterator(selfVector);
}

void Mangrove::add(PlantType* /*plant*/) {}
void Mangrove::remove(PlantType* /*plant*/) {}
std::vector<PlantType*> Mangrove::getChildren() { return {}; }