#ifndef AQUARIUM_FIELD_H
#define AQUARIUM_FIELD_H

#pragma once

#include <vector>
#include "Creature.h"
#include "Cell.h"
#include <algorithm>
#include <iostream>
#include <queue>

class Field {
private:
    bool isValid(int,int);
    void liveFun();
    long creatureNumber = 0;
    std::vector<Creature*> creatureList = std::vector<Creature*>();
    std::queue<Creature*> q = std::queue<Creature*>();
    Cell field[40][40];
    int size = 40;
    int iteration = 0;
public:
    Field();
    Field(int);
    void printField();
    void setNewCreature(Creature*,bool que = false);
    void removeCreature(Creature*);
    int getSize();
    Creature* getInstance(int,int,std::string);
    void shift(Creature*,int,int);
    void run(int iter = 0);
    ~Field() = default;
    int plankton = 0;
    int goats= 0;
    int predators = 0;


};


#endif //AQUARIUM_FIELD_H
