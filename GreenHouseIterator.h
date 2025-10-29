#ifndef GREENHOUSEITERATOR_H
#define GREENHOUSEITERATOR_H

#include "Iterator.h"
#include <vector>

/**
 * @class GreenHouseIterator
 * @brief Concrete iterator for traversing through the greenhouse plants
 */
class GreenHouseIterator : public Iterator {
private:
    std::vector<PlantType*>& plants; ///< Reference to the greenhouse inventory
    size_t index;                    ///< Current index position in iteration

public:
    /**
     * @brief Constructs an iterator for the given inventory vector.
     * @param p Reference to the vector of PlantType pointers.
     */
    explicit GreenHouseIterator(std::vector<PlantType*>& p);

    // Iterator interface implementation
    void first() override;
    void next() override;
    bool hasNext() const override;
    PlantType* currentItem() const override;
};

#endif