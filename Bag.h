#pragma once

#include <iostream>
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
	  
 private:
  static size_t MAX_BAG_CAPACITY = 64;
  map<string, Item> myBag;
};
