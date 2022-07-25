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

// Implementation of character class functions
#include "character.h"

#include <ctime>
#include <string>
using namespace std;

character::character(string name, int healthPoints = 20, int attackDamage = 5,
                     int defense = 0) {
  this->healthPoints = healthPoints;
  this->name = name;
  this->attackDamage = attackDamage;
  this->defense = defense;
}

int character::getHP() { return healthPoints; }

void character::setHP(int damage) { healthPoints -= damage; }
void character::setAddHP(int num) { healthPoints += num; }
void character::fullHealth(int num) { healthPoints = num; }

string character::getName() { return name; }

int character::getAttack() {
  // I added this to deal a random amount of damage when the player or the enemy
  // attacks.
  srand(time(0));
  attackDamage = rand() % 50 + 15;
  return attackDamage;
}

int character::getEnemyAttack() { return attackDamage; }
// I created this so the enemies attack would be decreased when the player
// chooses defend instead of attack
int character::getEnemyDefenseAttack() { return attackDamage - 10; }

int character::getDefense() {
  // added this in to deal a smaller damage amount than attack
  srand(time(0));
  defense = rand() % 15;

  return defense;
}

void character::changeHP(int changeAmount) { healthPoints += changeAmount; }
