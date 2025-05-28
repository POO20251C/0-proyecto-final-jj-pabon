// Minijefe.cpp
#include "minijefe.h"
#include <iostream>

MiniJefe::MiniJefe(const std::string& nombre)
    : Enemigo(nombre, 70, 10, 4, 4, 2) {}

void MiniJefe::attack(Heroe& objetivo) {
    std::cout << nombre << " lanza un ataque poderoso a "
              << objetivo.getNombre() << "!\n";
    objetivo.receiveDamage(atk);
}
