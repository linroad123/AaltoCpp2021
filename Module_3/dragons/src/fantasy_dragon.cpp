#include "fantasy_dragon.hpp"
#include <algorithm>

// Define FantasyDragon's methods here
FantasyDragon::FantasyDragon(const std::string &name, size_t age, size_t size) : Dragon(name, age, size) {}

void FantasyDragon::Eat(std::list<Food> &food)
{
    // food.remove_if(FantasyDragon::EatHerbs);
    // std::remove_if(food.begin(),food.end(),&EatHerbs);
    for (auto i : food)
    {
        if (EatHerbs(i))
        {
            food.remove(i);
            break;
        }
    }
}

bool FantasyDragon::EatHerbs(const Food &fd)
{
    if (fd.type == FoodType::People or fd.type == FoodType::PeopleFood)
    {
        std::cout << "Fantasy dragon ate: " << fd.name << std::endl;
        this->size_++;
        return true;
    }
    else
    {
        return false;
    }
}

void FantasyDragon::Hoard(std::list<Treasure> &treasure)
{
    // treasure.remove_if(&FantasyDragon::HoardPotion);
    for (auto i : treasure)
    {
        if (HoardPotion(i))
        {
            treasure.remove(i);
            break;
        }
    }
}

bool FantasyDragon::HoardPotion(const Treasure &tr)
{
    if (tr.type == TreasureType::Jewellery)
    {
        std::cout << "Fantasy dragon received: " << tr.name << std::endl;
        this->treasure_.push_back(tr);
        return true;
    }
    else
    {
        return false;
    }
}