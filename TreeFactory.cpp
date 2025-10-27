#include "TreeFactory.h"
#include "BonsaiTree.h"
#include "Mangrove.h"
#include "Jacka.h" 

// Factory Method 1 (Default creation)
// Why: Implements the PlantFactory interface by returning the default product (BonsaiTree) 
// using its default constructor value.
PlantType* TreeFactory::createPlant() const {
    // Default price is 60.0 [6]
    return new BonsaiTree();
}

// Factory Method 2 (Price specified creation)
// Why: Implements the overloaded Factory Method for custom pricing
PlantType* TreeFactory::createPlant(double price) const {
    return new BonsaiTree(price);
}

// Specific tree creation methods (Convenience methods)

// Why: Provide specific, named access for products handled by this factory
PlantType* TreeFactory::createBonsai(double price) const {
    return new BonsaiTree(price);
}

PlantType* TreeFactory::createMangrove(double price) const {
    return new Mangrove(price);
}

// Jacaranda tree creation (using the class name Jacka)
PlantType* TreeFactory::createJacarandaTree(double price) const {
    return new Jacka(price);
}

// Required accessor
// Why: Identifies the concrete factory type to clients [11].
std::string TreeFactory::getFactoryType() const override {
    return "Tree Factory";
}
