#ifndef HERO_H_
#define HERO_H_
#include "Person.h"

class Equiment {

};




class Hero : public Person {
private:
	int Exp;
	int level;
	Equiment equ;
	Bag bag;
public:
	void CheckUpdate();

};


#endif
