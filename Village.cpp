#include "Village.h"

Village::Village(string name, int population, int HeroNumber, vector<Hero>heros, int civil, int wealth) {
	this->name = name;
	this->population = population;
	this->HeroNumber = HeroNumber;
	this->heros = heros;
	this->Civil = civil;
	this->wealth = wealth;
}
Village::Village(string name, int population, int HeroNumber, int civil, int wealth) {
	vector<Hero>temp;
	Village(name, population, HeroNumber, temp, civil, wealth);
}
Village::Village(string name) {
	srand(time(NULL));
	vector<Hero>temp;
	Village(name, 100+rand()%100, 0, temp, rand()%50, 120+rand()%120);
}

//true when nothing happen, false when villages decide to attack the Boss
bool Village::Develop_In_A_Year() {
	int temp;
	//Civil + = 0~5
	Civil += rand() % 5;

	//Population += 0.5% to 2% * Civil/500
	temp =50+ rand() % 150;
	population += (temp * population / 1000 * ((Civil / 500) + 1));

	//Wealth += 0.6% ~2.4% * Civil/500
	temp =60+ rand() % 180;
	wealth += (temp * population / 1000 * ((Civil / 500) + 1));

	for (Hero h : heros)
		h.getOlder();

	CheckSuppors;

	//After entering Gods_age, 1/100 chance the village will attack the Dragon
	if (Civil > 2000) {
		if (rand() % 100 == 0) {
			return true;
		}

	}
	return false;

}

//Random generate a hero
void Village::GiveBirthToHero() {
	Hero rd;
	this->heros.push_back(rd);
}

//change the status of the village if found
bool Village::LookingForHistoricalRemains() {
	srand(time(NULL));
	int chance = rand() % 1000;
	if (chance == 0) {
		cout << "Village " << this->name << " just discovered a Historical Remains \n";
		this->Civil += rand() % 500;
		this->wealth += rand() % 100;
		return true;
	}
	return false;
}

//return satus about the village as string
string Village::ReportStatus() {
	string result = "";
	result += ("Name: " + this->name + "\n");
	result += ("Population: " + to_string(this->population)  + "\n");
	result += ("Hero: " + to_string(this->HeroNumber) + "\n");
	result += ("Civil: " + to_string(this->Civil) + "\n");
	result += ("Wealth: " + to_string(this->wealth) + "\n");
	result += "\n";
	return result;
}


//Add the hero that is going to fight with boss inti the vector
vector<Hero> Village::HeroAttack() {
	return heros;
}


void Village::CheckSuppors() {
	srand(time(NULL));
	if (population > wealth) {
		int temp = rand() % (population - wealth);
		population -= temp;
		Civil -= 1;
	}
}