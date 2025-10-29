#ifndef INTERACTIONSTRATEGY_H
#define INTERACTIONSTRATEGY_H

#include <string>
#include "PlantType.h"

class InteractionStrategy {
public:
    virtual ~InteractionStrategy() {}
    virtual void execute(PlantType* plant) = 0;
};

#endif
