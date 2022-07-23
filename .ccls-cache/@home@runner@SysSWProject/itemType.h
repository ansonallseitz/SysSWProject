#ifndef TYPE_H
#define TYPE_H

#include <map>
#include <string>

using namespace std;

enum itemType {WEAPON, ARMOR, POTION, KEY};

map<itemType, string> typeToStr
{
  {WEAPON, "Weapon"},
  {ARMOR, "ARMOR"},
  {POTION, "POTION"},
  {KEY, "Key"}
};

map<string, itemType> strToType
{
  {"Weapon", WEAPON},
  {"ARMOR", ARMOR},
  {"POTION", POTION},
  {"Key", KEY}
};

#endif