/*
Abstract base class for components (Staff, Customer) that communicate through the Mediator.
*/

#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>
#include "Mediator.h"

class Colleague {
protected:
    Mediator* mediator;
    std::string name;
public:
    Colleague();
    Colleague(Mediator* med, const std::string& n): mediator(med), name(n) {}
    virtual ~Colleague();

    virtual void receiveMessage(const std::string& message) = 0;
    virtual void sendMessage(const std::string& message);
    virtual std::string getName(){ return name;};
};

#endif
