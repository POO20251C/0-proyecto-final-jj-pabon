// accesorio.h
#ifndef ACCESORIO_H
#define ACCESORIO_H

#include "item.h"

class Accesorio : public Item {
private:
    int bonus;

public:
    Accesorio(const std::string& nombre, int peso, int valor, int bonus);

    int getBonus() const;

    void use() override;
};

#endif // ACCESORIO_H
