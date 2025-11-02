#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include <queue>
#include <vector>
#include "Iterator.h"
#include "PlantType.h"
// #include "Bundle.h"

class BreadthFirstIterator : public Iterator {
private:
    std::queue<PlantType*> queue_;   // BFS uses a queue
    PlantType* current_;             // Current node being visited

public:
    explicit BreadthFirstIterator(const std::vector<PlantType*>& topLevelPlants);

    void first() override;
    void next() override;
    bool hasNext() const override;
    PlantType* currentItem() const override;
};

#endif
