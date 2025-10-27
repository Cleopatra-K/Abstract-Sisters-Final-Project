#ifndef STAFF_H
#define STAFF_H

/*
Abstract base class for staff roles. Communicates through the Mediator.
*/

#include "Colleague.h"
#include <iostream>
#include <string>

class Staff : public Colleague {
protected:
    Staff* nextHandler = nullptr;

public:
    Staff(Mediator* med, const std::string& n)
        : Colleague(med, n) {}   

    virtual ~Staff() = default;

    void setNextHandler(Staff* next) { nextHandler = next; }

    virtual void handleRequest(const std::string& request) = 0;

    void sendMessage(const std::string& msg) override {
        mediator->sendMessage(msg, this);
    }

};

#endif
