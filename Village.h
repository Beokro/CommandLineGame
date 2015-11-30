#ifndef VILLAGE_H_
#define VILLAGE_H_

#include"Hero.h"

static const int Stone_Age=500;
static const int Bronze_Age = 1000;
static const int Iron_Age = 1500;
static const int Gods_Age = 2000;
static const int Industrial_Revolution = 3000;


class Village {
private:
	string name;
	int population = 300;
	int HeroNumber = 0;
	vector<Hero>heros;
	int Civil = 0;
	int wealth = 600;
public:
	Village(string name, int population, int HeroNumber, vector<Hero>heros, int civil, int wealth);
	Village(string name, int population, int HeroNumber, int civil, int wealth);
	Village(string name);
	//true when nothing happen, false when villages decide to attack the Boss
	bool Develop_In_A_Year();
	void GiveBirthToHero();
	void LookingForHistoricalRemains();
	string ReportStatus();
	string GetName() { return name; }
	int GetPopulation() { return population; }
	vector<Hero> HeroAttack();


};

#endif