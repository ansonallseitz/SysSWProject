//Class for item objects
#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item
{
  private:
    string name;
    int modAmount; //How much of an effect the item has. If the item is a key set to zero
    string type;
    
  public:
    item();
    item(string name, int modAmount, string type);
    string getName();
    int getModAmount();
    string getType();
};


#endif