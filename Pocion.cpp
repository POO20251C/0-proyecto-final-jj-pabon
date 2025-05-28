// pocion.cpp
#include "pocion.h"
#include "heroe.h" //
#include <iostream>
using namespace std;

Pocion::Pocion(const std::string& nombre, int peso, int valor, int cureAmount)
    : Item(nombre, peso, valor), cureAmount(cureAmount) {}

int Pocion::getCureAmount() const {
    return cureAmount;
}

void Pocion::use(Heroe& hero) {
    int hpAnterior = hero.getHP();
    hero.setHP(hpAnterior + cureAmount);
    cout << getNombre() << " usada. Cura " << cureAmount << " puntos de vida. Nuevo HP: " << hero.getHP() << endl;
}
