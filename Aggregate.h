#ifndef AGGREGATE_H
#define AGGREGATE_H
/*
Interface for creating iterators. Represents the collection of plants.
*/

#include "Iterator.h"

class Aggregate
{

public:
    virtual ~Aggregate(){};
    virtual Iterator* createIterator() = 0;
};

#endif