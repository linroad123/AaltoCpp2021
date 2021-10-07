#pragma once

#include "dragon.hpp"

/* TODO: class MagicDragon
 * ------------
 * Functions:
 * ------------
 * Other:
 * Public members of Dragon should be public in MagicDragon as well.
 */

class MagicDragon : public Dragon {
    MagicDragon(const std::string& name, size_t age, size_t size);

    virtual void Eat(std::list<Food> &food);
    virtual void Hoard(std::list<Treasure> &treasure);
    bool EatHerbs(Food &fd);
    bool HoardPotion(Treasure &tr);

};