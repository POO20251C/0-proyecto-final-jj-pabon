// Sala.cpp
#include "sala.h"
#include <iostream>

Sala::Sala(int numero) : numero(numero), tesoro(nullptr) {}

Sala::~Sala() {
    for (auto enemigo : enemigos) delete enemigo;
    delete tesoro;
}

void Sala::agregarEnemigo(Enemigo* enemigo) {
    if (enemigo) enemigos.push_back(enemigo);
}

void Sala::asignarTesoro(Item* item) {
    tesoro = item;
}

bool Sala::isCleared() const {
    for (auto& e : enemigos)
        if (e->getHP() > 0) return false;
    return true;
}

void Sala::enter() {
    std::cout << "\nIngresaste a la sala " << numero << ".\n";
    if (tesoro)
        std::cout << "Encontraste un tesoro: " << tesoro->getNombre() << "\n";
}

const std::vector<Enemigo*>& Sala::getEnemigos() const {
    return enemigos;
}

Item* Sala::getTesoro() const {
    return tesoro;
}
