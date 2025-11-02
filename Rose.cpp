#include "Rose.h"
#include <iostream>

Rose::Rose() : Outdoor() {}

Rose::Rose(const std::string& n, double p, const std::string& desc,
           const std::string& colourType, const std::string& season)
    : Outdoor(n, p, desc, colourType, season) {}

// Prototype
PlantType* Rose::clone() const {
    return new Rose(*this);
}

// Composite Leaf
std::string Rose::getCategory() const {
    return "Outdoor";
}

void Rose::display() const {
    std::cout << "Rose: " << getName() << " | Price: R" << getPrice()
              << " | Season: " << getSeason()
              << " | State: " << getStateAsString()
              << " | " << getDescription() << std::endl;
}

// Iterator (leaf: single element)
Iterator* Rose::createIterator() {
    std::vector<PlantType*> selfVector = { this };
    return new BreadthFirstIterator(selfVector);
}

// Template operations
void Rose::fertilize() {
    std::cout << "Fertilizing rose" << std::endl;
    setHealth(std::min(getHealth() + 5, 100));
}

void Rose::grow() {
    std::cout << "Rose growing" << std::endl;
    setDays(getDays() + 1);
}

void Rose::giveAttention() {
    std::cout << "Giving attention to rose" << std::endl;
    setHealth(std::min(getHealth() + 5, 100));
}

void Rose::removeWeed() {
    std::cout << "Removing weeds around rose" << std::endl;
    setHealth(std::min(getHealth() + 5, 100));
}

void Rose::water() {
    std::cout << "Watering rose" << std::endl;
    setHealth(std::min(getHealth() + 5, 100));
}

void Rose::sunlight() {
    std::cout << "Rose enjoying sunlight" << std::endl;
    setHealth(std::min(getHealth() + 5, 100));
}

//For Werror - —but it never actually uses those parameters (since a leaf has no children).

void Rose::add(PlantType* /*plant*/) {}
void Rose::remove(PlantType* /*plant*/) {}
std::vector<PlantType*> Rose::getChildren() { return {}; }
