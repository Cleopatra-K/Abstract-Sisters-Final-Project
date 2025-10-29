#include "Jacka.h"

Jacka::Jacka() : Outdoor("Jacaranda Tree", 45.0, "Beautiful purple flowering tree") {}

Jacka::Jacka(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) 
    : Outdoor(n, p, desc, colourType) {
        (void)season;
    }

PlantType* Jacka::clone() const {
    return new Jacka(*this);
}

std::string Jacka::getCategory() const {
    return "Tree";
}

void Jacka::display() const {
    std::cout << "Jacaranda Tree: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}

void Jacka::fertilize() { 
    std::cout << "Fertilizing Jacaranda tree" << std::endl; 
}

void Jacka::grow() { 
    std::cout << "Jacaranda tree growing" << std::endl; 
}

void Jacka::giveAttention() { 
    std::cout << "Giving attention to Jacaranda tree" << std::endl; 
}

void Jacka::removeWeed() { 
    std::cout << "Removing weeds around Jacaranda tree" << std::endl; 
}

void Jacka::water() { 
    std::cout << "Watering Jacaranda tree" << std::endl; 
}

void Jacka::add(PlantType* plant){

}

void Jacka::remove(PlantType* plant){

}

std::vector<PlantType*> Jacka::getChildren(){
    return std::vector<PlantType*>();
void Jacka::sunlight() { 
    std::cout << "Jacaranda tree enjoying sunlight" << std::endl; 
}
