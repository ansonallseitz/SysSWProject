//Parent class for any character in the game (player and enemies)
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

using namespace std;

class character
{
  protected:
    
    string name;
    int attackDamage;
    int defense;
  public:
    int healthPoints;
    character(string name, int healthPoints, int attackDamage, int defense);
    int getHP();
    void setHP(int damage);
    void fullHealth(int num);
    string getName();
    virtual int getAttack();
    virtual int getEnemyAttack();
    virtual int getEnemyDefenseAttack();
    virtual int getDefense();
    void changeHP(int changeAmount);
};

#endif