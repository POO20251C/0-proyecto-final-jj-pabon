// heroe.h
#ifndef HEROE_H
#define HEROE_H

#include <string>
#include "inventario.h"
class Enemigo;  // forward

class Heroe {
private:
    std::string nombre;
    int hp;
    int hpMax;
    int atk;
    int def;
    int spd;
    int lck;
    Inventario inventario;

public:
    Heroe(const std::string& nombre, int hp, int atk, int def, int spd, int lck);

    void attack(Enemigo& objetivo);
    void receiveDamage(int damage);
    void equipItem(Item* item);
    void usePotion();

    // Getters / setters
    int getHP() const;
    int getHPMax() const;
    int getATK() const;
    int getDEF() const;
    int getSPD() const;
    int getLCK() const;
    std::string getNombre() const;
    Inventario& getInventario();

    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
    void setSPD(int spd);
    void setLCK(int lck);
};

#endif // HEROE_H
