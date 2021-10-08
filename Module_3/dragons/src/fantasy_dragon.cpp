#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here
FantasyDragon::FantasyDragon(const std::string &name, size_t age, size_t size) : Dragon(name, age, size) {}

void FantasyDragon::Eat(std::list<Food> &food)
{
    food.remove_if([this](const Food fd)
                   {
                       if (fd.type == People or fd.type == PeopleFood)
                       {
                           std::cout << "Fantasy dragon ate: " << fd.name << std::endl;
                           size_++;
                           return true;
                       }
                       else
                       {
                           return false;
                       }
                   });
}

bool FantasyDragon::EatHerbs(Food &fd)
{
    if (fd.type == People or fd.type == PeopleFood)
    {
        std::cout << "Fantasy dragon ate: " << fd.name << std::endl;
        size_++;
        return true;
    }
    else
    {
        return false;
    }
}

void FantasyDragon::Hoard(std::list<Treasure> &treasure)
{
    treasure.remove_if([this](const Treasure tr)
                       {
                           if (tr.type == Jewellery)
                           {
                               std::cout << "Fantasy dragon received: " << tr.name << std::endl;
                               treasure_.push_back(tr);
                               return true;
                           }
                           else
                           {
                               return false;
                           }
                       });
}

bool FantasyDragon::HoardPotion(Treasure &tr)
{
    if (tr.type == Jewellery)
    {
        std::cout << "Fantasy dragon received: " << tr.name << std::endl;
        treasure_.push_back(tr);
        return true;
    }
    else
    {
        return false;
    }
}