#include"Person.h"

Person::Person(string name) {
	this->name = name;
	HP = 100;
	MP = 50;
	age = 0;
	alive = true;
}
Person::Person(string name, int HP, int MP, int age) {
	this->name = name;
	this->HP = HP;
	this->MP = MP;
	this->age = age;
	alive = true;
}
void Person::GetDamaged(int damage) {
	HP -= damage;
	if (HP <= 0)
		alive = false;
}
bool Person::UsedMP(int used) {
	if (MP < used)
		return false;
	MP -= used;
	return true;
}
void Person::getOlder(int age) {
	this->age += age;
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