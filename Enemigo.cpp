// Enemigo.cpp
#include "enemigo.h"
#include <iostream>

Enemigo::Enemigo(const std::string& nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Enemigo::receiveDamage(int damage) {
    int actual = damage - def;
    if (actual < 0) actual = 0;
    hp -= actual;
    std::cout << nombre << " recibe " << actual << " de golpe HP restante: " << hp << "\n";
}

int Enemigo::getHP() const {
    return hp;
}

std::string Enemigo::getNombre() const {
    return nombre;
}
