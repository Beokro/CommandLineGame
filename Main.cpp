#include "World.h"
#include<iostream>
using namespace std;




int main() {
	Boss Dragon(10000, 5000, 700, 1);
	vector<Village>villages;
	villages.push_back(Village("Avalon"));
	villages.push_back(Village("Jerusalem"));
	villages.push_back(Village("Changan"));

	World thisWorld(villages, Dragon);
	int yearToSleep = 0;
	string villageName = "";



	string command = "";
	cout << "Weclome to the this world, you are a Dragon, your goal will be collect as much money as possible. I will give you 5000 years. Good Luck\n";
	cout << "You can use one of the following command\n1.View the World Status\n2.Sleep\n3.Attack villages\n";

	while (cin >> command) {
		if (command != "1"&& command != "2" &&command != "3") {
			cout << "Please enter the valid command number\n";
			continue;
		}

		if (command == "1") {
			cout << thisWorld.InformationAboutThisWorld() << endl;
			continue;
		}

		if (command == "2") {
			cout << "Enter the year you want to sleep" << endl;
			cin >> yearToSleep;
			if (yearToSleep < 0) {
				cout << "Invalid number, back to main selection\n";
				continue;
			}
			thisWorld.PassYears(yearToSleep);
			if (thisWorld.CheckGameEnded())
				break;

			continue;
		}

		if (command == "3") {
			cout << thisWorld.PrintVillageName()<<endl;
			cout << "Enter the name of the village you want to attack\n";
			cin >> villageName;
			if (!thisWorld.CheckVillageExist(villageName))
				continue;
			thisWorld.AttackVillage(villageName);
			if (thisWorld.CheckGameEnded())
				break;
		}

	}
	thisWorld.ShowGameResult();

}