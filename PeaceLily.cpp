#include "PeaceLily.h"

PeaceLily::PeaceLily() : Indoor("Peace Lily", 30.0, "Elegant indoor plant with white flowers") {}

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
}

void PeaceLily::grow() { 
    std::cout << "Peace lily growing" << std::endl; 
}

void PeaceLily::giveAttention() { 
    std::cout << "Giving attention to peace lily" << std::endl; 
}

void PeaceLily::water() { 
    std::cout << "Watering peace lily" << std::endl; 
}

void PeaceLily::sunlight() { 
    std::cout << "Peace lily enjoying indirect sunlight" << std::endl; 
}