#pragma once

#include "dragon.hpp"

/* TODO: class FantasyDragon
 * ------------
 * ------------
 * Other:
 * Public members of Dragon should be public in FantasyDragon as well.
 */

class FantasyDragon : public Dragon {
    FantasyDragon(const std::string& name, size_t age, size_t size);

    virtual void Eat(std::list<Food> &food);
    virtual void Hoard(std::list<Treasure> &treasure);
    bool EatHerbs(Food &fd);
    bool HoardPotion(Treasure &tr);

};