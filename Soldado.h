// Soldado.h
#ifndef SOLDADO_H
#define SOLDADO_H

#include "enemigo.h"

class Soldado : public Enemigo {
public:
    Soldado(const std::string& nombre);
    void attack(Heroe& objetivo) override;
};

#endif // SOLDADO_H
