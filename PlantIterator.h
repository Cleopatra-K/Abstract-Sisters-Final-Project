#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"
#include <vector>

/*
Concrete iterator for traversing through the nursery’s plants.
*/

class PlantIterator : public Iterator {
private:
    std::vector<PlantType*> plants;
    size_t index;

public:
    PlantIterator(const std::vector<PlantType*>& collection)
        : plants(collection), index(0) {}

    void first() override {
        index = 0;
    }

    void next() override {
        if (index < plants.size()) {
            ++index;
        }
    }

    bool hasNext() const override {
        return index >= plants.size();
    }

    PlantType* currentItem() const override {
        if (!hasNext()) {
            return plants[index];
        }
        return nullptr;
    }
};

#endif
