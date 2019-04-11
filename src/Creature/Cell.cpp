#include "Cell.h"

bool Cell::remove(Creature *instance) {
    if (instance->getType() == "Plankton") {
        plankton.erase(std::remove(plankton.begin(),plankton.end(), instance), plankton.end());
        return true;

    } else if (instance->getType() == "Predators") {
        predators.erase(std::remove(predators.begin(), predators.end(), instance), predators.end());
        return true;

    } else if (instance->getType() == "Goats") {
        goats.erase(std::remove(goats.begin(), goats.end(), instance), goats.end());
        return true;
    }
    return false;
}
