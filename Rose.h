#ifndef ROSE_H
#define ROSE_H

#include <vector>
#include <string>
#include "Outdoor.h"
#include "BreadthFirstIterator.h"

/**
 * @class Rose
 * @brief A beautiful outdoor flower with thorns
 * 
 * Participates in:
 * - Composite: Leaf
 * - Prototype: clone()
 */
class Rose : public Outdoor {
public:
    Rose();
    Rose(const std::string& n, double p, const std::string& desc,
         const std::string& colourType, const std::string& season);
    ~Rose() override {};

    // Prototype
    PlantType* clone() const override;

    // Composite Leaf
    std::string getCategory() const override;
    void display() const override;

    // Iterator (Leaf version)
    Iterator* createIterator() override;

    // Composite leaf methods (no children)
    void add(PlantType* plant) override;
    void remove(PlantType* plant) override;
    std::vector<PlantType*> getChildren() override;

protected:
    // Template operations
    void fertilize() override;
    void grow() override;
    void giveAttention() override;
    void removeWeed() override;
    void water() override;
    void sunlight() override;
};

#endif
