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
        + attack(Enemigo& objetivo)
        + receiveDamage(int)
        + equipItem(Item*)
        + usePotion()
        + getHP()
        + getHPMax()
        + getATK()
        + getDEF()
        + getSPD()
        + getLCK()
        + getNombre()
        + getInventario()
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
        + addItem(Item*)
        + removeItem(Item*)
        + equipWeapon(Arma*)
        + equipArmor(Armadura*)
        + equipAccessory(Accesorio*)
        + equipItem(Item*)
        + usePotion(Heroe&)
        + getTotalWeight()
    }

    class Item {
        - string nombre
        - int peso
        - int valor
        + use(Heroe&)«virtual»
        + getNombre()
        + getWeight()
        + getValue()
    }

    class Arma {
        - int minDamage
        - int maxDamage
        + getMinDamage()
        + getMaxDamage()
        + use(Heroe&)
    }

    class Armadura {
        - int armorClass
        + getArmorClass()
        + use(Heroe&)
    }

    class Accesorio {
        - int bonus
        + getBonus()
        + use(Heroe&)
    }

    class Pocion {
        - int cureAmount
        + getCureAmount()
        + use(Heroe&)
    }

    class Enemigo {
        - string nombre
        - int hp
        - int atk
        - int def
        - int spd
        - int lck
        + attack(Heroe&)
        + receiveDamage(int)
        + getHP()
        + getNombre()
        + getSPD()
    }

    class Soldado {
        + attack(Heroe&)
    }

    class MiniJefe {
        + attack(Heroe&)
    }

    class GranJefe {
        + attack(Heroe&)
    }

    class Sala {
        - int numero
        - vector<Enemigo*> enemigos
        - Item* tesoro
        + agregarEnemigo(Enemigo*)
        + asignarTesoro(Item*)
        + isCleared()
        + enter()
        + getEnemigos()
        + getTesoro()
        + getNumero()
    }

    class Mazmorra {
        - vector<Sala> rooms
        - int currentRoomIndex
        + getCurrentRoom()
        + nextRoom()
        + isCleared()
        + reset()
        + getLastCleared()
    }

    class Combate {
        - vector<Heroe*> heroes
        - vector<Enemigo*> enemies
        + startBattle(vector<Heroe*>&, vector<Enemigo*>&)
        + nextTurn()
        + isBattleOver()
        + victoria()
        - calculateDamage(int,int)
    }

    %% Relationships
    Juego o-- Heroe       : team
    Juego o-- Mazmorra    : dungeon
    Juego o-- Combate     : combate

    Heroe *-- Inventario

    Inventario o-- Item

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
