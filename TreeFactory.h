/*
Creates tree-type plants (bonsai, baobab, mangrove, etc.).
*/
#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "PlantFactory.h" 
// Forward declarations of Concrete Products handled by this factory
class BonsaiTree;
class Mangrove;
class Jacaranda; 

/**
 * @class TreeFactory  
 * @brief A concrete factory that creates different types of trees.
 */
class TreeFactory : public PlantFactory {
public:
    // Factory Method 1 (Default creation): Default Product is BonsaiTree 
    PlantType* createPlant() const override;
    
    // Factory Method 2 (Price specified creation): Default Product is BonsaiTree 
    PlantType* createPlant(double price) const override;
    
    // Specific tree creation methods (implementations defer instantiation) 
    PlantType* createBonsai(double price = 60.0) const;
    PlantType* createMangrove(double price = 55.0) const;
    PlantType* createJacarandaTree(double price = 45.0) const;

    // Required accessor to identify this factory
    std::string getFactoryType() const override;
};

#endif