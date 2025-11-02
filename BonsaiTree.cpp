#include "BonsaiTree.h"


BonsaiTree::BonsaiTree() : Indoor() {}

BonsaiTree::BonsaiTree(const std::string &n, double p, const std::string &desc,
                       const std::string &colourType, const std::string &season)
    : Indoor(n, p, desc, colourType, season) {}

PlantType* BonsaiTree::clone() const {
    return new BonsaiTree(*this); // OK, but caller must delete
}

std::string BonsaiTree::getCategory() const {
    return "Tree";
}

void BonsaiTree::display() const {
    std::cout << "Bonsai Tree: " << getName() << " | Price: R" << getPrice()
        << " | Season: " << getSeason()
        << " | State: " << getStateAsString()
        << " | " << getDescription() << std::endl;
}


void BonsaiTree::fertilize() { 
    std::cout << "Fertilizing bonsai tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void BonsaiTree::grow() { 
    std::cout << "Bonsai tree growing slowly" << std::endl;
    int currentDays = getDays();
    setDays(currentDays + 1);
}

void BonsaiTree::giveAttention() { 
    std::cout << "Pruning and shaping bonsai tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void BonsaiTree::removeWeed() { 
    std::cout << "Removing weeds around bonsai tree" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void BonsaiTree::water() { 
    std::cout << "Watering bonsai tree carefully" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void BonsaiTree::sunlight() { 
    std::cout << "Bonsai tree enjoying filtered sunlight" << std::endl;
    int currentHealth = getHealth();
    setHealth(currentHealth + 5);
    if (getHealth() > 100) setHealth(100);
}

void BonsaiTree::add(PlantType* /*plant*/) {}
void BonsaiTree::remove(PlantType* /*plant*/) {}
std::vector<PlantType*> BonsaiTree::getChildren() { return {}; }

// Iterator (leaf: single element)
Iterator* BonsaiTree::createIterator() {
    std::vector<PlantType*> selfVector = { this };
    return new BreadthFirstIterator(selfVector);
}