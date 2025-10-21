#include "Colleague.h"
#include "Mediator.h"

void Colleague::sendMessage(const std::string& message) {
    if (mediator)
        mediator->sendMessage(message, this);
}
