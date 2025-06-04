// heroe.cpp
#include "heroe.h"
#include "enemigo.h"
#include <iostream>
#include <cstdlib>

Heroe::Heroe(const std::string& nombre, int hp, int atk, int def, int spd, int lck)
    : nombre(nombre), hp(hp), hpMax(hp), atk(atk), def(def), spd(spd), lck(lck) {}

void Heroe::attack(Enemigo& objetivo) {
    int critChance = std::rand() % 100;
    int damage = atk;
    if (critChance < lck * 2) {
        damage *= 2;
        std::cout << nombre << " asesta un golpe critico!\n";
    }
    objetivo.receiveDamage(damage);
}

void Heroe::receiveDamage(int damage) {
    int actual = damage - def;
    if (actual < 0) actual = 0;
    hp -= actual;
    std::cout << nombre << " recibe " << actual << " de golpe. HP restante: " << hp << "\n";
}

void Heroe::equipItem(Item* item) {
    inventario.addItem(item);
    inventario.equipItem(item);
}

void Heroe::usePotion() {
    inventario.usePotion(*this);
}

int Heroe::getHP() const     { return hp; }
int Heroe::getHPMax() const  { return hpMax; }
int Heroe::getATK() const    { return atk; }
int Heroe::getDEF() const    { return def; }
int Heroe::getSPD() const    { return spd; }
int Heroe::getLCK() const    { return lck; }
std::string Heroe::getNombre() const { return nombre; }
Inventario& Heroe::getInventario()   { return inventario; }

void Heroe::setHP(int v)  { hp = std::min(v, hpMax); }
void Heroe::setATK(int v) { atk = v; }
void Heroe::setDEF(int v) { def = v; }
void Heroe::setSPD(int v) { spd = v; }
void Heroe::setLCK(int v) { lck = v; }
