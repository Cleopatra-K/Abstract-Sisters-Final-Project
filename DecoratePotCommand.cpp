#include "DecoratePotCommand.h"
#include <iostream>
#include "Staff.h"


void DecoratePotCommand::execute()
{
    std::cout << staff->getName() << " is decorating the pot.\n";
    staff->sendMessage("Pot decoration complete.");
}
