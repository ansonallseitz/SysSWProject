/*
*******************************************************
PROGRAM NAME - AdventureGame

PROGRAMMERS - Logan Durham
              Stephanie Livengood
              Oussama Aireche
              Anson Allseitz

DESCRIPTION - This is text based adventure game in which players will choose a character to play as, 
              they will also have certain attacks they can use. 
              If the player has 0 health at any point they lose. 
               If they go through all of the encounters with health points above 0 they win.

DATE - Started 07 / 05 / 2022
DATE - Last Update  07 / 24 / 2022
* ******************************************************
*/

//Implementation for the player class functions
#include "player.h"

using namespace std;

player::player(string name, int healthPoints, int attackDamage, int defense, int room)
  : character(name, healthPoints, attackDamage, defense)
{
  this->roomNum = room;
 // weapon = item("Empty hands", 0, "Weapon");
 // armor = item("No Armor", 0, "Armor");
}
    
int player::getRoom()
{
  return roomNum;
}
  
void player::changeRoom(int roomNum)
{
  this->roomNum = roomNum;
}
    
void player::changeAttack(int changeAmount)
{
  if (changeAmount <= 0){
    throw "The player can not lose attack damage";
  }
  attackDamage += changeAmount;
}
    
void player::changeDefense(int changeAmount)
{
  if (changeAmount <= 0){
    throw "The player can not lose defense";
  }
  defense += changeAmount;
}

void player::displayBag()
{
  if (bag.getNumItems() <= 0)
  {
    throw "Can't check an empty bag!";
  }

  cout << "Inventory List" << endl;
  for (int i = 0; i < bag.getNumItems(); i++)
    {
      cout << i + 1 << ". " << bag.getItem(i).getName() << " +" << bag.getItem(i).getModAmount() << " " << bag.getItem(i).getType() << endl; 
      
    }
  cout<<"\nMake your choice: \n";
}

void player::useItem(int itemNum)
{
  if (bag.getMaxNumItems() < itemNum)
  {
    throw "Item not in bag!";
  }

  if (bag.getItem(itemNum).getType() == "Weapon")
  {
    char choice;
    cout << "Your equiped item will be lost!" << endl;
    cout << "Are you sure you wish to equip this item? (Y/N): ";
    cin >> choice;

    if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
      cout << "Incorrect input. Try again: ";
      cin >> choice;
    }

    if (choice == 'y' || choice == 'Y')
    {
      weapon = bag.getItem(itemNum);
      bag.removeItem(itemNum);

      cout << weapon.getName() << " has been equiped" << endl;
    }

    else
    {
      return;
    }
  }

  else if (bag.getItem(itemNum).getType() == "Armor")
  {
    char choice;
    cout << "Your equiped item will be lost!" << endl;
    cout << "Are you sure you wish to equip this item? (Y/N): ";
    cin >> choice;

    if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
      cout << "Incorrect input. Try again: ";
      cin >> choice;
    }

    if (choice == 'y' || choice == 'Y')
    {
      armor = bag.getItem(itemNum);
      bag.removeItem(itemNum);

      cout << armor.getName() << " has been equiped" << endl;
    }

    else
    {
      return;
    }
  }

  else if (bag.getItem(itemNum).getType() == "Potion")
  {
    healthPoints += bag.getItem(itemNum).getModAmount();

    cout << "You healed for " << bag.getItem(itemNum).getModAmount() << endl;
    bag.removeItem(itemNum);
    
  }

  else if (bag.getItem(itemNum).getType() == "Key")
  {
    cout << "An old key" << endl;
  }
}

string player::getWeapon()
{
  return weapon.getName();
}

string player::getArmor()
{
  return armor.getName();
}

int player::getAttack()
{
  return attackDamage + weapon.getModAmount();
}

int player::getDefense()
{
  return defense + armor.getModAmount();
}

int player::bagSize()
{
  return bag.getNumItems();
}

void player::addToBag(item theItem)
{
  bag.addItem(theItem);
}