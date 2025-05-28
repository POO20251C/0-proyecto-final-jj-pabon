// pocion.h
#ifndef POCION_H
#define POCION_H

#include "item.h"
class Heroe;

class Pocion : public Item {
private:
    int cureAmount;

public:
    Pocion(const std::string& nombre, int peso, int valor, int cureAmount);

    int getCureAmount() const;
    void use(Heroe& hero);
};

#endif // POCION_H
