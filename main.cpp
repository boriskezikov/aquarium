#include <iostream>
#include "Field.h"
#include "Plankton.h"
#include "Predators.h"
#include "Goats.h"



int main() {
    Field field = Field();

    for (int i = 0; i < 20; i++) {
        field.setNewCreature(new Plankton(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Plankton(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Plankton(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Plankton(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Goats(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Goats(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Goats(random() % field.getSize(), random() % field.getSize(), &field));

        field.setNewCreature(new Goats(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Predators(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Predators(random() % field.getSize(), random() % field.getSize(), &field));
        field.setNewCreature(new Predators(random() % field.getSize(), random() % field.getSize(), &field));

    }

    field.run();

    getchar();
}