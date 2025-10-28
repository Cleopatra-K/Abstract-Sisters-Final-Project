#ifndef SPECIALARRANGEMENT_H
#define SPECIALARRANGEMENT_H
#include "PlantDecorator.h"
/*
Special arrangement.
*/
class SpecialArrangement : public PlantDecorator{
 
    void decorate() override;
};

#endif //SPECIALARRANGEMENT_H