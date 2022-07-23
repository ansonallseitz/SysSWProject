//Class for the player character
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "inventory.h"
#include <iostream>
#include <string>

using namespace std;

class player : public character
{
  private:
    int roomNum = 0;
    inventory bag;
    item weapon;
    item armor;

  public:
    player(string name, int healthPoints, int attackDamage, int defense, int room);
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