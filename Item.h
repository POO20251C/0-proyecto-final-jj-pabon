// item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string nombre;
    int peso;
    int valor;

public:
    Item(const std::string& nombre, int peso, int valor);
    virtual ~Item() = default;

    std::string getNombre() const;
    int getWeight() const;
    int getValue() const;

    virtual void use() = 0;
};

#endif // ITEM_H
