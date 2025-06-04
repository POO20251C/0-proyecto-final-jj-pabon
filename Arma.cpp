// arma.cpp
#include "arma.h"
#include <iostream>
using namespace std;

Arma::Arma(const std::string& nombre, int peso, int valor, int minDamage, int maxDamage)
    : Item(nombre, peso, valor), minDamage(minDamage), maxDamage(maxDamage) {}

int Arma::getMinDamage() const {
    return minDamage;
}

int Arma::getMaxDamage() const {
    return maxDamage;
}

void Arma::use() {
    // Armas usualmente no se "usan" directamente. Esto puede quedar vacío o imprimir algo.
    cout << getNombre() << " está equipada como arma." << endl;
}
