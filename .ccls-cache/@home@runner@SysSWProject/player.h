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

// Class for the player character
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include <iostream>
#include <string>

using namespace std;

class player : public character {
private:
  int roomNum = 0;
  inventory bag;
  item weapon;
  item armor;

public:
  player(string name, int healthPoints, int attackDamage, int defense,
         int room);
  int getRoom();
  void changeRoom(int roomNum);
  void changeAttack(int changeAmount);
  void changeDefense(int changeAmount);
  void displayBag();
  void useItem(int itemNum);
  string getWeapon();
  string getArmor();
  int getAttack() override;
  int getDefense() override;
  int bagSize();
  void addToBag(item theItem);
};

#endif