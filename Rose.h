/**
 * @file Outdoor.h
 * @brief Inherited from PlantType
 *
*/
#ifndef ROSE_H
#define ROSE_H
#include "Outdoor.h"

/**
 * @class Rose
 * @brief A beautiful outdoor flower with thorns
 * @author Cleopatra
 */
class Rose : public OutdoorPlant {
public:
    Rose();
    PlantType* clone() const override;
};
#endif