/*
Creates flowering plants (roses, lilies, etc.).
*/
#ifndef FLOWERFACTORY_H
#define FLOWERFACTORY_H


#include "PlantFactory.h" 
// Forward declarations of Concrete Products handled by this factory 
class Rose;
class Jacaranda;
class PeaceLily;
class WaterLily;

/**
 * @class FlowerFactory
 * @brief A concrete factory that creates various flower and aquatic plant products.
 */
class FlowerFactory : public PlantFactory {
public:
    // Factory Method 1 (Default creation): Default Product is Rose 
    PlantType* createPlant() const override; 

    // Factory Method 2 (Price specified creation): Default Product is Rose 
    PlantType* createPlant(double price) const override;

    // Specific flower creation methods (implementations defer instantiation)
    PlantType* createRose(double price = 25.0) const; 
    PlantType* createPeaceLily(double price = 30.0) const; 
    PlantType* createWaterLily(double price = 35.0) const; 
    
    // Required accessor to identify this factory 
    std::string getFactoryType() const override;
};

#endif