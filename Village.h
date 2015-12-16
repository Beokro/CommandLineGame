#ifndef VILLAGE_H_
#define VILLAGE_H_

#include <iostream>
#include <vector>
#include "Person.h"
#include "Hero.h"
#include <time.h>

using namespace std;

static const int Stone_Age=500;
static const int Bronze_Age = 1000;
static const int Iron_Age = 1500;
static const int Gods_Age = 2000;
static const int Industrial_Revolution = 3000;


class Village {
private:
	string name;
	int population ;
	int HeroNumber ;
	vector<Hero*>heros;
	int Civil ;
	int wealth ;
	int WillPower=0;
public:
	Village(string name, int population, int HeroNumber, vector<Hero*>heros, int civil, int wealth);
	Village(string name, int population, int HeroNumber, int civil, int wealth);
	Village(string name);
	//true when nothing happen, false when villages decide to attack the Boss
	bool Develop_In_A_Year();

	//Random generate a hero
	void GiveBirthToHero();
	
	//change the status of the village if found
	bool LookingForHistoricalRemains();

	//return satus about the village as string
	string ReportStatus();


	string GetName() { return name; }
	int GetPopulation() { return population; }
	int GetWealth() { return wealth; }
	
	//Add the hero that is going to fight with boss inti the vector
	vector<Hero*>& HeroAttack();

	//Check if Village can feed the population, if not population decrease, Civcil will decrease too
	void CheckSuppors();


};

#endif
