#include "BonsaiTree.h"

BonsaiTree::BonsaiTree() : Indoor("Bonsai Tree", 60.0, "Miniature cultivated tree") {}

BonsaiTree::BonsaiTree(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) 
    : Indoor(n, p, desc, colourType) {
        (void)season;
    }

PlantType* BonsaiTree::clone() const {
    return new BonsaiTree(*this);
}

std::string BonsaiTree::getCategory() const {
    return "Tree";
}

void BonsaiTree::display() const {
    std::cout << "Bonsai Tree: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}


void BonsaiTree::fertilize() { 
    std::cout << "Fertilizing bonsai tree" << std::endl; 
}

void BonsaiTree::grow() { 
    std::cout << "Bonsai tree growing slowly" << std::endl; 
}

void BonsaiTree::giveAttention() { 
    std::cout << "Pruning and shaping bonsai tree" << std::endl; 
}

void BonsaiTree::water() { 
    std::cout << "Watering bonsai tree carefully" << std::endl; 
}

void BonsaiTree::sunlight() { 
    std::cout << "Bonsai tree enjoying filtered sunlight" << std::endl; 
}

