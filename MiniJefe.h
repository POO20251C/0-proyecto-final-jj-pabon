// Minijefe.h
#ifndef MINIJEFE_H
#define MINIJEFE_H

#include "enemigo.h"

class MiniJefe : public Enemigo {
public:
    MiniJefe(const std::string& nombre);
    void attack(Heroe& objetivo) override;
};

#endif // MINIJEFE_H
