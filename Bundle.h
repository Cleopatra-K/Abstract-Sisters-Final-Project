#ifndef BUNDLE_H
#define BUNDLE_H

#include "PlantType.h"
#include "BreadthFirstIterator.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Bundle : public PlantType {
private:
    std::vector<PlantType*> plants;

public:
    // Constructors
    Bundle() {}
    Bundle(const std::string& bundleName)
        : PlantType(bundleName, 0.0, "Bundle container", "", "") {}

    // Destructor: delete all cloned plants
    ~Bundle() override {
        for (PlantType* p : plants)
            delete p;
        plants.clear();
    }

    // No copy constructor or assignment operator: use clone() instead
    Bundle(const Bundle&) = delete;
    Bundle& operator=(const Bundle&) = delete;

    // Add a plant: clones it for safe ownership
    void add(PlantType* plant) override {
        if (plant)
            plants.push_back(plant->clone());
    }

    // Remove a plant by unique ID
    void remove(PlantType* plant) override {
        auto it = std::remove_if(plants.begin(), plants.end(),
            [&](PlantType* p) {
                return p->getUniqueID() == plant->getUniqueID();
            });
        for (auto itr = it; itr != plants.end(); ++itr)
            delete *itr;
        plants.erase(it, plants.end());
    }

    // Get all children
    std::vector<PlantType*> getChildren() override {
        return plants;
    }

    // Create a Breadth-First iterator
    Iterator* createIterator() override {
        return new BreadthFirstIterator(plants);
    }

    // Deep clone the bundle
    PlantType* clone() const override {
        Bundle* copy = new Bundle(getName());
        for (auto* child : plants)
            copy->add(child); // add() already clones
        return copy;
    }

    // Category
    std::string getCategory() const override { return "Bundle"; }

    // Display
    void display() const override {
        std::cout << "Bundle: " << getName()
                  << " contains " << plants.size() << " plants." << std::endl;
    }

    void printSize() const {
        std::cout << "Bundle has " << plants.size() << " plants.\n";
    }

    // Template operations (do nothing for bundles)
    void fertilize() override {}
    void grow() override {}
    void giveAttention() override {}
    void removeWeed() override {}
    void water() override {}
    void sunlight() override {}
    void careForPlant() override {}
};

#endif
