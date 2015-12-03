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
	int atk;
	int def;
	int res;
public:
	Person(string name);
	Person(string name, int HP, int MP, int age, int atk, int def, int res);
	void GetDamaged(int damage);
	bool ChangeMP(int change);
	bool ChangeHP(int change);
	bool ChangeRes(int change);
	bool ChangeAtk(int change);
	bool ChangeDef(int change);
	virtual void getOlder();
	bool CheckIfAlive() { return alive; }
	string GetFightingStatus();
	string GetName() { return name; }
	int GetAge() { return age; }
	int GetHP(){ return HP;}
	int GetMP(){ return MP;}
	int GetAtk(){ return atk;}
	int GetRes(){ return res;}
};



#endif
