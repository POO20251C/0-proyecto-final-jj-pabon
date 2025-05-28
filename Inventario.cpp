// inventario.cpp
#include "inventario.h"
#include <iostream>
#include <algorithm>
#include "heroe.h"
using namespace std;

Inventario::Inventario() {
    equippedWeapon = nullptr;
    equippedArmor = nullptr;
    equippedAccessory = nullptr;
}

Inventario::~Inventario() {
    for (Item* item : items) {
        delete item;
    }
}

void Inventario::addItem(Item* item) {
    if (item != nullptr) {
        items.push_back(item);
    }
}

void Inventario::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}

bool Inventario::equipWeapon(Arma* weapon) {
    if (weapon) {
        equippedWeapon = weapon;
        return true;
    }
    return false;
}

bool Inventario::equipArmor(Armadura* armor) {
    if (armor) {
        equippedArmor = armor;
        return true;
    }
    return false;
}

bool Inventario::equipAccessory(Accesorio* accessory) {
    if (accessory) {
        equippedAccessory = accessory;
        return true;
    }
    return false;
}

void Inventario::equipItem(Item* item) {
    if (auto arma = dynamic_cast<Arma*>(item)) equipWeapon(arma);
    else if (auto armadura = dynamic_cast<Armadura*>(item)) equipArmor(armadura);
    else if (auto acc = dynamic_cast<Accesorio*>(item)) equipAccessory(acc);
}

void Inventario::usePotion(Heroe& hero) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (auto pocion = dynamic_cast<Pocion*>(*it)) {
            pocion->use(hero);
            delete *it;
            items.erase(it);
            break;
        }
    }
}

int Inventario::getTotalWeight() const {
    int total = 0;
    for (const auto& item : items) {
        total += item->getWeight();
    }
    return total;
}

Arma* Inventario::getEquippedWeapon() const { return equippedWeapon; }
Armadura* Inventario::getEquippedArmor() const { return equippedArmor; }
Accesorio* Inventario::getEquippedAccessory() const { return equippedAccessory; }
