#include "SpecialArrangement.h"
#include <iostream>

SpecialArrangement::SpecialArrangement(PlantType* plant) : PlantDecorator(plant) {
}
void SpecialArrangement::decorate()
{
    if (plant != nullptr){
        plant->decorate();
    }
    std::cout << "Adding special arrangement: ceramic pot, ribbon, and personalized card." << std::endl;
    std::cin>> "Enter personal message">> message >> std::endl;
    std::cout <<"Personalized Message: "<<message<<std::endl; 
}