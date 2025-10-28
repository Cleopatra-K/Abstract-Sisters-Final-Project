/**
 * @file PotDecorator.cpp
 * @author Jessica Marodi
 * @brief Implementation of PotDecorator 
 */

#include "PotDecorator.h"
#include <iostream>
#include <string>
void PotDecorator::decorate()
{
    PlantDecorator::decorate();
    
    std::cout << "\033[34m" << "🪴 Placing the plant in a fancy ceramic pot.\n"<< "\033[0m"<< std::endl;
        
}