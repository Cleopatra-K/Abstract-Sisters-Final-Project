#include "Bundle.h"

Bundle::Bundle(std::string& bundleName){
    name = bundleName;
}

void Bundle::add(PlantType* plant){
    plants.push_back(plant);
}

void Bundle::remove(PlantType* plant){
    for (size_t i = 0; i < plants.size(); i++) {
        if (plants[i] == plant) {
            plants.erase(plants.begin() + i);
            break;
        }
    }
}


std::vector<PlantType*> Bundle::getChildren(){
    return plants;
}