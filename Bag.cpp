#include "Bag.h"
#include "Item.h"

size_t Bag::getUsed(){
	return myBag.size();
}

bool Bag::putInBag(Item &item){
  if(myBag.size() < MAX_BAG_CAPACITY){
    map<string, Item>::iterator it = myBag.at(item.getName());
    if(it == myBag.end()){
      myBag.insert(pair<string, Item>(item.getName(), item));
      return true;
    }
    else{
      if((*it).getNumber + item.getNumber() > MAX_ITEM_CAPACITY)
	return false;
      (*it).Overlay(item.getNumber());
      return true;
  }
  else
    return false;
}
bool Bag::removeFromBag(Item item){
  map<string, Item>::iterator it = myBag.find(item.getName());
  if(it != myBag.end()){
    myBag.erase(it);
    return true;
  }
  else
    return false;
}

bool Bag::removeFrombag(Item item, size_t number){
  map<string, Item>::iterator it = myBag.find(item.getName());
  if(it == myBag.end())
    return false;
  else {
    if((*it).getNumber() <= number){
      myBag.erase(it);
      return true;
    }
    (*it).Remove(number);
    return true;
  }
}
	
