// Sala.h
#ifndef SALA_H
#define SALA_H

#include <vector>
#include "enemigo.h"
#include "item.h"

class Sala {
private:
    int numero;
    std::vector<Enemigo*> enemigos;
    Item* tesoro;

public:
    Sala(int numero);
    ~Sala();

    void agregarEnemigo(Enemigo* enemigo);
    void asignarTesoro(Item* item);

    bool isCleared() const;
    void enter();

    const std::vector<Enemigo*>& getEnemigos() const;
    Item* getTesoro() const;

    // Getter del número de sala
    int getNumero() const { return numero; }
};

#endif // SALA_H
