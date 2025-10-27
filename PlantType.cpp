#include "PlantType.h"
#include "ColourImplementation.h"
#include "Green.h"
#include "Yellow.h"
#include "Red.h"

ColourImplementation* PlantType::createColour(std::string colourType){
    if(colourType == "green")
        return new Green();
    else if(colourType == "yellow")
        return new Yellow();
    else if(colourType == "red")
        return new Red();
    else
        return NULL;
}

std::string PlantType::getColour(){
    if(colourImpl == NULL){
        return "no colour";
    }
    return colourImpl->fillColour();
}

bool PlantType::hasColour(){
    return colourImpl != NULL;
}

PlantType::PlantType(const std::string& n, double p, const std::string& desc, std::string& colourType, std::string season){
    name = n;
    price = p;
    description = desc;
    colourImpl = createColour(colourType);
    this->season = season;
}

PlantType::~PlantType(){
    if(colourImpl){
        delete colourImpl;
    }
}

void PlantType::setColour(std::string& colourType){
    if(colourImpl){
        delete colourImpl;
    }
    colourImpl = createColour(colourType);
}