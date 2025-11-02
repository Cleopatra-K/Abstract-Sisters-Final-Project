#ifndef OUTDOOR_H
#define OUTDOOR_H

#include "PlantType.h"
#include "BreadthFirstIterator.h"
#include <vector>
#include "NullIterator.h" //for leaf

/**
 * @class Outdoor
 * @brief Abstract subclass of PlantType for outdoor plants
 */
class Outdoor : public PlantType {
public:
    Outdoor(){};
    Outdoor(const std::string& n, double p, const std::string& desc,
            const std::string& colourType, const std::string& season)
        : PlantType(n, p, desc, colourType, season) {}

    // Provide default implementations for leaf-like behaviour
    Iterator* createIterator() override { return new NullIterator(); }

    virtual void add(PlantType*) override {}
    virtual void remove(PlantType*) override {}
    virtual std::vector<PlantType*> getChildren() override { return {}; }

    // This can remain abstract if you want `Outdoor` to be abstract
    virtual std::string getCategory() const override = 0;

    virtual ~Outdoor() = default;
};

#endif
