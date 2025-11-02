#ifndef RED_H
#define RED_H

#include "ColourImplementation.h"

class Red : public ColourImplementation {
public:
    Red() {}
    ~Red() override {}

    std::string fillColour() override {
        return "Red";
    }

    ColourImplementation* clone() const override {
        return new Red(*this);
    }
};

#endif
