/**
 * @file GiftWrap.cpp
 * @author Jessica Marodi
 * @brief Implementation of GiftWrap decorator
 */

#include "GiftWrap.h"
#include <iostream>

GiftWrap::GiftWrap(PlantType* plant) : PlantDecorator(plant) {
}

GiftWrap::~GiftWrap() {
}

void GiftWrap::decorate() {
    PlantDecorator::decorate();
    if (plant != nullptr) {
        plant->decorate();
    }
    std::cout << "Adding gift wrapping" << std::endl;
    
}