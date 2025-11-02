#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
class PlantType;

class PlantState {
public:
    virtual ~PlantState() {}
    virtual void displayState() const= 0;
    virtual void changeState(PlantType* plant) = 0;
    virtual void handleGrowth(PlantType* plant) = 0;
    virtual std::string getStateName() const = 0;

    // Pure virtual clone method for derived classes
    virtual PlantState* clone() const = 0;
};

#endif
