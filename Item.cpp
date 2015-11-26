#include <iotream>
#include "Item.h"

using namespce std;

Item::Item(string name, size_t number, string description){
  this->name = name;
  this->number = number;
  this->description = description;
}

string Item::getDescription(){
  return description;
}

string Item::getName(){
  return name;
}

size_t Item::getNumber(){
  return number;
}

void Item::Remove(size_t number = 1){
    this->number -= number;
}
  
void Item::Overlay(size_t number = 1){
    this->number += number;
}

bool operator <(Item &item){
  return this->name < item.getName();
}
  
