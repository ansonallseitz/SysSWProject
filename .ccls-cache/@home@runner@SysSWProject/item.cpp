/*
*******************************************************
PROGRAM NAME - AdventureGame

PROGRAMMERS - Logan Durham
              Stephanie Livengood
              Oussama Aireche
              Anson Allseitz

DESCRIPTION - This is text based adventure game in which players will choose a
character to play as, they will also have certain attacks they can use. If the
player has 0 health at any point they lose. If they go through all of the
encounters with health points above 0 they win.

DATE - Started 07 / 05 / 2022
DATE - Last Update  07 / 24 / 2022
* ******************************************************
*/

// Implementation of the item class functions
#include "item.h"
#include <string>

using namespace std;

item::item() {
  name = "";
  modAmount = 0;
  type = "Weapon";
}

item::item(string name, int modAmount, string type) {
  this->name = name;
  this->modAmount = modAmount;

  if (type != "Weapon" && type != "Armor" && type != "Potion" &&
      type != "Key") {
    throw "Invalid item type!";
  }
  this->type = type;
}

string item::getName() { return name; }

int item::getModAmount() { return modAmount; }

string item::getType() { return type; }
