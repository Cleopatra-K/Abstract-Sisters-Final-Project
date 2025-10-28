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
