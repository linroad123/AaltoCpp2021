#pragma once

#include <string>
#include <list>
#include <iostream>

#include <vector>

/* Enumeration types for the different treasures */
enum TreasureType
{
  Jewellery,
  Wisdom,
  Potions
};

/* Implementation of Treasure */
struct Treasure
{
  TreasureType type;
  std::string name;
};

/* Enumeration types for the different foods */
enum FoodType
{
  PeopleFood,
  People,
  Herbs
};

/* Implementation of Food */
struct Food
{
  FoodType type;
  std::string name;
};

class Dragon
{
public:
  Dragon(const std::string &name, size_t age, size_t size)
      : name_(name), age_(age), size_(size) {}
  Dragon(const Dragon& d);

  virtual ~Dragon(){}

  const std::string &GetName() const;
  size_t GetAge() const;
  size_t GetSize() const;
  const std::list<Treasure> &GetTreasures() const;
  friend std::ostream &operator<<(std::ostream &out, const Dragon &dragon);

  virtual void Eat(std::list<Food> &food) = 0;
  virtual void Hoard(std::list<Treasure> &treasure) = 0;

protected:
  const std::string &name_;
  size_t age_;
  size_t size_;
  std::list<Treasure> treasure_;
};

