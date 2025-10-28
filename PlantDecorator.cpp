/**
 * @file PlantDecorator.cpp
 * @author Jessica Marodi
 * @brief Implementation of PlantDecorator
 */

#include <iostream>
#include "PlantDecorator.h"
#include "PlantType.h"

PlantDecorator::PlantDecorator(PlantType* comp) : plant(comp) {}

PlantDecorator::~PlantDecorator()
{
}

void PlantDecorator::decorate()
{
    if (plant){
        plant->decorate();
    }
}
