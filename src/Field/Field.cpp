#include "Field.h"
#include <stdlib.h>
#include <cstdlib>
#include <thread>
#include <chrono>


Field::Field() {
   for (int i = 0; i < getSize(); i++) {
       for (int j = 0; j < getSize(); j++) {
           field[i][j] = Cell();
       }
   }
}

Field::Field(int number) {

}

void Field::printField() {
    std::system("clear");
    std::cout << "Iteration " << ++iteration << std::endl;
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            if (field[i][j].goats.empty() && field[i][j].predators.empty() && field[i][j].plankton.empty())
                std::cout << "  ";
            else if (field[i][j].goats.size() >= field[i][j].predators.size()
            && field[i][j].goats.size() >= field[i][j].plankton.size())
                std::cout << "G ";
            else if(field[i][j].predators.size() >= field[i][j].plankton.size()
            && field[i][j].predators.size() >= field[i][j].predators.size())
                std::cout << "P ";
            else
                std::cout << ".";

            if (j == getSize()) std::cout << '|';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Field::setNewCreature(Creature* newInstance, bool que) {
    if (newInstance == nullptr) return;

    if (newInstance->getType() == "Plankton") {
        field[newInstance->getY()][newInstance->getX()]
        .plankton.push_back(newInstance);
        plankton++;
    } else if (newInstance->getType() == "Predators") {
        field[newInstance->getY()][newInstance->getX()]
        .predators.push_back(newInstance);
        predators++;
    } else if (newInstance->getType() == "Goats") {
        field[newInstance->getY()][newInstance->getX()]
        .goats.push_back(newInstance);
        goats++;
    }
    if (!que) q.push(newInstance);
    creatureList.push_back(newInstance);
    creatureNumber++;
}

void Field::removeCreature(Creature* instance) {
    if (std::find(creatureList.begin(), creatureList.end(), instance) != creatureList.end()) {
        field[instance->getY()][instance->getX()].remove(instance);
        creatureList.erase(std::remove(creatureList.begin(), creatureList.end(), instance), creatureList.end());
        creatureNumber--;
        instance->kill();
    }
}

int Field::getSize() {
    return size;
}

void Field::liveFun() {
    std::queue<Creature*> tmp;
    while (!q.empty()) {
        if (q.front()->stepForward()) {
            tmp.push(q.front());
            Creature* creature = q.front()->breedDescendant();
            if (creature != nullptr) {
                setNewCreature(creature, true);
                tmp.push(creature);
            }
        }
        q.pop();
    }
    printField();
    q = tmp;
}

Creature* Field::getInstance(int x, int y, std::string type) {
    if (isValid(x, y)) {
        if (type == "Plankton") {
            if (!field[y][x].plankton.empty())
                return field[y][x].plankton[0];
        } else if (type == "Goats")
            if (!field[y][x].goats.empty())
                return field[y][x].goats[0];
    }

    return nullptr;
}


void Field::shift(Creature *newInstance, int x, int y) {
    field[y][x].remove(newInstance);

    if (newInstance->getType() == "Plankton") {
        field[newInstance->getY()][newInstance->getX()]
                .plankton.push_back(newInstance);
    } else if (newInstance->getType() == "Predators") {
        field[newInstance->getY()][newInstance->getX()]
                .predators.push_back(newInstance);
    } else if (newInstance->getType() == "Goats") {
        field[newInstance->getY()][newInstance->getX()]
                .goats.push_back(newInstance);
    }
}

void Field::run(int iter) {
    if (iter == 0) {
        while (creatureNumber != 0)
            liveFun();
    } else {
        while (iter -- > 0)
            liveFun();
    }
}

bool Field::isValid(int x, int y) {
    return x >= 0 && x < getSize() && y >=0 && y < getSize();
}
