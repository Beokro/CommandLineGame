#ifndef BOSS_H_
#define BOSS_H_
#include "Skill.h"
#include<vector>
#include<string>
using std::vector;
using std::string;

static const int MaxHP = 1000000;

class Boss {
private:
	int HP;
	int MP;
	int age;
	int PhysicalDamage;
	vector<Skill> skills;

public:
	Boss(int HP, int MP, int PhysicalDamage, int age);
	Boss(int HP, int MP, int PhysicalDamage, int age, vector<Skill> skills);
	int * UseSkill(string skillName);
	int Attack() { return PhysicalDamage; };
};



#endif