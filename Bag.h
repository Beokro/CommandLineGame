#ifndef BAG_H_
#define BAG_H_

#include <map>
#include "Item.h"

using namespace std;

class Bag{
 public:
  size_t getUsed();
  bool putInBag(Item &item);
  bool removeFromBag(string itemName);
  bool removeFromBag(string itemName, size_t number);
  void emptyBag();
  //should call Item's Use function and pass the Person pointer
  void UseItem(Person *p, string name);
	  
 private:
  const static size_t MAX_BAG_CAPACITY = 64;
  map<string, Item> myBag;
};

#endif