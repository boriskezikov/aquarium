#include "Plankton.h"

Plankton::Plankton(int x, int y, Field* initField) : Creature(0, 20, 6, x, y, "Plankton"){
    field = initField;
}

bool Plankton::stepForward() {
    if(aliveParam) {
        liveTime++;
        if (liveTime >= LIVE_TIME) {
            field->removeCreature(this);
            field->plankton--;
        } else {
            move();
            return true;
        }
    }
    return false;
}

Creature* Plankton::breedDescendant() {
    int xShift = rand()%10;
    int yShift = rand()%10;
    bool isTime = true; //random()%2 == 0;

    if(liveTime % BREEDING_TIME != 0 || !isTime) return nullptr;

    while(xPos + xShift >= field->getSize() || xPos + xShift < 0
    || yPos + yShift >= field->getSize() || yPos + yShift < 0) {
        xShift = rand()%10;
        yShift = rand()%10;
    }
    return new Plankton(xPos + xShift, yPos + yShift, field);
}

void Plankton::move() {
    bool isStand = rand()%2 == 0;
    bool isLeft = rand()%2 == 0;
    bool isUp = rand()%2 == 0;
    int nextY;
    int nextX;

    if(!isStand && liveTime % 2 == 0) {
        if (isLeft) {
            if (xPos - 1 > 0) nextX = xPos - 1;
            else nextX = xPos + 1;
        } else {
            if (xPos + 1 < field->getSize()) nextX = xPos + 1;
            else nextX = xPos - 1;
        }

        if (isUp) {
            if (yPos - 1 > 0) nextY = yPos - 1;
            else nextY = yPos + 1;
        } else {
            if (yPos + 1 < field->getSize()) nextY = yPos + 1;
            else nextY = yPos - 1;
        }

        int prevX = xPos;
        int prevY = yPos;

        xPos = nextX;
        yPos = nextY;
        field->shift(this, prevX, prevY);
    }
}
