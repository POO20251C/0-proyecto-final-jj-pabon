// Juego.cpp
#include "juego.h"
#include "soldado.h"
#include "minijefe.h"
#include "granjefe.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <tuple>
#include <vector>

using namespace std;

// Declaración anticipada
void mostrarTop5Scores();

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
    getline(cin, playerAlias);
    cout << endl;

    cout << "Selecciona 3 heroes:\n";
    for (int i = 0; i < (int)pool.size(); ++i)
        cout << i + 1 << ". " << pool[i]->getNombre() << "\n";

    while ((int)team.size() < 3) {
        cout << "Elige heroe #" << team.size() + 1 << ": ";
        string entrada;
        getline(cin, entrada);

        stringstream ss(entrada);
        int idx;
        if (ss >> idx && idx >= 1 && idx <= (int)pool.size()) {
            Heroe* h = pool[idx - 1];
            if (find(team.begin(), team.end(), h) == team.end()) {
                team.push_back(h);
            } else {
                cout << "Ese heroe ya está en tu equipo.\n";
            }
        } else {
            cout << "Seleccion invalida.\n";
        }
    }

    cout << endl;
}

void Juego::poblarMazmorra() {
    dungeon.reset();
    for (int i = 1; i <= 10; ++i) {
        Sala* sala = dungeon.getCurrentRoom();
        if (i == 8)        sala->agregarEnemigo(new MiniJefe("MiniJefe"));
        else if (i == 10)  sala->agregarEnemigo(new GranJefe("GranJefe"));
        else               sala->agregarEnemigo(new Soldado("Soldado"));
        dungeon.nextRoom();
    }
    dungeon.reset();
}

void Juego::startGame() {
    cout << "\nBienvenido a Natal Combat\n\n";
    mostrarTop5Scores(); // ← se llama correctamente aquí
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

        string entrada;
        getline(cin, entrada);
        stringstream ss(entrada);

        if (!(ss >> opcion)) {
            cout << "Entrada invalida.\n";
            continue;
        }

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
        cout << "Santo Grial. Todos tus heroes recuperan 100% HP.\n";
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
    int saludPerdida = 0;
    for (Heroe* h : team) {
        saludPerdida += h->getHPMax() - h->getHP();
    }

    ofstream ofs("scores.txt", ios::app);
    time_t t = time(nullptr);

    ofs << playerAlias << ","
        << put_time(localtime(&t), "%Y-%m-%d %H:%M") << ","
        << dungeon.getLastCleared() + 1 << ","
        << saludPerdida << "\n";

    ofs.close();
}

void Juego::gameOver() {
    cout << "\nJuego terminado. Gracias por jugar\n";
}

// === Función libre ===
void mostrarTop5Scores() {
    std::ifstream ifs("scores.txt");
    if (!ifs.is_open()) {
        std::cout << "No hay puntajes registrados.\n";
        return;
    }

    std::vector<std::tuple<std::string, std::string, int, int>> scores;
    std::string linea;

    while (std::getline(ifs, linea)) {
        std::stringstream ss(linea);
        std::string alias, fecha;
        int sala, salud;

        if (std::getline(ss, alias, ',') &&
            std::getline(ss, fecha, ',') &&
            ss >> sala && ss.get() && ss >> salud) {
            scores.emplace_back(alias, fecha, sala, salud);
        }
    }

    ifs.close();

    std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        if (std::get<2>(a) != std::get<2>(b))
            return std::get<2>(a) > std::get<2>(b); // sala
        return std::get<3>(a) < std::get<3>(b);     // salud
    });

    std::cout << "\n--- Top 5 Puntajes ---\n";
    int top = std::min(5, (int)scores.size());
    for (int i = 0; i < top; ++i) {
        auto& [alias, fecha, sala, salud] = scores[i];
        std::cout << i+1 << ". " << alias << " | " << fecha
                  << " | Sala: " << sala
                  << " | Salud perdida: " << salud << "\n";
    }
    std::cout << "----------------------\n\n";
}
