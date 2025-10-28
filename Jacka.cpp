#include "Jacka.h"

Jacka::Jacka(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Outdoor(n, p, desc, colourType, season){

}

void Jacka::add(PlantType* plant){

}

void Jacka::remove(PlantType* plant){

}

std::vector<PlantType*> Jacka::getChildren(){
    return std::vector<PlantType*>();
}
