#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

// Forward declarations to avoid circular inclusion
class Customer;
class GreenHouseStaff;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class PurchaseCommand : public Command {
    Customer* customer;
public:
    PurchaseCommand(Customer* c) : customer(c) {}
    void execute() override;
};

class RemovePlantCommand : public Command {
    Customer* customer;
public:
    RemovePlantCommand(Customer* c) : customer(c) {}
    void execute() override;
};


class WaterPlantCommand : public Command {
    GreenHouseStaff* staff;
public:
    WaterPlantCommand(GreenHouseStaff* s) : staff(s) {}
    void execute() override;
};

class DecoratePotCommand : public Command {
    GreenHouseStaff* staff;
public:
    DecoratePotCommand(GreenHouseStaff* s) : staff(s) {}
    void execute() override;
};

#endif
