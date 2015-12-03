#include"Person.h"

Person::Person(string name) {
	this->name = name;
	HP = 100;
	MP = 50;
	age = 0;
	alive = true;
	atk = 100;
	def = 100;
	res = 0;
}
Person::Person(string name, int HP, int MP, int age, int atk, int def, int res) {
	this->name = name;
	this->HP = HP;
	this->MP = MP;
	this->age = age;
	alive = true;
	this->atk = atk;
	this->def = def;
	this->res = res;
}
void Person::GetDamaged(int damage) {
  HP -= damage * (1 - res);
	if (HP <= 0)
		alive = false;
}
bool Person::ChangeMP(int change) {
	if (MP + change < 0)
		return false;
	MP += change;
	return true;
}

bool Person::ChangeHP(int change){
  if(HP + change < 0)
    return false;
  HP += change;
  return true;
}

bool Person::ChangeRes(int change){
  if(res + change < 0)
    return false;
  res += change;
  return true;
}

bool Person::ChangeAtk(int change){
  if(atk + change < 0)
    return false;
  atk += change;
  return true;
}

bool Person::ChangeDef(int change){
  if(def + change < 0)
    return false;
  def += change;
  return true;
}

void Person::getOlder() {
	this->age+=1;
}

string Person::GetFightingStatus() {
	string status;
	status += "Name: ";
	status += name;
	status += "\n";
	status += "HP: ";
	status += HP;
	status += " \n";
	status += "MP: ";
	status += MP;
	status += "\n";
	return status;
}
