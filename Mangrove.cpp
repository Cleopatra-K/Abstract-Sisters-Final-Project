#include "Mangrove.h"

Mangrove::Mangrove(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Aquatic(n, p, desc, colourType, season){

}

void Mangrove::add(PlantType* plant){

}

void Mangrove::remove(PlantType* plant){

}

std::vector<PlantType*> Mangrove::getChildren(){
    return std::vector<PlantType*>();
}

Mangrove::Mangrove() : Aquatic("Mangrove", 55.0, "Coastal tree that grows in saltwater") {}

Mangrove::Mangrove(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season) 
    : Aquatic(n, p, desc, colourType) {
        (void)season;
    }

PlantType* Mangrove::clone() const {
    return new Mangrove(*this);
}

std::string Mangrove::getCategory() const {
    return "Tree";
}

void Mangrove::display() const {
    std::cout << "Mangrove: " << getName() << " | Price: R" << getPrice() 
        << " | " << getDescription() << std::endl;
}

void Mangrove::fertilize() { 
    std::cout << "Fertilizing mangrove" << std::endl; 
}

void Mangrove::grow() { 
    std::cout << "Mangrove growing in water" << std::endl; 
}

void Mangrove::giveAttention() { 
    std::cout << "Maintaining mangrove habitat" << std::endl; 
}

void Mangrove::removeWeed() { 
    std::cout << "Cleaning around mangrove roots" << std::endl; 
}

void Mangrove::water() { 
    std::cout << "Mangrove in its natural water environment" << std::endl; 
}

void Mangrove::sunlight() { 
    std::cout << "Mangrove enjoying coastal sunlight" << std::endl; 
}
