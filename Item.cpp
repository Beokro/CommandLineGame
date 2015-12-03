#include <iostream>
#include "Item.h"

using namespace std;

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

void Item::Remove(size_t number){
    this->number -= number;
}
  
bool Item::Overlay(size_t number ){
    if(this -> number + number > MAX_ITEM_CAPACITY)
        return false;
    this->number += number;
    return true;
}

bool Item::operator <(Item &item){
  return this->name < item.getName();
}
  
