// mazmorra.h
#ifndef MAZMORRA_H
#define MAZMORRA_H

#include <vector>
#include "sala.h"

class Mazmorra {
private:
    std::vector<Sala> rooms;
    int currentRoomIndex;

public:
    Mazmorra();
    Sala* getCurrentRoom();
    void nextRoom();
    bool isCleared() const;

    int getLastCleared() const { return currentRoomIndex; }

    void reset() { currentRoomIndex = 0; }
};

#endif // MAZMORRA_H
