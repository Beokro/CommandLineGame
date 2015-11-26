#pragma once
#include <iostream>

using namespace std;

class Item{
 private:
  static size_t MAX_ITEM_CAPACITY = 99;
  string name;
  size_t number;
  string description;

 public:
  Item(string name, size_t number, string description);
  string getDescription();
  string getName();
  size_t getNumber();
  void Remove(size_t number = 1);
  void Overlay(size_t number = 1);
  bool operator <(Item &item);
	
};
  
