#ifndef PERSON_H_
#define PERSON_H_

#include<string>
using std::string;

class Person {
private:
	int HP;
	int MP;
	int age;
	string name;
	bool alive;
public:
	Person(string name);
	Person(string name, int HP, int MP, int age);
	void GetDamaged(int damage);
	bool UsedMP(int used);
	void getOlder();
	bool CheckIfAlive() { return alive; }
	string GetFightingStatus();
	string GetName() { return name; }
	int GetAge() { return age; }
};



#endif
