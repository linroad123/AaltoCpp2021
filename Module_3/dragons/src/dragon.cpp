#include "dragon.hpp"

Dragon::~Dragon()
{

}

const std::string &Dragon::GetName() const
{
    return name_;
}

size_t Dragon::GetAge() const
{
    return age_;
}

size_t Dragon::GetSize() const
{
    return size_;
}

const std::list<Treasure> &Dragon::GetTreasures() const
{
    return treasure_;
}

