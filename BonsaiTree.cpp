#include "BonsaiTree.h"

BonsaiTree::BonsaiTree(const std::string &n, double p, const std::string &desc, std::string &colourType, std::string season):Indoor(n, p, desc, colourType, season){

}

void BonsaiTree::add(PlantType* plant){

}

void BonsaiTree::remove(PlantType* plant){

}

std::vector<PlantType*> BonsaiTree::getChildren(){
    return std::vector<PlantType*>();
}
