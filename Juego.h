// Juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include "heroe.h"
#include "mazmorra.h"
#include "combate.h"

class Juego {
private:
    std::vector<Heroe*> pool;    // Pool de héroes
    std::vector<Heroe*> team;    // Equipo seleccionado
    Mazmorra dungeon;
    Combate combate;
    std::string playerAlias;

    // Inicialización
    void crearPool();
    void seleccionarEquipo();
    void poblarMazmorra();

public:
    Juego();
    ~Juego();

    // Flujo principal
    void startGame();
    void showMenu();
    void explore();
    void guardarScore();
    void gameOver();
};

#endif //
