#include"Skill.h"

Skill::Skill(int TargetEmemy, int AOE, int HPChangeValue, int MPCost) {
	this->TargetEmemy = TargetEmemy;
	this->AOE = AOE;
	this->HPChangeValue = HPChangeValue;
	this->MPCost = MPCost;
}



//return the Skill info in order, Boss and Hero class will decide how to use these data
int* Skill::ReturnSKillInfo() {
	int* result = new int[4];
	result[0] = TargetEmemy;
	result[1] = AOE;
	result[2] = HPChangeValue;
	result[3] = MPCost;
	return result;
}