// Combate.h
#ifndef COMBATE_H
#define COMBATE_H

#include <vector>
#include "heroe.h"
#include "enemigo.h"

class Combate {
private:
    std::vector<Heroe*> heroes;
    std::vector<Enemigo*> enemies;

    int calculateDamage(int atk, int def);

public:
    void startBattle(std::vector<Heroe*>& heroes_, std::vector<Enemigo*>& enemies_);
    void nextTurn();
    bool isBattleOver() const;
    bool victoria() const;
};

#endif // COMBATE_H
