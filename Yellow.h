#ifndef YELLOW_H
#define YELLOW_H

#include "ColourImplementation.h"

class Yellow : public ColourImplementation {
public:
    Yellow() {}
    ~Yellow() override {}

    std::string fillColour() override {
        return "Yellow";
    }

    ColourImplementation* clone() const override {
        return new Yellow(*this);
    }
};

#endif
