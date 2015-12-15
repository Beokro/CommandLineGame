#include"World.h"

World::World(vector<Village>villages, Boss Dragon) {
	this->villages = villages;
	this->Dragon = Dragon;
}

//true when nothing happen, false when human start to attack Boss
bool World::PassAnotherYear() {
	int size = villages.size();
	vector<Hero> HeroHolder;
	bool WawrStart = false;
	for (int i = 0; i < size; i++) {
		if (!villages[i].Develop_In_A_Year()) {
			HeroHolder = villages[i].HeroAttack();
			for (int j = 0; j < HeroHolder.size(); j++)
				heroAttack.push_back(HeroHolder[j]);
			WawrStart = true;
		}
	}
	Dragon.PassAnotherYear();

	if (WawrStart) {
		fight();
		CheckBossStatusAfterFight();
	}
	return !WawrStart;
}

void World::AddVillage(Village v) {
	if (CheckVillageExist(v.GetName())) {
		cout << "Village with same name already exist" << endl;
		return;
	}
	this->villages.push_back(v);
}

string World::InformationAboutThisWorld() {
	string result = "";
	int size = villages.size();
	for (int i = 0; i < size; i++) {
		result += villages[i].ReportStatus();
		result += "\n";
	}

	result += Dragon.ReportStatus();
	result += "\n";
	return result;

}

//change the boss's status and herp's status in heroAttack vector(Change their HP to 0, 
//but don't delete them from vector)
void World::fight() {

}

void World::CheckBossStatusAfterFight() {
	if (this->Dragon.GetHP() == 0) {
		GameEnded = true;
		return;
	}
	if (this->Dragon.GetHP() < (MaxHP / 5)) {
		PassAnotherYear();
	}
}

string World::PrintVillageName() {
	int size = villages.size();
	string result = "";
	for (int i = 0; i < size; i++) {
		result += i;
		result += ". ";
		result += villages[i].GetName();
		result += "\n";
	}
	return result;
}

bool World::CheckVillageExist(string villageName) {
	int size = villages.size();
	for (int i = 0; i < size; i++) {
		if (villageName == villages[i].GetName())
			return true;
	}
	return false;
}

//true if attack success, false if attack failed, call CheckBossStatus
bool World::AttackVillage(string villageName) {

}


void World::ShowGameResult() {
	int size = villages.size();
	cout << "Finally you died, you are " << Dragon.GetAge() << " years old.\n";
	cout << "You own " << Dragon.GetWealth() << " gold conins\n";
	cout << "There are  " << size << " villages survied under your madness\n";
	cout << "You will reborn, see you in next reincarnation\n";
}