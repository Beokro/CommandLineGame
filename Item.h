#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include "Person.h"
using namespace std;

class Item{
 private:
  const static size_t MAX_ITEM_CAPACITY = 99;
  string name;
  size_t number;
  string description;
  int CHP;
  int CMP;
  int Cres;
  int Catk;
  int Cdef;

 public:
  Item();
  Item(string name, size_t number, string description, int CHP, int CMP, int Cres, int Catk, int Cdef);
  string getDescription();
  string getName();
  size_t getNumber();
  int getCHP(){ return CHP;}
  int getCMP(){ return CMP;}
  int getCres(){ return Cres;}
  int getCatk(){ return Catk;}
  int getCdef(){ return Cdef;}
  void Remove(size_t number = 1);
  bool Overlay(size_t number = 1);
  bool operator <(Item &item);
  //change person's status 
  void Use(Person* p);
};

#endif
  
