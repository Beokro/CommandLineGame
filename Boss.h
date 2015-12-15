#ifndef BOSS_H_
#define BOSS_H_

#include"Skill.h"
#include<vector>
#include<string>
#include<algorithm>

using std::vector;
using std::string;

static const int MaxHP = 1000000;
static const int MaxAge = 5000;

class Boss {
private:
	//At first is 1000000, decrease by certain amount every year
	int TotalHP;
	int HP;
	int MP;
	int age;
	int PhysicalDamage;
	vector<Skill> skills;
	int Wealth;

public:
	Boss();
	Boss(int HP, int MP, int PhysicalDamage, int age);
	Boss(int HP, int MP, int PhysicalDamage, int age, vector<Skill> skills);
	int * UseSkill(string skillName);
	int Attack() { return PhysicalDamage; };
	int GetAge() { return age; }
	int GetWealth() { return Wealth; }
	int GetTotalHP() { return TotalHP; }
	int GetHP() { return HP; }
	string ReportStatus();
	//status(PhysicalDamage and total HP) decrease by certain amount, 
	//recover 5% of Total HP if is damaged
	void PassAnotherYear();
};



#endif