#ifndef NULLITERATOR_H
#define NULLITERATOR_H

#include "Iterator.h"
#include "PlantType.h"

class NullIterator : public Iterator {
public:
    void first() override {}
    void next() override {}
    bool hasNext() const override { return false; }
    PlantType* currentItem() const override { return nullptr; }
};

#endif
