#ifndef WORLD_H_
#define WORLD_H_

#include"Village.h"
#include"Hero.h"
#include"Boss.h"
#include<iostream>

using namespace std;

class World {
private:
	vector<Village>villages;
	Boss Dragon;
	vector<Hero*>heroAttack;
	bool GameEnded = false;
	vector<string>VillageNames = {"Athens","Atlantic","Peking","Berlin","London","Los Angeles","Tokyo","Toronto","Washington","Asgard","Camelot","Heaven",
		"Storm", "Shambhala", "Zion", "Utopia", "Agartha", "Aztlan", "Camelot","Azeroth"};

public:
	World(vector<Village>villages, Boss Dragon);

	//true when nothing happen, false when human start to attack Boss
	bool PassAnotherYear();

	void AddVillage(Village v);

	string InformationAboutThisWorld();

	int GetAgeOfBoss() { return Dragon.GetAge(); }

	void PassYears(int n);

	void fight();

	void AddRandomVillage();

	void CheckBossStatusAfterFight();

	string PrintVillageName();

	bool CheckVillageExist(string villageName);

	//true if attack success, false if attack failed, call CheckBossStatus
	bool AttackVillage(string villageName);

	//Check if Game is ended
	bool CheckGameEnded() { return GameEnded; }

	void ShowGameResult();

	Village& GetVillageByName(string name);

	void RemoveVillage(string name);

	//Boss will withstand 3 turns of attack, (Hero will be provided in heroAttack vector). change Boss's status
	void WithStandThreeTurnAttack();
};


#endif