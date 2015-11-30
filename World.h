#ifndef WORLD_H_
#define WORLD_H_

#include"Village.h"
#include"Hero.h"
#include"Boss.h"

using namespace std;

class World {
private:
	vector<Village>villages();
	Boss Dragon;
	vector<Hero>heroAttack;
	bool BossAlive = true;

public:
	World(vector<Village>villages, Boss Dragon);

	//true when nothing happen, false when human start to attack Boss
	bool PassAnotherYear();

	void AddVillage(Village v);

	string InformationAboutThisWorld();

	int GetAgeOfBoss() { return Dragon.GetAge(); }

	//true if Boss win, false if boss is killed, call CheckBossStatus at last
	bool fight();

	void CheckBossStatusAfterFight();

	string PrintVillageName();

	bool CheckVillageExist(string villageName);

	//true if attack success, false if attack failed, call CheckBossStatus
	bool AttackVillage(string villageName);

	//Check if Game is ended
	bool CheckGameEnded() { return !BossAlive; }

	string ShowGameResult();
};


#endif