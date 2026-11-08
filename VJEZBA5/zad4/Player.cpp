#include <iostream>
#include "Player.h"

Player::Player(const std::string& name, const Level* lvl)
    : name(name), level(lvl) {
}

void Player::print() const {
    std::cout << "Igrac: " << name << '\n';
    std::cout << "Level: neprijatelja " << level->enemy_count()
        << ", oruzja " << level->weapon_count() << '\n';
}