//Implementation of the inventory class functions
#include "inventory.h"

using namespace std;

inventory::inventory()
{
  maxNumItems = 10;
}
    
int inventory::getNumItems()
{
  return itemList.size();
}
    
int inventory::getMaxNumItems()
{
  return maxNumItems;
}
    
void inventory::removeItem(int itemNum)
{
  if (itemNum < 0 || itemNum > itemList.size())
  {
    throw "Item not in list!";
  }
  itemList.erase(itemList.begin() + itemNum);
}
    
void inventory::addItem(item theItem)
{
  if (itemList.size() == maxNumItems)
  {
    throw "Inventory is full can not add item!";
  }
  itemList.push_back(theItem);
}

item inventory::getItem(int itemNum)
{
  if (itemList.size() < itemNum)
  {
    throw "Item not found in inventory!";
  }
  
  return (itemList.at(itemNum));
}