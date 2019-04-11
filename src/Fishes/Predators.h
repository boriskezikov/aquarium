#ifndef AQUARIUM_CARNIVORES_H
#define AQUARIUM_CARNIVORES_H

#include "Creature.h"
#include "Field.h"
#include <random>

class Predators : public Creature {
public:
    Predators(int,int,Field*);
    bool stepForward() override;
    Creature* breedDescendant() override;
    void move() override;
    ~Predators() = default;

private:
    Creature* getClosest();
    Creature* checkField(int,int);
    void eat();
    Field* field;
};


#endif //AQUARIUM_CARNIVORES_H
