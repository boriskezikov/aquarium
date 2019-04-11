#include "Creature.h"

Creature::Creature(int hungerMax, int live, int breed, int x, int y, std::string type) :
LIVE_TIME(live), BREEDING_TIME(breed), xPos(x), yPos(y), MAX_HUNGER(hungerMax), hunger(hungerMax/2), type(type){}

bool Creature::isAlive() {
    return aliveParam;
}

bool Creature::DeathTime() {
    return liveTime == LIVE_TIME;
}

void Creature::kill() {
    aliveParam = false;
}

std::string Creature::getType() {
    return type;
}

int Creature::getX() {
    return xPos;
}

int Creature::getY() {
    return yPos;
}

bool Creature::isHungerDeath() {
    return hunger >= MAX_HUNGER;
}

void Creature::setFamine(int newHunger) {
    hunger = newHunger;
}