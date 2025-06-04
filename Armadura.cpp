// armadura.cpp
#include "armadura.h"
#include <iostream>
using namespace std;

Armadura::Armadura(const std::string& nombre, int peso, int valor, int armorClass)
    : Item(nombre, peso, valor), armorClass(armorClass) {}

int Armadura::getArmorClass() const {
    return armorClass;
}

void Armadura::use() {
    cout << getNombre() << " esta equipada como armadura." << endl;
}
