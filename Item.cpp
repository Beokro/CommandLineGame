#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(){
  name = "";
  number = 0;
  description = "";
  CHP = 0;
  CMP = 0;
  Cres = 0;
  Catk = 0;
  Cdef = 0;
}

Item::Item(string name, size_t number, string description, int CHP, int CMP, int Cres, int Catk, int Cdef){
  this->name = name;
  this->number = number;
  this->description = description;
  this->CHP = CHP;
  this->CMP = CMP;
  this->Cres = Cres;
  this->Catk = Catk;
  this->Cdef = Cdef;
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
  
void Item::Use(Person* p){
  p -> ChangeHP(CHP);
  p -> ChangeMP(CMP);
  p -> ChangeRes(Cres);
  p -> ChangeAtk(Catk);
  p -> ChangeDef(Cdef);
}
	  
