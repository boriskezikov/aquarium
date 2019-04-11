#ifndef AQUARIUM_CELL_H
#define AQUARIUM_CELL_H

#include "Creature.h"
#include <vector>
#include <algorithm>


class Cell {
public:
    std::vector<Creature*> plankton = std::vector<Creature*>();
    std::vector<Creature*> goats = std::vector<Creature*>();
    std::vector<Creature*> predators = std::vector<Creature*>();

    ~Cell() = default;

    bool remove(Creature*);
};


#endif //AQUARIUM_CELL_H
