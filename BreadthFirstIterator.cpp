#include "BreadthFirstIterator.h"
#include <iostream>
class Bundle;
#include "Bundle.h"

BreadthFirstIterator::BreadthFirstIterator(const std::vector<PlantType*>& topLevelPlants)
    : current_(nullptr)
{
    // Initialize the queue with all top-level plants
    for (auto* plant : topLevelPlants)
        queue_.push(plant);
}

void BreadthFirstIterator::first() {
    // Start traversal from the first element
    if (!queue_.empty())
        current_ = queue_.front();
}

void BreadthFirstIterator::next() {
    if (queue_.empty()) {
        current_ = nullptr;
        return;
    }

    // Get current item and pop it
    PlantType* currentPlant = queue_.front();
    queue_.pop();

    // If it's a Bundle, enqueue its children
    Bundle* bundle = dynamic_cast<Bundle*>(currentPlant);
    if (bundle) {
        const std::vector<PlantType*>& children = bundle->getChildren();
        for (auto* child : children)
            queue_.push(child);
    }

    // Update current_ to next element if available
    current_ = queue_.empty() ? nullptr : queue_.front();
}

bool BreadthFirstIterator::hasNext() const {
    return !queue_.empty();
}

PlantType* BreadthFirstIterator::currentItem() const {
    return current_;
}
