#ifndef DECORATEPOTCOMMAND_H
#define DECORATEPOTCOMMAND_H
#include "Command.h"
#include "Customer.h"
#include "Staff.h"
#include "PotDecorator.h"
#include "PlantType.h"

class DecoratePotCommand : public Command{
public:
        PotDecorator* pot;
        Staff* staff;
        DecoratePotCommand(PotDecorator* p, Staff* s) : pot(p),staff(s) {
        }
        void execute() override;


};

#endif //DECORATEPOTCOMMAND_H