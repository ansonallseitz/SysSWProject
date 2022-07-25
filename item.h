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

// Class for item objects
#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item {
private:
  string name;
  int modAmount; // How much of an effect the item has. If the item is a key set
                 // to zero
  string type;

public:
  item();
  item(string name, int modAmount, string type);
  string getName();
  int getModAmount();
  string getType();
};

#endif