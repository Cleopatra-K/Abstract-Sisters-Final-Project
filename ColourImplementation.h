#ifndef COLOURIMPLEMENTATION_H
#define COLOURIMPLEMENTATION_H

#include <string>

class ColourImplementation{
    public:
        virtual ~ColourImplementation();
        virtual std::string fillColour() = 0;
};

#endif