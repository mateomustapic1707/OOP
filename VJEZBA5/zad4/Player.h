#pragma once

#include <string>
#include "Level.h"

class Player {
    std::string name;
    const Level* level; // Asocijacija: igrač zna u kojem je levelu

public:
    Player(const std::string& name, const Level* lvl);
    void print() const;
};