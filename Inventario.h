// inventario.h
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "item.h"
#include "arma.h"
#include "armadura.h"
#include "accesorio.h"
#include "pocion.h"

class Heroe;

class Inventario {
private:
    std::vector<Item*> items;
    Arma* equippedWeapon;
    Armadura* equippedArmor;
    Accesorio* equippedAccessory;

public:
    Inventario();
    ~Inventario();

    void addItem(Item* item);
    void removeItem(Item* item);

    bool equipWeapon(Arma* weapon);
    bool equipArmor(Armadura* armor);
    bool equipAccessory(Accesorio* accessory);
    void equipItem(Item* item);

    void usePotion(Heroe& hero);
    int getTotalWeight() const;

    Arma* getEquippedWeapon() const;
    Armadura* getEquippedArmor() const;
    Accesorio* getEquippedAccessory() const;
};

#endif // INVENTARIO_H