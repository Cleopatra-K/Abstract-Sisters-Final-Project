#ifndef BONSAITREE_H
#define BONSAITREE_H

#include "Indoor.h"
#include "BreadthFirstIterator.h"
#include <iostream>

class BonsaiTree : public Indoor {
public:
    BonsaiTree();
    BonsaiTree(const std::string& n, double p, const std::string& desc,
               const std::string& colourType, const std::string& season);
    ~BonsaiTree() override {};
    BonsaiTree(const BonsaiTree& other) : Indoor(other) {}


    PlantType* clone() const override;
    std::string getCategory() const override;
    void display() const override;

protected:
    virtual void fertilize() override;
    virtual void grow() override;
    virtual void giveAttention() override;
    virtual void removeWeed() override;
    virtual void water() override;
    virtual void sunlight() override;

    void add(PlantType* plant);
    void remove(PlantType* plant);
    std::vector<PlantType*> getChildren();
    Iterator* createIterator() override;
};

#endif
