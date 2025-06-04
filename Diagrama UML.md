```mermaid
classDiagram
    class Juego {
        - vector<Heroe*> pool
        - vector<Heroe*> team
        - Mazmorra dungeon
        - Combate combate
        - string playerAlias
        + startGame()
        + showMenu()
        + explore()
        + guardarScore()
        + gameOver()
    }

    class Heroe {
        - string nombre
        - int hp
        - int hpMax
        - int atk
        - int def
        - int spd
        - int lck
        - Inventario inventario
        + Heroe(const string&, int, int, int, int, int)
        + attack(Enemigo&)
        + receiveDamage(int)
        + equipItem(Item*)
        + usePotion()
        + getHP() : int
        + getHPMax() : int
        + getATK() : int
        + getDEF() : int
        + getSPD() : int
        + getLCK() : int
        + getNombre() : string
        + getInventario() : Inventario&
        + setHP(int)
        + setATK(int)
        + setDEF(int)
        + setSPD(int)
        + setLCK(int)
    }

    class Inventario {
        - vector<Item*> items
        - Arma* equippedWeapon
        - Armadura* equippedArmor
        - Accesorio* equippedAccessory
        + Inventario()
        + ~Inventario()
        + addItem(Item*)
        + removeItem(Item*)
        + equipWeapon(Arma*) : bool
        + equipArmor(Armadura*) : bool
        + equipAccessory(Accesorio*) : bool
        + equipItem(Item*)
        + usePotion(Heroe&)
        + getTotalWeight() : int
        + getEquippedWeapon() : Arma*
        + getEquippedArmor() : Armadura*
        + getEquippedAccessory() : Accesorio*
    }

    class Item {
        <<abstract>>
        - string nombre
        - int peso
        - int valor
        + Item(const string&, int, int)
        + getNombre() : string
        + getWeight() : int
        + getValue() : int
        + use() <<virtual>>
    }

    class Arma {
        - int minDamage
        - int maxDamage
        + Arma(const string&, int, int, int, int)
        + getMinDamage() : int
        + getMaxDamage() : int
        + use()
    }

    class Armadura {
        - int armorClass
        + Armadura(const string&, int, int, int)
        + getArmorClass() : int
        + use()
    }

    class Accesorio {
        - int bonus
        + Accesorio(const string&, int, int, int)
        + getBonus() : int
        + use()
    }

    class Pocion {
        - int cureAmount
        + Pocion(const string&, int, int, int)
        + getCureAmount() : int
        + use(Heroe&)
    }

    class Enemigo {
        <<abstract>>
        - string nombre
        - int hp
        - int atk
        - int def
        - int spd
        - int lck
        + Enemigo(const string&, int, int, int, int, int)
        + ~Enemigo()
        + attack(Heroe&) <<virtual>>
        + receiveDamage(int)
        + getHP() : int
        + getNombre() : string
        + getSPD() : int
    }

    class Soldado {
        + Soldado(const string&)
        + attack(Heroe&) 
    }

    class MiniJefe {
        + MiniJefe(const string&)
        + attack(Heroe&) 
    }

    class GranJefe {
        + GranJefe(const string&)
        + attack(Heroe&) 
    }

    class Sala {
        - int numero
        - vector<Enemigo*> enemigos
        - Item* tesoro
        + Sala(int)
        + ~Sala()
        + agregarEnemigo(Enemigo*)
        + asignarTesoro(Item*)
        + isCleared() : bool
        + enter()
        + getEnemigos() : const vector<Enemigo*>&
        + getTesoro() : Item*
        + getNumero() : int
    }

    class Mazmorra {
        - vector<Sala> rooms
        - int currentRoomIndex
        + Mazmorra()
        + getCurrentRoom() : Sala*
        + nextRoom()
        + isCleared() : bool
        + reset()
        + getLastCleared() : int
    }

    class Combate {
        - vector<Heroe*> heroes
        - vector<Enemigo*> enemies
        - calculateDamage(int, int) : int
        + startBattle(vector<Heroe*>&, vector<Enemigo*>&)
        + nextTurn()
        + isBattleOver() : bool
        + victoria() : bool
    }

    %% Relaciones
    Juego o-- Heroe       : pool, team
    Juego o-- Mazmorra    : dungeon
    Juego o-- Combate     : combate

    Heroe *-- Inventario

    Inventario o-- Item
    Inventario o-- Arma
    Inventario o-- Armadura
    Inventario o-- Accesorio
    Inventario o-- Pocion

    Item <|-- Arma
    Item <|-- Armadura
    Item <|-- Accesorio
    Item <|-- Pocion

    Enemigo <|-- Soldado
    Enemigo <|-- MiniJefe
    Enemigo <|-- GranJefe

    Sala o-- Enemigo
    Sala o-- Item         : tesoro

    Mazmorra o-- Sala

    Combate ..> Heroe
    Combate ..> Enemigo
