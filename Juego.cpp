// Juego.cpp
#include "juego.h"
#include "soldado.h"
#include "minijefe.h"
#include "granjefe.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

Juego::Juego() {
    crearPool();
    poblarMazmorra();
}

Juego::~Juego() {
    for (auto h : pool)
        delete h;
}

void Juego::crearPool() {
    pool.push_back(new Heroe("Archer", 60, 6, 3, 5, 2));
    pool.push_back(new Heroe("Knight", 80, 8, 5, 3, 1));
    pool.push_back(new Heroe("Mage",   50,10, 2, 4, 3));
    pool.push_back(new Heroe("Rogue",  55, 7, 4, 6, 4));
    pool.push_back(new Heroe("Cleric", 65, 5, 4, 3, 2));
    pool.push_back(new Heroe("Barbar", 75, 9, 2, 4, 1));
}

void Juego::seleccionarEquipo() {
    cout << "Nickname del jugador: ";
    cin >> playerAlias;
    cout << endl;
    cout << "Selecciona 3 heroes:\n";
    for (int i = 0; i < (int)pool.size(); ++i)
        cout << i+1 << ". " << pool[i]->getNombre() << "\n";

    while ((int)team.size() < 3) {
        int idx;
        cout << "Elige heroe #" << team.size()+1 << ": ";
        cin >> idx;
        if (idx >= 1 && idx <= (int)pool.size()) {
            Heroe* h = pool[idx-1];
            if (find(team.begin(), team.end(), h) == team.end())
                team.push_back(h);
            else
                cout << "Ya está en tu equipo.\n";
        } else {
            cout << "Selección invalida.\n";
        }
    }
    cout << endl;
}

void Juego::poblarMazmorra() {
    // Poblar sin mover el índice permanentemente
    dungeon.reset();
    for (int i = 1; i <= 10; ++i) {
        Sala* sala = dungeon.getCurrentRoom();
        if (i == 8)        sala->agregarEnemigo(new MiniJefe("MiniJefe"));
        else if (i == 10)  sala->agregarEnemigo(new GranJefe("GranJefe"));
        else               sala->agregarEnemigo(new Soldado("Soldado"));
        dungeon.nextRoom();
    }
    // Tras poblar, reseteamos para empezar en la sala 1
    dungeon.reset();
}

void Juego::startGame() {
    cout << "\nBienvenido a Natal Combat" << endl << endl;
    seleccionarEquipo();
    showMenu();
}

void Juego::showMenu() {
    int opcion;
    do {
        cout << "Menu Principal:\n"
             << "1. Explorar\n"
             << "2. Salir\n"
             << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: explore(); break;
            case 2: gameOver(); break;
            default: cout << "Opción invalida.\n";
        }
    } while (opcion != 2);
}

void Juego::explore() {
    Sala* sala = dungeon.getCurrentRoom();
    cout << "\nIngresando sala " << sala->getNumero() << "...\n";

    vector<Heroe*> heroesVivos = team;
    vector<Enemigo*> enemies = sala->getEnemigos();
    combate.startBattle(heroesVivos, enemies);

    if (combate.victoria()) {
        for (auto h : team) {
            h->setATK(int(h->getATK() * 1.02));
            h->setDEF(int(h->getDEF() * 1.02));
        }
    }

    int n = sala->getNumero();
    if (n == 3) cout << "Cofre. Obtienes pociones y/o accesorios.\n";
    if (n == 6) cout << "Tesoro raro. Armamento mejorado.\n";
    if (n == 8) {
        cout << "Santo Grial. Todos tus héroes recuperan 100% HP.\n";
        for (auto h : team) h->setHP(h->getHPMax());
    }

    dungeon.nextRoom();
    if (dungeon.isCleared()) {
        cout << "\nCompletaste la mazmorra\n";
        guardarScore();
        gameOver();
    }
}

void Juego::guardarScore() {
    ofstream ofs("scores.txt", ios::app);
    time_t t = time(nullptr);
    ofs << playerAlias << ","
        << ctime(&t)
        << dungeon.getLastCleared() << ",0\n";
    ofs.close();
}

void Juego::gameOver() {
    cout << "\nJuego terminado. Gracias por jugar\n";
}
