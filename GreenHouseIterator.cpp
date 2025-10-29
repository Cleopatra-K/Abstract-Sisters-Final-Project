#include "GreenHouseIterator.h"

/**
 * @brief Constructor for GreenHouseIterator
 * @param p Reference to the plant collection
 */
GreenHouseIterator::GreenHouseIterator(std::vector<PlantType*>& p)
    : plants(p), index(0) {
}

/**
 * @brief Resets the iterator to the first element
 */
void GreenHouseIterator::first() {
    index = 0;
}

/**
 * @brief Moves to the next element in the collection
 */
void GreenHouseIterator::next() {
    if (hasNext()) {
        ++index;
    }
}

/**
 * @brief Checks if there are more elements to iterate over
 * @return true if more elements exist, false otherwise
 */
bool GreenHouseIterator::hasNext() const {
    return index < plants.size();
}

/**
 * @brief Returns the current element in the iteration
 * @return Pointer to the current PlantType, or nullptr if iteration is done
 */
PlantType* GreenHouseIterator::currentItem() const {
    if (index < plants.size()) {
        return plants[index];
    }
    return nullptr;
}