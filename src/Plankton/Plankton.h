#ifndef AQUARIUM_PLANKTON_H
#define AQUARIUM_PLANKTON_H


#include "Creature.h"
#include "Field.h"
#include <random>

class Field;

class Plankton : public Creature {
public:
    Plankton(int,int,Field*);
    bool stepForward() override;
    Creature* breedDescendant() override;
    void move() override;
    ~Plankton() = default;

private:
    Field *field;
};


#endif //AQUARIUM_PLANKTON_H
