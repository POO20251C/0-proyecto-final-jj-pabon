// Granjefe.h
#ifndef GRANJEFE_H
#define GRANJEFE_H

#include "enemigo.h"

class GranJefe : public Enemigo {
public:
    GranJefe(const std::string& nombre);
    void attack(Heroe& objetivo) override;
};

#endif // GRANJEFE_H
