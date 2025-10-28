/*
Possible subtypes (categories) of plant factories.
*/
#ifndef INDOOR_H
#define INDOOR_H
#include "PlantType.h"

/**
 * @class IndoorPlant
 * @brief Plants that live inside your house
 * @author Cleopatra
 * 
 * These plants like being inside where it's warm and safe.
 * Examples: Peace Lilies, Spider Plants, Succulents
 */
class Indoor: public PlantType {
public:
    Indoor(const std::string& n, double p, const std::string& desc) 
        : PlantType(n, p, desc) {}

    Indoor(const std::string& n, double p, const std::string& desc, std::string& colourType) 
        : PlantType(n, p, desc) {(void)colourType;}

    virtual PlantType* clone() const override = 0;
    std::string getCategory() const override = 0;  // Still pure virtual
    void display() const override = 0;
    // std::string Indoor::getCategory() const override {
    // return "Indoor";
    // }

    // void Indoor::display() const override {
    //     std::cout << "Indoor Plant: " << getName() << " | Price: R" << getPrice() 
    //             << " | " << getDescription() << std::endl;
    // }

    //composite stuff @TheDzashe please check
    // void add(PlantType* component) override;
    // void remove(PlantType* component) override;
    // std::vector<PlantType*> getChildren() override;


};
#endif