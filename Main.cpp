#include "Boss.h"
#include "Hero.h"
#include "Village.h"

#include<iostream>
using namespace std;




int main() {
	Boss Dragon(10000, 5000, 700, 1);
	Village v1("Santa Barbara");
	Village v2("Goleta");
	Village v3("Avalon");





	string command = "";
	cout << "Weclome to the this world, you are a Dragon, your goal will be collect as much money as possible. I will give you 5000 years. Good Luck\n";
	cout << "You can use one of the following command\n1.View the World Status\n2.View your Age\n3.Attack villages\n";

	while (cin >> command) {
		if (command != "1"&&command != "2", &&command != "3") {
			cout << "Please enter the valid command number\n";
			continue;
		}


	}

}