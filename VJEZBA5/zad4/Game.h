#pragma once

#include <string>
#include "Level.h"
#include "Player.h"

class Game {
    std::string title;
    Level level;       // Kompozicija (Game posjeduje Level)
    Player player;     // Kompozicija (Game posjeduje Player)

public:
    Game(const std::string& title, const std::string& player_name);
    void print() const;
};