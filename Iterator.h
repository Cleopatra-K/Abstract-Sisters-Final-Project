#ifndef ITERATOR_H
#define ITERATOR_H
/*
Iterator interface defining methods like next() and hasNext().
*/

#include "PlantType.h"
class Iterator
{

public:
    virtual ~Iterator(){};
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0; //check if the traversal is done 
    virtual PlantType* currentItem() const = 0; 
};

#endif