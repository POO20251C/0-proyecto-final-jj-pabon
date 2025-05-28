// Granjefe.cpp
#include "granjefe.h"
#include <iostream>

GranJefe::GranJefe(const std::string& nombre)
    : Enemigo(nombre, 100, 15, 6, 5, 3) {}

void GranJefe::attack(Heroe& objetivo) {
    std::cout << nombre << " desata un ataque devastador contra "
              << objetivo.getNombre() << "!\n";
    objetivo.receiveDamage(atk);
}
