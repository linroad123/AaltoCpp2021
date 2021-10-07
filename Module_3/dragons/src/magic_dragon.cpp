#include "magic_dragon.hpp"

// Define MagicDragon's methods here
MagicDragon::MagicDragon(const std::string &name, size_t age, size_t size) : Dragon(name, age, size) {}

//  *  The food that the dragon eats is removed from the parameter food list and
//  *  each time the dragon feasts upon something you should print information of
//  *  the Food that is being eaten to standard output in the following format:
// Magic dragon ate: <Food's name>\n
//  *
//  *  The food should be eaten in the order from the list's beginning to end.
void MagicDragon::Eat(std::list<Food> &food)
{
    food.remove_if(EatHerbs);
}

bool MagicDragon::EatHerbs(Food &fd)
{
    FoodType Herbs;
    if (fd.type == Herbs)
    {
        std::cout << "Magic dragon ate: " << fd.name << std::endl;
        size_++;
        return true;
    }
    else
    {
        return false;
    }
}


void MagicDragon::Hoard(std::list<Treasure> &treasure)
{
    treasure.remove_if(HoardPotion);
}

bool MagicDragon::HoardPotion(Treasure &tr)
{
    if (tr.type == TreasureType::Potions)
    {
        std::cout << "Magic dragon received: " << tr.name << std::endl;
        treasure_.push_back(tr);
        return true;
    }
    else
    {
        return false;
    }
}