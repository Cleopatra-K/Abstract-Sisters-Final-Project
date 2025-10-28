/*
Possible subtypes (categories) of plant factories.
*/
#ifndef OUTDOOR_H
#define OUTDOOR_H
#include "PlantType.h"

/**
 * @class OutdoorPlant  
 * @brief Plants that live outside in the garden
 * @author Cleopatra
 * 
 * These plants like sunshine, rain, and lots of space to grow.
 * Examples: Roses, Sunflowers, Trees
 */
class Outdoor: public PlantType {
public:
    Outdoor(const std::string& n, double p, const std::string& desc) 
        : PlantType(n, p, desc) {}

    Outdoor(const std::string& n, double p, const std::string& desc, std::string& colourType) 
        : PlantType(n, p, desc) {(void)colourType;}

    virtual PlantType* clone() const override = 0;
    virtual std::string getCategory() const override = 0;  // Still pure virtual
    virtual void display() const override = 0;
    // std::string Outdoor::getCategory() const override {
    //     return "Outdoor";
    // }

    // void Outdoor::display() const override {
    //     std::cout << "Outdoor Plant: " << getName() << " | Price: R" << getPrice() 
    //             << " | " << getDescription() << std::endl;
    // }
    

    //@TheDzashe please check
    // void add(PlantType* component) override;
    // void remove(PlantType* component) override;
    // std::vector<PlantType*> getChildren() override;
};
#endif