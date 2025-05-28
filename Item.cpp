// item.cpp
#include "item.h"

Item::Item(const std::string& nombre, int peso, int valor)
    : nombre(nombre), peso(peso), valor(valor) {}

std::string Item::getNombre() const {
    return nombre;
}

int Item::getWeight() const {
    return peso;
}

int Item::getValue() const {
    return valor;
}
