#include"World.h"

World::World(vector<Village>villages, Boss Dragon) {
	this->villages = villages;
	this->Dragon = Dragon;
}

//true when nothing happen, false when human start to attack Boss
bool World::PassAnotherYear() {
	int size = villages.size();
	vector<Hero*> HeroHolder;
	bool WawrStart = false;

	//Every village pass a year
	for (int i = 0; i < size; i++) {
		if (villages[i].Develop_In_A_Year()) {
			HeroHolder = villages[i].HeroAttack();
			for (int j = 0; j < HeroHolder.size(); j++)
				heroAttack.push_back(HeroHolder[j]);
			WawrStart = true;
		}
	}

	//Boss pass another year
	Dragon.PassAnotherYear();

	//1/100 chance add a new village
	if (rand() % 100 == 0) {
		AddRandomVillage();
	}

	if (WawrStart) {
		fight();
		CheckBossStatusAfterFight();
	}
	return !WawrStart;
}


void World::AddRandomVillage() {
	int size = VillageNames.size(), temp = rand() % size;
	//if run out of the names, return without doing anything
	if (size == 0)
		return;
	string name = VillageNames[temp];
	VillageNames.erase(VillageNames.begin() + temp);
	AddVillage(Village(name));
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
//***********Remember change the WarStart back to false
void World::fight() {

}

void World::CheckBossStatusAfterFight() {
	cout << Dragon.ReportStatus() << endl;
	if (this->Dragon.GetHP() == 0) {
		GameEnded = true;
		return;
	}
	if (this->Dragon.GetHP() < (Dragon.GetTotalHP() / 5)) {
		cout << "You are injured, you must go to sleep for 10 years";
		PassYears(10);
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

//true if attack success, false if attack failed or cancel
bool World::AttackVillage(string villageName) {
	int coinsToTake = 0;
	Village& v = GetVillageByName(villageName);
	string command = "";
	cout << v.ReportStatus() << endl;
	cout << "Now you have two options. Enter 1 to destroy this village. Enter 2 to Plunder this village\n Enter B to back to main menu\n";
	cin >> command;
	while (command != "1"&&command != "2"&&command != "B"&&command != "b") {
		cout << "Invalid command, please try again\n";
		cin >> command;
		if (command == "B")
			return false;
	}
	if (command == "1") {
		heroAttack.clear();
		heroAttack = v.HeroAttack();
		fight();
		if (Dragon.GetHP() > 0) {
			cout << "You've successfully destroy this village\n";
			cout << "You have gain " << v.GetWealth() << " coins\n";
			Dragon.GainWealth(v.GetWealth());
			RemoveVillage(v.GetName());
		}
		CheckBossStatusAfterFight();
	}
	
	else if (command == "2") {
		cout << "If you want to fight with all heroes in this village, enter 1.";
		cout << "If you want to instead withstand 3 turns of their attack, enter 2. Enter B to back";
		cin >> command;
		while (command != "1"&&command != "2"&&command != "B"&&command != "b") {
			cout << "Invalid command, please try again\n";
			cin >> command;
			if (command == "B" || command == "b") {
				cout << "You have cancel the attack\n";
				return false;
			}
		}

		if (command == "1") {
			heroAttack.clear();
			heroAttack = v.HeroAttack();
			fight();
			//Because of the attack 3%~15% of population of this village will die
			int twelve_Percent_Population = v.GetPopulation()*0.12, three_percentage_population = v.GetPopulation()*0.03;
			int peopleDie = three_percentage_population + rand() % twelve_Percent_Population;
			v.LosePopulation(peopleDie);
			cout << "Because of your attack, " << peopleDie << " people dies\n";


			if (Dragon.GetHP() > 0) {
				cout << "You have succesfully beat all heroes in this village\n";
				cout << v.ReportStatus() << endl;
				cout << "Enter the amount of gold you want to take\n";
				cin >> coinsToTake;
				coinsToTake = v.LoseWealth(coinsToTake);
				Dragon.GainWealth(coinsToTake);
			}
			CheckBossStatusAfterFight();
		}

		else{
			heroAttack.clear();
			heroAttack = v.HeroAttack();
			WithStandThreeTurnAttack();
			if (Dragon.GetHP() > 0) {
				cout << "You have succesfully withstand three turns of attack\n";
				cout << "Enter the amount of gold you want to take\n";
				cin >> coinsToTake;
				coinsToTake = v.LoseWealth(coinsToTake);
				Dragon.GainWealth(coinsToTake);
			}
			CheckBossStatusAfterFight();
		}


	}
}


void World::ShowGameResult() {
	int size = villages.size();
	cout << "Finally you died, you are " << Dragon.GetAge() << " years old.\n";
	cout << "You own " << Dragon.GetWealth() << " gold conins\n";
	cout << "There are  " << size << " villages survied under your madness\n";
	cout << "You will reborn, see you in next reincarnation\n";
}

void World::PassYears(int n) {
	for (int i = 0; i < n; i++) {
		PassAnotherYear();
		if (CheckGameEnded)
			break;
	}
}

Village& World::GetVillageByName(string name) {
	for (int i = 0; i < villages.size(); i++) {
		if (villages[i].GetName() == name)
			return villages[i];
	}
}


void World::RemoveVillage(string name) {
	int size = villages.size();
	for (int i = 0; i < size; i++) {
		if (villages[i].GetName == name) {
			villages.erase(villages.begin() + i);
			return;
		}
	}
	cout << "The village with name " << name << " does not exist, unknown error\n";
}