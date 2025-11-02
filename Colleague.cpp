#include "Colleague.h"
#include "Mediator.h"

Colleague::~Colleague() { }

void Colleague::sendMessage(const std::string& message) {
    if (mediator)
        mediator->sendMessage(message, this);
}
