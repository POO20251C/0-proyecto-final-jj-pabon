// Soldado.cpp
#include "soldado.h"
#include <iostream>

Soldado::Soldado(const std::string& nombre)
    : Enemigo(nombre, 40, 5, 2, 3, 1) {}

void Soldado::attack(Heroe& objetivo) {
    std::cout << nombre << " ataca con su espada comun a "
              << objetivo.getNombre() << ".\n";
    objetivo.receiveDamage(atk);
}
