//Implementation of the item class functions
#include "item.h"
#include <string>

using namespace std;

item::item()
{
  name = "";
  modAmount = 0;
  type = "Weapon";
}

item::item(string name, int modAmount, string type)
{
  this->name = name;
  this->modAmount = modAmount;

  if (type != "Weapon" && type != "Armor" && type != "Potion" && type != "Key")
  {
    throw "Invalid item type!";
  }
  this->type = type;
}

string item::getName()
{
  return name;
}

int item::getModAmount()
{
  return modAmount;
}

string item::getType()
{
  return type;
}
