#include "Rose.h"

Rose::Rose(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Outdoor(n, p, desc, colourType, season){

}

void Rose::add(PlantType* plant){

}

void Rose::remove(PlantType* plant){

}

std::vector<PlantType*> Rose::getChildren(){
    return std::vector<PlantType*>();
}
