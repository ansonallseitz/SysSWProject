//Class for the players inventory
#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <string>
#include <vector>

using namespace std;

class inventory 
{
  private:
    int maxNumItems = 10;
    vector<item> itemList;
  public:
    inventory();
    int getNumItems();
    int getMaxNumItems();
    void removeItem(int itemNum);
    void addItem(item theItem);
    item getItem(int itemNum);
};

#endif