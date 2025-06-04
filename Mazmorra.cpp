// mazmorra.cpp
#include "mazmorra.h"

Mazmorra::Mazmorra() : currentRoomIndex(0) {
    for (int i = 1; i <= 10; ++i)
        rooms.emplace_back(i);
}

Sala* Mazmorra::getCurrentRoom() {
    if (currentRoomIndex < (int)rooms.size())
        return &rooms[currentRoomIndex];
    return nullptr;
}

void Mazmorra::nextRoom() {
    if (currentRoomIndex < (int)rooms.size() - 1)
        ++currentRoomIndex;
}

bool Mazmorra::isCleared() const {
    return currentRoomIndex >= (int)rooms.size() - 1;
}
