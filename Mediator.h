/*
Base interface for mediators. Defines communication between components.
*/

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

class Colleague;

class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void sendMessage(const std::string& message, Colleague* sender) = 0;
};

#endif
