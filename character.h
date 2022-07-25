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

// Parent class for any character in the game (player and enemies)
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class character {
protected:
  string name;
  int attackDamage;
  int defense;

public:
  int healthPoints;
  character(string name, int healthPoints, int attackDamage, int defense);
  int getHP();
  void setHP(int damage);
  void setAddHP(int num);
  void fullHealth(int num);
  string getName();
  virtual int getAttack();
  virtual int getEnemyAttack();
  virtual int getEnemyDefenseAttack();
  virtual int getDefense();
  void changeHP(int changeAmount);
};

#endif