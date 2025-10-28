#include "WaterLily.h"

WaterLily::WaterLily(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Aquatic(n, p, desc, colourType, season){

}

void WaterLily::add(PlantType* plant){

}

void WaterLily::remove(PlantType* plant){

}

std::vector<PlantType*> WaterLily::getChildren(){
    return std::vector<PlantType*>();
}
