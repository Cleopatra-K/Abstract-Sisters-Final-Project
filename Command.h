#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

class Customer;
class SalesStaff;
class GreenHouseStaff;
class PlantType;

// ---------------- Base Command ----------------
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

// ---------------- Customer Commands ----------------
class PurchaseCommand : public Command {
    Customer* customer;
    PlantType* plant;
public:
    PurchaseCommand(Customer* c, PlantType* p) : customer(c), plant(p) {}
    void execute() override;
};

class RemovePlantCommand : public Command {
    Customer* customer;
    PlantType* plant;
public:
    RemovePlantCommand(Customer* c, PlantType* p) : customer(c), plant(p) {}
    void execute() override;
};

// ---------------- Staff Commands ----------------
class WaterPlantCommand : public Command {
    GreenHouseStaff* staff;
    PlantType* plant;
public:
    WaterPlantCommand(GreenHouseStaff* s, PlantType* p) : staff(s), plant(p) {}
    void execute() override;
};

// ---------------- Decoration Command ----------------
class AddDecorationCommand : public Command {
private:
    SalesStaff* staff;
    PlantType* plant;
    std::string decorationType;  // e.g., "Pot", "GiftWrap", "SpecialArrangement"
    std::string message;         // optional custom message
    std::string occasion;        // optional occasion (e.g., "Mother's Day")

public:
    AddDecorationCommand(
        SalesStaff* s,
        PlantType* p,
        const std::string& type,
        const std::string& msg = "",
        const std::string& occ = ""
    ) : staff(s), plant(p), decorationType(type), message(msg), occasion(occ) {}

    void execute() override;
};

#endif
