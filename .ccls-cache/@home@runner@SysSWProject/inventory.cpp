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

// Implementation of the inventory class functions
#include "inventory.h"

using namespace std;

inventory::inventory() { maxNumItems = 10; }

int inventory::getNumItems() { return itemList.size(); }

int inventory::getMaxNumItems() { return maxNumItems; }

void inventory::removeItem(int itemNum) {
  if (itemNum < 0 || itemNum > itemList.size()) {
    throw "Item not in list!";
  }
  itemList.erase(itemList.begin() + itemNum);
}

void inventory::addItem(item theItem) {
  if (itemList.size() == maxNumItems) {
    throw "Inventory is full can not add item!";
  }
  itemList.push_back(theItem);
}

item inventory::getItem(int itemNum) {
  if (itemList.size() < itemNum) {
    throw "Item not found in inventory!";
  }

  return (itemList.at(itemNum));
}