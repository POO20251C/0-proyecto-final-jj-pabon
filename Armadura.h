// armadura.h
#ifndef ARMADURA_H
#define ARMADURA_H

#include "item.h"

class Armadura : public Item {
private:
    int armorClass;

public:
    Armadura(const std::string& nombre, int peso, int valor, int armorClass);

    int getArmorClass() const;

    void use() override;
};

#endif // ARMADURA_H

