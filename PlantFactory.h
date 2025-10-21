/*
Abstract factory defining the interface for creating plants.
*/
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>
// Forward declaration of the Product interface (PlantType is the Product)
class PlantType; 

/**
 * @class PlantFactory
 * @brief Defines the abstract interface for creating PlantType objects.
 */
class PlantFactory {
public:
    // Virtual destructor is mandatory for base classes used polymorphically
    virtual ~PlantFactory() {} 

    // Factory Method 1: Declares the interface for creating a Product object using default construction 
    virtual PlantType* createPlant() const = 0;

    // Factory Method 2: Declares the interface for creating a Product object using a specified price
    virtual PlantType* createPlant(double price) const = 0;

    /**
     * @brief Template Method for a standardized creation process.
     * The implementation uses createPlant() internally
     */
    PlantType* createPlantWithProcess() {
        // Implementation provided inline by the source
        // std::cout << "Starting plant creation process..." << std::endl; 
        // PlantType* plant = createPlant();
        // std::cout << "Plant created successfully: " << plant->getName() << std::endl;
        // return plant;
    }

    // Required accessor to identify the concrete factory type
    virtual std::string getFactoryType() const = 0;
};

#endif
