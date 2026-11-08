#include "Level.h"

Level::Level() {
    // Inicijalno prema ispisu: 1 neprijatelj, 0 oružja
    enemies.push_back(Enemy());
}

int Level::enemy_count() const {
    return enemies.size();
}

int Level::weapon_count() const {
    return weapons.size();
}