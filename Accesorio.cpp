// accesorio.cpp
#include "accesorio.h"
#include <iostream>
using namespace std;

Accesorio::Accesorio(const std::string& nombre, int peso, int valor, int bonus)
    : Item(nombre, peso, valor), bonus(bonus) {}

int Accesorio::getBonus() const {
    return bonus;
}

void Accesorio::use() {
    cout << getNombre() << " equipado como accesorio. Bonus aplicado." << endl;
}
