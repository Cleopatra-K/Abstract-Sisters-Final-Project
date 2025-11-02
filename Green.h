#ifndef GREEN_H
#define GREEN_H

#include "ColourImplementation.h"

class Green : public ColourImplementation {
public:
    Green() {}
    ~Green() override {}

    std::string fillColour() override {
        return "Green";
    }

    // Implement clone
    ColourImplementation* clone() const override {
        return new Green(*this); // copy constructor
    }
};

#endif
