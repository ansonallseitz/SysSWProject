//Implementation of character class functions
#include "character.h"


#include <string>

using namespace std;

character::character(string name, int healthPoints = 20,  int attackDamage = 5, int defense = 0)
    {
      this->healthPoints = healthPoints;
      this->name = name;
      this->attackDamage = attackDamage;
      this->defense = defense;
    }

int character::getHP()
{
  return healthPoints;
}

void character::setHP(int damage){
  healthPoints -= damage;
}
void character::fullHealth(int num){
  healthPoints = num;
}

string character::getName()
{
  return name;
}

int character::getAttack()
{
  //I added this to deal a random amount of damage when the player or the enemy attacks.
  srand(time(0));
  attackDamage = rand() % 50 + 1;
  return attackDamage;
}

int character::getEnemyAttack(){
  return attackDamage;
}
//I created this so the enemies attack would be decreased when the player chooses defend instead of attack
int character::getEnemyDefenseAttack(){
  return attackDamage-10;
}

int character::getDefense()
{
  //added this in to deal a smaller damage amount than attack
  srand(time(0));
  defense = rand() % 15;
  
  return defense;
}

void character::changeHP(int changeAmount)
{
  healthPoints += changeAmount;
}
