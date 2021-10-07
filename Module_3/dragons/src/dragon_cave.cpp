#include "dragon_cave.hpp"

#include <list>

// Define DragonCave's methods here
DragonCave::DragonCave(){};

const std::list<Dragon *> &DragonCave::GetDragons() const
{
    return dragons_;
}

void DragonCave::Accommodate(Dragon *dragon)
{
    dragons_.push_back(dragon);
}


//  * Tries to find a dragon with a matching name from the DragonCaves Dragon pointer
//  * list. Erases the first Dragon pointer with a matching name from the list. If
//  * there is no Dragon with a matching name in the list, the function does nothing.
//  * Note that the function only erases the pointer from the list, but DOES NOT delete
//  * the Dragon object. The function returns nothing.
void DragonCave::Evict(const std::string &name)
{
    for (auto i : dragons_) {
        if (name == i->GetName()) {
            delete i;
            return;
        }
    }
}

DragonCave::~DragonCave()
{
    for (auto i : dragons_)
    {
        delete i;
    }
}