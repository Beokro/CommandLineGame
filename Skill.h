#ifndef SKILL_H_
#define SKILL_H_

class Skill {
	// =0 if skill is target to self, = anything else means skill is target to enemy
	int TargetEmemy;

	//= 0 if it is not aoe, = anything else if it is a AOE
	int AOE;

	int HPChangeValue;
	int MPCost;
public:
	Skill(int TargetEmemy, int AOE, int HPChangeValue, int MPCost);
	//return the Skill info in order, Boss and Hero class will decide how to use these data
	int* ReturnSKillInfo();
};

#endif