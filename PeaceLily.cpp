#include "PeaceLily.h"

PeaceLily::PeaceLily(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Indoor(n, p, desc, colourType, season){

}

void PeaceLily::add(PlantType* plant){

}

void PeaceLily::remove(PlantType* plant){

}

std::vector<PlantType*> PeaceLily::getChildren(){
    return std::vector<PlantType*>();
}
