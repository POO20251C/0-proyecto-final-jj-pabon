// Combate.cpp
#include "combate.h"
#include <algorithm>
#include <iostream>

void Combate::startBattle(std::vector<Heroe*>& heroes_, std::vector<Enemigo*>& enemies_) {
    heroes = heroes_;
    enemies = enemies_;
    std::cout << "\nComienza el combate\n";
    while (!isBattleOver()) {
        nextTurn();
    }
    std::cout << "\nFin del combate.\n";
}

bool Combate::isBattleOver() const {
    bool anyHero = false, anyEnemy = false;
    for (auto h : heroes)   if (h->getHP() > 0) anyHero = true;
    for (auto e : enemies)  if (e->getHP() > 0) anyEnemy = true;
    return !(anyHero && anyEnemy);
}

bool Combate::victoria() const {
    bool anyHero = false, anyEnemy = false;
    for (auto h : heroes)   if (h->getHP() > 0) anyHero = true;
    for (auto e : enemies)  if (e->getHP() > 0) anyEnemy = true;
    return anyHero && !anyEnemy;
}

int Combate::calculateDamage(int atk, int def) {
    int dmg = atk - def;
    return dmg > 0 ? dmg : 0;
}

void Combate::nextTurn() {
    struct Actor { int spd; bool isHero; void* ptr; };
    std::vector<Actor> turnos;

    for (auto h : heroes)
        if (h->getHP() > 0)
            turnos.push_back( Actor{h->getSPD(), true, h} );

    for (auto e : enemies)
        if (e->getHP() > 0)
            turnos.push_back( Actor{e->getSPD(), false, e} );

    std::sort(turnos.begin(), turnos.end(),
              [](auto &a, auto &b){ return a.spd > b.spd; });

    for (auto &actor : turnos) {
        if (isBattleOver()) break;
        if (actor.isHero) {
            Heroe* h = static_cast<Heroe*>(actor.ptr);
            if (h->getHP() < h->getDEF()*2) h->usePotion();
            else {
                for (auto e : enemies)
                    if (e->getHP() > 0) {
                        h->attack(*e);
                        break;
                    }
            }
        } else {
            Enemigo* e = static_cast<Enemigo*>(actor.ptr);
            for (auto h : heroes)
                if (h->getHP() > 0) {
                    e->attack(*h);
                    break;
                }
        }
    }
}
