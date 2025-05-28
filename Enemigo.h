// Enemigo.h
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
#include "heroe.h"

class Enemigo {
protected:
    std::string nombre;
    int hp;
    int atk;
    int def;
    int spd;
    int lck;

public:
    Enemigo(const std::string& nombre, int hp, int atk, int def, int spd, int lck);
    virtual ~Enemigo() = default;

    virtual void attack(Heroe& objetivo) = 0;
    void receiveDamage(int damage);

    int getHP() const;
    std::string getNombre() const;
    int getSPD() const { return spd; }
};

#endif // ENEMIGO_H
