// #ifndef SPECIALARRANGEMENTDECORATOR_H
// #define SPECIALARRANGEMENTDECORATOR_H

// #include "PlantDecorator.h"
// #include <iostream>

// class SpecialArrangementDecorator : public PlantDecorator {
// private:
//     std::string message;
//     std::string occasion;

// public:
//     SpecialArrangementDecorator(PlantType* plant, const std::string& msg, const std::string& occ)
//         : PlantDecorator(plant), message(msg), occasion(occ) {}

//     double getPrice() const override {
//         double extra = 15.0; // base fee
//         if (!occasion.empty()) extra += 5.0; // e.g., special theme costs extra
//         return decoratedPlant->getPrice() + extra;
//     }

//     std::string getDescription() const override {
//         std::string desc = decoratedPlant->getDescription() + " (Special Arrangement";
//         if (!occasion.empty()) desc += " for " + occasion;
//         if (!message.empty()) desc += ": \"" + message + "\"";
//         desc += ")";
//         return desc;
//     }
// };

// #endif

#ifndef SPECIALARRANGEMENTDECORATOR_H
#define SPECIALARRANGEMENTDECORATOR_H

#include "PlantDecorator.h"

class SpecialArrangementDecorator : public PlantDecorator {
private:
    std::string occasion;
    std::string message;
    double arrangementPrice;

public:
    SpecialArrangementDecorator(PlantType* plant, const std::string& occ,
                                const std::string& msg, double price = 7.0)
        : PlantDecorator(plant), occasion(occ), message(msg), arrangementPrice(price) {}

    double getPrice() const override {
        return decoratedPlant->getPrice() + arrangementPrice;
    }

    std::string getDescription() const override {
        return decoratedPlant->getDescription() + " + Special Arrangement [" +
               occasion + ": " + message + "]";
    }

    PlantType* clone() const override {
        return new SpecialArrangementDecorator(decoratedPlant->clone(), occasion, message, arrangementPrice);
    }
};

#endif
