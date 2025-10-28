#include "TreeFactory.h"
#include "BonsaiTree.h"
#include "Mangrove.h"
#include "Jacka.h" 

// Factory Method 1: Create default tree (BonsaiTree)
PlantType* TreeFactory::createPlant() const {
    std::cout << "TreeFactory: Creating default Bonsai Tree..." << std::endl;
    return new BonsaiTree();  // Use default constructor
}

// Factory Method 2: Create default tree with custom price
PlantType* TreeFactory::createPlant(double price) const {
    std::cout << "TreeFactory: Creating Bonsai Tree with custom price..." << std::endl;
    return createBonsai(price);
}

PlantType* TreeFactory::createBonsai(double price) const {
    std::string colourType = "green";
    std::string name = "Bonsai Tree";
    std::string desc = "Miniature cultivated tree requiring expert care";
    BonsaiTree* bonsai = new BonsaiTree(name, price, desc, colourType);
    std::cout << "Created: Bonsai Tree at R" << price << std::endl;
    return bonsai;
}

PlantType* TreeFactory::createMangrove(double price) const {
    std::string colourType = "green";
    std::string name = "Mangrove";
    std::string desc = "Salt-tolerant coastal tree";
    Mangrove* mangrove = new Mangrove(name, price, desc, colourType);
    std::cout << "Created: Mangrove at R" << price << std::endl;
    return mangrove;
}

PlantType* TreeFactory::createJacarandaTree(double price) const {
    std::string colourType = "purple";
    std::string name = "Jacaranda";
    std::string desc = "Stunning purple-flowering tree";
    Jacka* jacaranda = new Jacka(name, price, desc, colourType);
    std::cout << "Created: Jacaranda Tree at R" << price << std::endl;
    return jacaranda;
}

std::string TreeFactory::getFactoryType() const {
    return "TreeFactory";
}