// arma.h
#ifndef ARMA_H
#define ARMA_H

#include "item.h"

class Arma : public Item {
private:
    int minDamage;
    int maxDamage;

public:
    Arma(const std::string& nombre, int peso, int valor, int minDamage, int maxDamage);

    int getMinDamage() const;
    int getMaxDamage() const;

    void use() override; // opcional si aplica efecto inmediato
};

#endif // ARMA_H

